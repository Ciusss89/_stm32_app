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

## Hardware Overview

The Nucleo-F401 is a board from ST's Nucleo family supporting a ARM Cortex-M4
STM32F401RE microcontroller with 96Kb of SRAM and 512Kb of ROM Flash.

![Nucleo64 F401](http://www.open-electronics.org/wp-content/uploads/2015/08/Figura2-500x467.png)

### MCU

| MCU        | STM32F401RE       |
|:------------- |:--------------------- |
| Family | ARM Cortex-M4     |
| Vendor | ST Microelectronics   |
| RAM        | 96Kb |
| Flash      | 512Kb             |
| Frequency  | up to 84MHz |
| FPU        | yes               |
| Timers | 11 (2x watchdog, 1 SysTick, 6x 16-bit, 2x 32-bit [TIM2])  |
| ADCs       | 1x 12-bit         |
| UARTs      | 3                 |
| SPIs       | 4                 |
| I2Cs       | 3                 |
| RTC        | 1                 |
| Vcc        | 2.0V - 3.6V           |
| Datasheet  | [Datasheet](http://www.st.com/resource/en/datasheet/stm32f401re.pdf) |
| Reference Manual | [Reference Manual](http://www.st.com/web/en/resource/technical/document/reference_manual/DM00031936.pdf) |
| Programming Manual | [Programming Manual](http://www.st.com/resource/en/programming_manual/dm00046982.pdf) |
| Board Manual   | [Board Manual](http://www.st.com/resource/en/user_manual/dm00105823.pdf)|
