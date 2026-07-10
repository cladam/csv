// display.hc — Display and serialization for CsvTable
import "./csv_types"

// ============================================================
// Column width computation
// ============================================================

// Width of the header at column col.
pub fun header_width(headers: list<string>, col: int) : int => match headers {
  [] => 0,
  [h, ..rest] => if col == 0 { str_length(h) } else { header_width(rest, col - 1) }
}

// Length of the cell at column col in one row.
pub fun cell_len(cells: list<string>, col: int) : int => match cells {
  [] => 0,
  [c, ..rest] => if col == 0 { str_length(c) } else { cell_len(rest, col - 1) }
}

// Maximum cell length at column col across all rows.
pub fun max_col_width(rows: list<list<string>>, col: int, acc: int) : int =>
  fold(rows, acc, (a, row) => max(a, cell_len(row, col)))

// Number of columns (headers if present, else first row).
pub fun display_num_cols(t: CsvTable) : int {
  if length(t.headers) > 0 {
    length(t.headers)
  } else {
    match t.rows {
      [] => 0,
      [first, ..] => length(first)
    }
  }
}

// Display width for column col (max of header and all data cells).
pub fun col_width_for(t: CsvTable, col: int) : int {
  let hw = header_width(t.headers, col)
  max_col_width(t.rows, col, hw)
}

// Compute display widths for all columns.
pub fun compute_widths(t: CsvTable, n: int, i: int) : list<int> {
  if i >= n { [] }
  else { [col_width_for(t, i)] + compute_widths(t, n, i + 1) }
}

pub fun col_widths(t: CsvTable) : list<int> =>
  compute_widths(t, display_num_cols(t), 0)

// ============================================================
// Table formatting
// ============================================================

pub fun head_width(widths: list<int>) : int => match widths {
  [] => 0,
  [w, ..] => w
}

// Format a single row using pre-computed column widths.
pub fun format_cells(cells: list<string>, widths: list<int>) : string {
  match cells {
    [] => "",
    [c] => pad_right(c, head_width(widths), " "),
    [c, ..rest] =>
      pad_right(c, head_width(widths), " ") + " | " + format_cells(rest, tail(widths))
  }
}

// Separator line between header and data rows.
pub fun separator_line(widths: list<int>) : string {
  match widths {
    [] => "",
    [w] => repeat_str("-", w),
    [w, ..rest] => repeat_str("-", w) + "-+-" + separator_line(rest)
  }
}

// Format all data rows as strings.
pub fun rows_to_strs(rows: list<list<string>>, widths: list<int>) : list<string> =>
  map(rows, (row) => format_cells(row, widths))

// ============================================================
// Public display functions
// ============================================================

// Brief metadata string: "[csv: 3 rows x 4 cols]"
pub fun csv_show(t: CsvTable) : string =>
  "[csv: " + show(length(t.rows)) + " rows x " + show(display_num_cols(t)) + " cols]"

// Pretty-print as an aligned table with a header separator.
pub fun csv_pretty(t: CsvTable) : string {
  let widths = col_widths(t)
  let header_part =
    if length(t.headers) > 0 {
      format_cells(t.headers, widths) + "\n" + separator_line(widths) + "\n"
    } else { "" }
  let data_part = rows_to_strs(t.rows, widths) |> join("\n")
  header_part + data_part
}

// ============================================================
// Serialization — back to CSV
// ============================================================

// Quote a field if it contains special characters (RFC 4180).
pub fun csv_quote_field(s: string, delim: string, quote: string) : string {
  if contains(s, delim) || contains(s, quote) || contains(s, "\n") || contains(s, "\r") {
    quote + replace(s, quote, quote + quote) + quote
  } else { s }
}

// Format one row as a CSV line.
pub fun format_csv_fields(fields: list<string>, delim: string, quote: string) : string =>
  fields
    |> map((f) => csv_quote_field(f, delim, quote))
    |> join(delim)

// Format all rows as CSV lines.
pub fun format_csv_rows(rows: list<list<string>>, delim: string, quote: string) : list<string> =>
  map(rows, (row) => format_csv_fields(row, delim, quote))

pub fun csv_to_csv_opts(t: CsvTable, opts: CsvOptions) : string {
  let d = opts.delimiter
  let q = opts.quote_char
  let header_part =
    if length(t.headers) > 0 { format_csv_fields(t.headers, d, q) + "\n" }
    else { "" }
  let body = format_csv_rows(t.rows, d, q) |> join("\n")
  header_part + body
}

// Serialize back to CSV with default options.
pub fun csv_to_csv(t: CsvTable) : string =>
  csv_to_csv_opts(t, default_opts())
