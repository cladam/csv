// examples/read_file.hc — Read and analyse a CSV file from disk
import "../src/csv"

// Safe cell accessor: returns "" for out-of-bounds.
fun cell_str(row: list<string>, col: int) : string =>
  match str_at(row, col) { Some(v) => v, None => "" }

fun cell_int(row: list<string>, col: int) : int =>
  match str_at(row, col) { Some(v) => to_int(v), None => 0 }

// Count rows where column col equals target.
fun count_where_eq(rows: list<list<string>>, col: int, target: string) : int => match rows {
  [] => 0,
  [row, ..rest] => {
    let inc = if cell_str(row, col) == target { 1 } else { 0 }
    inc + count_where_eq(rest, col, target)
  }
}

// Sum an int column for rows where another column equals filter_val.
fun sum_where_eq(rows: list<list<string>>, sum_c: int, filter_c: int, filter_val: string) : int =>
  match rows {
    [] => 0,
    [row, ..rest] => {
      let cell = if cell_str(row, filter_c) == filter_val { cell_int(row, sum_c) } else { 0 }
      cell + sum_where_eq(rest, sum_c, filter_c, filter_val)
    }
  }

fun print_dept_summary(t: CsvTable, dept: string) {
  let dept_col = find_col(t.headers, "department", 0)
  let sal_col  = find_col(t.headers, "salary", 0)
  let n        = count_where_eq(t.rows, dept_col, dept)
  let total    = sum_where_eq(t.rows, sal_col, dept_col, dept)
  let avg      = if n > 0 { total / n } else { 0 }
  println("  {dept}: {n} employees, avg salary {avg}")
}

fun find_by_name(rows: list<list<string>>, name: string) : maybe<list<string>> => match rows {
  [] => None,
  [row, ..rest] =>
    if cell_str(row, 1) == name { Some(row) }
    else { find_by_name(rest, name) }
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
      match find_by_name(t.rows, "Carol Carlsson") {
        Some(row) => {
          let one = CsvTable { headers: t.headers, rows: [row] }
          match csv_row_as_map(one, 0) {
            Some(m) => {
              let dept = match map_get(m, "department") { Some(v) => v, None => "?" }
              let sal  = match map_get(m, "salary")     { Some(v) => v, None => "?" }
              println("Carol Carlsson — dept: {dept}, salary: {sal}")
            },
            None => println("not found")
          }
        },
        None => println("employee not found")
      }
    }
  }
}
