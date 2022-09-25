#include "httpRequest.h"

#define PHOTOVOLTAIC 6
#define NUMBER_OF_SAMPLES 10



esp_err_t client_event_get_handler(esp_http_client_event_handle_t evt)
{
    switch (evt->event_id)
    {
    case HTTP_EVENT_ON_DATA:
        printf("HTTP_EVENT_ON_DATA: %.*s\n", evt->data_len, (char *)evt->data);
        break;

    default:
        break;
    }
    return ESP_OK;
}

/*static esp_err_t adc_value_get_handler(httpd_req_t *req)
{
    char str [4];
    adcReadAsString(PHOTOVOLTAIC, NUMBER_OF_SAMPLES, str);
    httpd_resp_sendstr(req, str);
    return ESP_OK;
}*/

void rest_get(const char* value)
{
    char str[80];
    strcpy(str, "http://192.168.0.158:1880/api-form?value=");
    strcat(str, value);
    printf("URL: %s", str);
    esp_http_client_config_t config_get = {
        .url = str,
        .method = HTTP_METHOD_GET,
        .cert_pem = NULL,
        .event_handler = client_event_get_handler};
        
    esp_http_client_handle_t client = esp_http_client_init(&config_get);
    esp_http_client_perform(client);
    esp_http_client_cleanup(client);

}

