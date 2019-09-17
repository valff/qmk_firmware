#include QMK_KEYBOARD_H
#include "version.h"

#define L_BASE 0
/*
 * ┌────────┬──────┬──────┬──────┬──────┬──────┬──────┐          ┌──────┬──────┬──────┬──────┬──────┬──────┬────────┐
 * │   [    │  ~   │  |   │  &   │  =   │  $   │ Del  │          │Insert│  \   │  /   │  -   │  *   │  %   │   ]    │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┤          ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │   {    │  Q   │  W   │  F   │  P   │  B   │      │          │      │  J   │  L   │  U   │  Y   │  ,   │   }    │
 * ├────────╆━━━━━━╈━━━━━━╈━━━━━━╈━━━━━━╅──────┤ Esc  │          │Enter ├──────╆━━━━━━╈━━━━━━╈━━━━━━╈━━━━━━╅────────┤
 * │   (    ┃  A   ┃  R   ┃  S   ┃  T   ┃  G   ├──────┤          ├──────┤  M   ┃  N   ┃  E   ┃  I   ┃  O   ┃   )    │
 * ├────────╄━━━━━━╇━━━━━━╇━━━━━━╇━━━━━━╃──────┤      │          │      ├──────╄━━━━━━╇━━━━━━╇━━━━━━╇━━━━━━╃────────┤
 * │   <    │  Z   │  X   │  C   │  D   │  V   │ Tab  │          │ BkSp │  K   │  H   │  ;   │  '   │  .   │   >    │
 * └─┬──────┼──────┼──────┼──────┼──────┼──────┴──────┘          └──────┴──────┼──────┼──────┼──────┼──────┼──────┬─┘
 *   │  @   │  ?   │  `   │  #   │  "   │                                      │  _   │  :   │  +   │  !   │  ^   │
 *   └──────┴──────┴──────┴──────┴──────┘                                      └──────┴──────┴──────┴──────┴──────┘
 *                                        ┌──────┬──────┐      ┌──────┬──────┐
 *                                        │L_FUNC│L_NUM │      │PrnScr│L_FUNC│
 *                                 ┌──────┼──────┼──────┤      ├──────┼──────┼──────┐
 *                                 │      │      │RShift│      │Hyper │      │      │
 *                                 │ Left │ Left ├──────┤      ├──────┤ Left │L_NUM │
 *                                 │Shift │ Ctrl │ LGui │      │Space │ Alt  │      │
 *                                 └──────┴──────┴──────┘      └──────┴──────┴──────┘
 */
#define L_NUM 1
/*
 * ┌────────┬──────┬──────┬──────┬──────┬──────┬──────┐          ┌──────┬──────┬──────┬──────┬──────┬──────┬────────┐
 * │   @`   │  @1  │  @2  │  @3  │  @4  │  @5  │      │          │      │  @6  │      │      │      │  @7  │   @8   │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┤          ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │   @-   │  @Q  │ PgUp │  Up  │ PgDn │  @B  │      │          │      │  @J  │  7   │  8   │  9   │      │   @=   │
 * ├────────╆━━━━━━╈━━━━━━╈━━━━━━╈━━━━━━╅──────┤      │          │      ├──────╆━━━━━━╈━━━━━━╈━━━━━━╈━━━━━━╅────────┤
 * │   @9   ┃ Home ┃ Left ┃ Down ┃Right ┃ End  ├──────┤          ├──────┤  0   ┃  4   ┃  5   ┃  6   ┃  @O  ┃   @0   │
 * ├────────╄━━━━━━╇━━━━━━╇━━━━━━╇━━━━━━╃──────┤      │          │      ├──────╄━━━━━━╇━━━━━━╇━━━━━━╇━━━━━━╃────────┤
 * │   @[   │  @Z  │  @X  │  @C  │  @D  │  @V  │      │          │      │  @K  │  1   │  2   │  3   │      │   @]   │
 * └─┬──────┼──────┼──────┼──────┼──────┼──────┴──────┘          └──────┴──────┼──────┼──────┼──────┼──────┼──────┬─┘
 *   │  @,  │  @/  │  @'  │  @;  │  @A  │                                      │      │      │      │  @\  │  @.  │
 *   └──────┴──────┴──────┴──────┴──────┘                                      └──────┴──────┴──────┴──────┴──────┘
 *                                        ┌──────┬──────┐      ┌──────┬──────┐
 *                                        │L_NPAD│      │      │ App  │L_NPAD│
 *                                 ┌──────┼──────┼──────┤      ├──────┼──────┼──────┐
 *                                 │      │      │      │      │      │      │      │
 *                                 │      │      ├──────┤      ├──────┤      │      │
 *                                 │      │      │      │      │      │      │      │
 *                                 └──────┴──────┴──────┘      └──────┴──────┴──────┘
 */
