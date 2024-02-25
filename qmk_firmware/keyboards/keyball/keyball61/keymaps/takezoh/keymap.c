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
	L_MOUSE,
};

//Tap dance enums
enum {
	X_LANG_EX = 0,
	X_LSFT_LAYER,
  SOME_OTHER_DANCE
};


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_DEF] = LAYOUT_universal(
    KC_ESC   , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                                  KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , KC_MINS  ,
    KC_TAB   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                  KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_MINS  ,
LCTL_T(KC_ESC),KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                  KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , RCTL_T(KC_QUOT) ,
LSFT_T(KC_LCTL),KC_Z    , KC_X     , KC_C     , KC_V     , KC_B     , _______  ,            _______  , KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , RSFT_T(S(KC_2))  ,
 _______,_______,KC_LALT,MO(L_GUI),TD(X_LANG_EX),LT(L_MOD,KC_SPC),LT(L_FN,KC_ESC),/**/LT(L_FN,KC_BSPC),LT(L_MOD,KC_ENT), _______  , _______  , _______  , KC_RALT  , _______
  ),
	// shift
  /* [L_SFT] = LAYOUT_universal( */
  /*   S(KC_ESC), S(KC_1)  , KC_LBRC  , S(KC_3)  , S(KC_4)  , S(KC_5)  ,                                  KC_EQL   , S(KC_6)  ,S(KC_QUOT), S(KC_8)  , S(KC_9)  ,S(KC_INT1), */
  /*   S(KC_TAB), S(KC_Q)  , S(KC_W)  , S(KC_E)  , S(KC_R)  , S(KC_T)  ,                                  S(KC_Y)  , S(KC_U)  , S(KC_I)  , S(KC_O)  , S(KC_P)  ,S(KC_MINS), */
  /*   S(KC_LCTL),S(KC_A)  , S(KC_S)  , S(KC_D)  , S(KC_F)  , S(KC_G)  ,                                  S(KC_H)  , S(KC_J)  , S(KC_K)  , S(KC_L)  ,S(KC_SCLN),S(KC_QUOT), */
  /*   _______  , S(KC_Z)  , S(KC_X)  , S(KC_C)  , S(KC_V)  , S(KC_B)  , _______  ,            _______  , S(KC_N)  , S(KC_M)  ,S(KC_COMM), S(KC_DOT),S(KC_SLSH), _______  , */
  /*   _______  , _______  ,S(KC_LALT),S(KC_LGUI), _______  , S(KC_SPC), S(KC_ESC),            KC_DEL   , KC_BSPC  , _______  ,S(KC_RGUI), _______  ,S(KC_RALT), _______ */
  /* ), */
	// mod
  [L_MOD] = LAYOUT_universal(
    KC_ESC   , KC_F1    , KC_F2    , KC_SLSH  , S(KC_8)  , _______  ,                                  KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   ,
    KC_0     , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                                  KC_6     , KC_7     , KC_8     , KC_9     , S(KC_9)  , S(KC_0)  ,
LCTL_T(KC_GRV),KC_LBRC  ,S(KC_LBRC), XXXXXXX  , XXXXXXX  , S(KC_4)  ,                                  S(KC_EQL), KC_EQL   , S(KC_8)  , KC_MINS  ,S(KC_SCLN),RCTL_T(S(KC_QUOT)),
LSFT_T(S(KC_GRV)),KC_RBRC,S(KC_RBRC),S(KC_3)  , S(KC_1)  , S(KC_5)  , _______  ,             _______ , S(KC_6)  , S(KC_7)  ,S(KC_COMM), S(KC_DOT),S(KC_NUHS),RSFT_T(KC_NUHS) ,
    _______  , _______  , _______  , _______  , KC_LNG1  , KC_SPC   , _______  ,             KC_DEL  , KC_BSPC  , _______  , _______  , _______  , _______  , _______
  ),
	// fn/num
  [L_FN] = LAYOUT_universal(
	  S(KC_ESC), KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,                                  KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   ,
    KC_F1    ,  KC_F2   , KC_P7    , KC_P8    , KC_P9    , KC_BSPC  ,                                  KC_PGUP  , _______  , KC_UP    , _______  , KC_F7    , KC_F8    ,
    KC_F3    ,  KC_F4   , KC_P4    , KC_P5    , KC_P6    , KC_PMNS  ,                                  KC_PGDN  , KC_LEFT  , KC_DOWN  , KC_RGHT  , KC_F9    , KC_F10   ,
    KC_F5    ,  KC_F6   , KC_P1    , KC_P2    , KC_P3    , KC_PPLS  , _______  ,            _______  , _______  , _______  , _______  , _______  , KC_F11   , KC_F12   ,
    _______  , _______  , KC_P0    , KC_PDOT  , KC_PSLS  , KC_PAST  , KC_PENT  ,            _______  , _______  , _______  , _______  , _______  , _______  , _______
  ),
	// meta (windows)
  [L_GUI] = LAYOUT_universal(
    G(KC_ESC), G(KC_1)  , KC_LBRC  , G(KC_3)  , G(KC_4)  , G(KC_5)  ,                                  KC_EQL   , G(KC_6)  ,G(KC_QUOT), G(KC_8)  , G(KC_9)  ,G(KC_INT1),
    G(KC_TAB), G(KC_Q)  , G(KC_W)  , G(KC_E)  , G(KC_R)  , G(KC_T)  ,                                  G(KC_Y)  , G(KC_U)  , G(KC_I)  , G(KC_O)  , G(KC_P)  ,G(KC_INT3),
    G(KC_LCTL),G(KC_A)  , G(KC_S)  , G(KC_D)  , G(KC_F)  , G(KC_G)  ,                                  G(KC_H)  , G(KC_J)  , G(KC_K)  , G(KC_L)  ,G(KC_SCLN),G(KC_QUOT),
    G(KC_LSFT),G(KC_Z)  , G(KC_X)  , C(KC_INS), S(KC_INS), G(KC_B)  , _______  ,            _______  , G(KC_N)  , G(KC_M)  ,G(KC_COMM), G(KC_DOT),G(KC_SLSH),G(KC_RSFT),
    _______  , _______  ,G(KC_LALT), _______  , _______  , G(KC_SPC), _______  ,            KC_DEL   , KC_BSPC  , _______  , _______  , _______  ,G(KC_RALT), _______
  ),

	// extend
  [L_EX] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    RGB_TOG  , CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , _______  ,                                  KC_PGUP  , _______  , KC_UP    , _______  , _______  , _______  ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , _______  , _______  ,                                  KC_PGDN  , KC_LEFT  , KC_DOWN  , KC_RGHT  , _______  , _______  ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , _______  , _______  , _______  ,            _______  , _______  , _______  , _______  , _______  , KBC_SAVE , KBC_RST  ,
    _______  , _______  , QK_BOOT  , KC_LGUI  , _______  , _______  , _______  ,            _______  , _______  , _______  , _______  , _______  , QK_BOOT  , _______
  ),

	// mouse
  [L_MOUSE] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , KC_BTN3  , KC_BTN2  , _______  , KC_BTN1  , _______  ,                                  _______  , KC_BTN1  , _______  , KC_BTN2  , KC_BTN3  , _______  ,
    MO(L_SFT), _______  , _______  , _______  , _______  , _______  , _______  ,            _______  , _______  , _______  , _______  , _______  , _______  , KC_RSFT  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  ,          A(KC_LEFT),A(KC_RIGHT), _______  , _______  , _______  , _______  , _______
  ),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	/* uint64_t modcode = 0; */
	/* dprintf("kc: %d\n", keycode); */
	/* if (IS_QK_MOD_TAP(keycode)) { */
	/* 	modcode = QK_MOD_TAP_GET_MODS(keycode); */
	/* 	dprintf("is qk mod tap, mc: %d\n", modcode); */
	/* } */
	/* if ((modcode & MOD_LSFT) || (keycode == KC_LSFT || keycode == KC_RSFT)) { */
	/* 	dprintf("scroll %d\n", record->event.pressed); */
	/* 	keyball_set_scroll_mode(record->event.pressed); */
	/* } */
	switch (keycode) {
		case RSFT_T(S(KC_2)):
			if (record->tap.count && record->event.pressed) {
				tap_code16(S(KC_2));
				return false;
			}
			break;
		case RCTL_T(S(KC_QUOT)):
			if (record->tap.count && record->event.pressed) {
				tap_code16(S(KC_QUOT));
				return false;
			}
			break;
		case LSFT_T(S(KC_GRV)):
			if (record->tap.count && record->event.pressed) {
				tap_code16(S(KC_GRV));
				return false;
			}
			break;
	}
	return true;
}


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
		case TD(X_LANG_EX):
		case TD(X_LSFT_LAYER):
			return TAPPING_TERM + 70;
		default:
			return TAPPING_TERM;
  }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case LT(L_MOD,KC_SPC):
			return 0;
		default:
			return QUICK_TAP_TERM;
	}
}

