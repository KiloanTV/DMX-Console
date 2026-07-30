# DMX Console

- [] Output Modules for DMX & RDM (bidirectonal)
- [] Output Modules for Relais (Pyrotechnik)
- [] Art-Net Output Board
- [] Network Ouput for Remote Controll
- [] Internal Network Switch
- [] Light Software running on a mini PC or Raspberry PI
- [] Big Touch Screen
- [] X32 Motorized Faders on Alibaba (cheap)
- [] Power Supply for everything

## Output Modules

### [] DMX Ouput Modules - 1 Unverse & 4 Universes

- 5v for the board
- ethernet for internal communication (Connector is placed but not used, direkt connection)
- MAX3485 Chip (3V3 Logic) for DMX Output and Input
- DMX 3 pined or 5 pined
- stm32 chip for signal generation, recives signals from the light software over ethernet
- W5500 10/100 base ethernet - SPI chip
- RDM !
- STM32G0B1 with 4 UARTs for 4 Outputs (Universen)
- Some cheaper STM32 for the 1 Output Module

### [] Relai Output Module

- 5v + stm32 + W5500 architecture
- direkt lan connection to a Relai Board so the board can be placed near Pyrotechnik or similar

### [] Art-Net Output Board

- using two W5500 to recive data from the internal network and send Art-Net via the second.
- STM32F401CCU6 is the best and cheapest option there.

## Control Modules

### [] Fader Module

- Four Faders (motorized)
- on button for every fader to select it
- two programmable buttons for each fader slot
- one small oled display (2 I2C lanes) for displaying what fader slot does
- motor controlles aswell as ADC pins for the faders
- W5500 for connecting to the internal network
- USB port for updates/programming of the STM32

### [] HDMI-to-Screen Module

- converting the HDMI signal to the 40-Pin 14-inch display panel connector
- brightniss controll via a digital potentiometer (need to be controlled via the internal network)