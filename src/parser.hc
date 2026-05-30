// parser.hc — RFC 4180 CSV parser
import "./csv_types"

// Internal result type for field parsing
pub struct FieldResult {
  value: string,
  row_end: bool,
  remaining: list<string>
}

// ============================================================
// Character-level parsing
// ============================================================

// Parse chars inside a quoted field (after the opening quote).
// Returns (field_content, chars_after_closing_quote).
pub fun parse_quoted_chars(chars: list<string>, quote: string, acc: list<string>) : (string, list<string>) {
  match chars {
    [] =>
      (join(reverse(acc), ""), []),
    [c, next, ..rest] if c == quote && next == quote =>
      parse_quoted_chars(rest, quote, [quote] + acc),
    [c, ..rest] if c == quote =>
      (join(reverse(acc), ""), rest),
    [c, ..rest] =>
      parse_quoted_chars(rest, quote, [c] + acc)
  }
}

// Skip chars after a closing quote until the next field boundary.
// Returns (at_row_end, remaining_chars).
pub fun skip_after_quote(chars: list<string>, delim: string) : (bool, list<string>) {
  match chars {
    [] => (true, []),
    [c, ..rest] if c == delim => (false, rest),
    ["\n", ..rest] => (true, rest),
    ["\r", "\n", ..rest] => (true, rest),
    ["\r", ..rest] => (true, rest),
    [_, ..rest] => skip_after_quote(rest, delim)
  }
}

// Accumulate chars for an unquoted field until a field boundary.
pub fun parse_unquoted_chars(chars: list<string>, delim: string, acc: list<string>) : FieldResult {
  match chars {
    [] =>
      FieldResult { value: join(reverse(acc), ""), row_end: true, remaining: [] },
    [c, ..rest] if c == delim =>
      FieldResult { value: join(reverse(acc), ""), row_end: false, remaining: rest },
    ["\n", ..rest] =>
      FieldResult { value: join(reverse(acc), ""), row_end: true, remaining: rest },
    ["\r", "\n", ..rest] =>
      FieldResult { value: join(reverse(acc), ""), row_end: true, remaining: rest },
    ["\r", ..rest] =>
      FieldResult { value: join(reverse(acc), ""), row_end: true, remaining: rest },
    [c, ..rest] =>
      parse_unquoted_chars(rest, delim, [c] + acc)
  }
}

// Parse a quoted field (chars after the opening quote has been consumed).
pub fun parse_quoted_field(chars: list<string>, delim: string, quote: string) : FieldResult {
  let (val, after_quote) = parse_quoted_chars(chars, quote, [])
  let (at_end, remaining) = skip_after_quote(after_quote, delim)
  FieldResult { value: val, row_end: at_end, remaining: remaining }
}

// Parse one field from a character stream.
pub fun parse_one_field(chars: list<string>, delim: string, quote: string) : FieldResult {
  match chars {
    [] =>
      FieldResult { value: "", row_end: true, remaining: [] },
    [c, ..rest] if c == quote =>
      parse_quoted_field(rest, delim, quote),
    [c, ..rest] if c == delim =>
      FieldResult { value: "", row_end: false, remaining: rest },
    ["\n", ..rest] =>
      FieldResult { value: "", row_end: true, remaining: rest },
    ["\r", "\n", ..rest] =>
      FieldResult { value: "", row_end: true, remaining: rest },
    ["\r", ..rest] =>
      FieldResult { value: "", row_end: true, remaining: rest },
    [c, ..rest] =>
      parse_unquoted_chars(rest, delim, [c])
  }
}

// ============================================================
// Row-level parsing
// ============================================================

// Parse one complete row. Returns (fields, remaining_chars).
pub fun parse_row(chars: list<string>, delim: string, quote: string, acc: list<string>) : (list<string>, list<string>) {
  let fr = parse_one_field(chars, delim, quote)
  if fr.row_end {
    (reverse([fr.value] + acc), fr.remaining)
  } else {
    parse_row(fr.remaining, delim, quote, [fr.value] + acc)
  }
}

pub fun is_empty_row(row: list<string>) : bool => match row {
  [""] => true,
  _ => false
}

// Decide whether to emit the row and continue, or stop (trailing newline).
pub fun finish_or_continue(row: list<string>, remaining: list<string>, delim: string, quote: string) : list<list<string>> {
  match remaining {
    [] => if is_empty_row(row) { [] } else { [row] },
    _ => [row] + parse_all_rows(remaining, delim, quote)
  }
}

// Parse all rows from a character stream.
pub fun parse_all_rows(chars: list<string>, delim: string, quote: string) : list<list<string>> {
  match chars {
    [] => [],
    _ => {
      let (row, remaining) = parse_row(chars, delim, quote, [])
      finish_or_continue(row, remaining, delim, quote)
    }
  }
}

// ============================================================
// Public parse functions
// ============================================================

pub fun csv_parse_opts(input: string, opts: CsvOptions) : CsvTable {
  let chars = split(input, "")
  let all_rows = parse_all_rows(chars, opts.delimiter, opts.quote_char)
  if opts.has_header {
    match all_rows {
      [] => CsvTable { headers: [], rows: [] },
      [first, ..rest] => CsvTable { headers: first, rows: rest }
    }
  } else {
    CsvTable { headers: [], rows: all_rows }
  }
}

// Parse CSV with default options (comma delimiter, first row is header).
pub fun csv_parse(input: string) : CsvTable =>
  csv_parse_opts(input, default_opts())
