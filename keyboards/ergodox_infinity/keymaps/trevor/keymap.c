#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

enum custom_layers {
    _QWERTY,
    _DVORAK,
    _COLEMAK,
    _GAME,
    _MOUSE,
    _NUM,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NAV,
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    DVORAK,
    COLEMAK,
    LOWER,
    RAISE,
    GAME,
    MOUSE,
    NUM,
    EPRM,
    VRSN,
    NAV,
    RGB_SLD
};

//TD Declarations
enum {
RZEALT = 0,
// PRN,
// EGT,
// HRD,
// XRD,
// DSH,
// ESC,
// EQE,
// PGN,
// HND,
// COD,
// UND,
// F11,
// F12,
// F13,
// F14,
// F15,
// F16,
// F17,
// F18,
// F19,
// F20,
// //unicode_inputctl
// LINUX,
// WIN,
// WINSH,
// OSX,
};

// navigation layer keys
#define W1 LGUI(KC_1)
#define W2 LGUI(KC_2)
#define W3 LGUI(KC_3)
#define W4 LGUI(KC_4)
#define W5 LGUI(KC_5)
#define W6 LGUI(KC_6)
#define W7 LGUI(KC_7)
#define W8 LGUI(KC_8)
#define W9 LGUI(KC_9)
#define W10 LGUI(KC_0)
#define W11 LALT(LGUI(KC_1))
#define W12 LALT(LGUI(KC_2))
#define W13 LALT(LGUI(KC_3))
#define W14 LALT(LGUI(KC_4))
#define W15 LALT(LGUI(KC_5))
#define W16 LALT(LGUI(KC_6))
#define W17 LALT(LGUI(KC_7))
#define W18 LALT(LGUI(KC_8))
#define W19 LALT(LGUI(KC_9))
#define W20 LALT(LGUI(KC_0))
#define TERM LGUI(KC_ENT)
#define OPEN LGUI(KC_O)
#define LOCK LGUI(KC_U)

// LT(layer, kc) hold: layer tap: key
// TO(layer) hold: layer
// TG(layer) toggle layer
// OSM(mod) hold mod for one keypress
// OSL(layer) hold layer for one keypress
// MT(mod, kc) hold: mod tap: key


// make bottom left button on right thumb cluster a leader key
//

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic QWERTY layer
 *
 * ,---------------------------------------------.           ,---------------------------------------------.
 * |   `    |  1  |  2  |  3  |  4  |  5  | Esc  |           | Num  |  6  |  7  |  8  |  9  |  0  |   -    |
 * |--------+-----+-----+-----+-----+------------|           |------+-----+-----+-----+-----+-----+--------|
 * |  Tab   |  Q  |  W  |  E  |  R  |  T  |  [{  |           |  ]}  |  Y  |  U  |  I  |  O  |  P  |   \    |
 * |--------+-----+-----+-----+-----+-----|      |           |      |-----+-----+-----+-----+-----+--------|
 * |NAV/bksp|  A  |  S  |  D  |  F  |  G  |------|           |------|  H  |  J  |  K  |  L  |  ;  |   '"   |
 * |--------+-----+-----+-----+-----+-----|  (   |           |   )  |-----+-----+-----+-----+-----+--------|
 * |Shift   |  Z  |  X  |  C  |  V  |  B  |      |           |      |  N  |  M  |  ,  |  .  |mou//|Shift   |
 * `--------+-----+-----+-----+-----+------------'           `------------+-----+-----+-----+-----+--------'
 *   | Ctrl |LGUI |LGUI | ALT |Lower|                                     |Raise|Left |Down | Up  |Right |
 *   `------------------------------'                                     `------------------------------'
 *                                   ,------------.          ,------------.
 *                                   |Esc  |Mouse |          | Num  |Mouse|
 *                              ,----|-----|------|          |------+-----+-----.
 *                              |    |     | Adj  |          | Adj  |ENTER|     |
 *                              | SPC|LOWER|------|          |------|RAISE|Space|
 *                              |    |     | LGUI |          | LGUI |     |     |
 *                              `-----------------'          `------------------'
 */