#define L_FUNC 2
/*
 * ┌────────┬──────┬──────┬──────┬──────┬──────┬──────┐          ┌──────┬──────┬──────┬──────┬──────┬──────┬────────┐
 * │        │      │      │ Mclk │      │      │ Mute │          │ Play │ Stop │ F10  │ F11  │ F12  │      │ Power  │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┤          ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │      │ Lclk │ MsUp │ Rclk │ WhUp │Volume│          │      │      │  F7  │  F8  │  F9  │      │ Sleep  │
 * ├────────╆━━━━━━╈━━━━━━╈━━━━━━╈━━━━━━╅──────┤  Up  │          │ Prev ├──────╆━━━━━━╈━━━━━━╈━━━━━━╈━━━━━━╅────────┤
 * │        ┃WhLeft┃MsLeft┃MsDown┃MsRght┃WhRght├──────┤          ├──────┤      ┃  F4  ┃  F5  ┃  F6  ┃      ┃  Wake  │
 * ├────────╄━━━━━━╇━━━━━━╇━━━━━━╇━━━━━━╃──────┤Volume│          │      ├──────╄━━━━━━╇━━━━━━╇━━━━━━╇━━━━━━╃────────┤
 * │        │      │Accel0│Accel1│Accel2│WhDown│ Down │          │ Next │      │  F1  │  F2  │  F3  │      │ Pause  │
 * └─┬──────┼──────┼──────┼──────┼──────┼──────┴──────┘          └──────┴──────┼──────┼──────┼──────┼──────┼──────┬─┘
 *   │Versn │      │CpsLck│NumLck│SclLck│                                      │      │      │      │      │Reset │
 *   └──────┴──────┴──────┴──────┴──────┘                                      └──────┴──────┴──────┴──────┴──────┘
 *                                        ┌──────┬──────┐      ┌──────┬──────┐
 *                                        │      │L_NPAD│      │Toggle│      │
 *                                 ┌──────┼──────┼──────┤      ├──────┼──────┼──────┐
 *                                 │      │      │      │      │      │      │      │
 *                                 │      │      ├──────┤      ├──────┤      │L_NPAD│
 *                                 │      │      │      │      │      │      │      │
 *                                 └──────┴──────┴──────┘      └──────┴──────┴──────┘
 */
