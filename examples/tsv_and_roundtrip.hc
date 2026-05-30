// examples/tsv_and_roundtrip.hc — Custom delimiters, format conversion, and round-trip
import "../src/csv"

fun main() {
  // ── 1. Parse a TSV (tab-separated values) ──────────────────────────────
  let tsv = "city\tcountry\tpopulation\nStockholm\tSweden\t975551\nOslo\tNorway\t693494\nCopenhagen\tDenmark\t794128\nHelsinki\tFinland\t656920"

  let tsv_opts = CsvOptions { delimiter: "\t", has_header: true, quote_char: "\"" }
  let t_tsv = csv_parse_opts(tsv, tsv_opts)

  println("=== Parsed TSV ===")
  println(csv_pretty(t_tsv))
  println("")

  // ── 2. Convert TSV → CSV ───────────────────────────────────────────────
  let as_csv = csv_to_csv(t_tsv)
  println("=== Re-serialized as CSV ===")
  println(as_csv)

  // Verify the round-trip parsed correctly
  let t_csv = csv_parse(as_csv)
  println("Round-trip row count: {csv_num_rows(t_csv)}")
  println("")

  // ── 3. Convert CSV → semicolon-delimited (European locale) ────────────
  let semi_opts = CsvOptions { delimiter: ";", has_header: true, quote_char: "\"" }
  let as_semi = csv_to_csv_opts(t_tsv, semi_opts)
  println("=== Semicolon-delimited ===")
  println(as_semi)
  println("")

  // ── 4. Quoted fields containing the delimiter survive round-trips ───────
  let tricky = "name,note\nSmith; Co.,\"needs semicolons\"\n\"O'Brien\",plain"
  let t_tricky = csv_parse(tricky)

  println("=== Tricky quoted fields ===")
  println(csv_pretty(t_tricky))
  println("")

  // Serialize with semicolon delimiter — "Smith; Co." now needs quoting
  let tricky_semi = csv_to_csv_opts(t_tricky, semi_opts)
  println("=== Semicolon round-trip ===")
  println(tricky_semi)

  // Parse it back and verify
  let t_back = csv_parse_opts(tricky_semi, semi_opts)
  let name0 = csv_get_by_name(t_back, 0, "name")
  let note1 = csv_get_by_name(t_back, 1, "note")
  println("")
  match name0 {
    Some(v) => println("Row 0 name: {v}"),
    None => println("not found")
  }
  match note1 {
    Some(v) => println("Row 1 note: {v}"),
    None => println("not found")
  }
}
