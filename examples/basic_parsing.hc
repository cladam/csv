// examples/basic_parsing.hc — CSV parsing examples
import "../src/csv"

fun main() {
  // Basic parse with headers
  let input = "name,age,city\nAlice,30,New York\nBob,25,London\nCarol,35,Paris"
  let table = csv_parse(input)

  println(csv_show(table))
  println("")
  println(csv_pretty(table))
  println("")

  // Cell access by index
  match csv_get(table, 0, 0) {
    Some(v) => println("Row 0, Col 0: {v}"),
    None => println("Not found")
  }

  // Cell access by column name
  match csv_get_by_name(table, 2, "city") {
    Some(v) => println("Carol's city: {v}"),
    None => println("Not found")
  }

  // Row as a key-value map
  match csv_row_as_map(table, 1) {
    Some(m) => {
      match map_get(m, "name") {
        Some(n) => println("Row 1 name: {n}"),
        None => println("No name key")
      }
    },
    None => println("Row 1 not found")
  }

  println("")

  // Quoted fields: commas and embedded quotes inside fields
  let quoted = "product,price,notes\nApple,1.50,\"Fresh, organic\"\nBanana,0.75,\"\"\"Best\"\" deal\""
  let t2 = csv_parse(quoted)
  println(csv_pretty(t2))
  println("")

  // Tab-separated values (TSV)
  let tsv_input = "id\tvalue\n1\thello\n2\tworld"
  let tsv_opts = CsvOptions { delimiter: "\t", has_header: true, quote_char: "\"" }
  let t3 = csv_parse_opts(tsv_input, tsv_opts)
  println(csv_pretty(t3))
  println("")

  // No-header mode
  let raw = "10,20,30\n40,50,60"
  let no_header_opts = CsvOptions { delimiter: ",", has_header: false, quote_char: "\"" }
  let t4 = csv_parse_opts(raw, no_header_opts)
  println(csv_show(t4))

  // Round-trip serialization
  let serialized = csv_to_csv(table)
  println("")
  println("Round-trip:")
  println(serialized)

  // Filter rows with an inline predicate
  let young = csv_filter_rows(table, (row) =>
    match str_at(row, 1) { Some(s) => to_int(s) < 30, None => false }
  )
  println("")
  println("Under 30:")
  println(csv_pretty(young))
}
