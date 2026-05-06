/*
 * SPDX-FileCopyrightText: 2021-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <string.h>
#include <stdio.h>
#include "sdkconfig.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "esp_timer.h"

#include "lvgl.h"
#include "lgfx_wrapper.h"
#include "lv_examples.h"

#include "ui.h"
#include "actions.h"

#include "wifi_sta.h"

//====================================================================================
// VARIABLES
//====================================================================================

static TaskHandle_t s_task_handle;
static const char *TAG = "EXAMPLE";

// UI
static lv_disp_draw_buf_t   draw_buf;
static lv_color_t           buf[DISP_WIDTH * DISP_HEIGHT / 10]; /*Declare a buffer for 1/10 screen size*/

//====================================================================================
// UI
//====================================================================================

void action_set_temperature(lv_event_t *e) {
    // TODO: Implement action set_temperature here
}

//////////////////////
// Main Screen actions
//////////////////////

void action_main_wi_fi_settings_pressed(lv_event_t *e) {
    // Show WiFi Settings screen
    loadScreen(SCREEN_ID_WI_FI_SETTINGS_SCREEN);
}

void action_main_server_settings_pressed(lv_event_t *e) {
    // Show Server Settings screen
    loadScreen(SCREEN_ID_SERVER_SETTINGS_SCREEN);

}

///////////////////////////////
// WiFi Settings screen actions
///////////////////////////////

void action_wi_fi_settings_back_pressed(lv_event_t *e) {
    // Back to Main screen
    loadScreen(SCREEN_ID_MAIN_SCREEN);
}

void action_wi_fi_settings_ok_pressed(lv_event_t *e) {
    // Get selected SSID from dropdown
    char ssid[33] = {0};
    lv_dropdown_get_selected_str(objects.ssid_list, ssid, sizeof(ssid));
    
    // Get password from text area
    const char *password = lv_textarea_get_text(objects.password_text);
    
    // Show spinner (hide was already done in screens.c creation with LV_OBJ_FLAG_HIDDEN)
    lv_obj_clear_flag(objects.wifi_connect_spinner, LV_OBJ_FLAG_HIDDEN);
    
    // Start WiFi connection
    wifi_connect(ssid, password);
}

void action_wi_fi_settings_keyboard(lv_event_t *e) 
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    lv_obj_t * kb = objects.wifi_settings_keyboard;

    if(code == LV_EVENT_FOCUSED) {
        lv_keyboard_set_textarea(kb, ta);
        lv_obj_clear_flag(kb, LV_OBJ_FLAG_HIDDEN);
    }

    if(code == LV_EVENT_DEFOCUSED) {
        lv_keyboard_set_textarea(kb, NULL);
        lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
    }
}

/////////////////////////////////
// Server Settings screen actions
/////////////////////////////////

void action_server_settings_keyboard(lv_event_t *e) 
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    lv_obj_t * kb = objects.server_settigs_keyboard;

    if(code == LV_EVENT_FOCUSED) {
        lv_keyboard_set_textarea(kb, ta);
        lv_obj_clear_flag(kb, LV_OBJ_FLAG_HIDDEN);
    }

    if(code == LV_EVENT_DEFOCUSED) {
        lv_keyboard_set_textarea(kb, NULL);
        lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
    }
    
}

void action_server_settings_ok_pressed(lv_event_t *e) {
    // TODO: Implement action server_settings_ok_pressed here
}

void action_server_settings_back_pressed(lv_event_t *e) {
    // Back to Main screen
    loadScreen(SCREEN_ID_MAIN_SCREEN);
}


//====================================================================================
// MAIN
//====================================================================================

static esp_timer_handle_t lvgl_tick_timer;

static void lvgl_tick_cb(void *arg) 
{
    lv_tick_inc(10);  // Tick LVGL by 10ms
}




void app_main(void)
{   
    // Initialize graphical libraries
    lgfx_init_display();
    lv_init();
    lv_disp_draw_buf_init(&draw_buf, buf, NULL, DISP_WIDTH * DISP_HEIGHT / 10);  /*Initialize the display buffer.*/

    // Initialize the display
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);

    /*Change the following line to your display resolution*/
    disp_drv.hor_res = DISP_WIDTH;
    disp_drv.ver_res = DISP_HEIGHT;
    disp_drv.flush_cb = lgfx_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);

    /*Initialize the input device driver - Touchpad*/
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = lgfx_touchpad_read;
    lv_indev_drv_register(&indev_drv);

    // Configure LVGL Tick timer
    // lv_tick_set_cb(my_tick_get_cb);  // For LVGL 9.x versions

    const esp_timer_create_args_t lvgl_tick_timer_args = {
        .callback = &lvgl_tick_cb,  // Функция, которая будет вызываться
        .name = "lvgl_tick_timer",  // Имя таймера (для отладки)
    };

    // Create timer
    esp_timer_create(&lvgl_tick_timer_args, &lvgl_tick_timer);

    // Start 1ms times
    esp_timer_start_periodic(lvgl_tick_timer, 10000);  // 10 000 us = 10 ms


    ui_init();
    wifi_init();

    while (1) {
        lv_timer_handler();
        vTaskDelay(1);
    }
}
