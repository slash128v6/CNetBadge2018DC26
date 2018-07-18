@slash128 2018
CompuNet DC26

To upload the sketch from the Arduino IDE:
  Requires the FastLED 2.1 or higher library to be installed in Arduino.
    The FastLED library can be found by searching under "Sketch/Include Library/Manage Libraries" menu.
  Set the power switch to "USB" and connect to computer via USB. Note the COM port detected.
  Under the "Tools/Board" menu select the “Arduino Pro or Pro Mini” option.
  Under the "Tools/Processor" menu select “ATmega328 (5V, 16MHz)”.
  Under the "Tools/Port" menu select the COM port detected when plugging in the board to USB.
  Click the "Upload" button.
  After the sketch compiles it should upload and the "TX/RX" lights will flash.
  Once upload is complete the NeoPixels will start to cycle through the patterns.

Operation:
  [Press] the SW1 button to cycle through available effects
  [Press and hold] the SW1 button (one second) to switch between auto and manual mode
    * Auto Mode (two green blinks): Effects automatically cycle over time per cycleTime
    * Manual Mode (two red blinks): Effects must be selected manually with SW1 button

  [Press] the SW2 button to cycle through available brightness levels
  [Press and hold] the SW2 button (one second) to reset brightness to startup value

  Brightness, selected effect, and auto-cycle are saved in EEPROM after a delay
  The badge will automatically start up with the last-selected settings