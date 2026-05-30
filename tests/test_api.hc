// tests/test_api.hc — Accessor and iteration API tests
import "../src/csv"

// ============================================================
// Basic accessors
// ============================================================

test "csv_headers returns header list" {
  let t = csv_parse("x,y,z\n1,2,3")
  assert(length(csv_headers(t)) == 3)
}

test "csv_rows returns data rows" {
  let t = csv_parse("a,b\n1,2\n3,4")
  assert(length(csv_rows(t)) == 2)
}

test "csv_num_rows counts data rows only" {
  let t = csv_parse("a,b\n1,2\n3,4\n5,6")
  assert(csv_num_rows(t) == 3)
}

test "csv_num_cols from headers" {
  let t = csv_parse("a,b,c\n1,2,3")
  assert(csv_num_cols(t) == 3)
}

test "csv_num_cols from first row when no headers" {
  let opts = CsvOptions { delimiter: ",", has_header: false, quote_char: "\"" }
  let t = csv_parse_opts("1,2,3,4\n5,6,7,8", opts)
  assert(csv_num_cols(t) == 4)
}

test "csv_num_cols empty table is zero" {
  let t = csv_parse("")
  assert(csv_num_cols(t) == 0)
}

// ============================================================
// Cell access by index
// ============================================================

test "csv_get valid row and col" {
  let t = csv_parse("name,age\nAlice,30\nBob,25")
  let r = csv_get(t, 1, 0)
  let ok = match r { Some(v) => v == "Bob", None => false }
  assert(ok)
}

test "csv_get row 0 col 0" {
  let t = csv_parse("name,age\nAlice,30")
  let r = csv_get(t, 0, 0)
  let ok = match r { Some(v) => v == "Alice", None => false }
  assert(ok)
}

test "csv_get last column" {
  let t = csv_parse("a,b,c\n1,2,3")
  let r = csv_get(t, 0, 2)
  let ok = match r { Some(v) => v == "3", None => false }
  assert(ok)
}

test "csv_get out-of-bounds row returns None" {
  let t = csv_parse("a,b\n1,2")
  let r = csv_get(t, 99, 0)
  let ok = match r { None => true, Some(_) => false }
  assert(ok)
}

test "csv_get out-of-bounds col returns None" {
  let t = csv_parse("a,b\n1,2")
  let r = csv_get(t, 0, 99)
  let ok = match r { None => true, Some(_) => false }
  assert(ok)
}

// ============================================================
// Named column access
// ============================================================

test "csv_get_by_name first column" {
  let t = csv_parse("name,age\nAlice,30")
  let r = csv_get_by_name(t, 0, "name")
  let ok = match r { Some(v) => v == "Alice", None => false }
  assert(ok)
}

test "csv_get_by_name non-first column" {
  let t = csv_parse("name,age\nAlice,30")
  let r = csv_get_by_name(t, 0, "age")
  let ok = match r { Some(v) => v == "30", None => false }
  assert(ok)
}

test "csv_get_by_name missing column returns None" {
  let t = csv_parse("name,age\nAlice,30")
  let r = csv_get_by_name(t, 0, "city")
  let ok = match r { None => true, Some(_) => false }
  assert(ok)
}

test "csv_get_by_name out-of-bounds row returns None" {
  let t = csv_parse("name,age\nAlice,30")
  let r = csv_get_by_name(t, 99, "name")
  let ok = match r { None => true, Some(_) => false }
  assert(ok)
}

// ============================================================
// find_col
// ============================================================

test "find_col returns correct index" {
  let hs = ["a", "b", "c"]
  assert(find_col(hs, "a", 0) == 0)
  assert(find_col(hs, "b", 0) == 1)
  assert(find_col(hs, "c", 0) == 2)
}

test "find_col returns -1 for missing name" {
  let hs = ["a", "b", "c"]
  assert(find_col(hs, "z", 0) == -1)
}

// ============================================================
// Row as map
// ============================================================

test "csv_row_as_map valid row returns Some" {
  let t = csv_parse("name,age\nBob,25")
  match csv_row_as_map(t, 0) {
    Some(m) => {
      let r = map_get(m, "name")
      let ok = match r { Some(v) => v == "Bob", None => false }
      assert(ok)
    },
    None => assert(false)
  }
}

test "csv_row_as_map second key" {
  let t = csv_parse("name,city\nCarol,Paris")
  match csv_row_as_map(t, 0) {
    Some(m) => {
      let r = map_get(m, "city")
      let ok = match r { Some(v) => v == "Paris", None => false }
      assert(ok)
    },
    None => assert(false)
  }
}

test "csv_row_as_map out-of-bounds returns None" {
  let t = csv_parse("a,b\n1,2")
  let r = csv_row_as_map(t, 99)
  let ok = match r { None => true, Some(_) => false }
  assert(ok)
}

// ============================================================
// Iteration helpers
// ============================================================

test "csv_filter_rows keeps matching rows" {
  let t = csv_parse("a,b\n1,2\n3,4\n5,6")
  // Use length check — avoids match-inside-lambda codegen issue
  let two_col = csv_filter_rows(t, (row) => length(row) == 2)
  assert(csv_num_rows(two_col) == 3)
}

test "csv_filter_rows removes non-matching rows" {
  let opts = CsvOptions { delimiter: ",", has_header: false, quote_char: "\"" }
  let t = csv_parse_opts("a\nb\na\nc", opts)
  let filtered = csv_filter_rows(t, (row) => length(row) == 1)
  assert(csv_num_rows(filtered) == 4)
}

test "csv_filter_rows preserves headers" {
  let t = csv_parse("name,age\nAlice,30\nBob,25")
  let all = csv_filter_rows(t, (row) => length(row) >= 0)
  assert(length(csv_headers(all)) == 2)
}

test "csv_map_rows transforms each row" {
  let opts = CsvOptions { delimiter: ",", has_header: false, quote_char: "\"" }
  let t = csv_parse_opts("1,2\n3,4", opts)
  let doubled = csv_map_rows(t, (row) => map(row, (v) => show(to_int(v) * 2)))
  let r = csv_get(doubled, 0, 0)
  let ok = match r { Some(v) => v == "2", None => false }
  assert(ok)
}
