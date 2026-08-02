# DMX Console

- [] Output Modules for DMX & RDM (bidirectonal)
- [] Output Modules for Relays (Pyrotechnik)
- [] Art-Net Output Board
- [] Network Ouput for Remote Controll
- [] Internal Network Switch
- [] firmware for the Output Modules and Fader Boards
- [] Big Touch Screen
- [] X32 Motorized Faders on Alibaba (cheap)
- [] Power Supply for everything

## Output Modules

### [] DMX Ouput Modules - 1 Unverse & 4 Universes

- [x] 5v for the board
- [x] ethernet for internal communication
- [x] MAX3485 Chip (3V3 Logic) for DMX Output and Input
- [x] DMX 3 pined or 5 pined
- [x] stm32 chip for signal generation, recives signals from the light software over ethernet
- [x] W5500 10/100 base ethernet - SPI chip
- [x] RDM on all ports possible

- [] make the pcb layout
- [] route the pcb

### [] Relay Output Module

- [x] 5v + stm32 + W5500 architecture
- [x] direkt lan connection to a Relay Board so the board can be placed near Pyrotechnik or similar

- [] make the pcb layout
- [] route the pcb

### [] Art-Net Output Board

- [x] using two W5500 to recive data from the internal network and send Art-Net via the second.

- [] make the pcb layout
- [] route the pcb

## Control Modules

### [] Fader Module

- [x] Four Faders with ADC pins
- [x] IO Espander for the Buttons (switches)
- [x] on button for every fader to select it
- [x] two programmable buttons for each fader slot
- [x] one small oled display (2 I2C lanes) for displaying what fader slot does
- [x] motor controlles for the faders
- [x] W5500 for connecting to the internal network
- [x] USB port for updates/programming of the STM32

- https://www.alibaba.com/product-detail/Set-of-5-High-Performance-100mm_1601281604613.html?spm=a2700.prosearch.normal_offer.d_title.36eb67afccgAYp&priceId=4d35275952de4e86a10c2bc27c13d5f2
- https://www.alibaba.com/product-detail/Terwin-X32-Motor-Fader-100mm-Travel_1601238129471.html?spm=a2700.prosearch.normal_offer.d_image.2e8f67afmJxxMf&priceId=ad31270e432b4abc9cdc3bcf5230f13c

- [] make the pcb layout
- [] route the pcb

### [] HDMI-to-Screen Module

- [] converting the HDMI signal to the 40-Pin 14-inch display panel connector
- [] brightniss controll via a digital potentiometer (need to be controlled via the internal network)
- [] using the B140XW01_V8 laptop screen panel (super cheap)
- [] 40 pin 0,5mm pitch to EDP flat kabel
- [] Display size is 14 inches and Resolutions 1366 x 768 pixel
- [] nutzen des TI TS3DV642A0RUAR obwohl nur eine hdmi quelle für ESD-Schutz der hdmi leitung und hot plug detect

- [] make the pcb layout
- [] route the pcb

### internal Network switch

- [] using the REALTEK RTL8367RB-VB-CG chip for simple 10/100/1000 Base network switching

- [] make the pcb layout
- [] route the pcb

## Software Notes

- protocol for communication via the internal network

- firmware for single/4x Output Boards
- firmware for Art-Net Output Board
- firmware for the Relay Output Board and remote Relay board itself

- firmware for the Fader Module
- firmware for the backlight control