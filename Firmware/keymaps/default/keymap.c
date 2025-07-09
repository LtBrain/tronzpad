// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐  ┌───┐
     * │ 1 │ 2 │ 3 │ 4 │ ││ E ││
     * ├───┼───┼───┼───┤  └───┘ 
     * │ 5 │ 6 │ 7 │ 8 │
     * ├───┼───┼───┼───┤
     * │ 9 │ 0 │SPC│ENT│
     * └───┴───┴───┴───┘ 
    
     */
    [0] = LAYOUT(
        KC_1,   KC_2,   KC_3,   KC_4, DF(1),
        KC_5,   KC_6,   KC_7,   KC_8,
        KC_9,   KC_0,   KC_SPC, KC_ENTER
    ),
    [1] = LAYOUT(
        KC_Q,   KC_W,   KC_E,   KC_R, DF(0),
        KC_A,   KC_S,   KC_D,   KC_F,
        KC_Z,   KC_X,   KC_C,   KC_F
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(UG_PREV, UG_NEXT) }
};
#endif