[_QWERTY] = LAYOUT_ergodox(
  // left hand
  KC_GRV,               KC_1,    KC_2,    KC_3,    KC_4,  KC_5, KC_ESC,
  KC_TAB,               KC_Q,    KC_W,    KC_E,    KC_R,  KC_T, KC_LBRACKET,
  LT(_NAV,KC_BSPACE),   KC_A,    KC_S,    KC_D,    KC_F,  KC_G,
  OSM(MOD_LSFT),         KC_Z,    KC_X,    KC_C,    KC_V,  KC_B, KC_LPRN,
  KC_LCTL,              KC_LGUI, KC_LGUI, KC_LALT, LOWER,

                                                  KC_ESC,   TG(_MOUSE),
                                                            TG(_ADJUST),
                                        KC_SPACE, KC_LGUI,   KC_LGUI,

  // right hand
  TG(_NUM),     KC_6,          KC_7,     KC_8,    KC_9,                  KC_0,      KC_MINS,
  KC_RBRACKET,  KC_Y,          KC_U,     KC_I,    KC_O,                  KC_P,      KC_BSLS,
                KC_H,          KC_J,     KC_K,    KC_L,              KC_SCOLON,   LT(_NAV, KC_QUOTE),
  KC_RPRN,      KC_N,          KC_M,  KC_COMM,   KC_DOT,   LT(_MOUSE, KC_SLSH), OSM(MOD_RSFT),
                              RAISE, KC_LEFT,  KC_DOWN,                 KC_UP,      KC_RIGHT,

  TG(_NUM), TG(_MOUSE),
  TG(_ADJUST),
  KC_LGUI,  MT(MOD_LGUI, KC_ENTER), KC_SPACE
),

/* Keymap 0: Basic Dvorak layer
 *TD(RZEALT)
 * ,---------------------------------------------.           ,--------------------------------------------.
 * |        |     |     |     |     |     |      |           |      |     |     |     |     |     |        |
 * |--------+-----+-----+-----+-----+------------|           |------+-----+-----+-----+-----+-----+--------|
 * |        |  '  |  ,  |  .  |  P  |  Y  |      |           |      |  F  |  G  |  C  |  R  |  L  |        |
 * |--------+-----+-----+-----+-----+-----|      |           |      |-----+-----+-----+-----+-----+--------|
 * |        |  A  |  O  |  E  |  U  |  I  |------|           |------|  D  |  H  |  T  |  N  |  S  |   /    |
 * |--------+-----+-----+-----+-----+-----|      |           |      |-----+-----+-----+-----+-----+--------|
 * |        |  ;  |  Q  |  J  |  K  |  X  |      |           |      |  B  |  M  |  W  |  V  |  Z  |        |
 * `--------+-----+-----+-----+-----+------------'           `------------+-----+-----+-----+-----+--------'
 *   |      |     |     |     |     |                                     |     |     |     |     |      |
 *   `------------------------------'                                     `------------------------------'
 *                                   ,------------.          ,------------.
 *                                   |     |      |          |      |     |
 *                              ,----|-----|------|          |------+-----+-----.
 *                              |    |     |      |          |      |     |     |
 *                              |    |     |------|          |------|     |     |
 *                              |    |     |      |          |      |     |     |
 *                              `-----------------'          `------------------'
 */
[_DVORAK] = LAYOUT_ergodox(
  // left hand
  _______,   _______, _______, _______, _______, _______, _______,
  _______,   KC_QUOT, KC_COMM,  KC_DOT,    KC_P,    KC_Y, _______,
  _______,      KC_A,    KC_O,    KC_E,    KC_U,    KC_I,
  _______, KC_SCOLON,    KC_Q,    KC_J,    KC_K,    KC_X, _______,
  _______,   _______, _______, _______, _______,

                                                 _______, _______,
                                                          _______,
                                      _______,  _______,  _______,

  // right hand
   _______,  _______, _______, _______, _______, _______,  _______,
   _______,     KC_F,    KC_G,    KC_C,    KC_R,    KC_L,  _______,
                KC_D,    KC_H,    KC_T,    KC_N,    KC_S,  LT(MOUSE, KC_SLSH),
   _______,     KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,  _______,
                      _______, _______, _______, _______,  _______,

  TG(_NUM), _______,
   _______,
   _______, _______,  _______
),

