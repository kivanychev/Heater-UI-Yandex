#ifndef EEZ_LVGL_UI_IMAGES_H
#define EEZ_LVGL_UI_IMAGES_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const lv_img_dsc_t img_server_bmp;
extern const lv_img_dsc_t img_wi_fi_small;
extern const lv_img_dsc_t img_wifi_no_bmp;
extern const lv_img_dsc_t img_wifi_25_bmp;
extern const lv_img_dsc_t img_wifi_50_bmp;
extern const lv_img_dsc_t img_wifi_75_bmp;
extern const lv_img_dsc_t img_wifi_100_bmp;

#ifndef EXT_IMG_DESC_T
#define EXT_IMG_DESC_T
typedef struct _ext_img_desc_t {
    const char *name;
    const lv_img_dsc_t *img_dsc;
} ext_img_desc_t;
#endif

extern const ext_img_desc_t images[7];


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_IMAGES_H*/