/**
 * @example   "1.FilteredAnalog.ino"
 * 
 * 1.FilteredAnalog
 * ================
 *
 * This examples shows how to filter an analog input, so you can get the 
 * position of a knob or fader without noise.
 * 
 * @boards  AVR, AVR USB, Teensy 3.x, ESP32
 * 
 * Connections
 * -----------
 * 
 * - A0: wiper of a potentiometer
 * 
 * Connect the left terminal of the potentiometer to ground, and the right one
 * to V<sub>CC</sub>.
 * 
 * Behavior
 * --------
 * 
 * - Upload the sketch to the Arduino, and open the Serial Monitor 
 *   (`CTRL+Shift+M`)
 * - When you turn the potentiometer, you should see the position of the 
 *   potentiometer being printed as a number between 0 and 1023.
 * - The analog input is filtered, so there shouldn't be any noise on the 
 *   position. If there is, check your wiring, and make sure that the resistance
 *   of the potentiometer isn't too high (10 kΩ is ideal). 
 * 
 * Written by PieterP, 2019-10-10  
 * https://github.com/tttapa/Arduino-Helpers
 */

/**
 * @example   "2.RGB-LED-Chaser.ino"
 * 
 * 2.RGB-LED-Chaser
 * ================
 *
 * This is an example of the ShiftRegisterOut class of the Control Surface 
 * library. It creates light effects using three 8-bit shift registers and some
 * RGB LEDs.
 *
 * @boards  AVR, AVR USB, Teensy 3.x, ESP32
 *
 * Connections
 * -----------
 *
 * Connect three daisy-chained shift registers to the SPI pins.  
 * Connect 8 RGB LEDs (+ current limiting resistors) to the outputs of the shift
 * registers.
 * 
 * ```
 * SCK   >───────────┬──────────────────────┬──────────────────────┐
 *           ┏━━━━━━━┷━━━━━━━┓      ┏━━━━━━━┷━━━━━━━┓      ┏━━━━━━━┷━━━━━━━┓
 *           ┃     SH_CP     ┃      ┃     SH_CP     ┃      ┃     SH_CP     ┃
 * MOSI  >───┨ DS        Q7S ┠──────┨ DS        Q7S ┠──────┨ DS        Q7S ┃
 *           ┃     ST_CP     ┃      ┃     ST_CP     ┃      ┃     ST_CP     ┃
 *           ┗━━━━━━━┯━━━━━━━┛      ┗━━━━━━━┯━━━━━━━┛      ┗━━━━━━━┯━━━━━━━┛
 * SS    >───────────┴──────────────────────┴──────────────────────┘
 * ```
 * Remember to connect the enable pin of the shift register to ground and the 
 * master reset pin to Vcc in order to enable it.  
 * 
 * The order of the colors doesn't matter. You can change them in software using
 * the `ShiftRegisterOutRGB::redBit`, `ShiftRegisterOutRGB::greenBit` and 
 * `ShiftRegisterOutRGB::blueBit` constants.
 * 
 * If you wired the LEDs as RGB (red first, then green and then blue), the red 
 * bit is 0, the green bit is 1 and the blue bit is 2.  
 * If you wired the LEDs as BGR (blue first, then green and then red), the red
 * bit is 2, the green bit is 1 and the blue bit is 0.  
 * Other combinations are possible as well.
 * 
 * Behavior
 * --------
 * 
 * This example will turn on all red LEDs one by one, then turn them off one by
 * one, next, it will turn on and off all green LEDs in the same manner, and
 * finally the same for the blue LEDs. This is repeated indefinitely.
 * 
 * Demo
 * ----
 * 
 * @htmlonly
 * <iframe width="560" height="315"
 * src="https://www.youtube.com/embed/7ywcTTdnseU?loop=1" frameborder="0"
 * allow="accelerometer; autoplay; encrypted-media; gyroscope;
 * picture-in-picture" allowfullscreen></iframe>
 * @endhtmlonly
 * 
 * Written by Pieter P, 2018-07-13  
 * https://github.com/tttapa/Arduino-Helpers
 */

/**
 * @example   "2.BitBang-Blink.ino"
 * 
 * 2.BitBang-Blink
 * ===============
 *
 * This example demonstrates the use of shift registers as if they were just
 * normal IO pins. This version uses bit-banging to drive the  shift register. 
 * You should probably be using the SPI version instead.
 * 
 * @boards  AVR, AVR USB, Teensy 3.x, ESP32
 * 
 * Connections
 * -----------
 * 
 *   - 10: 74HC595 ST_CP
 *   - 11: 74HC595 DS
 *   - 13: 74HC595 SH_CP
 * 
 * Connect an LED (and series resistor) between the first output of the
 * shift register and ground.
 * 
 * Remember to connect the enable pin the shift register to ground and the 
 * master reset pin to Vcc in order to enable it.  
 * 
 * Behavior
 * --------
 * 
 * This sketch will blink the LED once a second.
 * 
 * Written by PieterP, 2018-09-01
 * https://github.com/tttapa/Arduino-Helpers
 */

