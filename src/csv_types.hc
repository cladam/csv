// csv_types.hc — Core CSV types

pub struct CsvOptions {
  delimiter: string,
  has_header: bool,
  quote_char: string
}

pub struct CsvTable {
  headers: list<string>,
  rows: list<list<string>>
}

pub fun default_opts() : CsvOptions =>
  CsvOptions { delimiter: ",", has_header: true, quote_char: "\"" }
