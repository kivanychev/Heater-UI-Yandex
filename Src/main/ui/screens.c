#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;
uint32_t active_theme_index = 0;

static lv_meter_scale_t * scale0;

void create_screen_main_screen() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 320);
    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xffe6e6e6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff806d55), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // Btn_WiFi_settings
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_wi_fi_settings = obj;
            lv_obj_set_pos(obj, 12, 235);
            lv_obj_set_size(obj, 203, 68);
            lv_obj_add_event_cb(obj, action_main_wi_fi_settings_pressed, LV_EVENT_CLICKED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffece2d8), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 40, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff312f2f), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    lv_obj_set_pos(obj, -14, -20);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_wi_fi_small);
                    lv_img_set_pivot(obj, 0, 0);
                    lv_img_set_zoom(obj, 70);
                    lv_obj_set_style_img_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj0 = obj;
                    lv_obj_set_pos(obj, 21, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff523c35), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "settings");
                }
            }
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj1 = obj;
            lv_obj_set_pos(obj, 240, 11);
            lv_obj_set_size(obj, 228, 208);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfffffaf4), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff605959), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_meter_create(parent_obj);
                    objects.obj2 = obj;
                    lv_obj_set_pos(obj, 20, 8);
                    lv_obj_set_size(obj, 157, 156);
                    {
                        lv_meter_scale_t *scale = lv_meter_add_scale(obj);
                        scale0 = scale;
                        lv_meter_set_scale_ticks(obj, scale, 41, 1, 5, lv_color_hex(0xff523c35));
                        lv_meter_set_scale_major_ticks(obj, scale, 5, 2, 8, lv_color_hex(0xff523c35), 10);
                        lv_meter_set_scale_range(obj, scale, 0, 40, 300, 120);
                    }
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xfffffaf4), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff523c35), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_opa(obj, 255, LV_PART_TICKS | LV_STATE_DEFAULT);
                    lv_obj_set_style_blend_mode(obj, LV_BLEND_MODE_REPLACE, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                }
                {
                    // Arc_SetTemperature
                    lv_obj_t *obj = lv_arc_create(parent_obj);
                    objects.arc_set_temperature = obj;
                    lv_obj_set_pos(obj, 20, 8);
                    lv_obj_set_size(obj, 157, 162);
                    lv_arc_set_range(obj, 0, 40);
                    lv_arc_set_value(obj, 20);
                    lv_arc_set_bg_start_angle(obj, 120);
                    lv_arc_set_bg_end_angle(obj, 60);
                    lv_obj_add_event_cb(obj, action_set_temperature, LV_EVENT_VALUE_CHANGED, (void *)0);
                    lv_obj_set_style_arc_color(obj, lv_color_hex(0xffd3c6c1), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_color(obj, lv_color_hex(0xffec8260), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff954918), LV_PART_KNOB | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_Server_settings
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_server_settings = obj;
            lv_obj_set_pos(obj, 240, 235);
            lv_obj_set_size(obj, 228, 68);
            lv_obj_add_event_cb(obj, action_main_server_settings_pressed, LV_EVENT_CLICKED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffece2d8), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff312f2f), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    lv_obj_set_pos(obj, -59, -75);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_server_bmp);
                    lv_img_set_zoom(obj, 100);
                    lv_obj_set_style_img_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj3 = obj;
                    lv_obj_set_pos(obj, 43, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff523c35), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Server settings");
                }
            }
        }
        {
            // Label_Temperature
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_temperature = obj;
            lv_obj_set_pos(obj, 0, 53);
            lv_obj_set_size(obj, 230, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_bebas_120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "23°C");
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 5, 5);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_wifi_no_bmp);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 5, 5);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_wifi_25_bmp);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 5, 5);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_wifi_50_bmp);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 5, 5);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_wifi_75_bmp);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 5, 5);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_wifi_100_bmp);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
        }
    }
    
    tick_screen_main_screen();
}

void tick_screen_main_screen() {
}

