
@slash128 2018
CompuNet DC26


Badge Operation:

Press the left button to cycle through available effects

Press and hold the left button for one second to switch between auto and manual mode

* Auto Mode (two green blinks): Effects automatically cycle over time per cycleTime
* Manual Mode (two red blinks): Effects must be selected manually with SW1 button

Press the right button to cycle through available brightness levels

Press and hold the right button for one second to reset brightness to startup value

Brightness, selected effect, and auto-cycle are saved in EEPROM after a delay
The badge will automatically start up with the last-selected settings


Programming the Badge from the Arduino IDE:

* Download the badge repo and unzip in your Arduino sketch folder
* https://github.com/slash128v6/CnetBadge2018DC26
* Install the FastLED library under "Sketch/Include Library/Manage Libraries" menu.
* Set the power switch to "USB" and connect to computer via USB.
* Note the COM port detected in Device Manager.
* Under the "Tools/Board" menu select the “Arduino Pro or Pro Mini” option.
* Under the "Tools/Processor" menu select “ATmega328 (5V, 16MHz)”.
* Under the "Tools/Port" menu select the COM port detected when plugging in the board to USB.
* Click the "Upload" button.
* After the sketch compiles it should upload and the "TX/RX" lights will flash.
* Once upload is complete the NeoPixels will start to cycle through the patterns.