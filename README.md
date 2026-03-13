# Logic Analyzer cu Raspberry Pi Pico W

## Descriere
Logic analyzer care capturează și decodează 
comunicația I2C dintre ESP32 și MPU6050.

## Componente
- Raspberry Pi Pico W
- ESP32 WROVER DEV
- MPU6050 (accelerometru + giroscop)

## Etape
- [x] Etapa 1: ESP32 citește MPU6050 via I2C
- [x] Etapa 2: Pico W capturează I2C cu PIO
- [ ] Etapa 3: Streaming Wi-Fi către browser
- [ ] Etapa 4: Dashboard web live

## Tehnologii
- C (Pico SDK + PIO)
- Arduino Framework (ESP32)
- WebSocket
- HTML/CSS/JS