typedef struct {
  bool is_press_action;
  int state;
} tap;

//instanalize an instance of 'tap' for the 'x' tap dance.
static tap xtap_state = {
  .is_press_action = true,
  .state = 0
};

void dance_lang_ex_finished (tap_dance_state_t *state, void *user_data) {
	xtap_state.state = 0;
	if (state->pressed) {
		xtap_state.state = 3;
	} else if (state->count < 3) {
		xtap_state.state = state->count;
	}
	switch (xtap_state.state) {
		case 1: register_code(KC_LNG2); break;
		case 2: register_code(KC_LNG1); break;
		case 3: layer_on(L_EX); break;
	}
}

void dance_lang_ex_reset(tap_dance_state_t *state, void *user_data) {
	switch (xtap_state.state) {
		case 1: unregister_code(KC_LNG2); break;
		case 2: unregister_code(KC_LNG1); break;
		case 3: layer_off(L_EX); break;
	}
  xtap_state.state = 0;
}

void dance_lsft_layer_finished (tap_dance_state_t *state, void *user_data) {
	if (state->pressed) {
		xtap_state.state = 1;
		if (state->count > 1) {
			xtap_state.state = 2;
		}
	} else {
		xtap_state.state = 3;
		for (int i = 1; i < state->count; i++) {
			register_code(KC_LCTL);
			unregister_code(KC_LCTL);
		}
	}
	switch (xtap_state.state) {
		case 1: layer_on(L_SFT); break;
		case 2: register_code(KC_LSFT); break;
		case 3: register_code(KC_LCTL); break;
	}
}

