// Copyright 2021 Hayashi (@w_vwbw)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "add_keycodes.h"
#include "add_joystick.h"
#include "add_rgblayers.h"

// レイヤー名
enum layer_number {
    BASE = 0,
    ONOFF, OFFON, ONON,                       // トグルスイッチで変更するレイヤー
//    LOWER, UPPER, UTIL,                       // 長押しで変更するレイヤー
    MOUSE, BALL_SETTINGS, LIGHT_SETTINGS, // 自動マウスレイヤー切り替えや設定用のレイヤー
    NAV, SYM, NUM                           // レイヤー切り替え用のレイヤー
};

// キーマップの設定
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
        // 左手
        // 天面スイッチ
        KC_ESC,  KC_1,          KC_2,           KC_3,           LT(BALL_SETTINGS, KC_4),    LT(LIGHT_SETTINGS, KC_5),
        KC_TAB,  KC_Q,          KC_W,           KC_E,           KC_R,                       KC_T,
        KC_LSFT, LGUI_T(KC_A),  LALT_T(KC_S),   LCTL_T(KC_D),   LSFT_T(KC_F),               KC_G,
        KC_Z,    KC_X,          KC_C,           KC_V,           KC_B,                       KC_BSLS ,
        // 側面スイッチ
        MO(MOUSE), LT(NAV, KC_SPACE),               
        // 十字キーorジョイスティック               // ジョイスティックスイッチ
        KC_UP, KC_DOWN, KC_LEFT, KC_RIGHT,      KC_ENT,      
        // 追加スイッチ                           // トグルスイッチ
        KC_MS_BTN2, KC_MS_BTN1,                 MO(ONOFF),
        // 右手
        KC_6, KC_7,             KC_8,           KC_9,           KC_0,                       KC_BSPC,
        KC_Y, KC_U,             KC_I,           KC_O,           KC_P,                       KC_QUOT,
        KC_H, RSFT_T(KC_J),     RCTL_T(KC_K),   RALT_T(KC_L),   RGUI_T(KC_SCLN),            KC_SLSH,
        KC_N, KC_M,             KC_COMM,        KC_DOT,         KC_RBRC,                    KC_LBRC,
        LT(SYM, KC_ENT), LT(NUM, KC_BSPC),                   
        KC_UP, KC_DOWN, KC_LEFT, KC_RIGHT,      KC_ENT,     
        CMD_CTL, MO(MOUSE),                     MO(OFFON)
    ),
    [MOUSE] = LAYOUT(
        //left hand
        KC_GRV,  KC_F1,         KC_F2,          KC_F3,          KC_F4,                      KC_F5,
        KC_CAPS, _______,       _______,        KC_EQL,         WINDOW_RIGHT,               _______,
        _______, _______,       _______,        KC_MS_BTN2,     KC_MS_BTN1,                 _______,
        _______, _______,       _______,        _______,        _______,                    KC_LGUI,
        _______, _______,
        KC_PGUP, KC_PGDN, KC_HOME, KC_END,      _______,
        _______, _______,                       _______,
        //right hand
        KC_F6,   KC_F7,         KC_F8,          KC_F9,          KC_F10,                     KC_DEL,
        REDO,    PASTE,         COPY,           CUT,            UNDO,                       _______,
        _______, KC_MS_BTN1,    KC_MS_BTN2,     WINDOW_LEFT,    _______,                    _______,
        _______, KC_MINS,       _______,        _______,        KC_LNG1,                   KC_LNG5,
        _______, _______,
        _______, _______, _______, _______,     _______,
        _______, _______,                       _______
    ),
    [BALL_SETTINGS] = LAYOUT(
        XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, _______, L_CHMOD,
        XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, CPI_I, XXXXXXX,
        AUTO_MOUSE, XXXXXXX, XXXXXXX, L_ANG_D, L_INV,   L_ANG_I,
                    XXXXXXX, XXXXXXX, XXXXXXX, CPI_D, XXXXXXX,
                             INV_SCRL,
        XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, INV_SCRL,                           XXXXXXX,
        R_CHMOD, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, CPI_I,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        R_ANG_D, R_INV,   R_ANG_I, XXXXXXX, XXXXXXX, AUTO_MOUSE,
        XXXXXXX, CPI_D,   XXXXXXX, XXXXXXX, XXXXXXX,
                                     INV_SCRL,
        XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX,                            XXXXXXX
    ),
    [LIGHT_SETTINGS] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD, RGB_MOD, _______,
        XXXXXXX, RGB_SPI, RGB_VAI, RGB_SAI, RGB_HUI, RGB_TOG,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 RGB_SPD, RGB_VAD, RGB_SAD, RGB_HUD, XXXXXXX,
                          XXXXXXX,
        RGB_MOD, RGB_MOD,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX,                            XXXXXXX,
        _______, RGB_MOD, RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX,
        RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD,
                                   XXXXXXX,
        RGB_MOD, RGB_MOD,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX,                            XXXXXXX
    ),
    [NAV] = LAYOUT(
        // 左手
        // 天面スイッチ
        _______,  _______,      _______,        _______,        _______,                    _______,
        _______,  _______,      _______,        _______,        _______,                    _______,
        _______,  _______,      _______,        _______,        _______,                    _______,
        _______,  _______,      _______,        _______,        _______,                    _______,
        // 側面スイッチh
        _______, _______,               
        // 十字キーorジョイスティック               // ジョイスティックスイッチ
        _______, _______, _______, _______,     _______,      
        // 追加スイッチ                           // トグルスイッチ
        _______, _______,                 _______,
        // 右手
        _______,  _______,      _______,        _______,        _______,                    _______,
        REDO,     PASTE,        COPY,           CUT,            UNDO,                       _______,
        KC_CAPS,  KC_LEFT,      KC_DOWN,        KC_UP,          KC_RGHT,                    _______,
        KC_INS,   KC_HOME,      KC_PGDN,        KC_PGUP,        KC_END,                     _______,
        _______,  _______,                     
        _______,  _______, _______, _______,     _______,
        _______,  _______,                      _______
    ),
    [SYM] = LAYOUT(
        // 左手
        // 天面スイッチ
        _______,  _______,      _______,        _______,        _______,                    _______,
        _______,  LSFT(KC_LBRC),LSFT(KC_7),     LSFT(KC_8),     LSFT(KC_9),                 LSFT(KC_RBRC),
        _______,  LSFT(KC_SCLN),LSFT(KC_4),     LSFT(KC_5),     LSFT(KC_6),                 LSFT(KC_EQL),
        LSFT(KC_GRV), LSFT(KC_1),LSFT(KC_2),    LSFT(KC_3),     LSFT(KC_BSLS),              _______,
        // 側面スイッチh
        LSFT(KC_MINS), LSFT(KC_0),               
        // 十字キーorジョイスティック               // ジョイスティックスイッチ
        _______, _______, _______, _______,     _______,      
        // 追加スイッチ                           // トグルスイッチ
        _______, _______,                 _______,
        // 右手
        _______,  _______,      _______,        _______,        _______,                    _______,
        _______,  _______,      _______,        _______,        _______,                    _______,
        _______,  _______,      _______,        _______,        _______,                    _______,
        _______,  _______,      _______,        _______,        _______,                    _______,
        _______,  _______,                     
        _______,  _______, _______, _______,     _______,
        _______,  _______,                      _______
    ),
    [NUM] = LAYOUT(
        // 左手
        // 天面スイッチ
        _______,  _______,      _______,        _______,        _______,                    _______,
        _______,  KC_LBRC,      KC_7,           KC_8,           KC_9,                       KC_RBRC,
        _______,  KC_SCLN,      KC_4,           KC_5,           KC_6,                       KC_EQL,
        KC_GRV,   KC_1,         KC_2,           KC_3,           KC_BSLS,                    _______,
        // 側面スイッチh
        KC_MINS,  KC_0,               
        // 十字キーorジョイスティック               // ジョイスティックスイッチ
        _______, _______, _______, _______,     _______,      
        // 追加スイッチ                           // トグルスイッチ
        _______, _______,                 _______,
        // 右手
        _______,  _______,      _______,        _______,        _______,                    _______,
        _______,  _______,      _______,        _______,        _______,                    _______,
        _______,  _______,      _______,        _______,        _______,                    _______,
        _______,  _______,      _______,        _______,        _______,                    _______,
        _______,  _______,                     
        _______,  _______, _______, _______,     _______,
        _______,  _______,                      _______
    )

};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [BASE] =   { 
        ENCODER_CCW_CW(KC_ESC, KC_TAB),
        ENCODER_CCW_CW(REDO, UNDO),
        ENCODER_CCW_CW(KC_WH_U, KC_WH_D),
        ENCODER_CCW_CW(KC_WH_D, KC_WH_U),
        ENCODER_CCW_CW(KC_DEL, KC_BSPC),
        ENCODER_CCW_CW(KC_UP, KC_DOWN),
        ENCODER_CCW_CW(KC_WH_U, KC_WH_D),
        ENCODER_CCW_CW(KC_WH_L, KC_WH_R)
    },
    [BALL_SETTINGS] =   { 
        ENCODER_CCW_CW(CPI_I, CPI_D), 
        ENCODER_CCW_CW(L_ANG_I, L_ANG_D), 
        ENCODER_CCW_CW(L_INV, L_CHMOD), 
        ENCODER_CCW_CW(R_ANG_I, R_ANG_D),
        ENCODER_CCW_CW(R_INV, R_CHMOD), 
        ENCODER_CCW_CW(CPI_I, CPI_D), 
        ENCODER_CCW_CW(L_ANG_I, L_ANG_D), 
        ENCODER_CCW_CW(L_INV, L_CHMOD)
    },
    [LIGHT_SETTINGS] =   { 
        ENCODER_CCW_CW(RGB_SPI, RGB_SPD), 
        ENCODER_CCW_CW(RGB_VAI, RGB_VAD), 
        ENCODER_CCW_CW(RGB_SAI, RGB_SAD), 
        ENCODER_CCW_CW(RGB_HUI, RGB_HUD),
        ENCODER_CCW_CW(RGB_SPI, RGB_SPD), 
        ENCODER_CCW_CW(RGB_VAI, RGB_VAD), 
        ENCODER_CCW_CW(RGB_SAI, RGB_SAD), 
        ENCODER_CCW_CW(RGB_HUI, RGB_HUD)
    },
    [NAV] =   { 
        ENCODER_CCW_CW(KC_ESC, KC_TAB),
        ENCODER_CCW_CW(REDO, UNDO),
        ENCODER_CCW_CW(KC_WH_U, KC_WH_D),
        ENCODER_CCW_CW(KC_WH_D, KC_WH_U),
        ENCODER_CCW_CW(KC_DEL, KC_BSPC),
        ENCODER_CCW_CW(KC_UP, KC_DOWN),
        ENCODER_CCW_CW(KC_WH_U, KC_WH_D),
        ENCODER_CCW_CW(KC_WH_L, KC_WH_R)
    },
    [SYM] =   { 
        ENCODER_CCW_CW(KC_ESC, KC_TAB),
        ENCODER_CCW_CW(REDO, UNDO),
        ENCODER_CCW_CW(KC_WH_U, KC_WH_D),
        ENCODER_CCW_CW(KC_WH_D, KC_WH_U),
        ENCODER_CCW_CW(KC_DEL, KC_BSPC),
        ENCODER_CCW_CW(KC_UP, KC_DOWN),
        ENCODER_CCW_CW(KC_WH_U, KC_WH_D),
        ENCODER_CCW_CW(KC_WH_L, KC_WH_R)
    },
    [NUM] =   { 
        ENCODER_CCW_CW(KC_ESC, KC_TAB),
        ENCODER_CCW_CW(REDO, UNDO),
        ENCODER_CCW_CW(KC_WH_U, KC_WH_D),
        ENCODER_CCW_CW(KC_WH_D, KC_WH_U),
        ENCODER_CCW_CW(KC_DEL, KC_BSPC),
        ENCODER_CCW_CW(KC_UP, KC_DOWN),
        ENCODER_CCW_CW(KC_WH_U, KC_WH_D),
        ENCODER_CCW_CW(KC_WH_L, KC_WH_R)
    }
};

// 初期化関係
void matrix_init_user(void) {
    matrix_init_addedjoystick();
}
void keyboard_post_init_user(void) {
    keyboard_post_init_rgblayers();
}

// キースキャン関係
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    process_record_addedkeycodes(keycode, record);
    return true;
}

void matrix_scan_user(void) {
    matrix_scan_addedjoystick();
}

