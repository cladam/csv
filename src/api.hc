// api.hc — Accessor API for CsvTable
import "./csv_types"

// ============================================================
// Basic accessors
// ============================================================

pub fun csv_headers(t: CsvTable) : list<string> => t.headers

pub fun csv_rows(t: CsvTable) : list<list<string>> => t.rows

pub fun csv_num_rows(t: CsvTable) : int => length(t.rows)

pub fun csv_num_cols(t: CsvTable) : int {
  if length(t.headers) > 0 {
    length(t.headers)
  } else {
    match t.rows {
      [] => 0,
      [first, ..] => length(first)
    }
  }
}

// ============================================================
// Row and cell access
// ============================================================

// Get the nth element of a list<string> (0-based). Returns None if out of bounds.
pub fun str_at(xs: list<string>, i: int) : maybe<string> => match xs {
  [] => None,
  [x, ..rest] => if i == 0 { Some(x) } else { str_at(rest, i - 1) }
}

// Internal helper: index into list<list<string>>.
pub fun row_at(rows: list<list<string>>, i: int) : maybe<list<string>> => match rows {
  [] => None,
  [r, ..rest] => if i == 0 { Some(r) } else { row_at(rest, i - 1) }
}

// Get a row by index (0-based).
pub fun csv_row(t: CsvTable, i: int) : maybe<list<string>> =>
  row_at(t.rows, i)

// Get a cell by row and column index (0-based).
pub fun csv_get(t: CsvTable, row: int, col: int) : maybe<string> =>
  match csv_row(t, row) {
    Some(r) => str_at(r, col),
    None => None
  }

// ============================================================
// Named column access
// ============================================================

// Find the index of a header by name. Returns -1 if not found.
pub fun find_col(headers: list<string>, name: string, i: int) : int => match headers {
  [] => -1,
  [h, ..rest] => if h == name { i } else { find_col(rest, name, i + 1) }
}

// Get a cell by row index and column name.
pub fun csv_get_by_name(t: CsvTable, row: int, name: string) : maybe<string> {
  let col = find_col(t.headers, name, 0)
  if col < 0 { None } else { csv_get(t, row, col) }
}

// ============================================================
// Row as associative map
// ============================================================

// Zip header names with row values into a key-value list.
pub fun zip_str(ks: list<string>, vs: list<string>) : list<(string, string)> =>
  match ks {
    [] => [],
    [k, ..ks2] => match vs {
      [] => [],
      [v, ..vs2] => [(k, v)] + zip_str(ks2, vs2)
    }
  }

// Get a row as a list<(header, value)> map. Returns None if the index is out of bounds.
pub fun csv_row_as_map(t: CsvTable, i: int) : maybe<list<(string, string)>> =>
  match csv_row(t, i) {
    Some(r) => Some(zip_str(t.headers, r)),
    None => None
  }

// ============================================================
// Iteration helpers
// ============================================================

// Apply a function to every row (for side effects).
pub fun csv_foreach_row(t: CsvTable, f: (list<string>) -> ()) : () =>
  foreach(t.rows, f)

// Transform every row into a new list.
pub fun csv_map_rows(t: CsvTable, f: (list<string>) -> list<string>) : CsvTable =>
  CsvTable { headers: t.headers, rows: map(t.rows, f) }

// Keep only rows that satisfy a predicate.
pub fun csv_filter_rows(t: CsvTable, f: (list<string>) -> bool) : CsvTable =>
  CsvTable { headers: t.headers, rows: filter(t.rows, f) }
