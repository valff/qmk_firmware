#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  VRSN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.          ,--------------------------------------------------.
 * |   ~    |  `   |  |   |  &   |  =   |  @   | Del  |          |SysReq|  \   |  /   |  !   |  *   |  %   |   ^    |
 * |--------+------+------+------+------+-------------|          |------+------+------+------+------+------+--------|
 * |   {    |  Q   |  W   |  F   |  P   |  B   | Esc  |          |Enter |  J   |  L   |  U   |  Y   |  ,   |   }    |
 * |--------+------+------+------+------+------|      |          |      |------+------+------+------+------+--------|
 * |   (    |  A   |  R   |  S   |  T   |  G   |------|          |------|  M   |  N   |  E   |  I   |  O   |   )    |
 * |--------+------+------+------+------+------| Tab  |          |  _   |------+------+------+------+------+--------|
 * |   [    |  Z   |  X   |  C   |  D   |  V   |      |          |      |  K   |  H   |  :   |  "   |  .   |   ]    |
 * `--------+------+------+------+------+-------------'          `-------------+------+------+------+------+--------'
 *   |  <   |  ?   |  $   |  #   |  '   |                                      | BkSp |  ;   |  -   |  +   |  >   |
 *   `----------------------------------'                                      `----------------------------------'
 *                                        ,-------------.      ,-------------.
 *                                        |LShift|  L2  |      |  L2  |RCtrl |
 *                                 ,------|------|------|      |------+------+------.
 *                                 |      |      | LGui |      | RAlt |      |      |
 *                                 |Space | Left |------|      |------|Right |  L1  |
 *                                 |      | Ctrl | LAlt |      | RGui |Shift |      |
 *                                 `--------------------'      `--------------------'
 */
  [0] = LAYOUT_ergodox(
    // left hand
    KC_TILD , KC_GRV  , KC_PIPE , KC_AMPR , KC_EQL  , KC_AT   , KC_DELT ,
    KC_LCBR , KC_Q    , KC_W    , KC_F    , KC_P    , KC_B    , KC_ESC  ,
    KC_LPRN , KC_A    , KC_R    , KC_S    , KC_T    , KC_G    ,
    KC_LBRC , KC_Z    , KC_X    , KC_C    , KC_D    , KC_V    , KC_TAB  ,
    KC_LABK , KC_QUES , KC_DLR  , KC_HASH , KC_QUOT ,
                                                      KC_LSFT , MO(2)   ,
                                                                KC_LGUI ,
                                            KC_SPC  , KC_LCTL , KC_LALT ,
    // right hand
    KC_SYSREQ , KC_BSLS , KC_SLSH , KC_EXLM , KC_ASTR , KC_PERC , KC_CIRC ,
    KC_ENT    , KC_J    , KC_L    , KC_U    , KC_Y    , KC_COMM , KC_RCBR ,
                KC_M    , KC_N    , KC_E    , KC_I    , KC_O    , KC_RPRN ,
    KC_UNDS   , KC_K    , KC_H    , KC_COLN , KC_DQUO , KC_DOT  , KC_RBRC ,
                          KC_BSPC , KC_SCLN , KC_MINS , KC_PLUS , KC_RABK ,
    MO(2)     , KC_RCTL ,
    KC_RALT   ,
    KC_RGUI   , KC_RSFT , MO(1)
  ),
/* Keymap 1: Numeric Layer
 *
 * ,--------------------------------------------------.          ,--------------------------------------------------.
 * |        |      |      |      |      |      |Insert|          |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------|          |------+------+------+------+------+------+--------|
 * |        |      | PgUp |  Up  | PgDn | App  |      |          |      |      |  7   |  8   |  9   |      |        |
 * |--------+------+------+------+------+------|      |          |      |------+------+------+------+------+--------|
 * |        | Home | Left | Down |Right | End  |------|          |------|      |  4   |  5   |  6   |      |        |
 * |--------+------+------+------+------+------|      |          |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |          |      |      |  1   |  2   |  3   |      |        |
 * `--------+------+------+------+------+-------------'          `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                      |      |  0   |      |      |      |
 *   `----------------------------------'                                      `----------------------------------'
 *                                        ,-------------.      ,-------------.
 *                                        |      |      |      |      |      |
 *                                 ,------|------|------|      |------+------+------.
 *                                 |      |      |      |      |      |      |      |
 *                                 |      |      |------|      |------|      |      |
 *                                 |      |      |      |      |      |      |      |
 *                                 `--------------------'      `--------------------'
 */
  [1] = LAYOUT_ergodox(
    // left hand
    _______ , _______ , _______ , _______ , _______ , _______ , KC_INS  ,
    _______ , _______ , KC_PGUP , KC_UP   , KC_PGDN , KC_APP  , _______ ,
    _______ , KC_HOME , KC_LEFT , KC_DOWN , KC_RGHT , KC_END  ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ ,
                                                      _______ , _______ ,
                                                                _______ ,
                                            _______ , _______ , _______ ,
    // right hand
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , KC_7    , KC_8    , KC_9    , _______ , _______ ,
              _______ , KC_4    , KC_5    , KC_6    , _______ , _______ ,
    _______ , _______ , KC_1    , KC_2    , KC_3    , _______ , _______ ,
                        _______ , KC_0    , _______ , _______ , _______ ,
    _______ , _______ ,
    _______ ,
    _______ , _______ , _______
  ),
