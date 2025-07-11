// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Toggle for 12-key backlight
static bool backlight_on = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐  ┌───┐
     * │ 1 │ 2 │ 3 │ 4 │ ││DF1││
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
    /*
     * ┌───┬───┬───┬───┐  ┌───┐
     * │ Q │ W │ E │ R │ ││DF2││
     * ├───┼───┼───┼───┤  └───┘ 
     * │ A │ S │ D │ F │
     * ├───┼───┼───┼───┤
     * │ Z │ X │ C │ F │
     * └───┴───┴───┴───┘ 
    */
    [1] = LAYOUT(
        KC_Q,   KC_W,   KC_E,   KC_R, DF(2),
        KC_A,   KC_S,   KC_D,   KC_F,
        KC_Z,   KC_X,   KC_C,   KC_F
    ),
    /*
     * ┌───┬───┬───┬───┐  ┌───┐
     * │ CP│CAL│SLP│HOM│ ││DF0││
     * ├───┼───┼───┼───┤  └───┘ 
     * │MUT│MPL│SEL│WSC│
     * ├───┼───┼───┼───┤
     * │F13│F14│F15│F16│
     * └───┴───┴───┴───┘ 
    */
    [2] = LAYOUT(
        KC_CONTROL_PANEL,   KC_CALC,   KC_SYSTEM_SLEEP,   KC_HOME, DF(0),
        KC_MUTE,            KC_MPLY,   KC_MSEL,           KC_WSCH,
        KC_F13,             KC_F14,    KC_F15,            KC_F16
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == KC_F13 && record->event.pressed) {
        backlight_on = !backlight_on;
        return false;
    }
    return true;
}

bool rgb_matrix_indicators_user(void) {
    // Toggle backlight for 12 key LEDs
    for (int i = 0; i < 12; i++) {
        if (backlight_on) {
            rgb_matrix_set_color(i, 120, 80, 40); // amber color
        } else {
            rgb_matrix_set_color(i, 0, 0, 0);     // off
        }
    }

    // Turn off all status LEDs first
    rgb_matrix_set_color(12, 0, 0, 0);
    rgb_matrix_set_color(13, 0, 0, 0);
    rgb_matrix_set_color(14, 0, 0, 0);

    // Amber indicates the layer selected, pastel orange to count
    switch (get_highest_layer(layer_state)) {
        case 0:
            rgb_matrix_set_color(12, 255, 191, 0);   // Amber
            break;
        case 1:
            rgb_matrix_set_color(12, 255, 192, 103); // Pastel Orange
            rgb_matrix_set_color(13, 255, 191, 0);   // Amber 
            break;
        case 2:
            rgb_matrix_set_color(12, 255, 192, 103); // Pastel Orange
            rgb_matrix_set_color(13, 255, 192, 103); // Pastel Orange
            rgb_matrix_set_color(14, 255, 191, 0);   // Amber
            break;
        default:
            break;
    }

    return true;
}

// EC11 Rotary Encoder  
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(RM_VALD, RM_SPDU) },
    [2] = { ENCODER_CCW_CW(RM_HUED, RM_HUEU) } 
};
#endif
