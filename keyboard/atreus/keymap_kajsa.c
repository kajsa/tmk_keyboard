#include "keymap_common.h"

/* This layout is designed to be used on machines where the OS is */
/* already set to a dvorak layout. It assumes that the dvorak mapping */
/* will be happening in the OS and sends "un-dvorakized" */
/* keycodes. (So it sends qwerty letters, but specially-shuffled */
/* punctuation.)  This is helpful for laptops where you want to be */
/* able to use the internal keyboard in dvorak without having to */
/* change the OS mappings. */

/* This is an older variant of the multidvorak layout that has
   dual-use modifiers.*/

#define PWM ACTION_MODS_KEY(MOD_LGUI, KC_BSLS)
#define PWW ACTION_MODS_KEY(MOD_LCTL, KC_BSLS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: qwerty */
  KEYMAP(KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, \
         KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, \
         KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, \
         KC_TAB, KC_FN9, KC_FN10, KC_FN1, KC_BSPC, KC_FN7, \
         // KC_MINS and KC_LBRC are inverse-dvorakized
	 KC_FN8, KC_FN10, KC_FN2, KC_QUOT, KC_LBRC, KC_ESC), \
  /* 1: numbers and un-dvoraked symbols */
  KEYMAP(KC_6, KC_7, KC_8, KC_9, KC_0, \
         SHIFT(KC_RBRC), SHIFT(KC_MINUS), SHIFT(KC_EQUAL), SHIFT(KC_7), SHIFT(KC_8), \
         KC_1, KC_2, KC_3, KC_4, KC_5, \
         SHIFT(KC_QUOT), SHIFT(KC_9), SHIFT(KC_0), KC_MINUS, KC_EQUAL, \
         SHIFT(KC_6), SHIFT(KC_2), SHIFT(KC_3), SHIFT(KC_4), SHIFT(KC_5), \
         SHIFT(KC_1), KC_RBRC, SHIFT(KC_RBRC), SHIFT(KC_BSLS), KC_BSLS, \
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
	 KC_TRNS, KC_TRNS, KC_TRNS, KC_GRAVE, SHIFT(KC_GRAVE), KC_FN3), \
  /* 2: arrows and function keys */
  KEYMAP(KC_INS, KC_TRNS, KC_UP, KC_TRNS, KC_PGUP, KC_TRNS, KC_F9, KC_F10, KC_F11, KC_F12, \
         KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, KC_TRNS, KC_F5, KC_F6, KC_F7, KC_F8, \
         KC_TRNS, KC_TRNS, KC_HOME, KC_END, PWW, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, \
         SHIFT(KC_TAB), KC_TRNS, KC_TRNS, KC_TRNS, KC_DELETE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_FN0), \
  /* 3: hard dvorak */
  KEYMAP(KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, \
         KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, \
         KC_SCLN, KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, \
         KC_TRNS, KC_TRNS, KC_TRNS, KC_FN4, KC_BSPC, KC_TRNS, \
	 KC_TRNS, KC_TRNS, KC_FN5, KC_MINS, KC_SLASH, KC_ESC), \

  /* 4: hard dvorak symbols & numbers */
  KEYMAP(KC_6, KC_7, KC_8, KC_9, KC_0, \
	 SHIFT(KC_SLASH), SHIFT(KC_LBRC), SHIFT(KC_RBRC), SHIFT(KC_7), SHIFT(KC_8), \
         KC_1, KC_2, KC_3, KC_4, KC_5, \
	 KC_MINUS, SHIFT(KC_9), SHIFT(KC_0), KC_LBRC, KC_RBRC, \
         SHIFT(KC_6), SHIFT(KC_2), SHIFT(KC_3), SHIFT(KC_4), SHIFT(KC_5), \
         SHIFT(KC_1), KC_EQUAL, SHIFT(KC_EQUAL), SHIFT(KC_BSLS), KC_BSLS, \
         KC_TRNS, KC_TRNS, KC_TRNS, KC_FN4, KC_TRNS, KC_TRNS, \
	 KC_TRNS, KC_TRNS, KC_FN5, KC_GRAVE, SHIFT(KC_GRAVE), KC_FN6), \

  /* 5: hard dvorak navigation and function keys */
  KEYMAP(KC_INS, KC_TRNS, KC_UP, KC_TRNS, KC_PGUP, KC_TRNS, KC_F9, KC_F10, KC_F11, KC_F12, \
         KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, KC_TRNS, KC_F5, KC_F6, KC_F7, KC_F8, \
         KC_TRNS, KC_TRNS, KC_HOME, KC_END, PWM, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, \
         SHIFT(KC_TAB), KC_TRNS, KC_TRNS, KC_TRNS, KC_DELETE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_FN0) 
};

  const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_FUNCTION(BOOTLOADER),
  [1] = ACTION_LAYER_TAP_KEY(1, KC_SPC),  // to layer 1 while held, space when tapped
  [2] = ACTION_LAYER_TAP_KEY(2, KC_SPC),  // to layer 2 while held, space when tapped
  [3] = ACTION_LAYER_ON(3, 1),  // to hard dvorak
  [4] = ACTION_LAYER_TAP_KEY(4, KC_SPC),  // to hard dvorak's fn
  [5] = ACTION_LAYER_TAP_KEY(5, KC_SPC),  // switch to layer 2 hard
  [6] = ACTION_LAYER_OFF(3, 1), // to soft dvorak

  [7] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_DELETE),
  [8] = ACTION_MODS_TAP_KEY(MOD_LALT, KC_ENT),
  [9] = ACTION_MODS_TAP_KEY(MOD_LGUI, KC_SPC),
  [10] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_SPC),
  };

  void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
  {
  if (id == BOOTLOADER) {
  bootloader();
  }
  }
