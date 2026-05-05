// lgfx_wrapper.h
#ifndef LGFX_WRAPPER_H
#define LGFX_WRAPPER_H

#define DISP_WIDTH                          480
#define DISP_HEIGHT                         320

#include "stdint.h"
#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

void lgfx_init_display(void);
void lgfx_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p);
void lgfx_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data);

#ifdef __cplusplus
}
#endif

#endif // LGFX_WRAPPER_H
