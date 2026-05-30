#pragma once
#ifndef kk_src_main_H
#define kk_src_main_H
// Koka generated module: src/main, koka version: 3.2.3, platform: 64-bit
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_hnd.h"
#include "std_core_exn.h"
#include "std_core_bool.h"
#include "std_core_order.h"
#include "std_core_char.h"
#include "std_core_int.h"
#include "std_core_vector.h"
#include "std_core_string.h"
#include "std_core_sslice.h"
#include "std_core_list.h"
#include "std_core_maybe.h"
#include "std_core_maybe2.h"
#include "std_core_either.h"
#include "std_core_tuple.h"
#include "std_core_lazy.h"
#include "std_core_show.h"
#include "std_core_debug.h"
#include "std_core_delayed.h"
#include "std_core_console.h"
#include "std_core.h"

// type declarations

// value declarations

kk_unit_t kk_src_main_hc_assert(bool b, kk_context_t* _ctx); /* (b : bool) -> exn () */ 

static inline kk_integer_t kk_src_main_hc__abs(kk_integer_t n, kk_context_t* _ctx) { /* (n : int) -> int */ 
  bool _match_x163 = kk_integer_lt_borrow(n,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x163) {
    return kk_integer_sub((kk_integer_from_small(0)),n,kk_context());
  }
  {
    return n;
  }
}

static inline kk_integer_t kk_src_main_hc__min(kk_integer_t a, kk_integer_t b, kk_context_t* _ctx) { /* (a : int, b : int) -> int */ 
  bool _match_x162 = kk_integer_lt_borrow(a,b,kk_context()); /*bool*/;
  if (_match_x162) {
    kk_integer_drop(b, _ctx);
    return a;
  }
  {
    kk_integer_drop(a, _ctx);
    return b;
  }
}

static inline kk_integer_t kk_src_main_hc__max(kk_integer_t a, kk_integer_t b, kk_context_t* _ctx) { /* (a : int, b : int) -> int */ 
  bool _match_x161 = kk_integer_gt_borrow(a,b,kk_context()); /*bool*/;
  if (_match_x161) {
    kk_integer_drop(b, _ctx);
    return a;
  }
  {
    kk_integer_drop(a, _ctx);
    return b;
  }
}

kk_integer_t kk_src_main_hc__clamp(kk_integer_t v, kk_integer_t lo, kk_integer_t hi, kk_context_t* _ctx); /* (v : int, lo : int, hi : int) -> int */ 

kk_integer_t kk_src_main_hc__gcd(kk_integer_t a, kk_integer_t b, kk_context_t* _ctx); /* (a : int, b : int) -> div int */ 

kk_integer_t kk_src_main_hc__lcm(kk_integer_t a, kk_integer_t b, kk_context_t* _ctx); /* (a : int, b : int) -> div int */ 

kk_integer_t kk_src_main_hc__pow(kk_integer_t base, kk_integer_t exp, kk_context_t* _ctx); /* (base : int, exp : int) -> div int */ 

kk_integer_t kk_src_main_hc__sign(kk_integer_t n, kk_context_t* _ctx); /* (n : int) -> int */ 

bool kk_src_main_hc__is__digit(kk_char_t c, kk_context_t* _ctx); /* (c : char) -> bool */ 

bool kk_src_main_hc__is__upper(kk_char_t c, kk_context_t* _ctx); /* (c : char) -> bool */ 

bool kk_src_main_hc__is__lower(kk_char_t c, kk_context_t* _ctx); /* (c : char) -> bool */ 

bool kk_src_main_hc__is__alpha(kk_char_t c, kk_context_t* _ctx); /* (c : char) -> bool */ 

bool kk_src_main_hc__is__alnum(kk_char_t c, kk_context_t* _ctx); /* (c : char) -> bool */ 

bool kk_src_main_hc__is__space(kk_char_t c, kk_context_t* _ctx); /* (c : char) -> bool */ 

bool kk_src_main_hc__is__punct(kk_char_t c, kk_context_t* _ctx); /* (c : char) -> bool */ 

