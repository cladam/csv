// tests/test_display.hc — Display and serialization tests
import "../src/csv"

// ============================================================
// csv_show
// ============================================================

test "csv_show reports row and col count" {
  let t = csv_parse("a,b,c\n1,2,3\n4,5,6")
  let s = csv_show(t)
  assert(contains(s, "2"))
  assert(contains(s, "3"))
}

test "csv_show empty table" {
  let t = csv_parse("")
  let s = csv_show(t)
  assert(contains(s, "0"))
}

// ============================================================
// csv_pretty — headers present
// ============================================================

test "csv_pretty contains header names" {
  let t = csv_parse("name,age\nAlice,30")
  let s = csv_pretty(t)
  assert(contains(s, "name"))
  assert(contains(s, "age"))
}

test "csv_pretty contains data values" {
  let t = csv_parse("name,age\nAlice,30\nBob,25")
  let s = csv_pretty(t)
  assert(contains(s, "Alice"))
  assert(contains(s, "Bob"))
  assert(contains(s, "30"))
  assert(contains(s, "25"))
}

test "csv_pretty has separator line" {
  let t = csv_parse("a,b\n1,2")
  let s = csv_pretty(t)
  assert(contains(s, "-"))
}

test "csv_pretty no-header table has no separator" {
  let opts = CsvOptions { delimiter: ",", has_header: false, quote_char: "\"" }
  let t = csv_parse_opts("1,2\n3,4", opts)
  let s = csv_pretty(t)
  assert(!contains(s, "-+-"))
}

// ============================================================
// Round-trip: csv_to_csv
// ============================================================

test "csv_to_csv preserves headers" {
  let t = csv_parse("name,age\nAlice,30")
  let out = csv_to_csv(t)
  assert(starts_with(out, "name,age"))
}

test "csv_to_csv preserves data values" {
  let t = csv_parse("name,age\nAlice,30")
  let out = csv_to_csv(t)
  assert(contains(out, "Alice"))
  assert(contains(out, "30"))
}

test "csv_to_csv round-trip row count" {
  let input = "a,b\n1,2\n3,4\n5,6"
  let t = csv_parse(input)
  let out = csv_to_csv(t)
  let t2 = csv_parse(out)
  assert(csv_num_rows(t2) == 3)
}

test "csv_to_csv round-trip cell values" {
  let input = "x,y\nhello,world"
  let t = csv_parse(input)
  let out = csv_to_csv(t)
  let t2 = csv_parse(out)
  let r = csv_get(t2, 0, 0)
  let ok = match r { Some(v) => v == "hello", None => false }
  assert(ok)
}

// ============================================================
// Quoting in serialization
// ============================================================

test "csv_to_csv quotes field containing delimiter" {
  let t = csv_parse("a,b\n\"hello, world\",2")
  let out = csv_to_csv(t)
  assert(contains(out, "\"hello, world\""))
}

test "csv_to_csv escapes embedded quotes" {
  let t = csv_parse("a\n\"say \"\"hi\"\"\"")
  let out = csv_to_csv(t)
  assert(contains(out, "\"\""))
}

test "csv_to_csv plain field is not quoted" {
  let t = csv_parse("a,b\nhello,world")
  let out = csv_to_csv(t)
  assert(!contains(out, "\"hello\""))
}

// ============================================================
// Custom delimiter serialization
// ============================================================

test "csv_to_csv_opts uses custom delimiter" {
  let t = csv_parse("a,b\n1,2")
  let opts = CsvOptions { delimiter: ";", has_header: true, quote_char: "\"" }
  let out = csv_to_csv_opts(t, opts)
  assert(starts_with(out, "a;b"))
}
