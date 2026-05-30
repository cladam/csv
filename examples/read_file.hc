// examples/read_file.hc — Read and analyse a CSV file from disk
import "../src/csv"

fun print_dept_summary(t: CsvTable, dept: string) {
  let dept_col  = find_col(t.headers, "department", 0)
  let sal_col   = find_col(t.headers, "salary", 0)
  let dept_rows = filter(t.rows, (row) =>
    match str_at(row, dept_col) { Some(v) => v == dept, None => false }
  )
  let n         = length(dept_rows)
  let total     = fold(dept_rows, 0, (acc, row) =>
    match str_at(row, sal_col) { Some(v) => acc + to_int(v), None => acc }
  )
  let avg       = if n > 0 { total / n } else { 0 }
  println("  {dept}: {n} employees, avg salary {avg}")
}

fun main() {
  match read_file("examples/employees.csv") {
    Err(e) => println("Could not read file: {e}"),
    Ok(text) => {
      let t = csv_parse(text)

      println("=== Employees ({csv_num_rows(t)} records) ===")
      println(csv_pretty(t))
      println("")

      println("=== Department summary ===")
      print_dept_summary(t, "Engineering")
      print_dept_summary(t, "Marketing")
      print_dept_summary(t, "HR")
      println("")

      println("=== Row lookup by name ===")
      match find(t.rows, (row) =>
        match str_at(row, 1) { Some(v) => v == "Carol Carlsson", None => false }
      ) {
        Some(row) => {
          let m    = zip(t.headers, row)
          let dept = unwrap_maybe_or(map_get(m, "department"), "?")
          let sal  = unwrap_maybe_or(map_get(m, "salary"), "?")
          println("Carol Carlsson — dept: {dept}, salary: {sal}")
        },
        None => println("employee not found")
      }
    }
  }
}
