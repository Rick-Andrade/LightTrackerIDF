#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"
#include "freertos/event_groups.h"
#include "esp_wifi.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "esp_netif.h"
#include "esp_http_client.h"
#include "esp_http_server.h"


#define WEB_SERVER_LOCAL "192.168.0.251"
#define WEB_PORT_LOCAL "1880"
#define WEB_PATH "/"
#define END_POINT "api-form"

esp_err_t client_event_get_handler(esp_http_client_event_handle_t evt);

/**
 * @brief Do the GET method in a server
 * 
 * @param value Value to be send
 */
void rest_get(const char* value);

#endif