/* Keymap 0: Basic Colemak layer
 *
 * ,---------------------------------------------.           ,--------------------------------------------.
 * |        |     |     |     |     |     |      |           |      |     |     |     |     |     |        |
 * |--------+-----+-----+-----+-----+------------|           |------+-----+-----+-----+-----+-----+--------|
 * |        |  Q  |  D  |  R  |  W  |  B  |      |           |      |  J  |  F  |  U  |  P  |  ;  |        |
 * |--------+-----+-----+-----+-----+-----|      |           |      |-----+-----+-----+-----+-----+--------|
 * |        |  A  |  S  |  H  |  T  |  G  |------|           |------|  Y  |  N  |  E  |  O  |  I  |   '"   |
 * |--------+-----+-----+-----+-----+-----|      |           |      |-----+-----+-----+-----+-----+--------|
 * |        |  Z  |  X  |  M  |  C  |  V  |      |           |      |  K  |  L  |  ,  |  .  |  /  |        |
 * `--------+-----+-----+-----+-----+------------'           `------------+-----+-----+-----+-----+--------'
 *   |      |     |     |     |     |                                     |     |     |     |     |      |
 *   `------------------------------'                                     `------------------------------'
 *                                   ,------------.          ,------------.
 *                                   |     |      |          |      |     |
 *                              ,----|-----|------|          |------+-----+-----.
 *                              |    |     |      |          |      |     |     |
 *                              |    |     |------|          |------|     |     |
 *                              |    |     |      |          |      |     |     |
 *                              `-----------------'          `------------------'
 */
[_COLEMAK] = LAYOUT_ergodox(
  // left hand
  _______, _______, _______, _______, _______, _______, _______,
  _______,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G, _______,
  _______,    KC_A,    KC_R,    KC_S,    KC_T,    KC_D,
  _______,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, _______,
  _______, _______, _______, _______, _______,

                                                  _______, _______,
                                                           _______,
                                      _______,  _______,   _______,

  // right hand
  _______,  _______, _______, _______, _______,             _______,  _______,
  _______,     KC_J,    KC_L,    KC_U,    KC_Y,           KC_SCOLON,  _______,
               KC_H,    KC_N,    KC_E,    KC_I,                KC_O, KC_QUOTE,
  _______,     KC_K,    KC_M, KC_COMM,  KC_DOT, LT(_MOUSE, KC_SLSH),  _______,
                     _______, _______, _______,             _______,  _______,

      NUM,  _______,
  _______,
  _______,  _______, _______
),

/* Lower
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * | Version |  F1  |  F2  |  F3  |  F4  |  F5  | F11  |           | F12  |  F6  |  F7  |  F8  |  F9  | F10  |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |    ~    |  !   |  @   |  #   |  $   |  %   |      |           |      |  ^   |  &   |  *   |  (   |  )   |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   Del   |  F1  |  F2  |  F3  |  F4  |  F5  |------|           |------|  F6  |  _   |  +   |  {   |  }   |   |    |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |  F7  |  F8  |  F9  | F10  | F11  |      |           |      | F12  |ISO ~ |ISO | | Home | End  |  ENTER |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      | Next | Vol- | Vol+ | Play |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                       ,-------------.           ,-------------.
 *                                       |      |      |           |      |       |
 *                                ,------|------|------|           |------+------+------.
 *                                |      |      |      |           |      |      |      |
 *                                |      |      |------|           |------|      |      |
 *                                |      |      |      |           |      |      |      |
 *                                `--------------------'           `--------------------'

 test lower
_+{}(
 */

[_LOWER] = LAYOUT_ergodox(
  // left hand
  VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   KC_F11,
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,   KC_PERC, _______,
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  _______,
  _______, _______, _______, _______, _______,

                                       _______, _______,
                                                _______,
                              _______, _______, _______,

  // right hand
  KC_F12,  KC_F6,   KC_F7,      KC_F8,      KC_F9,   KC_F10,  KC_F11,
  _______, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, _______,
           KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
  _______, KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  KC_ENTER,
                    _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY,

  _______, _______,
  _______,
  _______, _______, _______
),

