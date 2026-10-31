// 4x ADC für Fader, 4x Motortreiber (L91105), 4x OLED (2 I2C lines) and Switches

#include "common.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

SPIClass spi1(PA7, PA6, PA5);
W5500 eth{&spi1, PB12, PB14};

TwoWire bus1(PB7, PB6); // OLED 1+2, MCP23017
TwoWire bus2(PB11, PB10); // OLED 3+4
const uint8_t MCP = 0x20; // I2C address of MCP23017
const uint8_t OLED_ADDR[4] = {0x3C, 0x3D, 0x3E, 0x3F}; // I2C addresses of OLEDs

Adafruit_SSD1306 oled[4] = {
    Adafruit_SSD1306(128, 32, &bus1, -1),
    Adafruit_SSD1306(128, 32, &bus1, -1),
    Adafruit_SSD1306(128, 32, &bus2, -1),
    Adafruit_SSD1306(128, 32, &bus2, -1)
};
bool oledOK[4];

const uint32_t Fader[4] = {PA0, PA1, PA2, PA3}; // ADC pins for faders
const uint32_t SPD[4] = {PB4, PB5, PB0, PB1}; // L91105 motor driver pins
const uint32_t DIR[4] = {PC13, PC14, PC15, PF0}; // L9110S IB

void scan(TwoWire &w, const char *name) {
    logf("I2C scan %s: ", name);
    for (uint8_t a = 1; a < 127; a++) {
        w.beginTransmission(a);
        if (w.endTransmission() == 0) {
            logf("0x%02X ", a);
        }
    }
    logf("\n");
}

void mcpWrite(uint8_t r, uint8_t v) {
    bus1.beginTransmission(MCP); busA.write(r); bus1.write(v); bus1.endTransmission();
}

void mcpRead(uint8_t r) {
    bus1.beginTransmission(MCP); bus1.write(r); bus1.endTransmission();
    bus1.requestFrom(MCP, (uint8_t)1);
    return bus1.available() ? bus1.read() : 0xFF;
}

//Motor n kurz in eine Richtung bewegen, dann stoppen
void nudge(int n, bool up) {
    digitalWrite(SPD[n], up ? HIGH : LOW);
    analogWrite(SPD[n], up ? 255 - 90 : 90);
    delay(150);
    digialWrite(DIR[n], LOW);
    analogWrite(SPD[n], 0);
}

void setup() {
    testBegin();
    analogReadResolution(12);
    for (int i = 0; i < 4; i++) {
        pinMode(DIR[i], OUTPUT); digitalWrite(DIR[i], LOW);
        pinMode(SPD[i], OUTPUT); analogWrite(SPD[i], 0);
    }
    bus1.begin(); bus2.begin();
    scan(bus1, "bus1");
    scan(bus2, "bus2");

    for (int i = 0; i < 4; i++) {
        oledOK[i] = oled[i].begin(SSD1306_SWITCHCAPVCC, OLED_ADDR[i]);
        logf("OLED %d @0x%s\n", i + 1, oledADDR[i], oledOK[i] ? "OK" : "FEHLER");
    }
    eth.init();
    eth.report("W5500");
}

void loop() {
    static uint32_t last;
    if (Serial.available() && Serial.read() == 'm') {
        for (int i = 0; i < 4; i++) {
            nudge(i, true);
            delay(300);
            nudge(i, false);
            delay(300);
        }
    }

    uint8_t a = mcpRead(0x12), b = mcpRead(0x13);
    int adc[4];
    for (int i = 0; i < 4; i++) {
        adc[i] = analogRead(Fader[i]);
        if oledOK[i] {
            oled[i].clearDisplay();
            oled[i].setTextSize(2); oled[i].setTextColor(SSD1306_WHITE);
            oled[i].setCursor(0, 0); oled[i].printf("Fader "); oled[i].print(i + 1);
            oled[i].setCursor(0, 32); oled[i].print(adc[i]);
            oled[i].display();
        }
    }
    if (millis() - last > 500) {
        last = millis();
        logf("ADC: %4d %4d %4d %4d | GPA=0x%02X GPB=0x%02X (0=gedrückt)\n", adc[0], adc[1], adc[2], adc[3], a, b);
        eth.report("W5500");
    }
}
