#include "wifi_server.h"
#include <stdio.h>
#include <string.h>

#define PORT 8080

static struct tcp_pcb *active_client = NULL;
static err_t client_connected(void *arg, struct tcp_pcb *newpcb, err_t err) {
    printf("Client conectat!\n");
    active_client=newpcb;
    return ERR_OK;
}

void wifi_server_init(void)
{
    cyw43_arch_init();
    cyw43_arch_enable_sta_mode();

    if (cyw43_arch_wifi_connect_timeout_ms(
        WIFI_SSID, 
        WIFI_PASSWORD, 
        CYW43_AUTH_WPA2_AES_PSK, 
        10000) != 0) {
        printf("Wi-Fi connection failed!\n");
        return;
    }
    printf("Connected to Wi-Fi!\n");

    struct tcp_pcb *pcb =tcp_new();
    tcp_bind(pcb, IP_ADDR_ANY, PORT);
    pcb = tcp_listen(pcb);

    tcp_accept(pcb, client_connected);

}
void wifi_server_send(const char* data)
{
    if (active_client == NULL) return;
    tcp_write(active_client, data, strlen(data), TCP_WRITE_FLAG_COPY);
    tcp_output(active_client);
}