/* Keymap 2: Functional Layer
 *
 * ,--------------------------------------------------.          ,--------------------------------------------------.
 * |  Calc  |      |      | Mclk |      |      | Mute |          | Play |Pause | F10  | F11  | F12  |PrnScr| Power  |
 * |--------+------+------+------+------+------+------|          |------+------+------+------+------+------+--------|
 * | MyComp |      | Lclk | MsUp | Rclk | WhUp |Volume|          |      |      |  F7  |  F8  |  F9  |CpsLck| Sleep  |
 * |--------+------+------+------+------+------|  Up  |          | Prev |------+------+------+------+------+--------|
 * |  Mail  |WhLeft|MsLeft|MsDown|MsRght|WhRght|------|          |------|      |  F4  |  F5  |  F6  |SclLck|  Wake  |
 * |--------+------+------+------+------+------|Volume|          |      |------+------+------+------+------+--------|
 * | Player |Versn |Accel0|Accel1|Accel2|WhDown| Down |          | Next |      |  F1  |  F2  |  F3  |NumLck| Reset  |
 * `--------+------+------+------+------+-------------'          `-------------+------+------+------+------+--------'
 *   |RgbMo1|RgbMo2|RgbMo3|RgbMo4|RgbMo5|                                      |RgbMo6|RgbMo7|RgbMo8|RgbMo9|      |
 *   `----------------------------------'                                      `----------------------------------'
 *                                        ,-------------.      ,-------------.
 *                                        |Static|      |      |      |Toggle|
 *                                 ,------|------|------|      |------+------+------.
 *                                 |Bright|Bright|RgbRev|      | Sat+ |      |      |
 *                                 |ness- |ness+ |------|      |------| Hue- | Hue+ |
 *                                 |      |      |RgbFor|      | Sat- |      |      |
 *                                 `--------------------'      `--------------------'
 */
  [2] = LAYOUT_ergodox(
    // left hand
    KC_CALC , _______ , _______ , KC_BTN3  , _______  , _______ , KC_MUTE  ,
    KC_MYCM , _______ , KC_BTN1 , KC_MS_U  , KC_BTN2  , KC_WH_U , KC_VOLU  ,
    KC_MAIL , KC_WH_L , KC_MS_L , KC_MS_D  , KC_MS_R  , KC_WH_R ,
    KC_MSEL , VRSN    , KC_ACL0 , KC_ACL1  , KC_ACL2  , KC_WH_D , KC_VOLD  ,
    RGB_M_P , RGB_M_B , RGB_M_R , RGB_M_SW , RGB_M_SN ,
                                                        RGB_M_P , _______  ,
                                                                  RGB_MOD  ,
                                             RGB_VAD  , RGB_VAI , RGB_RMOD ,
    // right hand
    KC_MPLY , KC_PAUS , KC_F10  , KC_F11  , KC_F12  , KC_PSCR , KC_PWR  ,
    KC_MPRV , _______ , KC_F7   , KC_F8   , KC_F9   , KC_CLCK , KC_SLEP ,
              _______ , KC_F4   , KC_F5   , KC_F6   , KC_SLCK , KC_WAKE ,
    KC_MNXT , _______ , KC_F1   , KC_F2   , KC_F3   , KC_NLCK , RESET   ,
                        RGB_M_K , RGB_M_X , RGB_M_G , RGB_M_T , _______ ,
    _______ , RGB_TOG ,
    RGB_SAI ,
    RGB_SAD , RGB_HUD , RGB_HUI
  ),
};

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
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};
