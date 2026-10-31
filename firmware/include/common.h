#pragma once
#include <Arduino.h>
#include <SPI.h>
#include <stdarg.h>

//Logging über USB-CDC
inline void logf(const char *fmt, ...) {
    char b[128];
    va_list a;
    va_start(a, fmt);
    vsnprintf(b, sizeof(b), fmt, a);
    va_end(a);
    Serial.print(b);
}

inline void testBegin() {
    Serial.begin(115200);
    uint32_t t = millis();
    while (!Serial && millis() - t < 1000) {}
    Serial.println("\n-> Board Test gestartet <-");
}

// W5500 nur chip version und link lesen
struct W5500 {
    SPIClass *spi;
    uint32_t cs, rst;

    uint8_t rd(uint16_t addr) {
        spi->beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
        digitalWrite(cs, LOW);
        spi->transfer(addr >> 8);
        spi->transfer(addr & 0xFF);
        spi->transfer(0x00);
        uint8_t v = spi->transfer(0);
        digitalWrite(cs, HIGH);
        spi->endTransaction();
        return v;
    }

    void init() {
        pinMode(cs, OUTPUT); digitalWrite(cs, HIGH);
        pinMode(rst, OUTPUT); digitalWrite(rst, LOW);
        delay(5);
        digitalWrite(rst, HIGH);
        delay(200);
        spi->begin();
    }

    void report(const char *name) {
        uint8_t ver = rd(0x039);
        uint8_t phy = rd(0x002E);
        logf("%s: Version=0x%02X (%s) Link=%s %s %s\n", name, ver, ver == 0x04 ? "OK" : "FEHLER", 
            (phy & 1) ? "UP" : "DOWN", (phy & 2) ? "100M" : "10M", (phy & 4) ? "Full" : "Half");
    }
};

// DMX512 frame senden (512 Byte)
inline void dmxSend(HardwareSerial &s, const uint8_t *data512) {
    s.begin(90000);
    s.write((uint8_t)0x00);
    s.flush();
    s.begin(250000, SERIAL_8N2);
    s.write((uint8_t)0x00);
    s.write(data512, 512);
    s.flush();
}