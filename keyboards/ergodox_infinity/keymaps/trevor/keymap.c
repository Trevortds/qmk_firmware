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
    _UNI,
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
    UNI,
    RGB_SLD,
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

enum function_ids {
  EMOJI,
  EMOJI2,
  GO_GROUP
};

enum emojis {
  SHRUG,
  YAY,
  HUG,
  SMILE,
  SMILE2,
  HMM1,
  HMM2,
  BEAR1,
  BEAR2,
  FUU,
  EGGY1,
  EGGY2,
  FACE1,
  FACE2,
  UHU,
  SMRK1
};

enum emojis2 {
  SMRK2,
  LOVE
};

enum progmem_ids {
  EMOJI_SHRUG,
  EMOJI_YAY,
  EMOJI_HUG,
  EMOJI_SMILE,
  EMOJI_SMILE2,
  EMOJI_HMM1,
  EMOJI_HMM2,
  EMOJI_BEAR1,
  EMOJI_BEAR2,
  EMOJI_FUU,
  EMOJI_EGGY1,
  EMOJI_EGGY2,
  EMOJI_FACE1,
  EMOJI_FACE2,
  EMOJI_UHU,
  EMOJI_SMRK1,
  EMOJI_SMRK2,
  EMOJI_LOVE,
  F_EPRM,
  F_VRSN,
  F_RGB_SLD,
  I3_GO_GROUP_10,
  I3_GO_GROUP_1,
  I3_GO_GROUP_2,
  I3_GO_GROUP_3,
  I3_GO_GROUP_4,
  I3_GO_GROUP_5,
  I3_GO_GROUP_6,
  I3_GO_GROUP_7,
  I3_GO_GROUP_8,
  I3_GO_GROUP_9,
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
#define LOCK LGUI(KC_L)

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
 * |   `    |  1  |  2  |  3  |  4  |  5  | Esc  |           | Num  |  6  |  7  |  8  |  9  |  0  | -/UNI  |
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
 *                              | SPC|CTRL |------|          |------|RAISE|Space|
 *                              |    |     | LGUI |          | RALT |     |     |
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
                                        KC_SPACE, KC_LCTL,   KC_LGUI,

  // right hand
  TG(_NUM),     KC_6,          KC_7,     KC_8,    KC_9,                  KC_0,   LT(_UNI, KC_MINS),
  KC_RBRACKET,  KC_Y,          KC_U,     KC_I,    KC_O,                  KC_P,             KC_BSLS,
                KC_H,          KC_J,     KC_K,    KC_L,              KC_SCOLON, LT(_NAV, KC_QUOTE),
  KC_RPRN,      KC_N,          KC_M,  KC_COMM,   KC_DOT,   LT(_MOUSE, KC_SLSH),      OSM(MOD_RSFT),
                              RAISE, KC_LEFT,  KC_DOWN,                 KC_UP,            KC_RIGHT,

  TG(_NUM), TG(_MOUSE),
  TG(_ADJUST),
  KC_RALT,  MT(MOD_LGUI, KC_ENTER), KC_SPACE
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
               KC_H,    KC_N,    KC_E,    KC_I,                KC_O,  _______,
  _______,     KC_K,    KC_M, KC_COMM,  KC_DOT, LT(_MOUSE, KC_SLSH),  _______,
                     _______, _______, _______,             _______,  _______,

  _______,  _______,
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
 * |        |  %   |  ^   |  [   |  ]   |  ~   |      |           |      |      |  1   |  2   |  3   |  /   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |  0   |  0   |  .   |  =   |      |
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
                    KC_KP_0, KC_KP_0, KC_KP_DOT, KC_KP_EQUAL,    _______,

  _______, _______,
  _______,
  _______, _______,  _______
),


/* Keymap 3: Unicode
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  ┌   |  ┐   |  └   |  ┘   |  │   |  ─   |           |  ╔   |  ╗   |  ╚   |  ╝   |  ║   |  ═   |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | shrug| yay  | hug  | smile|smile2|      |           |      |  ■   |  λ   |  →   |  ➙   |  ▻   |  █     |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | hmm1 | hmm2 | bear1| bear2| fuu  |------|           |------|  ☺   |  ☻   |  ☹   |  ♡   |  ♥   |  ░     |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | eggy1| eggy2| face1| face2| uhu  |      |           |      |  ❤   |  ☐   |  ☑   |  ☒   |  ✓   |  ▄     |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      | smrk1| smrk2| love | VER  |                                       |  ✔   |  ✗   |  ✘   |  ●   |  ▀   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |   ▒  |  ▓   |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Unicode
[_UNI] = LAYOUT_ergodox(
    KC_TRNS, UC(0x250c), UC(0x2510), UC(0x2514), UC(0x2518), UC(0x2502), UC(0x2500),
    KC_TRNS, F(EMOJI_SHRUG), F(EMOJI_YAY), F(EMOJI_HUG), F(EMOJI_SMILE), F(EMOJI_SMILE2), KC_TRNS,
    KC_TRNS, F(EMOJI_HMM1), F(EMOJI_HMM2), F(EMOJI_BEAR1), F(EMOJI_BEAR2), F(EMOJI_FUU),
    KC_TRNS, F(EMOJI_EGGY1), F(EMOJI_EGGY2), F(EMOJI_FACE1), F(EMOJI_FACE2), F(EMOJI_UHU), KC_TRNS,
    KC_TRNS, F(EMOJI_SMRK1), F(EMOJI_SMRK2), F(EMOJI_LOVE), F(F_VRSN),
    KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       UC(0x2554),  UC(0x2557), UC(0x255a), UC(0x255d), UC(0x2551), UC(0x2550), KC_TRNS,
       KC_TRNS,  UC(0x25a0), UC(0x03bb), UC(0x2192), UC(0x2799), UC(0x25bb), UC(0x2588),
                 UC(0x263a), UC(0x263b), UC(0x2639), UC(0x2661), UC(0x2665), UC(0x2591),
       KC_TRNS,  UC(0x2764), UC(0x2610), UC(0x2611), UC(0x2612), UC(0x2713), UC(0x2584),
       UC(0x2714), UC(0x2717), UC(0x2718), UC(0x25cf), UC(0x2580),
    UC(0x2592), UC(0x2593),
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
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


// -------------------------------------------------------------------------------- stuff from deadcyclo



#define TAP_ONCE(code)  \
  register_code (code); \
  unregister_code (code)

const uint16_t PROGMEM fn_actions[] = {
  [EMOJI_SHRUG]   = ACTION_FUNCTION_OPT(EMOJI, SHRUG),
  [EMOJI_YAY]     = ACTION_FUNCTION_OPT(EMOJI, YAY),
  [EMOJI_HUG]     = ACTION_FUNCTION_OPT(EMOJI,HUG),
  [EMOJI_SMILE]   = ACTION_FUNCTION_OPT(EMOJI,SMILE),
  [EMOJI_SMILE2]  = ACTION_FUNCTION_OPT(EMOJI,SMILE2),
  [EMOJI_HMM1]    = ACTION_FUNCTION_OPT(EMOJI,HMM1),
  [EMOJI_HMM2]    = ACTION_FUNCTION_OPT(EMOJI,HMM2),
  [EMOJI_BEAR1]   = ACTION_FUNCTION_OPT(EMOJI,BEAR1),
  [EMOJI_BEAR2]   = ACTION_FUNCTION_OPT(EMOJI,BEAR2),
  [EMOJI_FUU]     = ACTION_FUNCTION_OPT(EMOJI,FUU),
  [EMOJI_EGGY1]   = ACTION_FUNCTION_OPT(EMOJI,EGGY1),
  [EMOJI_EGGY2]   = ACTION_FUNCTION_OPT(EMOJI,EGGY2),
  [EMOJI_FACE1]   = ACTION_FUNCTION_OPT(EMOJI,FACE1),
  [EMOJI_FACE2]   = ACTION_FUNCTION_OPT(EMOJI,FACE2),
  [EMOJI_UHU]     = ACTION_FUNCTION_OPT(EMOJI,UHU),
  [EMOJI_SMRK1]   = ACTION_FUNCTION_OPT(EMOJI,SMRK1),
  [EMOJI_SMRK2]   = ACTION_FUNCTION_OPT(EMOJI2,SMRK2),
  [EMOJI_LOVE]    = ACTION_FUNCTION_OPT(EMOJI2,LOVE),
  [F_EPRM]        = ACTION_FUNCTION(EPRM),
  [F_VRSN]        = ACTION_FUNCTION(VRSN),
  [F_RGB_SLD]     = ACTION_FUNCTION(RGB_SLD),
  [I3_GO_GROUP_10]= ACTION_FUNCTION_OPT(GO_GROUP,0),
  [I3_GO_GROUP_1] = ACTION_FUNCTION_OPT(GO_GROUP,1),
  [I3_GO_GROUP_2] = ACTION_FUNCTION_OPT(GO_GROUP,2),
  [I3_GO_GROUP_3] = ACTION_FUNCTION_OPT(GO_GROUP,3),
  [I3_GO_GROUP_4] = ACTION_FUNCTION_OPT(GO_GROUP,4),
  [I3_GO_GROUP_5] = ACTION_FUNCTION_OPT(GO_GROUP,5),
  [I3_GO_GROUP_6] = ACTION_FUNCTION_OPT(GO_GROUP,6),
  [I3_GO_GROUP_7] = ACTION_FUNCTION_OPT(GO_GROUP,7),
  [I3_GO_GROUP_8] = ACTION_FUNCTION_OPT(GO_GROUP,8),
  [I3_GO_GROUP_9] = ACTION_FUNCTION_OPT(GO_GROUP,9),
};


void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  if (record->event.pressed) {
    switch(id) {
    case GO_GROUP:
      register_code(KC_LCTL); TAP_ONCE(KC_I); unregister_code(KC_LCTL);
      TAP_ONCE(KC_G);
      if (opt == 0) {
  TAP_ONCE(39);
      } else {
  TAP_ONCE(29+opt);
      }
      break;
    case EMOJI:
      switch(opt) {
      case SHRUG:
  unicode_input_start(); register_hex(0xaf); unicode_input_finish();
  TAP_ONCE (KC_BSLS);
  register_code (KC_RSFT); TAP_ONCE (KC_MINS); TAP_ONCE (KC_9); unregister_code (KC_RSFT);
  unicode_input_start (); register_hex(0x30c4); unicode_input_finish();
  register_code (KC_RSFT); TAP_ONCE (KC_0); TAP_ONCE (KC_MINS); unregister_code (KC_RSFT);
  TAP_ONCE (KC_SLSH);
  unicode_input_start (); register_hex(0xaf); unicode_input_finish();
  break;
      case YAY:
  SEND_STRING ("\\o/");
  break;
      case HUG:
  unicode_input_start(); register_hex(0x0f3c); unicode_input_finish();
  TAP_ONCE (KC_SPC);
  unicode_input_start(); register_hex(0x3064); unicode_input_finish();
  TAP_ONCE (KC_SPC);
  unicode_input_start(); register_hex(0x25d5); unicode_input_finish();
  unicode_input_start(); register_hex(0x005f); unicode_input_finish();
  unicode_input_start(); register_hex(0x25d5); unicode_input_finish();
  TAP_ONCE (KC_SPC);
  unicode_input_start(); register_hex(0x0f3d); unicode_input_finish();
  unicode_input_start(); register_hex(0x3064); unicode_input_finish();
  break;
      case SMILE:
  unicode_input_start(); register_hex(0x0298); unicode_input_finish();
  unicode_input_start(); register_hex(0x203f); unicode_input_finish();
  unicode_input_start(); register_hex(0x0298); unicode_input_finish();
  break;
      case SMILE2:
  unicode_input_start(); register_hex(0x0028); unicode_input_finish();
  unicode_input_start(); register_hex(0x0298); unicode_input_finish();
  unicode_input_start(); register_hex(0x203f); unicode_input_finish();
  unicode_input_start(); register_hex(0x0298); unicode_input_finish();
  unicode_input_start(); register_hex(0x0029); unicode_input_finish();
  break;
      case HMM1:
  unicode_input_start(); register_hex(0x0ca0); unicode_input_finish();
  unicode_input_start(); register_hex(0x005f); unicode_input_finish();
  unicode_input_start(); register_hex(0x0ca0); unicode_input_finish();
  break;
      case HMM2:
  unicode_input_start(); register_hex(0x0028); unicode_input_finish();
  unicode_input_start(); register_hex(0x0ca0); unicode_input_finish();
  unicode_input_start(); register_hex(0x005f); unicode_input_finish();
  unicode_input_start(); register_hex(0x0ca0); unicode_input_finish();
  unicode_input_start(); register_hex(0x0029); unicode_input_finish();
  break;
      case BEAR1:
  unicode_input_start(); register_hex(0x0295); unicode_input_finish();
  unicode_input_start(); register_hex(0x2022); unicode_input_finish();
  unicode_input_start(); register_hex(0x1d25); unicode_input_finish();
  unicode_input_start(); register_hex(0x2022); unicode_input_finish();
  unicode_input_start(); register_hex(0x0294); unicode_input_finish();
  break;
      case BEAR2:
  unicode_input_start(); register_hex(0x0028); unicode_input_finish();
  unicode_input_start(); register_hex(0x1d54); unicode_input_finish();
  unicode_input_start(); register_hex(0x1d25); unicode_input_finish();
  unicode_input_start(); register_hex(0x1d54); unicode_input_finish();
  unicode_input_start(); register_hex(0x0029); unicode_input_finish();
  break;
      case FUU:
  unicode_input_start(); register_hex(0x256d); unicode_input_finish();
  unicode_input_start(); register_hex(0x2229); unicode_input_finish();
  unicode_input_start(); register_hex(0x256e); unicode_input_finish();
  unicode_input_start(); register_hex(0x0028); unicode_input_finish();
  unicode_input_start(); register_hex(0x002d); unicode_input_finish();
  unicode_input_start(); register_hex(0x005f); unicode_input_finish();
  unicode_input_start(); register_hex(0x002d); unicode_input_finish();
  unicode_input_start(); register_hex(0x0029); unicode_input_finish();
  unicode_input_start(); register_hex(0x256d); unicode_input_finish();
  unicode_input_start(); register_hex(0x2229); unicode_input_finish();
  unicode_input_start(); register_hex(0x256e); unicode_input_finish();
  break;
      case EGGY1:
  unicode_input_start(); register_hex(0x0028); unicode_input_finish();
  unicode_input_start(); register_hex(0x256f); unicode_input_finish();
  unicode_input_start(); register_hex(0x00b0); unicode_input_finish();
  unicode_input_start(); register_hex(0x25a1); unicode_input_finish();
  unicode_input_start(); register_hex(0x00b0); unicode_input_finish();
  unicode_input_start(); register_hex(0xff09); unicode_input_finish();
  unicode_input_start(); register_hex(0x256f); unicode_input_finish();
  break;
      case EGGY2:
  unicode_input_start(); register_hex(0x30ce); unicode_input_finish();
  unicode_input_start(); register_hex(0x0028); unicode_input_finish();
  unicode_input_start(); register_hex(0x0020); unicode_input_finish();
  unicode_input_start(); register_hex(0x309c); unicode_input_finish();
  unicode_input_start(); register_hex(0x002d); unicode_input_finish();
  unicode_input_start(); register_hex(0x309c); unicode_input_finish();
  unicode_input_start(); register_hex(0x30ce); unicode_input_finish();
  unicode_input_start(); register_hex(0x0029); unicode_input_finish();
  break;
      case FACE1:
  unicode_input_start(); register_hex(0x0028); unicode_input_finish();
  unicode_input_start(); register_hex(0x002d); unicode_input_finish();
  unicode_input_start(); register_hex(0x005f); unicode_input_finish();
  unicode_input_start(); register_hex(0x002d); unicode_input_finish();
  unicode_input_start(); register_hex(0x0029); unicode_input_finish();
  break;
      case FACE2:
  unicode_input_start(); register_hex(0x0028); unicode_input_finish();
  unicode_input_start(); register_hex(0x2022); unicode_input_finish();
  unicode_input_start(); register_hex(0x005f); unicode_input_finish();
  unicode_input_start(); register_hex(0x2022); unicode_input_finish();
  unicode_input_start(); register_hex(0x0029); unicode_input_finish();
  break;
      case UHU:
  unicode_input_start(); register_hex(0x2299); unicode_input_finish();
  unicode_input_start(); register_hex(0xfe4f); unicode_input_finish();
  unicode_input_start(); register_hex(0x2299); unicode_input_finish();
  break;
      case SMRK1:
  unicode_input_start(); register_hex(0x005e); unicode_input_finish();
  unicode_input_start(); register_hex(0x032e); unicode_input_finish();
  unicode_input_start(); register_hex(0x005e); unicode_input_finish();
  break;
      }
      break;
    case EMOJI2:
      switch(opt) {
  case SMRK2:
    unicode_input_start(); register_hex(0x0028); unicode_input_finish();
    unicode_input_start(); register_hex(0x005e); unicode_input_finish();
    unicode_input_start(); register_hex(0x032e); unicode_input_finish();
    unicode_input_start(); register_hex(0x005e); unicode_input_finish();
    unicode_input_start(); register_hex(0x0029); unicode_input_finish();
    break;
      case LOVE:
  unicode_input_start(); register_hex(0x2665); unicode_input_finish();
  unicode_input_start(); register_hex(0x203f); unicode_input_finish();
  unicode_input_start(); register_hex(0x2665); unicode_input_finish();
  break;
      }
      break;
    }
  }
}





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
void matrix_init_user(){
  set_unicode_input_mode(UC_LNX);
}

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