/* Raise
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * | Version |  F1  |  F2  |  F3  |  F4  |  F5  | F11  |           | F12  |  F6  |  F7  |  F8  |  F9  | F10  |  F11   |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |    `    |  1   |  2   |  3   |  4   |  5   |      |           |      |  6   |  7   |  8   |  9   |  0   |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   Del   |  F1  |  F2  |  F3  |  F4  |  F5  |------|           |------|  F6  |  -   |  =   |  [   |  ]   |   \    |
 * |---------+------+------+------+------+------|  L2  |           |  L2  |------+------+------+------+------+--------|
 * |         |  F7  |  F8  |  F9  | F10  | F11  |      |           |      | F12  |ISO # |ISO / |Pg Up |Pg Dn | ENTER  |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      | Next | Vol- | Vol+ | Play |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                       ,-------------.           ,-------------.
 *                                       |      |      |           |      |      |
 *                                ,------|------|------|           |------+------+------.
 *                                |      |      |      |           |      |      |      |
 *                                |      |      |------|           |------|      |      |
 *                                |      |      |      |           |      |      |      |
 *                                `--------------------'           `--------------------'
 */
[_RAISE] = LAYOUT_ergodox(
  // left hand
  VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______,
  _______, _______, _______, _______, _______,

                                               _______, _______,
                                                        _______,
                                      _______, _______, _______,

  // right hand
  KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
           KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
  _______, KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, KC_ENTER,
                    _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY,

  _______, _______,
  _______,
  _______, _______,  _______
),

/* Adjust
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |Version |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |Reset |Debug |      |      |      |      |           |      |      |TRM on|TRMoff|      | RESET|  Del   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |AG Nrm|------|           |------|AG Swp|QWERTY|Wrkman|Dvorak|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                      ,-------------.           ,-------------.
 *                                      |      |      |           |      |      |
 *                               ,------|------|------|           |------+------+------.
 *                               |      |      |      |           |      |      |      |
 *                               |      |      |------|           |------|      |      |
 *                               |      |      |      |           |      |      |      |
 *                               `--------------------'           `--------------------'
 */
[_ADJUST] = LAYOUT_ergodox(
  // left hand
  VRSN,    _______, _______, _______, _______, _______, _______,
  _______, RESET,   DEBUG,   _______, _______, _______, _______,
  _______, _______, _______, _______, _______, AG_NORM,
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,

                                               _______, _______,
                                                        _______,
                                      _______, _______, _______,

  // right hand
  _______, _______, _______, _______,  _______, _______, _______,
  _______, _______, TERM_ON, TERM_OFF, _______,   RESET,  KC_DEL,
           AG_SWAP, QWERTY,  COLEMAK,  DVORAK,  _______, _______,
  _______, _______, _______, _______,  _______, _______, _______,
                    _______, _______,  _______, _______, _______,

  _______, _______,
  _______,
  _______, _______,  _______
),

/*  Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | Lclk | MsUp | Rclk |Wh Up |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|Wh Dn |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                      ,-------------.           ,-------------.
 *                                      |      |      |           |      |      |
 *                               ,------|------|------|           |------+------+------.
 *                               |      |      |      |           |      |Brwser|Brwser|
 *                               | Lclk | Rclk |------|           |------|Back  |Fwd   |
 *                               |      |      |      |           |      |      |      |
 *                               `--------------------'           `--------------------'
 */
// MOUSE
[_MOUSE] = LAYOUT_ergodox(
  // left hand
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, _______,
  _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,
  _______, _______, KC_WH_L, KC_BTN3, KC_WH_R, _______, TO(_GAME),
  _______, _______, _______, _______, _______,

                                       _______, _______,
                                                KC_WH_U,
                              KC_BTN1, KC_BTN2, KC_WH_D,

  // right hand
  _______,   _______, _______, _______, _______, _______, _______,
  _______,   _______, _______, _______, _______, _______, _______,
             _______, _______, _______, _______, _______, KC_MPLY,
  TO(_GAME), _______, _______, KC_MPRV, KC_MNXT, _______, _______,
                      KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,

  _______, _______,
  _______,
  _______, KC_WBAK, KC_WFWD
),

/* arrow and navigation keys
 * Imitate my old pok3r layout
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  w1  |  w2  |  w3  |  w4  |  w5  |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  w6  |  w7  |  w8  |  w9  | w10  |      |           |      |      | lock |  UP  |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | w11  | w12  | w13  | w14  | w15  |------|           |------| HOME | LEFT | DOWN | RIGHT| open |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  SHIFT | w16  | w17  | w18  | w19  | w20  |      |           |      | END  |      | Prev | Next |      |  term  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                      ,-------------.           ,-------------.
 *                                      |      |      |           |      |      |
 *                               ,------|------|------|           |------+------+------.
 *                               |      |      |      |           |      |Brwser|      |
 *                               | Lclk | Rclk |------|           |------|Back  |SPACE |
 *                               |      |      |      |           |      |      |      |
 *                               `--------------------'           `--------------------'
 */
