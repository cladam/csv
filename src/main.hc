// main.hc — CSV library demo
import "./csv"

fun main() {
  let input = "name,age,city\nAlice,30,New York\nBob,25,London\nCarol,35,Paris"
  let table = csv_parse(input)

  println(csv_show(table))
  println("")
  println(csv_pretty(table))
  println("")

  match csv_get_by_name(table, 1, "city") {
    Some(v) => println("Bob's city: {v}"),
    None => println("Not found")
  }
}
