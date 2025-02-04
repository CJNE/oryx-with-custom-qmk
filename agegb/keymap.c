#include QMK_KEYBOARD_H
#include "version.h"

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
  ST_MACRO_6,
  ST_MACRO_7,
  ST_MACRO_8,
  ST_MACRO_9,
  ST_MACRO_10,
};


enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,
    KC_LEFT_CTRL,   MT(MOD_LCTL, KC_A),MT(MOD_LALT, KC_S),MT(MOD_LGUI, KC_D),MT(MOD_LSFT, KC_F),KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           MT(MOD_RSFT, KC_SCLN),KC_QUOTE,
    KC_LEFT_SHIFT,  KC_Z,           TD(DANCE_0),    TD(DANCE_1),    TD(DANCE_2),    KC_B,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RIGHT_SHIFT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    MT(MOD_LGUI, KC_BSPC),LT(1,KC_DELETE),KC_TRANSPARENT, KC_TRANSPARENT, LT(2,KC_ENTER), LT(1,KC_SPACE)
  ),
  [1] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_TRANSPARENT, KC_EXLM,        KC_PLUS,        KC_EQUAL,       KC_LCBR,        KC_RCBR,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_GRAVE,       KC_7,           KC_8,           KC_9,           KC_ASTR,        LALT(KC_LBRC),
    KC_TRANSPARENT, KC_HASH,        KC_DLR,         KC_GRAVE,       KC_LPRN,        KC_RPRN,                                                                        KC_TILD,        KC_4,           KC_5,           KC_6,           LALT(KC_SCLN),  LALT(KC_QUOTE),
    KC_TRANSPARENT, KC_PERC,        KC_CIRC,        KC_TILD,        KC_LBRC,        KC_RBRC,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_PIPE,        KC_1,           KC_2,           KC_3,           KC_AMPR,        KC_PLUS,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_0,           KC_TRANSPARENT
  ),
  [2] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, ST_MACRO_0,     ST_MACRO_1,     ST_MACRO_2,     ST_MACRO_3,     ST_MACRO_4,     KC_TRANSPARENT,                                 KC_TRANSPARENT, ST_MACRO_6,     ST_MACRO_7,     ST_MACRO_8,     ST_MACRO_9,     ST_MACRO_10,    QK_BOOT,
    LGUI(LSFT(KC_TAB)),LGUI(KC_TAB),   KC_MS_BTN1,     KC_MS_UP,       KC_MS_BTN2,     LCTL(KC_Z),     KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_PAGE_UP,     KC_PGDN,        KC_HOME,        KC_END,         KC_AUDIO_VOL_UP,KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    ST_MACRO_5,                                                                     KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_AUDIO_VOL_DOWN,KC_MEDIA_PLAY_PAUSE,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),   KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_AUDIO_MUTE,  KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};




rgblight_config_t rgblight_config;
bool disable_layer_color = 0;

bool suspended = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_1));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_2));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_3));
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_4));
    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_5));
    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_F) SS_DELAY(100) SS_TAP(X_G)  SS_DELAY(100) SS_TAP(X_ENTER));
    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_6));
    }
    break;
    case ST_MACRO_7:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_7));
    }
    break;
    case ST_MACRO_8:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_8));
    }
    break;
    case ST_MACRO_9:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_9));
    }
    break;
    case ST_MACRO_10:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_0));
    }
    break;

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case TOGGLE_LAYER_COLOR:
      if (record->event.pressed) {
        disable_layer_color ^= 1;
      }
      return false;
  }
  return true;
}

uint8_t layer_state_set_user(uint8_t state) {
    uint8_t layer = biton(state);
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case 1:
        ergodox_right_led_1_on();
        break;
      case 2:
        ergodox_right_led_2_on();
        break;
      case 3:
        ergodox_right_led_3_on();
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }
    switch (layer) {
      case 0:
        if(!disable_layer_color) {
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(1);
          rgblight_sethsv_noeeprom(74,255, rgblight_config.val);
        }
        break;
      case 1:
        if(!disable_layer_color) {
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(1);
          rgblight_sethsv_noeeprom(188,255, rgblight_config.val);
        }
        break;
      case 2:
        if(!disable_layer_color) {
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(1);
          rgblight_sethsv_noeeprom(131,255, rgblight_config.val);
        }
        break;
      default:
        if(!disable_layer_color) {
          rgblight_config.raw = eeconfig_read_rgblight();
          if(rgblight_config.enable == true) {
            rgblight_enable();
            rgblight_mode(rgblight_config.mode);
            rgblight_sethsv(rgblight_config.hue, rgblight_config.sat, rgblight_config.val);
          }
          else {
            rgblight_disable();
          }
        }
        break;
    }
    return state;
};

void keyboard_post_init_user(void) {
  layer_state_set_user(layer_state);
}


typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[3];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_X);
        tap_code16(KC_X);
        tap_code16(KC_X);
    }
    if(state->count > 3) {
        tap_code16(KC_X);
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_X); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_X)); break;
        case DOUBLE_TAP: register_code16(KC_X); register_code16(KC_X); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_X); register_code16(KC_X);
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_X); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_X)); break;
        case DOUBLE_TAP: unregister_code16(KC_X); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_X); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_C);
        tap_code16(KC_C);
        tap_code16(KC_C);
    }
    if(state->count > 3) {
        tap_code16(KC_C);
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_C); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_C)); break;
        case DOUBLE_TAP: register_code16(KC_C); register_code16(KC_C); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_C); register_code16(KC_C);
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_C); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_C)); break;
        case DOUBLE_TAP: unregister_code16(KC_C); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_C); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(tap_dance_state_t *state, void *user_data);
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void on_dance_2(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_V);
        tap_code16(KC_V);
        tap_code16(KC_V);
    }
    if(state->count > 3) {
        tap_code16(KC_V);
    }
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_V); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_V)); break;
        case DOUBLE_TAP: register_code16(KC_V); register_code16(KC_V); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_V); register_code16(KC_V);
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_V); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_V)); break;
        case DOUBLE_TAP: unregister_code16(KC_V); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_V); break;
    }
    dance_state[2].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
};