// NAV
[_NAV] = LAYOUT_ergodox(
  // left hand
  _______,      W1,      W2,      W3,      W4,      W5, _______,
  _______,      W6,      W7,      W8,      W9,     W10, _______,
  _______,     W11,     W12,     W13,     W14,     W15,
  KC_LSFT,     W16,     W17,     W18,     W19,     W20, _______,
  _______, _______, _______, _______, _______,

                                       _______, _______,
                                                KC_WH_D,
                            KC_BSPACE, _______, KC_WH_U,

  // right hand
  _______,   _______, _______, _______,  _______, _______, _______,
  _______,   _______,    LOCK,   KC_UP,  _______, _______, _______,
             KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT,    OPEN, _______,
  _______,    KC_END, _______, KC_MPRV,  KC_MNXT, _______,    TERM,
                      KC_VOLU, KC_VOLD,  KC_MUTE, _______, _______,

  _______, _______,
  _______,
  _______, KC_WBAK, KC_BSPACE
),

/* GAME
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | Lclk | MsUp | Rclk |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                      ,-------------.           ,-------------.
 *                                      |      |      |           |      |      |
 *                               ,------|------|------|           |------+------+------.
 *                               |      |      |      |           |      |Brwser|Brwser|
 *                               | Lclk | Rclk |------|           |------|Back  |Fwd   |
 *                               |      |      |      |           |      |      |      |
 *                               `--------------------'           `--------------------'
 */
[_GAME] = LAYOUT_ergodox(
  // left hand
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,

                                                  _______, _______,
                                                           _______,
                                        KC_SPACE, KC_LGUI, KC_LALT,

  // right hand
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______, _______,

  TG(_MOUSE), TG(_NUM),
  _______,
  _______,    _______,  _______
),


/* NUMPAD
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  | F11  |           | F12  |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |  !   |  @   |  {   |  }   |  |   |      |           | num  |      |  7   |  8   |  9   |  *   |        |
 * |--------+------+------+------+------+------|      |           | lock |------+------+------+------+------+--------|
 * |        |  #   |  $   |  (   |  )   |  `   |------|           |------|      |  4   |  5   |  6   |  +   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  %   |  ^   |  [   |  ]   |  ~   |      |           |      |      |  1   |  2   |  3   |  /

    |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |  .   |  0   |  0   |  =   |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                      ,-------------.           ,-------------.
 *                                      |      |      |           |      |      |
 *                               ,------|------|------|           |------+------+------.
 *                               |      |      |      |           |      |      |      |
 *                               |      |      |------|           |------|      |      |
 *                               |      |      |      |           |      |      |      |
 *                               `--------------------'           `--------------------'
 */
[_NUM] = LAYOUT_ergodox(
  // left hand
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,
  _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, _______,
  _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,
  _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______,
  _______, _______, _______, _______, _______,

                                               _______, _______,
                                                        _______,
                                      _______, _______, _______,

  // right hand
       KC_F12,   KC_F6,   KC_F7,     KC_F8,   KC_F9,   KC_F10,         KC_F11,
   KC_NUMLOCK, _______, KC_KP_7,   KC_KP_8, KC_KP_9, KC_KP_ASTERISK, _______,
               _______, KC_KP_4,   KC_KP_5, KC_KP_6, KC_KP_PLUS,     _______,
      _______, _______, KC_KP_1,   KC_KP_2, KC_KP_3, KC_KP_SLASH,    _______,
                    KC_KP_DOT, KC_KP_0, KC_KP_0, KC_KP_EQUAL,    _______,

  _______, _______,
  _______,
  _______, _______,  _______
),

};


//---------------------------------------------------------------------------------tap dance




enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5 //send SINGLE_TAP twice - NOT DOUBLE_TAP
  // Add more enums here if you want for triple, quadruple, etc.
};


typedef struct {
  bool is_press_action;
  int state;
} tap;