/**
 * @example   "1.SPI-Blink.ino"
 * 
 * 1.SPI-Blink
 * ===========
 *
 * This example demonstrates the use of shift registers as if they were just
 * normal IO pins. The SPI interface is used because it's easy and fast.
 * 
 * @boards  AVR, AVR USB, Teensy 3.x, ESP32
 * 
 * Connections
 * -----------
 * 
 *   - SS:   74HC595 ST_CP
 *   - MOSI: 74HC595 DS
 *   - SCK:  74HC595 SH_CP
 * 
 * Connect an LED (and series resistor) between the first output of the
 * shift register and ground.
 * 
 * Remember to connect the enable pin of the shift register to ground and the 
 * master reset pin to Vcc in order to enable it.  
 * 
 * Behavior
 * --------
 * 
 * This sketch will just blink the LED once a second.
 * 
 * Mapping
 * -------
 * 
 * None.
 * 
 * Written by PieterP, 2018-09-01
 * https://github.com/tttapa/Arduino-Helpers
 */

/**
 * @example   "Toggle-LEDs.ino"
 * 
 * Toggle-LEDs
 * ===========
 *
 * This example demonstrates the use of push buttons and LEDs and how to use
 * shift registers and analog multiplexers to save pins.
 * 
 * @boards  AVR, AVR USB, Teensy 3.x, ESP32
 * 
 * Connections
 * -----------
 * 
 *   - SS:   74HC595 ST_CP
 *   - MOSI: 74HC595 DS
 *   - SCK:  74HC595 SH_CP
 *   - 2: 74HC4067 A (COM OUT/IN)
 *   - 3: 74HC4067 S0
 *   - 4: 74HC4067 S1
 *   - 5: 74HC4067 S2
 *   - 6: 74HC4067 S3
 * 
 * Connect 16 momentary push buttons between the input pins of the 
 * multiplexer and ground.  
 * The internal pull-up resistor for the buttons will be enabled automatically,
 * so no external resistors are necessary.
 * 
 * Connect 16 LEDs (and series resistors) between the eight outputs of the
 * two shift registers and ground. 
 * 
 * Remember to connect the enable pins of both the multiplexer and the shift
 * registers to ground in order to enable them. Also connect the master reset 
 * pin of the shift registers to Vcc.  
 * Connect the serial data output of the first shift register (QH' or Q7S) to
 * the serial input of the second shift register.
 * 
 * Behavior
 * --------
 *  
 * Pressing the first button will turn on the first LED. Pressing it again will
 * turn it off again.
 * Pressing the second button will turn on the second LED. Pressing it again 
 * will turn it off again, and so on.
 * 
 * Mapping
 * -------
 * 
 * None.
 * 
 * Written by PieterP, 2018-08-28  
 * https://github.com/tttapa/Arduino-Helpers
 */

/**
 * @example   "1.AnalogReadSerial.ino"
 * 
 * 1.AnalogReadSerial
 * ==================
 *
 * This is an example of the AnalogMultiplex class. It prints the values of all
 * 16 inputs of a multiplexers to the serial monitor.
 * 
 * @boards  AVR, AVR USB, Teensy 3.x, ESP32
 * 
 * Connections
 * -----------
 * 
 *  - A0: CD74HC4067 signal pin ("common input/output")
 *  - 3:  CD74HC4067 address pin S0
 *  - 4:  CD74HC4067 address pin S1
 *  - 5:  CD74HC4067 address pin S2
 *  - 6:  CD74HC4067 address pin S3
 *  
 * Optionally you can connect the enable pin as well, this is useful
 * if you want to use multiple multiplexers with the same address 
 * lines and the same analog input. Otherwise, just connect the enable
 * pin to ground.
 * 
 * If you are using a 3-bit multiplexer, like the CD74HC4051, you can
 * uncomment the code specific to this multiplexer, and use only three
 * address pins.
 *  
 * Behavior
 * --------
 * 
 * Connect some potentiometers or other analog sensors to the 16 inputs
 * of the multiplexer, and open the serial monitor (CTRL+SHIFT+M) or the
 * serial plotter (CTRL+SHIFT+L). You should see all 16 signals printed
 * or plotted.
 * 
 * Written by Pieter P, 31-01-2019  
 * https://github.com/tttapa/Arduino-Helpers
 */

/**
 * @example   "2.DigitalReadSerial.ino"
 * 
 * 2.DigitalReadSerial
 * ===================
 *
 * This is an example of the AnalogMultiplex class. It prints the states of all
 * 16 switches connected to a multiplexers to the serial monitor.
 * 
 * @boards  AVR, AVR USB, Teensy 3.x, ESP32
 * 
 * Connections
 * -----------
 * 
 *  - 2: CD74HC4067 signal pin ("common input/output")
 *  - 3: CD74HC4067 address pin S0
 *  - 4: CD74HC4067 address pin S1
 *  - 5: CD74HC4067 address pin S2
 *  - 6: CD74HC4067 address pin S3
 *  
 * Optionally you can connect the enable pin as well, this is useful
 * if you want to use multiple multiplexers with the same address 
 * lines and the same analog input. Otherwise, just connect the enable
 * pin to ground.
 * 
 * If you are using a 3-bit multiplexer, like the CD74HC4051, you can
 * uncomment the code specific to this multiplexer, and use only three
 * address pins.
 * 
 * Connect a switch or push button between each input pin of the multiplexer and
 * ground. A pull-up resistor is not necessary, because we'll use the internal 
 * one.
 *  
 * Behavior
 * --------
 * 
 * Open the serial monitor (CTRL+SHIFT+M) or the serial plotter (CTRL+SHIFT+L),
 * and press some buttons, you should see all 16 signals printed or plotted.
 * 
 * Written by Pieter P, 2019-08-08   
 * https://github.com/tttapa/Arduino-Helpers
 */
