/* Copyright 2019 Biacco42
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "meishi2.h"
// ↓これがないとUSキーマップ前提でSEND_STRINGしちゃうので"&"とかがshift押したときの文字入力がおかしくなる
#include "sendstring_jis.h"
#include "./private_data.h"

// Optional override functions below.
// You can leave any or all of these undefined.
// These are only required if you want to perform custom actions.


void matrix_init_kb(void) {
    // put your keyboard start-up code here
    // runs once when the firmware starts up

    matrix_init_user();
}

void matrix_scan_kb(void) {
    // put your looping keyboard code here
    // runs every cycle (a lot)

    matrix_scan_user();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // キーを押してなかったら門前払い
  if (record->event.pressed == false) {
      return false;
  }

  if (KC_MY_KEY_GLOBAL_ID == keycode ){
    dprint("pushed KC_MY_KEY_GLOBAL_ID\n");
    SEND_STRING(PRI_DATA_GLOBAL_ID);
  } else if(KC_MY_KEY_GLOBAL_PASS == keycode ){
    dprint("pushed KC_MY_KEY_GLOBAL_PASS\n");
    SEND_STRING(PRI_DATA_GLOBAL_PASS);
  }else if(KC_MY_KEY_ADMIN_ID == keycode ){
    dprint("pushed KC_MY_KEY_ADMIN_ID\n");
    SEND_STRING(PRI_DATA_ADMIN_ID);
  }else if(KC_MY_KEY_ADMIN_PASS == keycode ){
    dprint("pushed KC_MY_KEY_ADMIN_PASS\n");
    SEND_STRING(PRI_DATA_ADMIN_PASS);
  }

  return true;
}

void led_set_kb(uint8_t usb_led) {
    // put your keyboard LED indicator (ex: Caps Lock LED) toggling code here

    //   led_set_user(usb_led);
}
