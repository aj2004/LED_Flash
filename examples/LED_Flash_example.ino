#include "Arduino.h"
#include "LED_Flash.h"




LED_Flash_Single onboardLED (13, false);

//LED_Flash_PWM redLED (9, true);
//LED_Flash_PWM grnLED (10, true);
//LED_Flash_PWM bluLED (11, true);

LED_Flash_RGB rgbLED (9, 10, 11, true);


uint32_t delayTimer = 0;
uint8_t x = 0;

void setup(void){
    Serial.begin(115200);
    pinMode(A0, INPUT_PULLUP);
    pinMode(A1, INPUT_PULLUP);
    pinMode(A2, INPUT_PULLUP);
    pinMode(A3, INPUT_PULLUP);
}

void loop(void){

    if (!digitalRead(A0)){
        onboardLED.flash(FLASH_BLIP);
        rgbLED.flash(FLASH_BLIP);
        //grnLED.flash(FLASH_BLIP, 50, 250);
        //bluLED.flash(FLASH_BLIP, 50, 250);
    } else
    if (!digitalRead(A1)){
        onboardLED.flash(FLASH_SLOW);
        rgbLED.flash(FLASH_SLOW, 0x00FFFF, 0x00FF00);
        //grnLED.flash(0,128);
        //bluLED.flash(255,0);
    } else
    if (!digitalRead(A2)){
        onboardLED.flash(FLASH_FAST);
        rgbLED.flash(500, 100);
        //grnLED.flash(FLASH_FAST);
        //bluLED.flash(FLASH_FAST);
    } else
    if (!digitalRead(A3)){
        onboardLED.flash(100, 100);
        rgbLED.flash(1000, 2000, 0xFF0000, 0x00FF00);
        //grnLED.flash(1000, 2000, 255, 0);
        //bluLED.flash(1000, 2000, 20, 0);
    }

    
    
    

    onboardLED.update();
    rgbLED.update();
    //grnLED.update();
    //bluLED.update();

}