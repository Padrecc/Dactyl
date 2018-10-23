Links:
https://www.instructables.com/id/Burn-Bootloader-Arduino-Nano-As-ISP-to-Pro-Micro/
https://www.reddit.com/r/olkb/comments/8sxgzb/replace_pro_micro_bootloader_with_qmk_dfu/


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

### Flash

Test

avrdude -c avrisp -p m32U4 -P COM9 -b19200

For left hand

avrdude -c avrisp -p m32U4 -P COM9 -b19200 -U flash:w:"Dactyl_rev1_default_production.hex":a -U lfuse:w:0x5E:m -U hfuse:w:0xD9:m -U efuse:w:0xC3:m -U lock:w:0x3F:m -U eeprom:w:"eeprom-lefthand.eep":a 

for right hand

avrdude -c avrisp -p m32U4 -P COM9 -b19200 -U flash:w:"Dactyl_rev1_default_production.hex":a -U lfuse:w:0x5E:m -U hfuse:w:0xD9:m -U efuse:w:0xC3:m -U lock:w:0x3F:m -U eeprom:w:"eeprom-righthand.eep":a 


### DFU programm

Download and install
https://sourceforge.net/projects/dfu-programmer/files/latest/download
https://dfu-programmer.github.io/

- Connect controller and reset it with GND+RST
- Update windows driver for bootload with "ATmega32U4" one from dfu-programmer 

