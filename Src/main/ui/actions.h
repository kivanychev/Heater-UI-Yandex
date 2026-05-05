#ifndef EEZ_LVGL_UI_EVENTS_H
#define EEZ_LVGL_UI_EVENTS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void action_set_temperature(lv_event_t * e);
extern void action_main_wi_fi_settings_pressed(lv_event_t * e);
extern void action_main_server_settings_pressed(lv_event_t * e);
extern void action_wi_fi_settings_ok_pressed(lv_event_t * e);
extern void action_wi_fi_settings_back_pressed(lv_event_t * e);
extern void action_wi_fi_settings_keyboard(lv_event_t * e);
extern void action_server_settings_keyboard(lv_event_t * e);
extern void action_server_settings_ok_pressed(lv_event_t * e);
extern void action_server_settings_back_pressed(lv_event_t * e);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_EVENTS_H*/