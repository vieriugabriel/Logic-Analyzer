#include <Arduino.h>
#include <Wire.h>

const int MPU = 0x68;

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);

  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0x00);
  Wire.endTransmission(true);

  Serial.println("MPU6050 initialized");
}

void loop() {
 Wire.beginTransmission(MPU);
 Wire.write(0x3B);
 Wire.endTransmission(false);
 Wire.requestFrom(MPU,6,true);

 int16_t ax =Wire.read() << 8 | Wire.read();
 int16_t ay =Wire.read() << 8 | Wire.read();
 int16_t az =Wire.read() << 8 | Wire.read();
 
 Serial.printf("AX: %d AY: %d AZ: %d\n",ax, ay, az);
 delay(100);
}
