// Koka generated module: src/main, koka version: 3.2.3, platform: 64-bit
#include "src_main.h"


// lift anonymous function
struct kk_src_main_hc_assert_fun173__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_main_hc_assert_fun173(kk_function_t _fself, kk_box_t _b_x2, kk_context_t* _ctx);
static kk_function_t kk_src_main_new_hc_assert_fun173(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_main_hc_assert_fun173, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_main_hc_assert_fun173(kk_function_t _fself, kk_box_t _b_x2, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  bool _x_x174;
  bool b_0_9 = kk_bool_unbox(_b_x2); /*bool*/;
  if (b_0_9) {
    _x_x174 = false; /*bool*/
  }
  else {
    _x_x174 = true; /*bool*/
  }
  return kk_bool_box(_x_x174);
}

kk_unit_t kk_src_main_hc_assert(bool b, kk_context_t* _ctx) { /* (b : bool) -> exn () */ 
  bool _match_x164;
  kk_box_t _x_x172 = kk_std_core_hnd__open_none1(kk_src_main_new_hc_assert_fun173(_ctx), kk_bool_box(b), _ctx); /*10001*/
  _match_x164 = kk_bool_unbox(_x_x172); /*bool*/
  if (_match_x164) {
    kk_box_t _x_x175;
    kk_string_t _x_x176;
    kk_define_string_literal(static, _s_x177, 16, "assertion failed", _ctx)
    _x_x176 = kk_string_dup(_s_x177, _ctx); /*string*/
    _x_x175 = kk_std_core_exn_throw(_x_x176, kk_std_core_types__new_None(_ctx), _ctx); /*10000*/
    kk_unit_unbox(_x_x175); return kk_Unit;
  }
  {
    kk_Unit; return kk_Unit;
  }
}

kk_integer_t kk_src_main_hc__clamp(kk_integer_t v, kk_integer_t lo, kk_integer_t hi, kk_context_t* _ctx) { /* (v : int, lo : int, hi : int) -> int */ 
  kk_integer_t a_10002;
  bool _match_x160 = kk_integer_gt_borrow(v,lo,kk_context()); /*bool*/;
  if (_match_x160) {
    kk_integer_drop(lo, _ctx);
    a_10002 = v; /*int*/
  }
  else {
    kk_integer_drop(v, _ctx);
    a_10002 = lo; /*int*/
  }
  bool _match_x159 = kk_integer_lt_borrow(a_10002,hi,kk_context()); /*bool*/;
  if (_match_x159) {
    kk_integer_drop(hi, _ctx);
    return a_10002;
  }
  {
    kk_integer_drop(a_10002, _ctx);
    return hi;
  }
}

kk_integer_t kk_src_main_hc__gcd(kk_integer_t a, kk_integer_t b, kk_context_t* _ctx) { /* (a : int, b : int) -> div int */ 
  kk__tailcall: ;
  bool _match_x158 = kk_integer_eq_borrow(b,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x158) {
    kk_integer_drop(b, _ctx);
    return a;
  }
  { // tailcall
    kk_integer_t _x_x178 = kk_integer_dup(b, _ctx); /*int*/
    kk_integer_t _x_x179 = kk_integer_mod(a,b,kk_context()); /*int*/
    a = _x_x178;
    b = _x_x179;
    goto kk__tailcall;
  }
}

kk_integer_t kk_src_main_hc__lcm(kk_integer_t a, kk_integer_t b, kk_context_t* _ctx) { /* (a : int, b : int) -> div int */ 
  bool _match_x155 = kk_integer_eq_borrow(a,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x155) {
    kk_integer_drop(b, _ctx);
    kk_integer_drop(a, _ctx);
    return kk_integer_from_small(0);
  }
  {
    bool _match_x156 = kk_integer_eq_borrow(b,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    if (_match_x156) {
      kk_integer_drop(b, _ctx);
      kk_integer_drop(a, _ctx);
      return kk_integer_from_small(0);
    }
    {
      kk_integer_t n_10006;
      kk_integer_t _x_x180 = kk_integer_dup(a, _ctx); /*int*/
      kk_integer_t _x_x181 = kk_integer_dup(b, _ctx); /*int*/
      n_10006 = kk_integer_mul(_x_x180,_x_x181,kk_context()); /*int*/
      kk_integer_t _x_x182;
      bool _match_x157 = kk_integer_lt_borrow(n_10006,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      if (_match_x157) {
        _x_x182 = kk_integer_sub((kk_integer_from_small(0)),n_10006,kk_context()); /*int*/
      }
      else {
        _x_x182 = n_10006; /*int*/
      }
      kk_integer_t _x_x183 = kk_src_main_hc__gcd(a, b, _ctx); /*int*/
      return kk_integer_div(_x_x182,_x_x183,kk_context());
    }
  }
}

kk_integer_t kk_src_main_hc__pow(kk_integer_t base, kk_integer_t exp, kk_context_t* _ctx) { /* (base : int, exp : int) -> div int */ 
  bool _match_x154 = kk_integer_lte_borrow(exp,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x154) {
    kk_integer_drop(exp, _ctx);
    kk_integer_drop(base, _ctx);
    return kk_integer_from_small(1);
  }
  {
    kk_integer_t _x_x184 = kk_integer_dup(base, _ctx); /*int*/
    kk_integer_t _x_x185;
    kk_integer_t _x_x186 = kk_integer_add_small_const(exp, -1, _ctx); /*int*/
    _x_x185 = kk_src_main_hc__pow(base, _x_x186, _ctx); /*int*/
    return kk_integer_mul(_x_x184,_x_x185,kk_context());
  }
}

kk_integer_t kk_src_main_hc__sign(kk_integer_t n, kk_context_t* _ctx) { /* (n : int) -> int */ 
  bool _match_x151 = kk_integer_gt_borrow(n,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x151) {
    kk_integer_drop(n, _ctx);
    return kk_integer_from_small(1);
  }
  {
    bool _match_x152;
    bool _brw_x153 = kk_integer_lt_borrow(n,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    kk_integer_drop(n, _ctx);
    _match_x152 = _brw_x153; /*bool*/
    if (_match_x152) {
      return kk_integer_add_small_const(kk_integer_from_small(0), -1, _ctx);
    }
    {
      return kk_integer_from_small(0);
    }
  }
}

bool kk_src_main_hc__is__digit(kk_char_t c, kk_context_t* _ctx) { /* (c : char) -> bool */ 
  kk_integer_t n = kk_integer_from_int(c,kk_context()); /*int*/;
  bool _match_x149 = kk_integer_gte_borrow(n,(kk_integer_from_small(48)),kk_context()); /*bool*/;
  if (_match_x149) {
    bool _brw_x150 = kk_integer_lte_borrow(n,(kk_integer_from_small(57)),kk_context()); /*bool*/;
    kk_integer_drop(n, _ctx);
    return _brw_x150;
  }
  {
    kk_integer_drop(n, _ctx);
    return false;
  }
}

bool kk_src_main_hc__is__upper(kk_char_t c, kk_context_t* _ctx) { /* (c : char) -> bool */ 
  kk_integer_t n = kk_integer_from_int(c,kk_context()); /*int*/;
  bool _match_x147 = kk_integer_gte_borrow(n,(kk_integer_from_small(65)),kk_context()); /*bool*/;
  if (_match_x147) {
    bool _brw_x148 = kk_integer_lte_borrow(n,(kk_integer_from_small(90)),kk_context()); /*bool*/;
    kk_integer_drop(n, _ctx);
    return _brw_x148;
  }
  {
    kk_integer_drop(n, _ctx);
    return false;
  }
}

bool kk_src_main_hc__is__lower(kk_char_t c, kk_context_t* _ctx) { /* (c : char) -> bool */ 
  kk_integer_t n = kk_integer_from_int(c,kk_context()); /*int*/;
  bool _match_x145 = kk_integer_gte_borrow(n,(kk_integer_from_small(97)),kk_context()); /*bool*/;
  if (_match_x145) {
    bool _brw_x146 = kk_integer_lte_borrow(n,(kk_integer_from_small(122)),kk_context()); /*bool*/;
    kk_integer_drop(n, _ctx);
    return _brw_x146;
  }
  {
    kk_integer_drop(n, _ctx);
    return false;
  }
}

bool kk_src_main_hc__is__alpha(kk_char_t c, kk_context_t* _ctx) { /* (c : char) -> bool */ 
  kk_integer_t n = kk_integer_from_int(c,kk_context()); /*int*/;
  bool _match_x138 = kk_integer_gte_borrow(n,(kk_integer_from_small(65)),kk_context()); /*bool*/;
  if (_match_x138) {
    bool _match_x141;
    bool _brw_x144 = kk_integer_lte_borrow(n,(kk_integer_from_small(90)),kk_context()); /*bool*/;
    kk_integer_drop(n, _ctx);
    _match_x141 = _brw_x144; /*bool*/
    if (_match_x141) {
      return true;
    }
    {
      kk_integer_t n_0 = kk_integer_from_int(c,kk_context()); /*int*/;
      bool _match_x142 = kk_integer_gte_borrow(n_0,(kk_integer_from_small(97)),kk_context()); /*bool*/;
      if (_match_x142) {
        bool _brw_x143 = kk_integer_lte_borrow(n_0,(kk_integer_from_small(122)),kk_context()); /*bool*/;
        kk_integer_drop(n_0, _ctx);
        return _brw_x143;
      }
      {
        kk_integer_drop(n_0, _ctx);
        return false;
      }
    }
  }
  {
    kk_integer_drop(n, _ctx);
    kk_integer_t n_0_0 = kk_integer_from_int(c,kk_context()); /*int*/;
    bool _match_x139 = kk_integer_gte_borrow(n_0_0,(kk_integer_from_small(97)),kk_context()); /*bool*/;
    if (_match_x139) {
      bool _brw_x140 = kk_integer_lte_borrow(n_0_0,(kk_integer_from_small(122)),kk_context()); /*bool*/;
      kk_integer_drop(n_0_0, _ctx);
      return _brw_x140;
    }
    {
      kk_integer_drop(n_0_0, _ctx);
      return false;
    }
  }
}

bool kk_src_main_hc__is__alnum(kk_char_t c, kk_context_t* _ctx) { /* (c : char) -> bool */ 
  bool _match_x135 = kk_src_main_hc__is__alpha(c, _ctx); /*bool*/;
  if (_match_x135) {
    return true;
  }
  {
    kk_integer_t n = kk_integer_from_int(c,kk_context()); /*int*/;
    bool _match_x136 = kk_integer_gte_borrow(n,(kk_integer_from_small(48)),kk_context()); /*bool*/;
    if (_match_x136) {
      bool _brw_x137 = kk_integer_lte_borrow(n,(kk_integer_from_small(57)),kk_context()); /*bool*/;
      kk_integer_drop(n, _ctx);
      return _brw_x137;
    }
    {
      kk_integer_drop(n, _ctx);
      return false;
    }
  }
}

bool kk_src_main_hc__is__space(kk_char_t c, kk_context_t* _ctx) { /* (c : char) -> bool */ 
  kk_integer_t n = kk_integer_from_int(c,kk_context()); /*int*/;
  bool _match_x131 = kk_integer_eq_borrow(n,(kk_integer_from_small(32)),kk_context()); /*bool*/;
  if (_match_x131) {
    kk_integer_drop(n, _ctx);
    return true;
  }
  {
    bool _match_x132 = kk_integer_eq_borrow(n,(kk_integer_from_small(9)),kk_context()); /*bool*/;
    if (_match_x132) {
      kk_integer_drop(n, _ctx);
      return true;
    }
    {
      bool _match_x133 = kk_integer_eq_borrow(n,(kk_integer_from_small(10)),kk_context()); /*bool*/;
      if (_match_x133) {
        kk_integer_drop(n, _ctx);
        return true;
      }
      {
        bool _brw_x134 = kk_integer_eq_borrow(n,(kk_integer_from_small(13)),kk_context()); /*bool*/;
        kk_integer_drop(n, _ctx);
        return _brw_x134;
      }
    }
  }
}

bool kk_src_main_hc__is__punct(kk_char_t c, kk_context_t* _ctx) { /* (c : char) -> bool */ 
  kk_integer_t n = kk_integer_from_int(c,kk_context()); /*int*/;
  bool _match_x120;
  bool _match_x127 = kk_integer_gte_borrow(n,(kk_integer_from_small(33)),kk_context()); /*bool*/;
  if (_match_x127) {
    bool _match_x129 = kk_integer_lte_borrow(n,(kk_integer_from_small(47)),kk_context()); /*bool*/;
    if (_match_x129) {
      _match_x120 = true; /*bool*/
    }
    else {
      bool _match_x130 = kk_integer_gte_borrow(n,(kk_integer_from_small(58)),kk_context()); /*bool*/;
      if (_match_x130) {
        _match_x120 = kk_integer_lte_borrow(n,(kk_integer_from_small(64)),kk_context()); /*bool*/
      }
      else {
        _match_x120 = false; /*bool*/
      }
    }
  }
  else {
    bool _match_x128 = kk_integer_gte_borrow(n,(kk_integer_from_small(58)),kk_context()); /*bool*/;
    if (_match_x128) {
      _match_x120 = kk_integer_lte_borrow(n,(kk_integer_from_small(64)),kk_context()); /*bool*/
    }
    else {
      _match_x120 = false; /*bool*/
    }
  }
  if (_match_x120) {
    kk_integer_drop(n, _ctx);
    return true;
  }
  {
    bool _match_x121 = kk_integer_gte_borrow(n,(kk_integer_from_small(91)),kk_context()); /*bool*/;
    if (_match_x121) {
      bool _match_x124 = kk_integer_lte_borrow(n,(kk_integer_from_small(96)),kk_context()); /*bool*/;
      if (_match_x124) {
        kk_integer_drop(n, _ctx);
        return true;
      }
      {
        bool _match_x125 = kk_integer_gte_borrow(n,(kk_integer_from_small(123)),kk_context()); /*bool*/;
        if (_match_x125) {
          bool _brw_x126 = kk_integer_lte_borrow(n,(kk_integer_from_small(126)),kk_context()); /*bool*/;
          kk_integer_drop(n, _ctx);
          return _brw_x126;
        }
        {
          kk_integer_drop(n, _ctx);
          return false;
        }
      }
    }
    {
      bool _match_x122 = kk_integer_gte_borrow(n,(kk_integer_from_small(123)),kk_context()); /*bool*/;
      if (_match_x122) {
        bool _brw_x123 = kk_integer_lte_borrow(n,(kk_integer_from_small(126)),kk_context()); /*bool*/;
        kk_integer_drop(n, _ctx);
        return _brw_x123;
      }
      {
        kk_integer_drop(n, _ctx);
        return false;
      }
    }
  }
}


// lift anonymous function
struct kk_src_main_hc__all__digits_fun188__t {
  struct kk_function_s _base;
};
static bool kk_src_main_hc__all__digits_fun188(kk_function_t _fself, kk_box_t _b_x12, kk_context_t* _ctx);
static kk_function_t kk_src_main_new_hc__all__digits_fun188(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_main_hc__all__digits_fun188, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static bool kk_src_main_hc__all__digits_fun188(kk_function_t _fself, kk_box_t _b_x12, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x189 = kk_char_unbox(_b_x12, KK_OWNED, _ctx); /*char*/
  return kk_src_main_hc__is__digit(_x_x189, _ctx);
}

bool kk_src_main_hc__all__digits(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> bool */ 
  bool _match_x117;
  kk_integer_t _brw_x118;
  kk_string_t _x_x187 = kk_string_dup(s, _ctx); /*string*/
  _brw_x118 = kk_std_core_string_chars_fs_count(_x_x187, _ctx); /*int*/
  bool _brw_x119 = kk_integer_eq_borrow(_brw_x118,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x118, _ctx);
  _match_x117 = _brw_x119; /*bool*/
  if (_match_x117) {
    kk_string_drop(s, _ctx);
    return false;
  }
  {
    kk_std_core_types__list _b_x10_13 = kk_std_core_string_list(s, _ctx); /*list<char>*/;
    return kk_std_core_list_all(_b_x10_13, kk_src_main_new_hc__all__digits_fun188(_ctx), _ctx);
  }
}


// lift anonymous function
struct kk_src_main_hc__all__alpha_fun191__t {
  struct kk_function_s _base;
};
static bool kk_src_main_hc__all__alpha_fun191(kk_function_t _fself, kk_box_t _b_x17, kk_context_t* _ctx);
static kk_function_t kk_src_main_new_hc__all__alpha_fun191(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_main_hc__all__alpha_fun191, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static bool kk_src_main_hc__all__alpha_fun191(kk_function_t _fself, kk_box_t _b_x17, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x192 = kk_char_unbox(_b_x17, KK_OWNED, _ctx); /*char*/
  return kk_src_main_hc__is__alpha(_x_x192, _ctx);
}

bool kk_src_main_hc__all__alpha(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> bool */ 
  bool _match_x114;
  kk_integer_t _brw_x115;
  kk_string_t _x_x190 = kk_string_dup(s, _ctx); /*string*/
  _brw_x115 = kk_std_core_string_chars_fs_count(_x_x190, _ctx); /*int*/
  bool _brw_x116 = kk_integer_eq_borrow(_brw_x115,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x115, _ctx);
  _match_x114 = _brw_x116; /*bool*/
  if (_match_x114) {
    kk_string_drop(s, _ctx);
    return false;
  }
  {
    kk_std_core_types__list _b_x15_18 = kk_std_core_string_list(s, _ctx); /*list<char>*/;
    return kk_std_core_list_all(_b_x15_18, kk_src_main_new_hc__all__alpha_fun191(_ctx), _ctx);
  }
}


// lift anonymous function
struct kk_src_main_hc__all__upper_fun194__t {
  struct kk_function_s _base;
};
static bool kk_src_main_hc__all__upper_fun194(kk_function_t _fself, kk_box_t _b_x22, kk_context_t* _ctx);
static kk_function_t kk_src_main_new_hc__all__upper_fun194(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_main_hc__all__upper_fun194, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static bool kk_src_main_hc__all__upper_fun194(kk_function_t _fself, kk_box_t _b_x22, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x195 = kk_char_unbox(_b_x22, KK_OWNED, _ctx); /*char*/
  return kk_src_main_hc__is__upper(_x_x195, _ctx);
}

bool kk_src_main_hc__all__upper(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> bool */ 
  bool _match_x111;
  kk_integer_t _brw_x112;
  kk_string_t _x_x193 = kk_string_dup(s, _ctx); /*string*/
  _brw_x112 = kk_std_core_string_chars_fs_count(_x_x193, _ctx); /*int*/
  bool _brw_x113 = kk_integer_eq_borrow(_brw_x112,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x112, _ctx);
  _match_x111 = _brw_x113; /*bool*/
  if (_match_x111) {
    kk_string_drop(s, _ctx);
    return false;
  }
  {
    kk_std_core_types__list _b_x20_23 = kk_std_core_string_list(s, _ctx); /*list<char>*/;
    return kk_std_core_list_all(_b_x20_23, kk_src_main_new_hc__all__upper_fun194(_ctx), _ctx);
  }
}


// lift anonymous function
struct kk_src_main_hc__all__lower_fun197__t {
  struct kk_function_s _base;
};
static bool kk_src_main_hc__all__lower_fun197(kk_function_t _fself, kk_box_t _b_x27, kk_context_t* _ctx);
static kk_function_t kk_src_main_new_hc__all__lower_fun197(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_main_hc__all__lower_fun197, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static bool kk_src_main_hc__all__lower_fun197(kk_function_t _fself, kk_box_t _b_x27, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x198 = kk_char_unbox(_b_x27, KK_OWNED, _ctx); /*char*/
  return kk_src_main_hc__is__lower(_x_x198, _ctx);
}

bool kk_src_main_hc__all__lower(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> bool */ 
  bool _match_x108;
  kk_integer_t _brw_x109;
  kk_string_t _x_x196 = kk_string_dup(s, _ctx); /*string*/
  _brw_x109 = kk_std_core_string_chars_fs_count(_x_x196, _ctx); /*int*/
  bool _brw_x110 = kk_integer_eq_borrow(_brw_x109,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x109, _ctx);
  _match_x108 = _brw_x110; /*bool*/
  if (_match_x108) {
    kk_string_drop(s, _ctx);
    return false;
  }
  {
    kk_std_core_types__list _b_x25_28 = kk_std_core_string_list(s, _ctx); /*list<char>*/;
    return kk_std_core_list_all(_b_x25_28, kk_src_main_new_hc__all__lower_fun197(_ctx), _ctx);
  }
}


// lift anonymous function
struct kk_src_main_hc__all__alnum_fun200__t {
  struct kk_function_s _base;
};
static bool kk_src_main_hc__all__alnum_fun200(kk_function_t _fself, kk_box_t _b_x32, kk_context_t* _ctx);
static kk_function_t kk_src_main_new_hc__all__alnum_fun200(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_main_hc__all__alnum_fun200, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static bool kk_src_main_hc__all__alnum_fun200(kk_function_t _fself, kk_box_t _b_x32, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x201 = kk_char_unbox(_b_x32, KK_OWNED, _ctx); /*char*/
  return kk_src_main_hc__is__alnum(_x_x201, _ctx);
}

bool kk_src_main_hc__all__alnum(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> bool */ 
  bool _match_x105;
  kk_integer_t _brw_x106;
  kk_string_t _x_x199 = kk_string_dup(s, _ctx); /*string*/
  _brw_x106 = kk_std_core_string_chars_fs_count(_x_x199, _ctx); /*int*/
  bool _brw_x107 = kk_integer_eq_borrow(_brw_x106,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x106, _ctx);
  _match_x105 = _brw_x107; /*bool*/
  if (_match_x105) {
    kk_string_drop(s, _ctx);
    return false;
  }
  {
    kk_std_core_types__list _b_x30_33 = kk_std_core_string_list(s, _ctx); /*list<char>*/;
    return kk_std_core_list_all(_b_x30_33, kk_src_main_new_hc__all__alnum_fun200(_ctx), _ctx);
  }
}


// lift anonymous function
struct kk_src_main_hc__glob__match__chars_fun207__t {
  struct kk_function_s _base;
};
static bool kk_src_main_hc__glob__match__chars_fun207(kk_function_t _fself, kk_box_t _b_x39, kk_context_t* _ctx);
static kk_function_t kk_src_main_new_hc__glob__match__chars_fun207(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_main_hc__glob__match__chars_fun207, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static bool kk_src_main_hc__glob__match__chars_fun207(kk_function_t _fself, kk_box_t _b_x39, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x208;
  kk_char_t _x_x209 = kk_char_unbox(_b_x39, KK_OWNED, _ctx); /*char*/
  _x_x208 = kk_std_core_string_char_fs_string(_x_x209, _ctx); /*string*/
  kk_string_t _x_x210;
  kk_define_string_literal(static, _s_x211, 1, "/", _ctx)
  _x_x210 = kk_string_dup(_s_x211, _ctx); /*string*/
  return kk_string_is_neq(_x_x208,_x_x210,kk_context());
}

bool kk_src_main_hc__glob__match__chars(kk_std_core_types__list pat, kk_std_core_types__list input, kk_context_t* _ctx) { /* (pat : list<char>, input : list<char>) -> div bool */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(pat, _ctx)) {
    if (kk_std_core_types__is_Nil(input, _ctx)) {
      return true;
    }
    {
      kk_std_core_types__list_drop(input, _ctx);
      return false;
    }
  }
  {
    struct kk_std_core_types_Cons* _con_x202 = kk_std_core_types__as_Cons(pat, _ctx);
    kk_box_t _box_x35 = _con_x202->head;
    kk_std_core_types__list prest = _con_x202->tail;
    kk_char_t p = kk_char_unbox(_box_x35, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(pat, _ctx)) {
      kk_datatype_ptr_free(pat, _ctx);
    }
    else {
      kk_std_core_types__list_dup(prest, _ctx);
      kk_datatype_ptr_decref(pat, _ctx);
    }
    kk_string_t _match_x102 = kk_std_core_string_char_fs_string(p, _ctx); /*string*/;
    if (kk_string_cmp_cstr_borrow(_match_x102, "\?", _ctx) == 0) {
      kk_string_drop(_match_x102, _ctx);
      if (kk_std_core_types__is_Nil(input, _ctx)) {
        kk_std_core_types__list_drop(prest, _ctx);
        return false;
      }
      {
        struct kk_std_core_types_Cons* _con_x203 = kk_std_core_types__as_Cons(input, _ctx);
        kk_box_t _box_x36 = _con_x203->head;
        kk_std_core_types__list irest = _con_x203->tail;
        kk_char_t c = kk_char_unbox(_box_x36, KK_BORROWED, _ctx);
        if kk_likely(kk_datatype_ptr_is_unique(input, _ctx)) {
          kk_datatype_ptr_free(input, _ctx);
        }
        else {
          kk_std_core_types__list_dup(irest, _ctx);
          kk_datatype_ptr_decref(input, _ctx);
        }
        bool _match_x104;
        kk_string_t _x_x204 = kk_std_core_string_char_fs_string(c, _ctx); /*string*/
        kk_string_t _x_x205;
        kk_define_string_literal(static, _s_x206, 1, "/", _ctx)
        _x_x205 = kk_string_dup(_s_x206, _ctx); /*string*/
        _match_x104 = kk_string_is_eq(_x_x204,_x_x205,kk_context()); /*bool*/
        if (_match_x104) {
          kk_std_core_types__list_drop(prest, _ctx);
          kk_std_core_types__list_drop(irest, _ctx);
          return false;
        }
        { // tailcall
          pat = prest;
          input = irest;
          goto kk__tailcall;
        }
      }
    }
    if (kk_string_cmp_cstr_borrow(_match_x102, "*", _ctx) == 0) {
      kk_string_drop(_match_x102, _ctx);
      if (kk_std_core_types__is_Nil(prest, _ctx)) {
        return kk_std_core_list_all(input, kk_src_main_new_hc__glob__match__chars_fun207(_ctx), _ctx);
      }
      {
        return kk_src_main_hc__glob__star(prest, input, _ctx);
      }
    }
    {
      kk_string_drop(_match_x102, _ctx);
      if (kk_std_core_types__is_Nil(input, _ctx)) {
        kk_std_core_types__list_drop(prest, _ctx);
        return false;
      }
      {
        struct kk_std_core_types_Cons* _con_x212 = kk_std_core_types__as_Cons(input, _ctx);
        kk_box_t _box_x40 = _con_x212->head;
        kk_std_core_types__list irest_0 = _con_x212->tail;
        kk_char_t c_1 = kk_char_unbox(_box_x40, KK_BORROWED, _ctx);
        if kk_likely(kk_datatype_ptr_is_unique(input, _ctx)) {
          kk_datatype_ptr_free(input, _ctx);
        }
        else {
          kk_std_core_types__list_dup(irest_0, _ctx);
          kk_datatype_ptr_decref(input, _ctx);
        }
        bool _match_x103 = (p == c_1); /*bool*/;
        if (_match_x103) { // tailcall
                           pat = prest;
                           input = irest_0;
                           goto kk__tailcall;
        }
        {
          kk_std_core_types__list_drop(prest, _ctx);
          kk_std_core_types__list_drop(irest_0, _ctx);
          return false;
        }
      }
    }
  }
}

bool kk_src_main_hc__glob__star(kk_std_core_types__list prest_0, kk_std_core_types__list input_0, kk_context_t* _ctx) { /* (prest : list<char>, input : list<char>) -> div bool */ 
  kk__tailcall: ;
  bool _match_x100;
  kk_std_core_types__list _x_x213 = kk_std_core_types__list_dup(prest_0, _ctx); /*list<char>*/
  kk_std_core_types__list _x_x214 = kk_std_core_types__list_dup(input_0, _ctx); /*list<char>*/
  _match_x100 = kk_src_main_hc__glob__match__chars(_x_x213, _x_x214, _ctx); /*bool*/
  if (_match_x100) {
    kk_std_core_types__list_drop(prest_0, _ctx);
    kk_std_core_types__list_drop(input_0, _ctx);
    return true;
  }
  if (kk_std_core_types__is_Nil(input_0, _ctx)) {
    kk_std_core_types__list_drop(prest_0, _ctx);
    return false;
  }
  {
    struct kk_std_core_types_Cons* _con_x215 = kk_std_core_types__as_Cons(input_0, _ctx);
    kk_box_t _box_x44 = _con_x215->head;
    kk_std_core_types__list irest_1 = _con_x215->tail;
    kk_char_t c_2 = kk_char_unbox(_box_x44, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(input_0, _ctx)) {
      kk_datatype_ptr_free(input_0, _ctx);
    }
    else {
      kk_std_core_types__list_dup(irest_1, _ctx);
      kk_datatype_ptr_decref(input_0, _ctx);
    }
    bool _match_x101;
    kk_string_t _x_x216 = kk_std_core_string_char_fs_string(c_2, _ctx); /*string*/
    kk_string_t _x_x217;
    kk_define_string_literal(static, _s_x218, 1, "/", _ctx)
    _x_x217 = kk_string_dup(_s_x218, _ctx); /*string*/
    _match_x101 = kk_string_is_eq(_x_x216,_x_x217,kk_context()); /*bool*/
    if (_match_x101) {
      kk_std_core_types__list_drop(prest_0, _ctx);
      kk_std_core_types__list_drop(irest_1, _ctx);
      return false;
    }
    { // tailcall
      input_0 = irest_1;
      goto kk__tailcall;
    }
  }
}

bool kk_src_main_hc__glob__doublestar(kk_std_core_types__list prest, kk_std_core_types__list paths, kk_context_t* _ctx) { /* (prest : list<string>, paths : list<string>) -> div bool */ 
  kk__tailcall: ;
  bool _match_x99;
  kk_std_core_types__list _x_x221 = kk_std_core_types__list_dup(prest, _ctx); /*list<string>*/
  kk_std_core_types__list _x_x222 = kk_std_core_types__list_dup(paths, _ctx); /*list<string>*/
  _match_x99 = kk_src_main_hc__glob__match__segments(_x_x221, _x_x222, _ctx); /*bool*/
  if (_match_x99) {
    kk_std_core_types__list_drop(prest, _ctx);
    kk_std_core_types__list_drop(paths, _ctx);
    return true;
  }
  if (kk_std_core_types__is_Nil(paths, _ctx)) {
    kk_std_core_types__list_drop(prest, _ctx);
    return false;
  }
  {
    struct kk_std_core_types_Cons* _con_x223 = kk_std_core_types__as_Cons(paths, _ctx);
    kk_box_t _box_x45 = _con_x223->head;
    kk_std_core_types__list srest = _con_x223->tail;
    kk_string_t _pat_3 = kk_string_unbox(_box_x45);
    if kk_likely(kk_datatype_ptr_is_unique(paths, _ctx)) {
      kk_string_drop(_pat_3, _ctx);
      kk_datatype_ptr_free(paths, _ctx);
    }
    else {
      kk_std_core_types__list_dup(srest, _ctx);
      kk_datatype_ptr_decref(paths, _ctx);
    }
    { // tailcall
      paths = srest;
      goto kk__tailcall;
    }
  }
}

bool kk_src_main_hc__glob__match__segments(kk_std_core_types__list pats, kk_std_core_types__list paths_0, kk_context_t* _ctx) { /* (pats : list<string>, paths : list<string>) -> div bool */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(pats, _ctx)) {
    if (kk_std_core_types__is_Nil(paths_0, _ctx)) {
      return true;
    }
    {
      kk_std_core_types__list_drop(paths_0, _ctx);
      return false;
    }
  }
  {
    struct kk_std_core_types_Cons* _con_x224 = kk_std_core_types__as_Cons(pats, _ctx);
    kk_box_t _box_x46 = _con_x224->head;
    kk_std_core_types__list prest_0 = _con_x224->tail;
    kk_string_t p = kk_string_unbox(_box_x46);
    if kk_likely(kk_datatype_ptr_is_unique(pats, _ctx)) {
      kk_datatype_ptr_free(pats, _ctx);
    }
    else {
      kk_string_dup(p, _ctx);
      kk_std_core_types__list_dup(prest_0, _ctx);
      kk_datatype_ptr_decref(pats, _ctx);
    }
    bool _match_x97;
    kk_string_t _x_x225 = kk_string_dup(p, _ctx); /*string*/
    kk_string_t _x_x226;
    kk_define_string_literal(static, _s_x227, 2, "**", _ctx)
    _x_x226 = kk_string_dup(_s_x227, _ctx); /*string*/
    _match_x97 = kk_string_is_eq(_x_x225,_x_x226,kk_context()); /*bool*/
    if (_match_x97) {
      kk_string_drop(p, _ctx);
      return kk_src_main_hc__glob__doublestar(prest_0, paths_0, _ctx);
    }
    if (kk_std_core_types__is_Nil(paths_0, _ctx)) {
      kk_std_core_types__list_drop(prest_0, _ctx);
      kk_string_drop(p, _ctx);
      return false;
    }
    {
      struct kk_std_core_types_Cons* _con_x228 = kk_std_core_types__as_Cons(paths_0, _ctx);
      kk_box_t _box_x47 = _con_x228->head;
      kk_std_core_types__list srest_0 = _con_x228->tail;
      kk_string_t s = kk_string_unbox(_box_x47);
      if kk_likely(kk_datatype_ptr_is_unique(paths_0, _ctx)) {
        kk_datatype_ptr_free(paths_0, _ctx);
      }
      else {
        kk_string_dup(s, _ctx);
        kk_std_core_types__list_dup(srest_0, _ctx);
        kk_datatype_ptr_decref(paths_0, _ctx);
      }
      bool _match_x98;
      kk_std_core_types__list _x_x229 = kk_std_core_string_list(p, _ctx); /*list<char>*/
      kk_std_core_types__list _x_x230 = kk_std_core_string_list(s, _ctx); /*list<char>*/
      _match_x98 = kk_src_main_hc__glob__match__chars(_x_x229, _x_x230, _ctx); /*bool*/
      if (_match_x98) { // tailcall
                        pats = prest_0;
                        paths_0 = srest_0;
                        goto kk__tailcall;
      }
      {
        kk_std_core_types__list_drop(srest_0, _ctx);
        kk_std_core_types__list_drop(prest_0, _ctx);
        return false;
      }
    }
  }
}


// lift anonymous function
struct kk_src_main_hc__glob__match__path_fun235__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_main_hc__glob__match__path_fun235(kk_function_t _fself, kk_box_t _b_x50, kk_context_t* _ctx);
static kk_function_t kk_src_main_new_hc__glob__match__path_fun235(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_main_hc__glob__match__path_fun235, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_main_hc__glob__match__path_fun235(kk_function_t _fself, kk_box_t _b_x50, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x236;
  kk_char_t _x_x237 = kk_char_unbox(_b_x50, KK_OWNED, _ctx); /*char*/
  _x_x236 = kk_std_core_string_char_fs_string(_x_x237, _ctx); /*string*/
  return kk_string_box(_x_x236);
}


// lift anonymous function
struct kk_src_main_hc__glob__match__path_fun244__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_main_hc__glob__match__path_fun244(kk_function_t _fself, kk_box_t _b_x55, kk_context_t* _ctx);
static kk_function_t kk_src_main_new_hc__glob__match__path_fun244(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_main_hc__glob__match__path_fun244, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_main_hc__glob__match__path_fun244(kk_function_t _fself, kk_box_t _b_x55, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x245;
  kk_char_t _x_x246 = kk_char_unbox(_b_x55, KK_OWNED, _ctx); /*char*/
  _x_x245 = kk_std_core_string_char_fs_string(_x_x246, _ctx); /*string*/
  return kk_string_box(_x_x245);
}

bool kk_src_main_hc__glob__match__path(kk_string_t pattern, kk_string_t hc__path, kk_context_t* _ctx) { /* (pattern : string, hc_path : string) -> div bool */ 
  kk_std_core_types__list pat__parts;
  bool _match_x94;
  kk_string_t _x_x231;
  kk_define_string_literal(static, _s_x232, 1, "/", _ctx)
  _x_x231 = kk_string_dup(_s_x232, _ctx); /*string*/
  kk_string_t _x_x233 = kk_string_empty(); /*string*/
  _match_x94 = kk_string_is_eq(_x_x231,_x_x233,kk_context()); /*bool*/
  if (_match_x94) {
    kk_std_core_types__list _b_x48_51 = kk_std_core_string_list(pattern, _ctx); /*list<char>*/;
    kk_function_t _brw_x95 = kk_src_main_new_hc__glob__match__path_fun235(_ctx); /*(10001) -> 10003 10002*/;
    kk_std_core_types__list _brw_x96 = kk_std_core_list_map(_b_x48_51, _brw_x95, _ctx); /*list<10002>*/;
    kk_function_drop(_brw_x95, _ctx);
    pat__parts = _brw_x96; /*list<string>*/
  }
  else {
    kk_vector_t v_10011;
    kk_string_t _x_x238;
    kk_define_string_literal(static, _s_x239, 1, "/", _ctx)
    _x_x238 = kk_string_dup(_s_x239, _ctx); /*string*/
    v_10011 = kk_string_splitv(pattern,_x_x238,kk_context()); /*vector<string>*/
    pat__parts = kk_std_core_vector_vlist(v_10011, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/
  }
  kk_std_core_types__list path__parts;
  bool _match_x91;
  kk_string_t _x_x240;
  kk_define_string_literal(static, _s_x241, 1, "/", _ctx)
  _x_x240 = kk_string_dup(_s_x241, _ctx); /*string*/
  kk_string_t _x_x242 = kk_string_empty(); /*string*/
  _match_x91 = kk_string_is_eq(_x_x240,_x_x242,kk_context()); /*bool*/
  if (_match_x91) {
    kk_std_core_types__list _b_x53_56 = kk_std_core_string_list(hc__path, _ctx); /*list<char>*/;
    kk_function_t _brw_x92 = kk_src_main_new_hc__glob__match__path_fun244(_ctx); /*(10001) -> 10003 10002*/;
    kk_std_core_types__list _brw_x93 = kk_std_core_list_map(_b_x53_56, _brw_x92, _ctx); /*list<10002>*/;
    kk_function_drop(_brw_x92, _ctx);
    path__parts = _brw_x93; /*list<string>*/
  }
  else {
    kk_vector_t v_10011_0;
    kk_string_t _x_x247;
    kk_define_string_literal(static, _s_x248, 1, "/", _ctx)
    _x_x247 = kk_string_dup(_s_x248, _ctx); /*string*/
    v_10011_0 = kk_string_splitv(hc__path,_x_x247,kk_context()); /*vector<string>*/
    path__parts = kk_std_core_vector_vlist(v_10011_0, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/
  }
  return kk_src_main_hc__glob__match__segments(pat__parts, path__parts, _ctx);
}


// lift anonymous function
struct kk_src_main_hc__words_fun254__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_main_hc__words_fun254(kk_function_t _fself, kk_box_t _b_x60, kk_context_t* _ctx);
static kk_function_t kk_src_main_new_hc__words_fun254(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_main_hc__words_fun254, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_main_hc__words_fun254(kk_function_t _fself, kk_box_t _b_x60, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x255;
  kk_char_t _x_x256 = kk_char_unbox(_b_x60, KK_OWNED, _ctx); /*char*/
  _x_x255 = kk_std_core_string_char_fs_string(_x_x256, _ctx); /*string*/
  return kk_string_box(_x_x255);
}


// lift anonymous function
struct kk_src_main_hc__words_fun259__t {
  struct kk_function_s _base;
};
static bool kk_src_main_hc__words_fun259(kk_function_t _fself, kk_box_t _b_x63, kk_context_t* _ctx);
static kk_function_t kk_src_main_new_hc__words_fun259(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_main_hc__words_fun259, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static bool kk_src_main_hc__words_fun259(kk_function_t _fself, kk_box_t _b_x63, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  bool b_10029;
  kk_integer_t _brw_x82;
  kk_string_t _x_x260 = kk_string_unbox(_b_x63); /*string*/
  _brw_x82 = kk_std_core_string_chars_fs_count(_x_x260, _ctx); /*int*/
  bool _brw_x83 = kk_integer_eq_borrow(_brw_x82,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x82, _ctx);
  b_10029 = _brw_x83; /*bool*/
  if (b_10029) {
    return false;
  }
  {
    return true;
  }
}

kk_std_core_types__list kk_src_main_hc__words(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> list<string> */ 
  kk_std_core_types__list _b_x61_64;
  bool _match_x84;
  kk_string_t _x_x250;
  kk_define_string_literal(static, _s_x251, 1, " ", _ctx)
  _x_x250 = kk_string_dup(_s_x251, _ctx); /*string*/
  kk_string_t _x_x252 = kk_string_empty(); /*string*/
  _match_x84 = kk_string_is_eq(_x_x250,_x_x252,kk_context()); /*bool*/
  if (_match_x84) {
    kk_std_core_types__list _b_x58_66 = kk_std_core_string_list(s, _ctx); /*list<char>*/;
    kk_function_t _brw_x85 = kk_src_main_new_hc__words_fun254(_ctx); /*(10001) -> 10003 10002*/;
    kk_std_core_types__list _brw_x86 = kk_std_core_list_map(_b_x58_66, _brw_x85, _ctx); /*list<10002>*/;
    kk_function_drop(_brw_x85, _ctx);
    _b_x61_64 = _brw_x86; /*list<string>*/
  }
  else {
    kk_vector_t v_10011;
    kk_string_t _x_x257;
    kk_define_string_literal(static, _s_x258, 1, " ", _ctx)
    _x_x257 = kk_string_dup(_s_x258, _ctx); /*string*/
    v_10011 = kk_string_splitv(s,_x_x257,kk_context()); /*vector<string>*/
    _b_x61_64 = kk_std_core_vector_vlist(v_10011, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/
  }
  return kk_std_core_list_filter(_b_x61_64, kk_src_main_new_hc__words_fun259(_ctx), _ctx);
}


// lift anonymous function
struct kk_src_main_hc__lines_fun265__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_main_hc__lines_fun265(kk_function_t _fself, kk_box_t _b_x71, kk_context_t* _ctx);
static kk_function_t kk_src_main_new_hc__lines_fun265(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_main_hc__lines_fun265, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_main_hc__lines_fun265(kk_function_t _fself, kk_box_t _b_x71, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x266;
  kk_char_t _x_x267 = kk_char_unbox(_b_x71, KK_OWNED, _ctx); /*char*/
  _x_x266 = kk_std_core_string_char_fs_string(_x_x267, _ctx); /*string*/
  return kk_string_box(_x_x266);
}

kk_std_core_types__list kk_src_main_hc__lines(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> list<string> */ 
  bool _match_x79;
  kk_string_t _x_x261;
  kk_define_string_literal(static, _s_x262, 1, "\n", _ctx)
  _x_x261 = kk_string_dup(_s_x262, _ctx); /*string*/
  kk_string_t _x_x263 = kk_string_empty(); /*string*/
  _match_x79 = kk_string_is_eq(_x_x261,_x_x263,kk_context()); /*bool*/
  if (_match_x79) {
    kk_std_core_types__list _b_x69_72 = kk_std_core_string_list(s, _ctx); /*list<char>*/;
    kk_function_t _brw_x80 = kk_src_main_new_hc__lines_fun265(_ctx); /*(10001) -> 10003 10002*/;
    kk_std_core_types__list _brw_x81 = kk_std_core_list_map(_b_x69_72, _brw_x80, _ctx); /*list<10002>*/;
    kk_function_drop(_brw_x80, _ctx);
    return _brw_x81;
  }
  {
    kk_vector_t v_10011;
    kk_string_t _x_x268;
    kk_define_string_literal(static, _s_x269, 1, "\n", _ctx)
    _x_x268 = kk_string_dup(_s_x269, _ctx); /*string*/
    v_10011 = kk_string_splitv(s,_x_x268,kk_context()); /*vector<string>*/
    return kk_std_core_vector_vlist(v_10011, kk_std_core_types__new_None(_ctx), _ctx);
  }
}

kk_string_t kk_src_main_hc__repeat__str(kk_string_t s, kk_integer_t n, kk_context_t* _ctx) { /* (s : string, n : int) -> div string */ 
  bool _match_x78 = kk_integer_lte_borrow(n,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x78) {
    kk_string_drop(s, _ctx);
    kk_integer_drop(n, _ctx);
    return kk_string_empty();
  }
  {
    kk_string_t _x_x275 = kk_string_dup(s, _ctx); /*string*/
    kk_string_t _x_x276;
    kk_integer_t _x_x277 = kk_integer_add_small_const(n, -1, _ctx); /*int*/
    _x_x276 = kk_src_main_hc__repeat__str(s, _x_x277, _ctx); /*string*/
    return kk_std_core_types__lp__plus__plus__rp_(_x_x275, _x_x276, _ctx);
  }
}

kk_string_t kk_src_main_hc__pad__left(kk_string_t s, kk_integer_t width, kk_string_t ch, kk_context_t* _ctx) { /* (s : string, width : int, ch : string) -> div string */ 
  kk_integer_t y_10043;
  kk_string_t _x_x278 = kk_string_dup(s, _ctx); /*string*/
  y_10043 = kk_std_core_string_chars_fs_count(_x_x278, _ctx); /*int*/
  kk_integer_t b_10041 = kk_integer_sub(width,y_10043,kk_context()); /*int*/;
  kk_string_t _x_x279;
  kk_integer_t _x_x280;
  bool _match_x77 = kk_integer_gt_borrow((kk_integer_from_small(0)),b_10041,kk_context()); /*bool*/;
  if (_match_x77) {
    kk_integer_drop(b_10041, _ctx);
    _x_x280 = kk_integer_from_small(0); /*int*/
  }
  else {
    _x_x280 = b_10041; /*int*/
  }
  _x_x279 = kk_src_main_hc__repeat__str(ch, _x_x280, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x279, s, _ctx);
}

kk_string_t kk_src_main_hc__pad__right(kk_string_t s, kk_integer_t width, kk_string_t ch, kk_context_t* _ctx) { /* (s : string, width : int, ch : string) -> div string */ 
  kk_integer_t y_10047;
  kk_string_t _x_x281 = kk_string_dup(s, _ctx); /*string*/
  y_10047 = kk_std_core_string_chars_fs_count(_x_x281, _ctx); /*int*/
  kk_integer_t b_10045 = kk_integer_sub(width,y_10047,kk_context()); /*int*/;
  kk_string_t _x_x282;
  kk_integer_t _x_x283;
  bool _match_x76 = kk_integer_gt_borrow((kk_integer_from_small(0)),b_10045,kk_context()); /*bool*/;
  if (_match_x76) {
    kk_integer_drop(b_10045, _ctx);
    _x_x283 = kk_integer_from_small(0); /*int*/
  }
  else {
    _x_x283 = b_10045; /*int*/
  }
  _x_x282 = kk_src_main_hc__repeat__str(ch, _x_x283, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(s, _x_x282, _ctx);
}

kk_string_t kk_src_main_hc__center(kk_string_t s, kk_integer_t width, kk_string_t ch, kk_context_t* _ctx) { /* (s : string, width : int, ch : string) -> div string */ 
  kk_integer_t y_10051;
  kk_string_t _x_x284 = kk_string_dup(s, _ctx); /*string*/
  y_10051 = kk_std_core_string_chars_fs_count(_x_x284, _ctx); /*int*/
  kk_integer_t b_10049 = kk_integer_sub(width,y_10051,kk_context()); /*int*/;
  kk_integer_t total;
  bool _match_x75 = kk_integer_gt_borrow((kk_integer_from_small(0)),b_10049,kk_context()); /*bool*/;
  if (_match_x75) {
    kk_integer_drop(b_10049, _ctx);
    total = kk_integer_from_small(0); /*int*/
  }
  else {
    total = b_10049; /*int*/
  }
  kk_integer_t left;
  kk_integer_t _x_x285 = kk_integer_dup(total, _ctx); /*int*/
  left = kk_integer_div(_x_x285,(kk_integer_from_small(2)),kk_context()); /*int*/
  kk_integer_t right;
  kk_integer_t _x_x286 = kk_integer_dup(left, _ctx); /*int*/
  right = kk_integer_sub(total,_x_x286,kk_context()); /*int*/
  kk_string_t _x_x287;
  kk_string_t _x_x288;
  kk_string_t _x_x289 = kk_string_dup(ch, _ctx); /*string*/
  _x_x288 = kk_src_main_hc__repeat__str(_x_x289, left, _ctx); /*string*/
  _x_x287 = kk_std_core_types__lp__plus__plus__rp_(_x_x288, s, _ctx); /*string*/
  kk_string_t _x_x290 = kk_src_main_hc__repeat__str(ch, right, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x287, _x_x290, _ctx);
}

kk_string_t kk_src_main_hc__removeprefix(kk_string_t s, kk_string_t pre, kk_context_t* _ctx) { /* (s : string, pre : string) -> string */ 
  kk_std_core_types__maybe maybe_10054;
  kk_string_t _x_x291 = kk_string_dup(s, _ctx); /*string*/
  kk_string_t _x_x292 = kk_string_dup(pre, _ctx); /*string*/
  maybe_10054 = kk_std_core_sslice_starts_with(_x_x291, _x_x292, _ctx); /*maybe<sslice/sslice>*/
  if (kk_std_core_types__is_Just(maybe_10054, _ctx)) {
    kk_box_t _box_x74 = maybe_10054._cons.Just.value;
    kk_std_core_types__maybe_drop(maybe_10054, _ctx);
    kk_std_core_types__list _x_x293;
    kk_std_core_types__list _x_x294 = kk_std_core_string_list(s, _ctx); /*list<char>*/
    kk_integer_t _x_x295 = kk_std_core_string_chars_fs_count(pre, _ctx); /*int*/
    _x_x293 = kk_std_core_list_drop(_x_x294, _x_x295, _ctx); /*list<10001>*/
    return kk_std_core_string_listchar_fs_string(_x_x293, _ctx);
  }
  {
    kk_string_drop(pre, _ctx);
    return s;
  }
}

// initialization
void kk_src_main__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core_exn__init(_ctx);
  kk_std_core_bool__init(_ctx);
  kk_std_core_order__init(_ctx);
  kk_std_core_char__init(_ctx);
  kk_std_core_int__init(_ctx);
  kk_std_core_vector__init(_ctx);
  kk_std_core_string__init(_ctx);
  kk_std_core_sslice__init(_ctx);
  kk_std_core_list__init(_ctx);
  kk_std_core_maybe__init(_ctx);
  kk_std_core_maybe2__init(_ctx);
  kk_std_core_either__init(_ctx);
  kk_std_core_tuple__init(_ctx);
  kk_std_core_lazy__init(_ctx);
  kk_std_core_show__init(_ctx);
  kk_std_core_debug__init(_ctx);
  kk_std_core_delayed__init(_ctx);
  kk_std_core_console__init(_ctx);
  kk_std_core__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_src_main__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core__done(_ctx);
  kk_std_core_console__done(_ctx);
  kk_std_core_delayed__done(_ctx);
  kk_std_core_debug__done(_ctx);
  kk_std_core_show__done(_ctx);
  kk_std_core_lazy__done(_ctx);
  kk_std_core_tuple__done(_ctx);
  kk_std_core_either__done(_ctx);
  kk_std_core_maybe2__done(_ctx);
  kk_std_core_maybe__done(_ctx);
  kk_std_core_list__done(_ctx);
  kk_std_core_sslice__done(_ctx);
  kk_std_core_string__done(_ctx);
  kk_std_core_vector__done(_ctx);
  kk_std_core_int__done(_ctx);
  kk_std_core_char__done(_ctx);
  kk_std_core_order__done(_ctx);
  kk_std_core_bool__done(_ctx);
  kk_std_core_exn__done(_ctx);
  kk_std_core_hnd__done(_ctx);
  kk_std_core_types__done(_ctx);
}