#define L_NPAD 3
/*
 * ┌────────┬──────┬──────┬──────┬──────┬──────┬──────┐          ┌──────┬──────┬──────┬──────┬──────┬──────┬────────┐
 * │        │      │      │      │  =   │      │Static│          │      │      │  /   │  -   │  *   │      │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┤          ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │  Hue+  │ Sat+ │RgbMo7│RgbMo8│RgbMo9│RgbFor│Bright│          │      │      │  7   │  8   │  9   │  ,   │        │
 * ├────────╆━━━━━━╈━━━━━━╈━━━━━━╈━━━━━━╅──────┤ness+ │          │Enter ├──────╆━━━━━━╈━━━━━━╈━━━━━━╈━━━━━━╅────────┤
 * │  Hue-  ┃ Sat- ┃RgbMo4┃RgbMo5┃RgbMo6┃RgbRev├──────┤          ├──────┤  0   ┃  4   ┃  5   ┃  6   ┃      ┃        │
 * ├────────╄━━━━━━╇━━━━━━╇━━━━━━╇━━━━━━╃──────┤Bright│          │      ├──────╄━━━━━━╇━━━━━━╇━━━━━━╇━━━━━━╃────────┤
 * │        │      │RgbMo1│RgbMo2│RgbMo3│      │ness- │          │      │      │  1   │  2   │  3   │  .   │        │
 * └─┬──────┼──────┼──────┼──────┼──────┼──────┴──────┘          └──────┴──────┼──────┼──────┼──────┼──────┼──────┬─┘
 *   │      │      │CpsLck│NumLck│SclLck│                                      │      │      │  +   │      │      │
 *   └──────┴──────┴──────┴──────┴──────┘                                      └──────┴──────┴──────┴──────┴──────┘
 *                                        ┌──────┬──────┐      ┌──────┬──────┐
 *                                        │      │      │      │      │      │
 *                                 ┌──────┼──────┼──────┤      ├──────┼──────┼──────┐
 *                                 │      │      │      │      │      │      │      │
 *                                 │      │      ├──────┤      ├──────┤      │      │
 *                                 │      │      │      │      │      │      │      │
 *                                 └──────┴──────┴──────┘      └──────┴──────┴──────┘
 */

