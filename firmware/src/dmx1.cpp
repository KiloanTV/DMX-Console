#include <common.h>

SPIClass spi1(PA7, PA6, PA5);
W5500 eth{&spi1, PB11, PB10};
HardwareSerial dmx(PB11, PB10);     //USART3
const uint32_t DE = PB1, RE = PB15; //MAX3485 DE / RE
uint8_t frame[512];

void setup() {
    testBegin();
    pinMode(DE, OUTPUT); digitalWrite(DE, HIGH); // Treiber an
    pinMode(RE, OUTPUT); digitalWrite(RE, HIGH); // Empfänger aus
    eth.init();
    eth.report("W5500");
}

void loop() {
    static uint32_t last;
    memset(frame, (millis() / 8) & 0xFF, sizeof(frame)); // Sägezahn Testmuster
    dmxSend(dmx, frame);
    if (millis() - last > 1000) {
        last = millis();
        eth.report("W5500");
    }
    delay(5);
}