bool kk_src_main_hc__all__digits(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> bool */ 

bool kk_src_main_hc__all__alpha(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> bool */ 

bool kk_src_main_hc__all__upper(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> bool */ 

bool kk_src_main_hc__all__lower(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> bool */ 

bool kk_src_main_hc__all__alnum(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> bool */ 

bool kk_src_main_hc__glob__match__chars(kk_std_core_types__list pat, kk_std_core_types__list input, kk_context_t* _ctx); /* (pat : list<char>, input : list<char>) -> div bool */ 

bool kk_src_main_hc__glob__star(kk_std_core_types__list prest_0, kk_std_core_types__list input_0, kk_context_t* _ctx); /* (prest : list<char>, input : list<char>) -> div bool */ 

static inline bool kk_src_main_hc__glob__match(kk_string_t pattern, kk_string_t s, kk_context_t* _ctx) { /* (pattern : string, s : string) -> div bool */ 
  kk_std_core_types__list _x_x219 = kk_std_core_string_list(pattern, _ctx); /*list<char>*/
  kk_std_core_types__list _x_x220 = kk_std_core_string_list(s, _ctx); /*list<char>*/
  return kk_src_main_hc__glob__match__chars(_x_x219, _x_x220, _ctx);
}

bool kk_src_main_hc__glob__doublestar(kk_std_core_types__list prest, kk_std_core_types__list paths, kk_context_t* _ctx); /* (prest : list<string>, paths : list<string>) -> div bool */ 

bool kk_src_main_hc__glob__match__segments(kk_std_core_types__list pats, kk_std_core_types__list paths_0, kk_context_t* _ctx); /* (pats : list<string>, paths : list<string>) -> div bool */ 

bool kk_src_main_hc__glob__match__path(kk_string_t pattern, kk_string_t hc__path, kk_context_t* _ctx); /* (pattern : string, hc_path : string) -> div bool */ 

static inline bool kk_src_main_hc__is__empty(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> bool */ 
  kk_integer_t _brw_x89 = kk_std_core_string_chars_fs_count(s, _ctx); /*int*/;
  bool _brw_x90 = kk_integer_eq_borrow(_brw_x89,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x89, _ctx);
  return _brw_x90;
}

static inline bool kk_src_main_hc__is__blank(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> bool */ 
  kk_string_t s_0_10024;
  kk_string_t _x_x249 = kk_string_trim_left(s,kk_context()); /*string*/
  s_0_10024 = kk_string_trim_right(_x_x249,kk_context()); /*string*/
  kk_integer_t _brw_x87 = kk_std_core_string_chars_fs_count(s_0_10024, _ctx); /*int*/;
  bool _brw_x88 = kk_integer_eq_borrow(_brw_x87,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x87, _ctx);
  return _brw_x88;
}

kk_std_core_types__list kk_src_main_hc__words(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> list<string> */ 

kk_std_core_types__list kk_src_main_hc__lines(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> list<string> */ 

static inline kk_string_t kk_src_main_hc__unwords(kk_std_core_types__list ws, kk_context_t* _ctx) { /* (ws : list<string>) -> string */ 
  kk_string_t _x_x270;
  kk_define_string_literal(static, _s_x271, 1, " ", _ctx)
  _x_x270 = kk_string_dup(_s_x271, _ctx); /*string*/
  return kk_std_core_list_joinsep(ws, _x_x270, _ctx);
}

static inline kk_string_t kk_src_main_hc__unlines(kk_std_core_types__list ls, kk_context_t* _ctx) { /* (ls : list<string>) -> string */ 
  kk_string_t _x_x272;
  kk_define_string_literal(static, _s_x273, 1, "\n", _ctx)
  _x_x272 = kk_string_dup(_s_x273, _ctx); /*string*/
  return kk_std_core_list_joinsep(ls, _x_x272, _ctx);
}

kk_string_t kk_src_main_hc__repeat__str(kk_string_t s, kk_integer_t n, kk_context_t* _ctx); /* (s : string, n : int) -> div string */ 

kk_string_t kk_src_main_hc__pad__left(kk_string_t s, kk_integer_t width, kk_string_t ch, kk_context_t* _ctx); /* (s : string, width : int, ch : string) -> div string */ 

kk_string_t kk_src_main_hc__pad__right(kk_string_t s, kk_integer_t width, kk_string_t ch, kk_context_t* _ctx); /* (s : string, width : int, ch : string) -> div string */ 

kk_string_t kk_src_main_hc__center(kk_string_t s, kk_integer_t width, kk_string_t ch, kk_context_t* _ctx); /* (s : string, width : int, ch : string) -> div string */ 

kk_string_t kk_src_main_hc__removeprefix(kk_string_t s, kk_string_t pre, kk_context_t* _ctx); /* (s : string, pre : string) -> string */ 
 
// .hc:1

static inline kk_unit_t kk_src_main_main(kk_context_t* _ctx) { /* () -> console/console () */ 
  kk_string_t _x_x296;
  kk_define_string_literal(static, _s_x297, 14, "hello from csv", _ctx)
  _x_x296 = kk_string_dup(_s_x297, _ctx); /*string*/
  kk_std_core_console_printsln(_x_x296, _ctx); return kk_Unit;
}

void kk_src_main__init(kk_context_t* _ctx);


void kk_src_main__done(kk_context_t* _ctx);

#endif // header
