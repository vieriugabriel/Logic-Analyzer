#include "i2c_capture.h"
#include "i2c_capture.pio.h"
#include <stdio.h>

#define SDA_PIN 2
#define SCL_PIN 3

static PIO pio;
static uint sm;

void i2c_capture_init(void){
    pio = pio0;
    sm = 0;

    uint offset = pio_add_program(pio, &i2c_capture_program);
    i2c_capture_program_init(pio, sm, offset, SDA_PIN);

    printf("I2C Capture initialized\n");
    printf("SDA: GPIO%d | SCL: GPIO%d\n", SDA_PIN, SCL_PIN);
}
void i2c_capture_process(void){
    static int byte_count = 0;
    static bool is_first_byte = true;

    while (!pio_sm_is_rx_fifo_empty(pio, sm)){
        uint32_t raw = pio_sm_get(pio, sm);
        printf("RAW: 0x%08X\n", raw);
        uint8_t byte = raw & 0xFF;

        if (is_first_byte) {
            uint8_t addr = byte >> 1;
            uint8_t rw   = byte & 0x01;
            printf("\n--- Pachet nou ---\n");
            printf("START | Adresa: 0x%02X | %s\n",
                   addr, rw ? "READ" : "WRITE");
            is_first_byte = false;
            byte_count = 0;
        } else {
            printf("DATA  | Byte %d: 0x%02X (%d)\n",
                   byte_count++, byte, byte);
            
            if (byte_count >= 10) {
                is_first_byte = true;
            }
    }
    }
}