#include "wifi_server.h"
#include "pico/stdlib.h"
#include "i2c_capture.h"

int main(){
    stdio_init_all();
    sleep_ms(2000);
    printf("Logic Analyzer Start\n");
    wifi_server_init();
    i2c_capture_init();
    while(1){
        i2c_capture_process();
        cyw43_arch_poll();
    }
    return 0;
}