int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    //If count = 1, and it has been interrupted - it doesn't matter if it is pressed or not: Send SINGLE_TAP
    if (state->interrupted || state->pressed==0) return SINGLE_TAP;
    else return SINGLE_HOLD;
  }
  //If count = 2, and it has been interrupted - assume that user is trying to type the letter associated
  //with single tap. In example below, that means to send `xx` instead of `Escape`.
  else if (state->count == 2) {
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  else return 6; //magic number. At some point this method will expand to work for more presses
}



static tap raisealt_state = {
  .is_press_action = true,
  .state = 0
};

void raisealt(qk_tap_dance_state_t *state, void *user_data)
{
  raisealt_state.state = cur_dance(state);
  switch (raisealt_state.state) {
    case SINGLE_TAP: break;

  }
}


void raisealt_reset(qk_tap_dance_state_t *state, void *user_data)
{

}



qk_tap_dance_action_t tap_dance_actions[] = {
  [RZEALT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, raisealt, raisealt_reset)//TO(_RAISE), KC_RALT)
 // [VOM] = ACTION_TAP_DANCE_DOUBLE(KC_VOLD, KC_MUTE),
 // [PRN] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
 // [EGT] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
 // [HRD] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
 // [DSH] = ACTION_TAP_DANCE_DOUBLE(KC_NDSH, KC_MDSH),
 // [ESC] = ACTION_TAP_DANCE_DOUBLE(KC_ESC,  LALT(KC_F4)),
 // [EQE] = ACTION_TAP_DANCE_DOUBLE(KC_EQL,  KC_ENT),
 // [UND] = ACTION_TAP_DANCE_DOUBLE(KC_Z,    LCTL(KC_Z)),
 // [PGN] = ACTION_TAP_DANCE_DOUBLE(KC_PGDN, KC_PGUP),
 // [HND] = ACTION_TAP_DANCE_DOUBLE(KC_HOME, KC_END),
 // [COD] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_DOT),
 // [F11] = ACTION_TAP_DANCE_DOUBLE(KC_F1,   KC_F11),
 // [F12] = ACTION_TAP_DANCE_DOUBLE(KC_F2,   KC_F12),
 // [F13] = ACTION_TAP_DANCE_DOUBLE(KC_F3,   KC_F13),
 // [F14] = ACTION_TAP_DANCE_DOUBLE(KC_F4,   KC_F14),
 // [F15] = ACTION_TAP_DANCE_DOUBLE(KC_F5,   KC_F15),
 // [F16] = ACTION_TAP_DANCE_DOUBLE(KC_F6,   KC_F16),
 // [F17] = ACTION_TAP_DANCE_DOUBLE(KC_F7,   KC_F17),
 // [F18] = ACTION_TAP_DANCE_DOUBLE(KC_F8,   KC_F18),
 // [F19] = ACTION_TAP_DANCE_DOUBLE(KC_F9,   KC_F19),
 // [F20] = ACTION_TAP_DANCE_DOUBLE(KC_F10,  KC_F20),
};

//-------------------------------------------------------------------------------- stuff from xd lets split

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
    if (record->event.pressed) {
      SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
    }
    break;
    case 1:
    if (record->event.pressed) { // For resetting EEPROM
      eeconfig_init();
    }
    break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
        if (IS_LAYER_ON(_ADJUST)) {
          layer_off(_LOWER);
          layer_off(_RAISE);
        }
      } else {
        layer_off(_LOWER);
        if (IS_LAYER_ON(_ADJUST)) {
          layer_off(_ADJUST);
          layer_on(_RAISE);
        }
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
        if (IS_LAYER_ON(_ADJUST)) {
          layer_off(_RAISE);
          layer_off(_LOWER);
        }
      } else {
        layer_off(_RAISE);
        if (IS_LAYER_ON(_ADJUST)) {
          layer_off(_ADJUST);
          layer_on(_LOWER);
        }
      }
      return false;
      break;
    case NAV:
      if (record->event.pressed) {
        layer_on(_NAV);
      } else {
        layer_off(_NAV);
      }
      return false;
      break;
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
        rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

/**
 * Runs just one time when the keyboard initializes.
 */
void matrix_init_user(void) {

};

/**
 * Runs constantly in the background, in a loop.
 */
void matrix_scan_user(void) {
  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  switch (layer) {
    case _LOWER:
      ergodox_right_led_1_on();
      break;
    case _RAISE:
      ergodox_right_led_2_on();
      break;
    case _ADJUST:
      ergodox_right_led_3_on();
      break;
  }
};
