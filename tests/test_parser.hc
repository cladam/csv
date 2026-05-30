// tests/test_parser.hc — Parser tests for csv_parse / csv_parse_opts
import "../src/csv"

// ============================================================
// Empty / minimal inputs
// ============================================================

test "empty string yields empty table" {
  let t = csv_parse("")
  assert(length(t.headers) == 0)
  assert(length(t.rows) == 0)
}

test "header-only input has no data rows" {
  let t = csv_parse("name,age,city")
  assert(length(t.headers) == 3)
  assert(length(t.rows) == 0)
}

test "single data row with header" {
  let t = csv_parse("a,b\n1,2")
  assert(length(t.headers) == 2)
  assert(length(t.rows) == 1)
}

// ============================================================
// Header values
// ============================================================

test "headers are parsed correctly" {
  let t = csv_parse("name,age,city\nAlice,30,London")
  let h0 = str_at(t.headers, 0)
  let ok0 = match h0 { Some(v) => v == "name", None => false }
  assert(ok0)
  let h1 = str_at(t.headers, 1)
  let ok1 = match h1 { Some(v) => v == "age", None => false }
  assert(ok1)
  let h2 = str_at(t.headers, 2)
  let ok2 = match h2 { Some(v) => v == "city", None => false }
  assert(ok2)
}

// ============================================================
// Multiple rows
// ============================================================

test "multiple data rows are all parsed" {
  let t = csv_parse("a,b\n1,2\n3,4\n5,6")
  assert(length(t.rows) == 3)
}

test "trailing newline does not produce an extra row" {
  let t = csv_parse("a,b\n1,2\n")
  assert(length(t.rows) == 1)
}

// ============================================================
// Quoted fields
// ============================================================

test "quoted field containing a comma" {
  let t = csv_parse("a,b\n\"hello, world\",2")
  let r = csv_get(t, 0, 0)
  let ok = match r { Some(v) => v == "hello, world", None => false }
  assert(ok)
}

test "quoted field with doubled embedded quote" {
  let t = csv_parse("a,b\n\"say \"\"hi\"\"\",2")
  let r = csv_get(t, 0, 0)
  let ok = match r { Some(v) => v == "say \"hi\"", None => false }
  assert(ok)
}

test "quoted field spanning special characters is preserved" {
  let t = csv_parse("notes\n\"line one\nline two\"")
  assert(length(t.rows) == 1)
  let r = csv_get(t, 0, 0)
  let ok = match r { Some(v) => contains(v, "line one"), None => false }
  assert(ok)
}

test "empty quoted field" {
  let t = csv_parse("a,b\n\"\",2")
  let r = csv_get(t, 0, 0)
  let ok = match r { Some(v) => v == "", None => false }
  assert(ok)
}

// ============================================================
// Empty (unquoted) fields
// ============================================================

test "empty field between delimiters" {
  let t = csv_parse("a,b,c\n1,,3")
  let r = csv_get(t, 0, 1)
  let ok = match r { Some(v) => v == "", None => false }
  assert(ok)
}

test "leading empty field" {
  let t = csv_parse("a,b,c\n,2,3")
  let r = csv_get(t, 0, 0)
  let ok = match r { Some(v) => v == "", None => false }
  assert(ok)
}

test "trailing empty field" {
  let t = csv_parse("a,b,c\n1,2,")
  let r = csv_get(t, 0, 2)
  let ok = match r { Some(v) => v == "", None => false }
  assert(ok)
}

// ============================================================
// Line endings
// ============================================================

test "crlf line endings" {
  let t = csv_parse("a,b\r\n1,2\r\n3,4")
  assert(length(t.rows) == 2)
}

test "cr-only line endings" {
  let t = csv_parse("a,b\r1,2\r3,4")
  assert(length(t.rows) == 2)
}

// ============================================================
// Options: no-header mode
// ============================================================

test "no-header mode treats all rows as data" {
  let opts = CsvOptions { delimiter: ",", has_header: false, quote_char: "\"" }
  let t = csv_parse_opts("1,2,3\n4,5,6", opts)
  assert(length(t.headers) == 0)
  assert(length(t.rows) == 2)
}

// ============================================================
// Options: custom delimiter (TSV)
// ============================================================

test "tab delimiter splits correctly" {
  let opts = CsvOptions { delimiter: "\t", has_header: true, quote_char: "\"" }
  let t = csv_parse_opts("id\tname\n1\tAlice", opts)
  assert(length(t.headers) == 2)
  assert(length(t.rows) == 1)
  let r = csv_get(t, 0, 1)
  let ok = match r { Some(v) => v == "Alice", None => false }
  assert(ok)
}

test "tab delimiter does not split on comma" {
  let opts = CsvOptions { delimiter: "\t", has_header: false, quote_char: "\"" }
  let t = csv_parse_opts("a,b\tc", opts)
  assert(length(t.rows) == 1)
  let r = csv_get(t, 0, 0)
  let ok = match r { Some(v) => v == "a,b", None => false }
  assert(ok)
}
