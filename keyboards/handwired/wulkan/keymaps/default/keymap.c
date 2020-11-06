#include QMK_KEYBOARD_H

enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _GAMING,
};

enum unicode_names {
  SE_AA_HIGH,
  SE_AE_HIGH,
  SE_OE_HIGH,
  SE_AA_LOW,
  SE_AE_LOW,
  SE_OE_LOW,
  SC_ALPHA_LOW,
  SC_BETA_LOW,
  SC_GAMMA_LOW,
  SC_DELTA_LOW,
  SC_DELTA_HIGH
};

const uint32_t PROGMEM unicode_map[] = {
  [SE_AA_HIGH] = 0x00C5,
  [SE_AE_HIGH] = 0x00C4,
  [SE_OE_HIGH] = 0x00D6,
  [SE_AA_LOW]  = 0x00E5,
  [SE_AE_LOW]  = 0x00E4,
  [SE_OE_LOW]  = 0x00F6,
  [SC_ALPHA_LOW] = 0x03B1,
  [SC_BETA_LOW] = 0x03B2,
  [SC_GAMMA_LOW] = 0x03B3,
  [SC_DELTA_LOW] = 0x03B4,
  [SC_DELTA_HIGH] = 0x0394,
};

// these are custom keycodes
// refer to "Defining a New Keycode" in https://beta.docs.qmk.fm/using-qmk/guides/custom_quantum_functions
enum my_keycodes {
  GAME_ON = SAFE_RANGE,
  GAME_OFF
};

// when adding combos don't forget to update COMBO_COUNT in conig.h
enum combos {
  CMD_RIGHT,
  CMD_LEFT,
  CMD_PLUS,
};

const uint16_t PROGMEM cmd_right_combo[] = {KC_LGUI, KC_RGHT, COMBO_END};
const uint16_t PROGMEM cmd_left_combo[] = {KC_LGUI, KC_LEFT, COMBO_END};
const uint16_t PROGMEM cmd_plus_combo[] = {KC_LGUI, KC_EQL, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [CMD_RIGHT] = COMBO(cmd_right_combo, KC_END),
  [CMD_LEFT] = COMBO(cmd_left_combo, KC_HOME),
  [CMD_PLUS] = COMBO(cmd_plus_combo, KC_F1),
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  -_  |  =+  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |  ;:  |  '"  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |  /?  |Lower |Space |Space |Raise |Shift | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_5x12(
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_ENT,
  KC_LCTL, KC_LGUI, KC_LALT, KC_SLSH, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_RSFT, KC_LEFT, KC_DOWN, KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |  [{  |  ]}  |  \|  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      | `~   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |  _   |ISO ~ |ISO | |      | Vol+ | Play |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      | Vol+ | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_5x12(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,      KC_F8,      KC_F9,  KC_F10,  KC_F11,  KC_F12,
  _______, _______, _______, _______, _______, _______, _______,    _______,    KC_LBRC, KC_RBRC, KC_BSLS,  KC_DEL, 
  _______, _______, _______, _______, _______, _______, _______,    _______,    _______, _______, _______,  KC_GRV,
  _______, _______, _______, _______, _______, _______, KC_UNDS, S(KC_NUHS), S(KC_NUBS), _______, KC_VOLU, KC_MPLY,
  _______, _______, _______, _______, _______, _______, _______,    _______,    _______, KC_MPRV, KC_VOLD, KC_MNXT
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |  NP/ | NP*  | NP-  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |SLEEP | WAKE |      | REC1 | REC2 |      |      | NP7  | NP8  | NP9  | NP+  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | RSTP |      | PLY1 | PLY3 |      |      | NP4  | NP5  | NP6  | NP+  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | NP1  | NP2  | NP3  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | NP0  | NP0  | Del. |Enter |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_5x12(
  _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_PSLS, KC_PAST, KC_PMNS,
  _______, KC_SLEP, KC_WAKE, _______, DM_REC1, DM_REC2, _______, _______,   KC_P7,  KC_P8,   KC_P9,   KC_PPLS,
  _______, _______, DM_RSTP, _______, DM_PLY1, DM_PLY2, _______, _______,   KC_P4,  KC_P5,   KC_P6,   KC_PPLS,
  _______, _______, _______, _______, _______, _______, _______, _______,   KC_P1,  KC_P2,   KC_P3,   KC_PENT,
  _______, _______, _______, _______, _______, _______, _______, _______,   KC_P0,  KC_P0,   KC_PDOT, KC_PENT
),

/* Adjust (Lower + Raise)

 * ,-----------------------------------------------------------------------------------.
 * |   α  |      |      |      |      |      |      |      |      |      |   Å  |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      | Reset|      |      |      |      |   Ö  |   Ä  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      | Game |      |      |      |   Ö  |   Ä  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  MAC |      |      | BRIU |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      | BRID |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_5x12(
  X(SC_ALPHA_LOW), X(SC_BETA_LOW), X(SC_GAMMA_LOW), XP(SC_DELTA_LOW, SC_DELTA_HIGH), _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, UC_M_WC, _______,   RESET, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, GAME_ON, _______, _______, _______, UC_M_LN, _______, _______,
  KC_RSFT, _______, _______, _______, _______, _______, _______, UC_M_MA, _______, _______, KC_BRIU, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_RSFT, _______, KC_BRID, _______
),

/* Gaming
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | Space|      |      |GAMEOF|      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_GAMING] = LAYOUT_ortho_5x12(
  _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______,
  _______, _______, _______, _______,  KC_SPC, _______, _______, GAME_OFF, _______, _______, _______, _______
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void eeconfig_init_user(void) {
  set_unicode_input_mode(UC_LNX);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case GAME_ON:
        if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
                PLAY_NOTE_ARRAY(tone_plover, false, 0);
            #endif        
            layer_off(_RAISE);
            layer_off(_LOWER);
            layer_off(_ADJUST);
            layer_on(_GAMING);
        }
        return false;
        break;
    case GAME_OFF:
        if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
                PLAY_NOTE_ARRAY(tone_plover_gb, false, 0);
            #endif
            layer_off(_GAMING);
        }
        return false;
        break;
    default:
      return true; // Process all other keycodes normally
  }
}
