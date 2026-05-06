#ifndef WIFI_STA_H
#define WIFI_STA_H

#include <stdint.h>
#include <stdbool.h>

void wifi_init(void);
void wifi_scan_start(void);
void wifi_connect(const char *ssid, const char *password);

#endif // WIFI_STA_H
