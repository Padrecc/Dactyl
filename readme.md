## Windows environment preparation

1. Install Bash Shell on Windows, follow this guide
2. Download and install AVRDudess, link here
3. Download and install WinAVR or LIBUSB to get the LIBUSB0.DLL

## First Time Setup

1. Clone original QMK repository
```
git clone
```
2. From qmk_firmware directory install all dependencies
```
sudo util/install_dependencies.sh
```
3. [Optional]
Delete all subdirectories from "keyboards"
4. Clone this repository to "keyboards"
```
cd keyboards
git clone https://github.com/Padrecc/Dactyl.git
```
or
```
git clone https://github.com/Padrecc/Dactyl.git
```
5. Build firmware from qmk_firmware directory
```
make Dactyl/rev3:default
```

## Replacing CATERINA bootloader with QMK DFU using Arduino Nano as ISP

### Prepare ISP:

- Connect Arduino Nano to PC.
- Arduino IDE: Tools-> Select Board -> Arduino Nano
- Tools->Processor-> Atmega328p (old bootloader)
- Tools->Processor->AVRISP mkII
- Open File->Examples->11.Arduino ISP
- Upload Sketch

### Wiring:

Nano | Micro
- GND - GND
- 5V - Vcc
- D10 - RST
- D11 - 16
- D12 - 14
- D13 - 15

### Compiling bootloader

Add following lines to the keymaps's config.h 
```
#define QMK_ESC_OUTPUT B5 // usually COL
#define QMK_ESC_INPUT B6 // usually ROW
#define QMK_LED B0
#define QMK_SPEAKER C6
```
to the rules.mk
```
BOOTLOADER = qmk-dfu
```
Build firmare with production target
```
make Dactyl/rev1:Default:production"
```

### Flashing bootloader

Test
```
avrdude -c avrisp -p m32U4 -P COM9 -b19200
```
- Left hand
```
avrdude -c avrisp -p m32U4 -P COM9 -b19200 -U flash:w:"Dactyl_rev1_default_production.hex":a -U lfuse:w:0x5E:m -U hfuse:w:0xD9:m -U efuse:w:0xC3:m -U lock:w:0x3F:m -U eeprom:w:"eeprom-lefthand.eep":a 
```
- Right hand
```
avrdude -c avrisp -p m32U4 -P COM9 -b19200 -U flash:w:"Dactyl_rev1_default_production.hex":a -U lfuse:w:0x5E:m -U hfuse:w:0xD9:m -U efuse:w:0xC3:m -U lock:w:0x3F:m -U eeprom:w:"eeprom-righthand.eep":a 
```
# Return Caterina bootloader
```
avrdude -c avrisp -p m32U4 -P COM9 -b19200 -U flash:w:"Caterina-promicro16.hex":a -U lfuse:w:0xFF:m -U hfuse:w:0xD8:m -U efuse:w:0xC3:m -U lock:w:0x3F:m
```

## Flashing firmware to Pro Micro with QMK DFU

Download and install 
- https://sourceforge.net/projects/dfu-programmer/files/latest/download 
or
- https://dfu-programmer.github.io/

Connect controller and reset it with GND+RST

Update windows driver for bootload with "ATmega32U4" one from dfu-programmer

Flash firmware
```
dfu-programmer.exe atmega32u4 flash d:\Work\Dactyl\qmk_firmware\Dactyl_rev1_default.hex
```
Flash eeprom
```
dfu-programmer.exe atmega32u4 flash --eeprom d:\Work\Dactyl\qmk_firmware\keyboards\Dactyl\eeprom-righthand.eep
```
Optional Hardware
-----------------

A speaker can be hooked-up to either side to the `5` (`C6`) pin and `GND`, and turned on via `AUDIO_ENABLE`.

Wiring
------

The 3 wires of the TRS/TRRS cable need to connect GND, VCC, and digital pin 3 (i.e.
PD0 on the ATmega32u4) between the two Pro Micros.

Then wire your key matrix to any of the remaining 17 IO pins of the pro micro
and modify the `matrix.c` accordingly.

The wiring for serial:

![serial wiring](https://i.imgur.com/C3D1GAQ.png)

The wiring for i2c:

![i2c wiring](https://i.imgur.com/Hbzhc6E.png)

The pull-up resistors may be placed on either half. It is also possible
to use 4 resistors and have the pull-ups in both halves, but this is
unnecessary in simple use cases.

You can change your configuration between serial and i2c by modifying your `config.h` file.

Pro Micro
---------
![pro micro minout](https://github.com/Padrecc/Dactyl/blob/master/pics/pro%20micro%20pinout.png)
