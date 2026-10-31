#include <common.h>

//zwei W5500, einer für Ethernet, einer für Artnet
SPIClass spiA(PA7, PA6, PA5);
SPIClass spiB(PB15, PB14, PB10);
W5500 eth{&spiA, PB7, PB5};
W5500 artnet{&spiB, PB8, PB6};

void setup() {
    testBegin();
    eth.init();
    artnet.init();
}

void loop() {
    eth.report("W5500 Ethernet");
    artnet.report("W5500 Artnet");
    delay(2000);
}