# LED_Flash
Functions to flash a single or RGB LED.

by aj2004

Original   : October 20, 2019

Last update: October 20, 2019

This library will allow either a single LED or an RGB LED to be flashed between 2 states at preset or custom time intervals.

------
## Usage

###1. Construct one of:

 - Single digitally-controlled LED
`myDig_LED (pin, invert);`

 - Single PWM-controlled LED
`myPWM_LED (pin, invert);`

 - PWM-controlled RGB LED
`myRGB_LED (pinRed, pinGrn, pinBlu, invert);`

###2. Tell your LED to flash:

Simple:
`myDig_LED.flash(FLASH_BLIP);`
`myDig_LED.flash(FLASH_SLOW);`
`myDig_LED.flash(FLASH_FAST);`

Custom:
`myDig_LED.flash(1000, 500);`