void dance_lsft_layer_reset(tap_dance_state_t *state, void *user_data) {
	switch (xtap_state.state) {
		case 1: layer_off(L_SFT); break;
		case 2: unregister_code(KC_LSFT); break;
		case 3: unregister_code(KC_LCTL); break;
	}
  xtap_state.state = 0;
}

tap_dance_action_t tap_dance_actions[] = {
  [X_LANG_EX] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_lang_ex_finished, dance_lang_ex_reset),
  [X_LSFT_LAYER] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_lsft_layer_finished, dance_lsft_layer_reset)
};

#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
void pointing_device_init_user(void) {
	set_auto_mouse_layer(L_MOUSE);
	set_auto_mouse_enable(true);
}
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
	bool bScrollMode = get_highest_layer(remove_auto_mouse_layer(state, true)) == L_MOD;
	if (bScrollMode) {
		state = remove_auto_mouse_layer(state, false);
	}
	set_auto_mouse_enable(!bScrollMode);
	keyball_set_scroll_mode(bScrollMode);
#else
	keyball_set_scroll_mode(get_highest_layer(state) == L_MOD);
#endif
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

void keyboard_post_init_user(void) {
  // Call the post init code.
	debug_enable = true;
	debug_matrix = true;
	debug_keyboard = true;
	debug_mouse = true;

#ifdef RGBLIGHT_ENABLE
  rgblight_enable_noeeprom(); // enables Rgb, without saving settings
  rgblight_sethsv_noeeprom(180, 255, 255); // sets the color to teal/cyan without saving
  rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3); // sets mode to Fast breathing without saving
#endif
}
