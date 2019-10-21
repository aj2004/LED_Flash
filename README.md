# LED_Flash
Functions to flash a single or RGB LED.

by aj2004

Original   : October 20, 2019

Last update: October 20, 2019

This library will allow either a single LED or an RGB LED to be flashed between 2 states at preset or custom time intervals.

------
## Usage

1. Construct one of:

 - Single digitally-controlled LED: `myDig_LED (pin, invert);`

 - Single PWM-controlled LED: `myPWM_LED (pin, invert);`

 - PWM-controlled RGB LED: `myRGB_LED (pinRed, pinGrn, pinBlu, invert);`

2. Tell your LED to flash:

Simple:

`myDig_LED.flash(FLASH_BLIP);`

`myDig_LED.flash(FLASH_SLOW);`

`myDig_LED.flash(FLASH_FAST);`

Custom:

`myDig_LED.flash(1000, 500);`
This will flash 1 second ON, and 500ms OFF.

PWM Mode:

`myPWM_LED.flash(500, 2000, 25, 255);`
This will flash 500ms ON at ~10% brightness, then 2 seconds OFF at 100% brightness.

RGB Mode:

`myRGB_LED.flash(250, 250, 0xFF0000, 0x00FFFF);`
This will flash 250ms full RED, and 250ms full CYAN.

Be sure to update the state of the LED each loop():

`myDig_LED.update();`