enum custom_keycodes {
    VRSN = SAFE_RANGE,
};

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_BASE] = LAYOUT_ergodox(
        KC_LBRC , KC_TILD , KC_PIPE , KC_AMPR , KC_EQL  , KC_DLR     , KC_DELT   ,
        KC_LCBR , KC_Q    , KC_W    , KC_F    , KC_P    , KC_B       , KC_ESC    ,
        KC_LPRN , KC_A    , KC_R    , KC_S    , KC_T    , KC_G       ,
        KC_LABK , KC_Z    , KC_X    , KC_C    , KC_D    , KC_V       , KC_TAB    ,
        KC_AT   , KC_QUES , KC_GRV  , KC_HASH , KC_DQUO ,
                                                          MO(L_FUNC) , MO(L_NUM) ,
                                                                       KC_RSFT   ,
                                                KC_LSFT , KC_LCTL    , KC_LGUI   ,

        KC_INS  , KC_BSLS    , KC_SLSH   , KC_MINS , KC_ASTR , KC_PERC , KC_RBRC ,
        KC_ENT  , KC_J       , KC_L      , KC_U    , KC_Y    , KC_COMM , KC_RCBR ,
                  KC_M       , KC_N      , KC_E    , KC_I    , KC_O    , KC_RPRN ,
        KC_BSPC , KC_K       , KC_H      , KC_SCLN , KC_QUOT , KC_DOT  , KC_RABK ,
                               KC_UNDS   , KC_COLN , KC_PLUS , KC_EXLM , KC_CIRC ,
        KC_PSCR , MO(L_FUNC) ,
        KC_HYPR ,
        KC_SPC  , KC_LALT    , MO(L_NUM)
    ),
    [L_NUM] = LAYOUT_ergodox(
        RGUI(KC_GRV)  , RGUI(KC_1)    , RGUI(KC_2)    , RGUI(KC_3)    , RGUI(KC_4) , RGUI(KC_5) , _______ ,
        RGUI(KC_MINS) , RGUI(KC_Q)    , KC_PGUP       , KC_UP         , KC_PGDN    , RGUI(KC_B) , _______ ,
        RGUI(KC_9)    , KC_HOME       , KC_LEFT       , KC_DOWN       , KC_RGHT    , KC_END     ,
        RGUI(KC_LBRC) , RGUI(KC_Z)    , RGUI(KC_X)    , RGUI(KC_C)    , RGUI(KC_D) , RGUI(KC_V) , _______ ,
        RGUI(KC_COMM) , RGUI(KC_SLSH) , RGUI(KC_QUOT) , RGUI(KC_SCLN) , RGUI(KC_A) ,
                                                                                     MO(L_NPAD) , _______ ,
                                                                                                  _______ ,
                                                                        _______    , _______    , _______ ,

        _______ , RGUI(KC_6) , _______ , _______ , _______ , RGUI(KC_7)    , RGUI(KC_8)    ,
        _______ , RGUI(KC_J) , KC_7    , KC_8    , KC_9    , _______       , RGUI(KC_EQL)  ,
                  KC_0       , KC_4    , KC_5    , KC_6    , RGUI(KC_O)    , RGUI(KC_0)    ,
        _______ , RGUI(KC_K) , KC_1    , KC_2    , KC_3    , _______       , RGUI(KC_RBRC) ,
                               _______ , _______ , _______ , RGUI(KC_BSLS) , RGUI(KC_DOT)  ,
        KC_APP  , MO(L_NPAD) ,
        _______ ,
        _______ , _______    , _______
    ),
    [L_FUNC] = LAYOUT_ergodox(
        _______ , _______ , _______ , KC_BTN3 , _______ , _______ , KC_MUTE    ,
        _______ , _______ , KC_BTN1 , KC_MS_U , KC_BTN2 , KC_WH_U , KC_VOLU    ,
        _______ , KC_WH_L , KC_MS_L , KC_MS_D , KC_MS_R , KC_WH_R ,
        _______ , _______ , KC_ACL0 , KC_ACL1 , KC_ACL2 , KC_WH_D , KC_VOLD    ,
        VRSN    , _______ , KC_CLCK , KC_NLCK , KC_SLCK ,
                                                          _______ , MO(L_NPAD) ,
                                                                    _______    ,
                                                _______ , _______ , _______    ,

        KC_MPLY , KC_MSTP , KC_F10     , KC_F11  , KC_F12  , _______ , KC_PWR  ,
        KC_MPRV , _______ , KC_F7      , KC_F8   , KC_F9   , _______ , KC_SLEP ,
                  _______ , KC_F4      , KC_F5   , KC_F6   , _______ , KC_WAKE ,
        KC_MNXT , _______ , KC_F1      , KC_F2   , KC_F3   , _______ , KC_PAUS ,
                            _______    , _______ , _______ , _______ , RESET   ,
        RGB_TOG , _______ ,
        _______ ,
        _______ , _______ , MO(L_NPAD)
    ),
    [L_NPAD] = LAYOUT_ergodox(
        _______ , _______ , _______  , _______  , KC_PEQL  , _______  , RGB_M_P ,
        RGB_HUI , RGB_SAI , RGB_M_X  , RGB_M_G  , RGB_M_T  , RGB_MOD  , RGB_VAI ,
        RGB_HUD , RGB_SAD , RGB_M_SW , RGB_M_SN , RGB_M_K  , RGB_RMOD ,
        _______ , _______ , RGB_M_P  , RGB_M_B  , RGB_M_R  , _______  , RGB_VAD ,
        _______ , _______ , KC_CLCK  , KC_NLCK  , KC_SLCK  ,
                                                             _______  , _______ ,
                                                                        _______ ,
                                                  _______  , _______  , _______ ,

        _______ , _______ , KC_PSLS , KC_PMNS , KC_PAST , _______ , _______ ,
        KC_PENT , _______ , KC_P7   , KC_P8   , KC_P9   , KC_PCMM , _______ ,
                  KC_P0   , KC_P4   , KC_P5   , KC_P6   , _______ , _______ ,
        _______ , _______ , KC_P1   , KC_P2   , KC_P3   , KC_PDOT , _______ ,
                            _______ , _______ , KC_PPLS , _______ , _______ ,
        _______ , _______ ,
        _______ ,
        _______ , _______ , _______
    ),
};
/* clang-format on */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
        }
    }
    return true;
}

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = biton32(state);
    switch (layer) {
        case L_BASE:
            rgblight_update_dword(rgblight_read_dword());
            break;
        case L_NUM:
            ergodox_right_led_1_on();
            rgblight_update_dword(rgblight_read_dword());
            break;
        case L_FUNC:
            ergodox_right_led_2_on();
            rgblight_update_dword(rgblight_read_dword());
            break;
        case L_NPAD:
            ergodox_right_led_3_on();
            rgblight_setrgb(0x00, 0x00, 0xFF);
            break;
        default:
            break;
    }

    return state;
};
