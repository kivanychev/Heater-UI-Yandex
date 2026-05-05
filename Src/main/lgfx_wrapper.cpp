// lgfx_wrapper.cpp
#include "LovyanGFX.hpp" // LovyanGFX header

#include "esp_log.h"
#include "lgfx_wrapper.h"

#include "ui/ui.h"

class LGFX : public lgfx::LGFX_Device
{
  lgfx::Panel_ST7796 _panel_instance;
  lgfx::Bus_Parallel8 _bus_instance;
  lgfx::Light_PWM _light_instance;
  lgfx::Touch_FT5x06 _touch_instance;

public:
  LGFX(void)
  {
    {
      auto cfg = _bus_instance.config();
      cfg.freq_write = 40000000;
      cfg.pin_wr = 47;
      cfg.pin_rd = -1;
      cfg.pin_rs = 0;
      cfg.pin_d0 = 9;
      cfg.pin_d1 = 46;
      cfg.pin_d2 = 3;
      cfg.pin_d3 = 8;
      cfg.pin_d4 = 18;
      cfg.pin_d5 = 17;
      cfg.pin_d6 = 16;
      cfg.pin_d7 = 15;
      _bus_instance.config(cfg);
      _panel_instance.setBus(&_bus_instance);
    }

    {
      auto cfg = _panel_instance.config();
      cfg.pin_cs = -1;
      cfg.pin_rst = 4;
      cfg.pin_busy = -1;
      cfg.memory_width = 320;
      cfg.memory_height = 480;
      cfg.panel_width = 320;
      cfg.panel_height = 480;
      cfg.offset_x = 0;
      cfg.offset_y = 0;
      cfg.offset_rotation = 0;
      cfg.dummy_read_pixel = 8;
      cfg.dummy_read_bits = 1;
      cfg.readable = true;
      cfg.invert = true;
      cfg.rgb_order = false;
      cfg.dlen_16bit = false;
      cfg.bus_shared = true;

      _panel_instance.config(cfg);
    }

    {
      auto cfg = _light_instance.config();
      cfg.pin_bl = 45;
      cfg.invert = false;
      cfg.freq = 44100;
      cfg.pwm_channel = 7;

      _light_instance.config(cfg);
      _panel_instance.setLight(&_light_instance);
    }

    {
      auto cfg = _touch_instance.config();
      cfg.i2c_port = 1;
      cfg.i2c_addr = 0x38;
      cfg.pin_sda = 6;
      cfg.pin_scl = 5;
      cfg.freq = 400000;
      cfg.x_min = 0;
      cfg.x_max = 320;
      cfg.y_min = 0;
      cfg.y_max = 480;

      _touch_instance.config(cfg);
      _panel_instance.setTouch(&_touch_instance);
    }

    setPanel(&_panel_instance);
  }

};
static LGFX tft;



extern "C" void lgfx_init_display() {
    uint16_t calibr_values[] = { 275, 3659, 258, 178, 3801, 3648, 3791, 161};

    tft.init();
    tft.setRotation(1);

// Calibration code that runs a calibration code on the screen that asks the user to press corners
//   uint16_t fg = TFT_WHITE;
//   uint16_t bg = TFT_BLACK;
//   if (tft.isEPD()) std::swap(fg, bg);
//   tft.calibrateTouch(&calibr_values[0], fg, bg, std::max(tft.width(), tft.height()) >> 3);
//   ESP_LOGI("TFT", "Calibr: %d, %d, %d, %d, %d, %d, %d, %d", calibr_values[0], calibr_values[1], calibr_values[2], 
//                                                             calibr_values[3], calibr_values[4], calibr_values[5], 
//                                                             calibr_values[6], calibr_values[7]);


// Use calibration data array
//    tft.setTouchCalibrate(&calibr_values[0]);


    tft.fillScreen(TFT_ORANGE);
    
    // Text parameters
    tft.setTextColor(TFT_BLACK, TFT_ORANGE);  
    tft.setTextSize(2);
    tft.setTextFont(1);
    
    // Центрируем текст
    int x = (tft.width() - tft.textWidth("Smart Home panel")) / 2;
    int y = (tft.height() - tft.fontHeight()) / 2;
    
    tft.drawString("Smart Home panel", x, y);
    
    // Обновите экран (если используется двойная буферизация)
    tft.display();
}




/* Display flushing */
extern "C" void lgfx_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

  tft.startWrite();
  tft.setAddrWindow(area->x1, area->y1, w, h);
  tft.writePixels((lgfx::rgb565_t *)&color_p->full, w * h);
  tft.endWrite();

  lv_disp_flush_ready(disp);
}




/*Read the touchpad*/
extern "C" void lgfx_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data)
{
  uint16_t x, y;
  if (tft.getTouch(&x, &y))
  {
    data->state = LV_INDEV_STATE_PR;
    data->point.x = x;
    data->point.y = y;

    ESP_LOGI("TOUCH", "x=%d, y=%d", x, y);
  }
  else
  {
    data->state = LV_INDEV_STATE_REL;
  }
}
