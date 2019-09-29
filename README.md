## Project for CYBER PHYSICAL SYSTEMS course

### Instructions
 1. git clone https://github.com/Ciusss89/_stm32_app.git
 2. cd app
 3. git submodule update --init # (Only needed once)
 4. make -C libopencm3 # (Only needed once)
 5. make
 6. write the firmware on the device: st-flash write *.bin 0x8000000

### Directories
* app contains your application
* common-code contains something shared.