void create_screen_wi_fi_settings_screen() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.wi_fi_settings_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 320);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff806d55), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xffe6e6e6), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // wifi_settings_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.wifi_settings_label = obj;
            lv_obj_set_pos(obj, 192, 17);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "WiFi settings");
        }
        {
            // password_text
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.password_text = obj;
            lv_obj_set_pos(obj, 247, 77);
            lv_obj_set_size(obj, 224, 40);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_placeholder_text(obj, "PASSWORD");
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, action_wi_fi_settings_keyboard, LV_EVENT_DEFOCUSED, (void *)0);
            lv_obj_add_event_cb(obj, action_wi_fi_settings_keyboard, LV_EVENT_FOCUSED, (void *)0);
        }
        {
            // wifi_settings_keyboard
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.wifi_settings_keyboard = obj;
            lv_obj_set_pos(obj, 0, 151);
            lv_obj_set_size(obj, 480, 169);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // wifi_back_button
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.wifi_back_button = obj;
            lv_obj_set_pos(obj, 10, 7);
            lv_obj_set_size(obj, 70, 37);
            lv_obj_add_event_cb(obj, action_wi_fi_settings_back_pressed, LV_EVENT_CLICKED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffece2d8), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff362626), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff494242), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "<<");
                }
            }
        }
        {
            // wifi_ok_button
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.wifi_ok_button = obj;
            lv_obj_set_pos(obj, 401, 7);
            lv_obj_set_size(obj, 70, 37);
            lv_obj_add_event_cb(obj, action_wi_fi_settings_ok_pressed, LV_EVENT_CLICKED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffece2d8), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff362626), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "OK");
                }
            }
        }
        {
            // wifi_connect_spinner
            lv_obj_t *obj = lv_spinner_create(parent_obj, 1000, 60);
            objects.wifi_connect_spinner = obj;
            lv_obj_set_pos(obj, 173, 108);
            lv_obj_set_size(obj, 134, 128);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_arc_color(obj, lv_color_hex(0xffe8aa5c), LV_PART_INDICATOR | LV_STATE_DEFAULT);
        }
        {
            // ssid_list
            lv_obj_t *obj = lv_dropdown_create(parent_obj);
            objects.ssid_list = obj;
            lv_obj_set_pos(obj, 10, 77);
            lv_obj_set_size(obj, 220, LV_SIZE_CONTENT);
            lv_dropdown_set_options(obj, "");
            lv_dropdown_set_selected(obj, 0);
        }
    }
    
    tick_screen_wi_fi_settings_screen();
}

void tick_screen_wi_fi_settings_screen() {
}

void create_screen_server_settings_screen() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.server_settings_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 320);
    lv_obj_add_event_cb(obj, action_server_settings_ok_pressed, LV_EVENT_CLICKED, (void *)0);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff806d55), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xffe6e6e6), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // server_settings_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.server_settings_label = obj;
            lv_obj_set_pos(obj, 181, 16);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Server settings");
        }
        {
            // server_settings_back_button
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.server_settings_back_button = obj;
            lv_obj_set_pos(obj, 6, 6);
            lv_obj_set_size(obj, 70, 37);
            lv_obj_add_event_cb(obj, action_server_settings_back_pressed, LV_EVENT_CLICKED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffece2d8), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff362626), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff494242), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "<<");
                }
            }
        }
        {
            // server_settings_ok_button
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.server_settings_ok_button = obj;
            lv_obj_set_pos(obj, 404, 6);
            lv_obj_set_size(obj, 70, 37);
            lv_obj_add_event_cb(obj, action_server_settings_ok_pressed, LV_EVENT_CLICKED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffece2d8), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff362626), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "OK");
                }
            }
        }
        {
            // mqtt_server_addr_text
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.mqtt_server_addr_text = obj;
            lv_obj_set_pos(obj, 6, 50);
            lv_obj_set_size(obj, 468, 40);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_placeholder_text(obj, "MQTT server address");
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, action_server_settings_keyboard, LV_EVENT_DEFOCUSED, (void *)0);
            lv_obj_add_event_cb(obj, action_server_settings_keyboard, LV_EVENT_FOCUSED, (void *)0);
        }
        {
            // mqtt_user_name_text
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.mqtt_user_name_text = obj;
            lv_obj_set_pos(obj, 7, 95);
            lv_obj_set_size(obj, 230, 40);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_placeholder_text(obj, "MQTT user name");
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, action_server_settings_keyboard, LV_EVENT_DEFOCUSED, (void *)0);
            lv_obj_add_event_cb(obj, action_server_settings_keyboard, LV_EVENT_FOCUSED, (void *)0);
        }
        {
            // mqtt_password_text
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.mqtt_password_text = obj;
            lv_obj_set_pos(obj, 240, 95);
            lv_obj_set_size(obj, 234, 40);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_placeholder_text(obj, "MQTT user password");
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, action_server_settings_keyboard, LV_EVENT_DEFOCUSED, (void *)0);
            lv_obj_add_event_cb(obj, action_server_settings_keyboard, LV_EVENT_FOCUSED, (void *)0);
        }
        {
            // server_settigs_keyboard
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.server_settigs_keyboard = obj;
            lv_obj_set_pos(obj, 0, 183);
            lv_obj_set_size(obj, 480, 137);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // firmware_update_addr
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.firmware_update_addr = obj;
            lv_obj_set_pos(obj, 7, 139);
            lv_obj_set_size(obj, 467, 40);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_placeholder_text(obj, "Firmware update server IP address");
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, action_server_settings_keyboard, LV_EVENT_DEFOCUSED, (void *)0);
            lv_obj_add_event_cb(obj, action_server_settings_keyboard, LV_EVENT_FOCUSED, (void *)0);
        }
    }
    
    tick_screen_server_settings_screen();
}

void tick_screen_server_settings_screen() {
}



typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main_screen,
    tick_screen_wi_fi_settings_screen,
    tick_screen_server_settings_screen,
};
void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen_funcs[screenId - 1]();
}

void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main_screen();
    create_screen_wi_fi_settings_screen();
    create_screen_server_settings_screen();
}
