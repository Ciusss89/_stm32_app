## Project for CYBER PHYSICAL SYSTEMS course

### Instructions
 1. git clone https://github.com/Ciusss89/_stm32_app.git
 2. cd app
 3. git submodule update --init # (Only needed once)
 4. make -C libopencm3 # (Only needed once)
 5. make
 6. write the firmware on the device: st-flash write *.bin 0x8000000

### Directories
* app contains: your application
* common-code: contains something shared.
* app/old_main: contains the examples, check the instructions in the dir.

### Debug by UART
The Nucleo board has debug chip on-board. It connectes its virtual COM
( /dev/ttyACM0 ) to the SUART2 of the mcu:

 `sudo picocom -b 115200 /dev/ttyACM0`
