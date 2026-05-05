#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main_screen;
    lv_obj_t *wi_fi_settings_screen;
    lv_obj_t *server_settings_screen;
    lv_obj_t *btn_wi_fi_settings;
    lv_obj_t *obj0;
    lv_obj_t *obj1;
    lv_obj_t *obj2;
    lv_obj_t *arc_set_temperature;
    lv_obj_t *btn_server_settings;
    lv_obj_t *obj3;
    lv_obj_t *label_temperature;
    lv_obj_t *wifi_settings_label;
    lv_obj_t *password_text;
    lv_obj_t *wifi_settings_keyboard;
    lv_obj_t *wifi_back_button;
    lv_obj_t *wifi_ok_button;
    lv_obj_t *wifi_connect_spinner;
    lv_obj_t *ssid_list;
    lv_obj_t *server_settings_label;
    lv_obj_t *server_settings_back_button;
    lv_obj_t *server_settings_ok_button;
    lv_obj_t *mqtt_server_addr_text;
    lv_obj_t *mqtt_user_name_text;
    lv_obj_t *mqtt_password_text;
    lv_obj_t *server_settigs_keyboard;
    lv_obj_t *firmware_update_addr;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_MAIN_SCREEN = 1,
    SCREEN_ID_WI_FI_SETTINGS_SCREEN = 2,
    SCREEN_ID_SERVER_SETTINGS_SCREEN = 3,
};

void create_screen_main_screen();
void tick_screen_main_screen();

void create_screen_wi_fi_settings_screen();
void tick_screen_wi_fi_settings_screen();

void create_screen_server_settings_screen();
void tick_screen_server_settings_screen();

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/