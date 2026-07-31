# DMX Console

- [] Output Modules for DMX & RDM (bidirectonal)
- [] Output Modules for Relais (Pyrotechnik)
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

### [] Relai Output Module

- [] 5v + stm32 + W5500 architecture
- [] direkt lan connection to a Relai Board so the board can be placed near Pyrotechnik or similar

- [] make the pcb layout
- [] route the pcb

### [] Art-Net Output Board

- [] using two W5500 to recive data from the internal network and send Art-Net via the second.

- [] make the pcb layout
- [] route the pcb

## Control Modules

### [] Fader Module

- [] Four Faders (motorized)
- [] on button for every fader to select it
- [] two programmable buttons for each fader slot
- [] one small oled display (2 I2C lanes) for displaying what fader slot does
- [] motor controlles aswell as ADC pins for the faders
- [] W5500 for connecting to the internal network
- [] USB port for updates/programming of the STM32

- [] make the pcb layout
- [] route the pcb

### [] HDMI-to-Screen Module

- converting the HDMI signal to the 40-Pin 14-inch display panel connector
- brightniss controll via a digital potentiometer (need to be controlled via the internal network)

- [] make the pcb layout
- [] route the pcb

## Software Notes

- protocol for communication via the internal network

- firmware for single/4x Output Boards
- firmware for Art-Net Output Board
- firmware for the Relai Output Board and remote Relai board itself

- firmware for the Fader Module
- firmware for the backlight control