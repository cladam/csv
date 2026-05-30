# csv

An RFC 4180 CSV parser library for [hica](https://github.com/cladam/hica). Parses comma-separated and delimiter-separated text into typed tables with named column access, filtering, aggregation, and round-trip serialization.

## Installation

Add as a git submodule to your hica project:

```sh
git submodule add https://github.com/cladam/csv.git lib/csv
```

Then import the library:

```rust
import "./lib/csv/src/csv"
```

## Supported CSV

- **RFC 4180** compliant: quoted fields, embedded delimiters, doubled-quote escaping
- **Line endings**: `\n`, `\r\n`, and `\r`
- **Empty fields**: leading, trailing, and mid-row
- **Custom delimiters**: tab (TSV), semicolon, or any single-character separator
- **Header row**: optional — `has_header: true/false` in `CsvOptions`
- **Round-trip**: serialize a `CsvTable` back to CSV (or any other delimiter)

## Quick start

```rust
import "./lib/csv/src/csv"

fun main() {
  let input = "name,age,city\nAlice,30,New York\nBob,25,London"
  let t = csv_parse(input)

  println(csv_pretty(t))
  // name  | age | city    
  // ------+-----+---------
  // Alice | 30  | New York
  // Bob   | 25  | London  

  match csv_get_by_name(t, 1, "city") {
    Some(v) => println(v),   // London
    None => println("not found")
  }
}
```

## API

### Types

```rust
struct CsvOptions {
  delimiter: string,   // default ","
  has_header: bool,    // default true
  quote_char: string   // default "\""
}

struct CsvTable {
  headers: list<string>,
  rows: list<list<string>>
}

fun default_opts() : CsvOptions
```

### Parsing

| Function | Signature | Purpose |
|---|---|---|
| `csv_parse` | `(string) -> CsvTable` | Parse with default options |
| `csv_parse_opts` | `(string, CsvOptions) -> CsvTable` | Parse with custom options |

```rust
// Default (comma, header row, double-quote)
let t = csv_parse(input)

// Tab-separated, no header
let opts = CsvOptions { delimiter: "\t", has_header: false, quote_char: "\"" }
let t = csv_parse_opts(input, opts)
```

### Accessors

| Function | Signature | Purpose |
|---|---|---|
| `csv_headers` | `(CsvTable) -> list<string>` | Header row |
| `csv_rows` | `(CsvTable) -> list<list<string>>` | All data rows |
| `csv_num_rows` | `(CsvTable) -> int` | Number of data rows |
| `csv_num_cols` | `(CsvTable) -> int` | Number of columns |
| `csv_row` | `(CsvTable, int) -> maybe<list<string>>` | Row by index |
| `csv_get` | `(CsvTable, int, int) -> maybe<string>` | Cell by row and column index |
| `csv_get_by_name` | `(CsvTable, int, string) -> maybe<string>` | Cell by row index and column name |
| `csv_row_as_map` | `(CsvTable, int) -> maybe<list<(string, string)>>` | Row as `header → value` map |
| `find_col` | `(list<string>, string, int) -> int` | Header index, or -1 if missing |
| `str_at` | `(list<string>, int) -> maybe<string>` | Safe element access on a row |

### Iteration

| Function | Signature | Purpose |
|---|---|---|
| `csv_filter_rows` | `(CsvTable, (list<string>) -> bool) -> CsvTable` | Keep rows matching predicate |
| `csv_map_rows` | `(CsvTable, (list<string>) -> list<string>) -> CsvTable` | Transform every row |
| `csv_foreach_row` | `(CsvTable, (list<string>) -> ()) -> ()` | Side-effectful iteration |

### Display

| Function | Signature | Purpose |
|---|---|---|
| `csv_show` | `(CsvTable) -> string` | Short summary: `[csv: 3 rows x 4 cols]` |
| `csv_pretty` | `(CsvTable) -> string` | Aligned table with header separator |

### Serialization

| Function | Signature | Purpose |
|---|---|---|
| `csv_to_csv` | `(CsvTable) -> string` | Serialize with default options |
| `csv_to_csv_opts` | `(CsvTable, CsvOptions) -> string` | Serialize with custom options |
| `csv_quote_field` | `(string, string, string) -> string` | Quote a single field if needed |

## Examples

### Filter and aggregate

```rust
import "./lib/csv/src/csv"

fun main() {
  let t = csv_parse("product,qty,price\nApple,10,3\nBanana,25,1\nCherry,5,8")

  // Filter rows where price > 2
  let expensive = csv_filter_rows(t, (row) =>
    match str_at(row, 2) { Some(v) => to_int(v) > 2, None => false }
  )
  println(csv_pretty(expensive))

  // Total quantity
  let total = fold(t.rows, 0, (acc, row) =>
    match str_at(row, 1) { Some(v) => acc + to_int(v), None => acc }
  )
  println("Total qty: {total}")
}
```

### Add a computed column

```rust
fun add_revenue(row: list<string>) : list<string> {
  let q = match str_at(row, 1) { Some(v) => to_int(v), None => 0 }
  let p = match str_at(row, 2) { Some(v) => to_int(v), None => 0 }
  row + [show(q * p)]
}

fun main() {
  let t = csv_parse("product,qty,price\nApple,10,3\nBanana,25,1")
  let with_rev = CsvTable {
    headers: t.headers + ["revenue"],
    rows: map(t.rows, add_revenue)
  }
  println(csv_pretty(with_rev))
}
```

### Read from a file

```rust
import "./lib/csv/src/csv"

fun main() {
  match read_file("data.csv") {
    Ok(text) => println(csv_pretty(csv_parse(text))),
    Err(e)   => println("Error: {e}")
  }
}
```

### Format conversion (CSV → TSV)

```rust
import "./lib/csv/src/csv"

fun main() {
  let t    = csv_parse("name,city\nAlice,London")
  let opts = CsvOptions { delimiter: "\t", has_header: true, quote_char: "\"" }
  println(csv_to_csv_opts(t, opts))
}
```

## Source layout

```
src/
  csv.hc        — barrel module (pub import all)
  csv_types.hc  — CsvOptions, CsvTable, default_opts
  parser.hc     — RFC 4180 character-level parser
  api.hc        — accessors and iteration helpers
  display.hc    — csv_pretty, csv_show, csv_to_csv
examples/
  basic_parsing.hc       — parse, access, quoted fields, TSV, round-trip
  filter_and_transform.hc — computed columns, filter, aggregation
  read_file.hc           — file I/O, per-group stats, row lookup
  tsv_and_roundtrip.hc   — delimiter conversion, quoting edge cases
tests/
  test_parser.hc   — 18 parser tests
  test_api.hc      — 24 accessor and iteration tests
  test_display.hc  — 14 display and serialization tests
```

## Running tests

```sh
hica test tests/test_parser.hc
hica test tests/test_api.hc
hica test tests/test_display.hc
```
