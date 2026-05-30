// examples/filter_and_transform.hc — Filtering, computing derived columns, aggregation
import "../src/csv"

// Compute "revenue" from quantity (col 1) and price (col 2).
// A named function is appropriate here: multi-step, not a simple predicate.
fun score_row(row: list<string>) : list<string> {
  let q = match str_at(row, 1) { Some(v) => to_int(v), None => 0 }
  let p = match str_at(row, 2) { Some(v) => to_int(v), None => 0 }
  row + [show(q * p)]
}

fun main() {
  let input = "product,quantity,price\nApple,10,3\nBanana,25,1\nCherry,5,8\nDate,2,15\nElderry,100,0"
  let t = csv_parse(input)

  println("=== Original table ===")
  println(csv_pretty(t))
  println("")

  // Add a computed "revenue" column
  let with_revenue = CsvTable {
    headers: t.headers + ["revenue"],
    rows: map(t.rows, score_row)
  }

  println("=== With revenue column ===")
  println(csv_pretty(with_revenue))
  println("")

  // Filter: only products with revenue > 20
  let high_revenue = csv_filter_rows(with_revenue, (row) =>
    match str_at(row, 3) { Some(v) => to_int(v) > 20, None => false }
  )
  println("=== Revenue > 20 ===")
  println(csv_pretty(high_revenue))
  println("")

  // Aggregate: total revenue across all products
  let total = fold(with_revenue.rows, 0, (acc, row) =>
    match str_at(row, 3) { Some(v) => acc + to_int(v), None => acc }
  )
  println("Total revenue: {total}")

  // Aggregate: total quantity
  let total_qty = fold(with_revenue.rows, 0, (acc, row) =>
    match str_at(row, 1) { Some(v) => acc + to_int(v), None => acc }
  )
  println("Total quantity: {total_qty}")
}
