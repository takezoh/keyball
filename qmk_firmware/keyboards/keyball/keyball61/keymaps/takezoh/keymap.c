/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

enum {
	L_DEF = 0,
	L_SFT,
	L_MOD,
	L_FN,
	L_GUI,
	L_EX,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_DEF] = LAYOUT_universal(
    KC_ESC   , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                                  KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , KC_MINS  ,
    KC_TAB   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                  KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_MINS  ,
 LCTL_T(KC_ESC),KC_A    , KC_S     , KC_D     , KC_F     , KC_G     ,                                  KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  ,RCTL_T(KC_LBRC),
 LT(L_SFT,KC_LCTL),KC_Z , KC_X     , KC_C     , KC_V     , KC_B     , KC_RBRC  ,              KC_LBRC, KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  ,RSFT_T(KC_RBRC),
    _______,_______,KC_LALT,LT(L_GUI,KC_LGUI),LT(L_FN,KC_LNG2),LT(L_MOD,KC_SPC),LT(L_EX,KC_LNG1),  LT(L_FN,KC_BSPC),LT(L_MOD,KC_ENT), _______  , _______  , _______  , KC_RALT  , _______
  ),
	// shift
  [L_SFT] = LAYOUT_universal(
    S(KC_ESC), S(KC_1)  , KC_LBRC  , S(KC_3)  , S(KC_4)  , S(KC_5)  ,                                  KC_EQL   , S(KC_6)  ,S(KC_QUOT), S(KC_8)  , S(KC_9)  ,S(KC_INT1),
    S(KC_TAB), S(KC_Q)  , S(KC_W)  , S(KC_E)  , S(KC_R)  , S(KC_T)  ,                                  S(KC_Y)  , S(KC_U)  , S(KC_I)  , S(KC_O)  , S(KC_P)  ,S(KC_GRV),
    S(KC_LCTL),S(KC_A)  , S(KC_S)  , S(KC_D)  , S(KC_F)  , S(KC_G)  ,                                  S(KC_H)  , S(KC_J)  , S(KC_K)  , S(KC_L)  , KC_QUOT  ,S(KC_SCLN),
    _______  , S(KC_Z)  , S(KC_X)  , S(KC_C)  , S(KC_V)  , S(KC_B)  ,S(KC_RBRC),           S(KC_NUHS), S(KC_N)  , S(KC_M)  ,S(KC_COMM), S(KC_DOT),S(KC_SLSH), KC_NUHS  ,
    _______  , _______  ,S(KC_LALT),S(KC_LGUI), _______  , S(KC_SPC), S(KC_ESC),            KC_DEL   , KC_BSPC  , _______  ,S(KC_RGUI), _______  , S(KC_RALT), _______
  ),
	// mod
  [L_MOD] = LAYOUT_universal(
    KC_ESC   , KC_F1    , KC_F2    , KC_SLSH  , S(KC_8)  , _______  ,                                  KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   ,
    KC_ESC   , S(KC_1)  , S(KC_2)  , S(KC_3)  , S(KC_4)  , S(KC_5)  ,                                  S(KC_6)  , S(KC_7)  , S(KC_8)  , S(KC_9)  , S(KC_0)  , KC_GRV   ,
    _______  , KC_BTN3  , KC_BTN2  , _______  , KC_BTN1  , _______  ,                                  _______  , S(KC_EQL), KC_EQL   ,S(KC_NUHS),S(KC_QUOT), S(KC_LBRC),
    _______  , _______  , _______  , _______  , _______  , _______  , S(KC_8)  ,            S(KC_9)  ,S(KC_MINS), _______  , _______  , _______  , _______  , S(KC_RBRC),
    _______  , _______  , _______  , _______  , _______  , _______  , _______  ,             KC_DEL  , KC_BSPC  , _______  , _______  , _______  , _______  , _______
  ),
	// fn/num
  [L_FN] = LAYOUT_universal(
	  S(KC_ESC), KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,                                  KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   ,
    KC_F1    ,  KC_F2   , KC_7     , KC_8     , KC_9     , KC_MINS  ,                                  KC_PGUP  , _______  , KC_UP    , _______  , KC_F7    , KC_F8    ,
    KC_F3    ,  KC_F4   , KC_4     , KC_5     , KC_6     , S(KC_EQL),                                  KC_PGDN  , KC_LEFT  , KC_DOWN  , KC_RGHT  , KC_F9    , KC_F10   ,
    KC_F5    ,  KC_F6   , KC_1     , KC_2     , KC_3     , KC_ENT   , _______  ,            _______  , KC_SLSH  , S(KC_8)  , KC_EQL   , _______  , KC_F11   , KC_F12   ,
    _______  , _______  , KC_0     , KC_DOT   , _______  , _______  , _______  ,            _______  , _______  , _______  , _______  , _______  , S(KC_RALT), _______
  ),
	// meta
  [L_GUI] = LAYOUT_universal(
    G(KC_ESC), G(KC_1)  , KC_LBRC  , G(KC_3)  , G(KC_4)  , G(KC_5)  ,                                  KC_EQL   , G(KC_6)  ,G(KC_QUOT), G(KC_8)  , G(KC_9)  ,G(KC_INT1),
    G(KC_TAB), G(KC_Q)  , G(KC_W)  , G(KC_E)  , G(KC_R)  , G(KC_T)  ,                                  G(KC_Y)  , G(KC_U)  , G(KC_I)  , G(KC_O)  , G(KC_P)  ,G(KC_INT3),
    G(KC_LCTL),G(KC_A)  , G(KC_S)  , G(KC_D)  , G(KC_F)  , G(KC_G)  ,                                  G(KC_H)  , G(KC_J)  , G(KC_K)  , G(KC_L)  ,G(KC_SCLN),G(KC_QUOT),
    G(KC_LSFT),G(KC_Z)  , G(KC_X)  , C(KC_INS), S(KC_INS), G(KC_B)  ,G(KC_RBRC),           G(KC_NUHS), G(KC_N)  , G(KC_M)  ,G(KC_COMM), G(KC_DOT),G(KC_SLSH),G(KC_RSFT),
    _______  , _______  ,G(KC_LALT), _______  , _______  , G(KC_SPC), _______  ,            KC_DEL   , KC_BSPC  , _______  , _______  , _______  , G(KC_RALT), _______
  ),
	// extend
  [L_EX] = LAYOUT_universal(
    RGB_TOG  , _______  , _______  , _______  , _______  , _______  ,                                  RGB_M_P  , RGB_M_B  , RGB_M_R  , RGB_M_SW , RGB_M_SN , RGB_M_K  ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , _______  , _______  ,                                  RGB_M_X  , RGB_M_G  , RGB_M_T  , RGB_M_TW , _______  , _______  ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , _______  , _______  ,                                  CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE , KBC_RST  ,
    _______  , _______  , SCRL_DVD , SCRL_DVI , SCRL_MO  , SCRL_TO  , EE_CLR  ,              EE_CLR  , KC_HOME  , KC_PGDN  , KC_PGUP  , KC_END   , _______  , _______  ,
    QK_BOOT  , _______  , _______  , _______  , KC_LNG1  , _______  , _______  ,             KC_DEL  , KC_BSPC  , _______  , _______  , _______  , _______  , QK_BOOT
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == L_SFT);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
