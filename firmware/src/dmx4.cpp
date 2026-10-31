#include "common.h"

SPIClass spi1(PA7, PA6, PA5);
W5500 eth{&spi1, PB12, PB14};

HardwareSerial u[4] = {
    HardwareSerial(PA10, PA9), // USART1
    HardwareSerial(PA3, PA2),   // USART2
    HardwareSerial(PB11, PB10), // USART3
    HardwareSerial(PA1, PA0)    // USART4
};

// MAX3485 DE / RE (bei 1 und 2 auf geimeinsamen pin)
const uint32_t DE[4] = {PB2, PA4, PB1, PA15};
const uint32_t RE[4] = {PB2, PA4, PB15, PA8};
uint8_t frame[512];

void setup() {
    testBegin();
    for (int i = 0; i < 4; i++) {
        pinMode(DE[i], OUTPUT); digitalWrite(DE[i], HIGH); // Treiber an
        pinMode(RE[i], OUTPUT); digitalWrite(RE[i], HIGH); // Empfänger aus
    }
    eth.init();
    eth.report("W5500");
}

void loop() {
    static uint32_t last;
    for (int i = 0; i < 4; i++) {
        memset(frame, ((millis() / 8) + i * 64) & 0xFF, sizeof(frame)); // Sägezahn Testmuster versetzt
        dmxSend(u[i], frame);
    }
    if (millis() - last > 1000) {
        last = millis();
        eth.report("W5500");
    }
    delay(5);
}