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
    ADD_KEYS
};

// キーマップの設定
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
        // 左手
        // 天面スイッチ
        KC_ESC,  KC_1,         KC_2,            KC_3, LT(BALL_SETTINGS, KC_4), LT(LIGHT_SETTINGS, KC_5),
        KC_TAB,  KC_Q,         KC_W,            KC_E, KC_R, KC_T,
        KC_LSFT, KC_A,         KC_S,            KC_D, KC_F, KC_G,
                 KC_Z,         KC_X,            KC_C, KC_V, KC_B,
                               KC_BSLS ,
        // 側面スイッチ
        KC_LCTL, MO(MOUSE),               
        // 十字キーorジョイスティック                // ジョイスティックスイッチ
        KC_UP, KC_DOWN, KC_LEFT, KC_RIGHT,         KC_ENT,      
        // 追加スイッチ                             // トグルスイッチ
        KC_MS_BTN2, KC_MS_BTN1,                    MO(ONOFF),
        // 右手
        KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
        KC_Y, KC_U, KC_I,    KC_O,             KC_P,    KC_QUOT,
        KC_H, KC_J, KC_K,    KC_L,             KC_SCLN, KC_SLSH,
        KC_N, KC_M, KC_COMM, KC_DOT,           KC_RBRC,
                             KC_LBRC,
        KC_SPACE, KC_ENT,                   
        KC_UP, KC_DOWN, KC_LEFT, KC_RIGHT,         KC_ENT,     
        KC_RSFT, KC_RCTL  ,                    MO(OFFON)
    ),
    [MOUSE] = LAYOUT(
        KC_LNG1, KC_F1,   KC_F2,   KC_F3, _______,    _______,
        KC_LGUI, _______, _______, KC_EQL,  _______,    _______,
        _______, _______, _______, KC_MS_BTN2, KC_MS_BTN1, _______,
                 _______, _______, _______, _______, _______,
                          _______,
        _______, _______,
        KC_PGUP, KC_PGDN, KC_HOME, KC_END,          _______,
        _______, _______,                            _______,
        _______, _______,    _______, _______, _______, KC_DEL,
        _______, _______,    _______, _______, _______, _______,
        _______, KC_MS_BTN1, KC_MS_BTN2, _______, _______, _______,
        _______, KC_MINS,    _______, _______, _______,
                                   _______,
        _______, _______,
        _______, _______, _______, _______,          _______,
        _______, _______,                            _______
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

