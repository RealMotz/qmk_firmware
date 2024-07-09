#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _LAYER1,
  _LAYER2,
  _LAYER3,
  _LAYER4,
  _LAYER5
};

enum custom_keycodes {
    NOWHITE = SAFE_RANGE,
    COLLAPSE,
    ARROW,
    ARROW2,
    ARROW3
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                      ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                      |   6  |   7  |   8  |   9  |   0  |  <-- |
 * |------+------+------+------+------+------|                      |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                      |   Y  |   U  |   I  |   O  |   P  |  Del |
 * |------+------+------+------+------+------|                      |------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |---------.  ,---------|   H  |   J  |   K  |   L  |   -  | CAPS |
 * |------+------+------+------+------+------|    ,    |  |    .    |------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  |   V  |   B  |---------|  |---------|   N  |   M  |   ,  |   .  |   /  | Shift|
 * `------------------------------------------/       /   \        \-----------------------------------------'
 *                   |  Alt | Ctrl |LAYER1 | / Space /     \ Enter  \  | LAYER2 |LAYER4 |LAYER3 T |
 *                   |      |      |       |/       /       \        \ |        |       |         |
 *                   `-----------------------------'         '------' '---------------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                             KC_6,    KC_7,  KC_8,    KC_9,   KC_0,    KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                             KC_Y,    KC_U,  KC_I,    KC_O,   KC_P,    KC_DEL,
  KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                             KC_H,    KC_J,  KC_K,    KC_L,   KC_MINS, KC_CAPS_LOCK,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,      KC_COMM, KC_DOT,       KC_N,    KC_M,  KC_COMM, KC_DOT, KC_SLASH, KC_RSFT,
                           KC_LALT, KC_LCTL, MO(_LAYER1), KC_SPC,  KC_ENT, MO(_LAYER2), MO(_LAYER4), TG(_LAYER3)
),
/* _LAYER1
 * ,-----------------------------------------.                      ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------|                      |------+------+------+------+------+------|
 * |  Tab |   |  |   !  |   #  |   (  |   )  |                      |   =  |   +  |   -  |   %  |   `  | lang |
 * |------+------+------+------+------+------|                      |------+------+------+------+------+------|
 * | Ctrl |   ~  |   ^  |   *  |   [  |   ]  |---------.  ,---------|   :  |   '  |   /  |   &  |   $  | CAPS |
 * |------+------+------+------+------+------|    ,    |  |    .    |------+------+------+------+------+------|
 * |Shift |  <   |   ?  |   _  |   {  |   }  |---------|  |---------|   ;  |   "  |   \  |   @  |   >  | Shift|
 * `------------------------------------------/       /   \         \-----------------------------------------'
 *                   |  Alt | Ctrl |LAYER1 | / Space /     \ Enter   \  | LAYER2 |LAYER4 |LAYER3 T |
 *                   |      |      |       |/       /       \         \ |        |       |         |
 *                   `-----------------------------'         '------'  '---------------------------'
 */
[_LAYER1] = LAYOUT(
  KC_F1,   KC_F2,    KC_F3,   KC_F4,    KC_F5,    KC_F6,                     KC_F7,    KC_F8,    KC_F9,    KC_F10,  KC_F11,    KC_F12,
  _______, KC_PIPE,  KC_EXLM, KC_HASH,  KC_LPRN,  KC_RPRN,                   KC_EQL,   KC_PLUS,  KC_MINS,  KC_PERC, KC_GRAVE,   LGUI(KC_SPC),
  _______, KC_TILDE, KC_CIRC, KC_ASTR,  KC_LBRC,  KC_RBRC,                   KC_COLON, KC_QUOTE, KC_SLASH, KC_AMPR, KC_DOLLAR,  _______,
  _______, KC_LABK,  KC_QUES, KC_UNDS,  KC_LCBR,  KC_RCBR, _______, _______, KC_SCLN,  KC_DQUO,  KC_BSLS,  KC_AT,   KC_RABK,    _______,
                             _______, _______, _______, _______, _______,  _______, _______, _______
),
/* _LAYER2
 * ,-------------------------------------------------------------.                      ,----------------------------------------------------.
 * | ESC  |open_con|ctrl+u|emmet(alt+m)|  ctrl+g    |ctrl+Shift+p|                      |ctrl+/ | ESC   |  alt+;  | alt+' |Shift+Alt+F| <--  |
 * |------+--------+------+------------+------------+------------|                      |-------+-------+---------+-------+-----------+------|
 * | Tab  |        |      |browser_sel |  sel_all   |  ctrl+alt  |                      |  Home | <--   |    End  |       |  del ws   |  Del |
 * |------+--------+------+------------+------------+------------|                      |-------+-------+---------+-------+-----------+------|
 * | Ctrl | "->"   | "=>" | "<-"       |   ctrl+\   |  Shift+Alt |---------.  ,---------| Left  | Down  |  Up     | Right |  collapse |alt+q |
 * |------+--------+------+------------+------------+------------|    ,    |  |    .    |-------+-------+---------+-------+-----------+------|
 * |Shift |        |      |            |ctrl+shift+c| ctrl+shift |---------|  |---------|ctrl+[ |ctrl+] |s-alt-L  |       |   ctrl+.  |ctrl+`|
 * `-------------------------------------------------------------/       /     \         \---------------------------------------------------'
 *                                      |  Alt | Ctrl |LAYER1 | / Space /       \ Enter   \  | LAYER2 |LAYER4 |LAYER3 T |
 *                                      |      |      |       |/       /         \         \ |        |       |         |
 *                                      `-----------------------------'           '--------' '--------------------------'
 */

