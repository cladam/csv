// examples/filter_and_transform.hc — Filtering, computing derived columns, aggregation
import "../src/csv"

// Compute a "score" from two numeric columns.
// Named function to avoid match-inside-lambda codegen issue.
fun score_row(row: list<string>) : list<string> {
  let q = match str_at(row, 1) { Some(v) => to_int(v), None => 0 }
  let p = match str_at(row, 2) { Some(v) => to_int(v), None => 0 }
  let score = q * p
  row + [show(score)]
}

// Keep only rows where revenue (col 3) is above 20.
fun revenue_above_20(row: list<string>) : bool {
  match str_at(row, 3) {
    Some(v) => to_int(v) > 20,
    None => false
  }
}

// Sum one int column across all rows.
fun sum_col(rows: list<list<string>>, col: int) : int => match rows {
  [] => 0,
  [row, ..rest] => {
    let v = match str_at(row, col) { Some(s) => to_int(s), None => 0 }
    v + sum_col(rest, col)
  }
}

fun main() {
  // Product sales data
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
  let high_revenue = csv_filter_rows(with_revenue, revenue_above_20)
  println("=== Revenue > 20 ===")
  println(csv_pretty(high_revenue))
  println("")

  // Aggregate: total revenue across all products
  let total = sum_col(with_revenue.rows, 3)
  println("Total revenue: {total}")

  // Aggregate: total quantity
  let total_qty = sum_col(with_revenue.rows, 1)
  println("Total quantity: {total_qty}")
}
