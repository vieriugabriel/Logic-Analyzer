#ifndef I2C_CAPTURE_H
#define I2C_CAPTURE_H

#include "hardware/pio.h"

void i2c_capture_init(void);
void i2c_capture_process(void);

#endif