[_LAYER2] = LAYOUT(
  _______, RCS(KC_C), LCTL(KC_U), LALT(KC_M),LCTL(KC_G),    RCS(KC_P),                    LCTL(KC_SLASH), KC_ESC,      LALT(KC_SCLN), LALT(KC_QUOTE), LSA(KC_F),  _______,
  _______, XXXXXXX,   XXXXXXX,    RCS(KC_I), RCS(KC_L),     LCA_T(KC_NO),                 KC_HOME,        KC_BSPC,     KC_END,        XXXXXXX,     NOWHITE,      _______,
  _______, ARROW3,    ARROW,      ARROW2,    LCTL(KC_BSLS), LSA(KC_NO),                   KC_LEFT,        KC_DOWN,     KC_UP,         KC_RGHT,     COLLAPSE,     LALT(KC_Q),
  _______, XXXXXXX,   XXXXXXX,    XXXXXXX,   RCS(KC_C),     RCS(KC_NO), _______, _______, LCTL(KC_LBRC),  LCTL(KC_RBRC), LSA(KC_L),     XXXXXXX,     LCTL(KC_DOT), LCTL(KC_GRAVE),
                                _______, _______, _______,  _______, _______,  _______, _______, _______
),
/* _LAYER3
 * ,-------------------------------------------.                       ,-------------------------------------------.
 * | ESC  |Print |NumLock|< track|track >| Mute |                      | Bri+ | Bri- |       |      |       |  <-- |
 * |------+------+-------+-------+-------+------|                      |------+------+-------+------+-------+------|
 * | Tab  |      |       |       | Play  | Vol+ |                      |      |      |       |      |       |  Del |
 * |------+------+-------+-------+-------+------|                      |------+------+-------+------+-------+------|
 * | Ctrl | <-M  |   Md  |   M^  |  M->  | Vol- |---------.  ,---------| W<-  |  Wd  | W^    | W->  |       | CAPS |
 * |------+------+-------+-------+-------+------|    ,    |  |    .    |------+------+-------+------+-------+------|
 * |Shift |      |       |Lclick | Rclick|      |---------|  |---------|PageUp|PagDown|      |      |       | Shift|
 * `-------------------------------------------/         /    \         \------------------------------------------'
 *                    |  Alt | Ctrl |LAYER1 | /  Space  /      \ Enter   \  | LAYER2 |LAYER4 |LAYER3 T |
 *                    |      |      |       |/         /        \         \ |        |       |         |
 *                    `-------------------------------'          '--------' '--------------------------'
 */
  [_LAYER3] = LAYOUT(
  _______, KC_PSCR, KC_NUM, KC_MNXT, KC_MPRV, KC_MUTE,                    KC_BRIU, KC_BRID, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPLY, KC_VOLU,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_VOLD,                   KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX, _______,
  _______, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN2, XXXXXXX, _______, _______, KC_PGUP, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
  ,
/* _LAYER4
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |  <   |   >  |                    |      |      | "->" | "=>" | "<-" |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |  &   |  $   |-------.   ,--------|      |      |   :  |   /  |  @   |  %   |
 * |------+------+------+------+------+------|    ,   |  |   .    |------+------+------+------+------+------|
 * |      |      |      |  A   |  D   |  0   |--------|  |--------|      |      |   ;  |   \  |  ?   |      |
 * `-----------------------------------------/       /    \       \-----------------------------------------'
 *                  |  Alt | Ctrl |LAYER1 | / Space /      \ Enter  \  | LAYER2 |LAYER4 |LAYER3 T |
 *                  |      |      |       |/       /        \        \ |        |       |         |
 *                  `-----------------------------'          '------' '---------------------------'
 */
  [_LAYER4] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LABK, KC_RABK,                    KC_QUES, XXXXXXX, ARROW3,   ARROW,    ARROW2,  XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_AMPR, KC_DOLLAR,                  XXXXXXX, XXXXXXX, KC_COLON, KC_SLASH, KC_AT,   KC_PERC,
  XXXXXXX, XXXXXXX, XXXXXXX, S(KC_A), S(KC_D), KC_0,     _______, _______, XXXXXXX, XXXXXXX, KC_SCLN,  KC_BSLS,  KC_QUES, XXXXXXX,
                             _______, _______, _______,  _______, _______, _______, _______, _______
  )
  ,
/* _LAYER5
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.   ,--------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|    ,   |  |   .    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |--------|  |--------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /    \       \-----------------------------------------'
 *                  |  Alt | Ctrl |LAYER1 | / Space /      \ Enter  \  | LAYER2 |LAYER4 |LAYER3 T |
 *                  |      |      |       |/       /        \        \ |        |       |         |
 *                  `-----------------------------'          '------' '---------------------------'
 */
  [_LAYER5] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

// layer_state_t layer_state_set_user(layer_state_t state) {
//   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
// }

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  switch (keycode) {
    case NOWHITE:
        if (record->event.pressed) {
            // when keycode NOWHITE is pressed
            SEND_STRING(SS_LCTL("k"));
            SEND_STRING(SS_LCTL("x"));
        }
        break;
    case COLLAPSE:
      if (record->event.pressed) {
          SEND_STRING(SS_LCTL("k"));
          SEND_STRING(SS_LCTL("0"));
      }
      break;
    case ARROW:
      if (record->event.pressed) {
        SEND_STRING("->");
      }
      break;
    case ARROW2:
      if (record->event.pressed) {
        SEND_STRING("=>");
      }
      break;
    case ARROW3:
      if (record->event.pressed) {
        SEND_STRING("<-");
      }
      break;
    break;
  }
  return true;
}
