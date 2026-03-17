#ifndef WIFI_SERVER_H
#define WIFI_SERVER_H

#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "lwip/tcp.h"

void wifi_server_init(void);
void wifi_server_send(const char* data);

#endif