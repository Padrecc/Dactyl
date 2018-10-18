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
5. Build firmware from qmk_firmware directory
```
make Dactyl/rev1:Default"
```

## Flashing

# FLASHING (Not the one that gets you in trouble)

1) Open up AVRDUDESS

> * If you get an error saying that it can’t start because libusb0.dll is missing then **read step 2 of the SETUP GUIDE** above

2) Select **Atmel AppNote AVR109 Boot Loader** for the **programmer**

![](http://i.imgur.com/ks0bPdL.png)

3) Select **ATmega32U4** for the **MCU** 

![](http://i.imgur.com/wefkngw.png)

4) Select your .hex file in the for the flash box (click the … box to the right)

![](http://i.imgur.com/ZR0UON1.png)

5) Select the **`eeprom-lefthand.eep`** file in the QMK Lets_split folder for the **EEPROM box** 

> * Make sure to select only one file, as you will have to change this file when flashing the right side

6) Connect **only the left side** of your board to the computer through a USB cable

7) Take note of the port drop down menu and see if you have any COMM listings, if you do, then Don’t select those particular ones in the next step 

![](http://i.imgur.com/b55RQa5.png)

8) Locate the **ground and reset** pins on your pro micro and short them, was 2 from the top on the right side of the pro micro for me

![](http://www.14core.com/wp-content/uploads/2015/12/Reset-Button-Place-Micro-Mini-Pro.jpg)

9) Take something metal and touch between the **ground and reset** pins to short them out, or if your’s has a reset button then press that to enter the bootloader mode

10) Quickly open the Port drop down menu and select the new **COMM** port that has popped up, then click program 

![](http://i.imgur.com/uYK8bpd.png)

> * If the pro micro came out of bootloader mode, then you won’t be able to flash it, but all you have to do is enter bootloader mode again by shorting the pins again.

11) **Now the left side is done, we have to flash the right side**, so connect it to your PC through USB 

12) **Be sure to change the EEPROM file to the right hand one (eeprom-righthand.eep)**

13) Locate the ground and reset pins on your pro micro and short them, was 3 from the top on the right side of the pro micro for me

14) Take something metal and touch between the ground and reset pins to short them out, or if your’s has a reset button then press that to enter the bootloader mode

15) Quickly open the Port drop down menu and select the new COMM port that has popped up, then click program 

> * If the pro micro came out of bootloader mode, then you won’t be able to flash it, but all you have to do is enter bootloader mode again by shorting the pins again.

16) Time to test it out, plug in your TRRS cable to both sides, and then plug in the USB on the left side and open a notepad window to test out all the keys and make sure your soldering skills were good


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
