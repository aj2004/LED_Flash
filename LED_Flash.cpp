/* LED_Flash.cpp - Library Source file
 *
 * by Kevin W. <aj2004@shaw.ca>
 *
 *
 * This library will allow an easy way to flash an LED.
 * A single LED can be used in an ON/OFF (digital) mode
 * A single LED can be used in PWM mode
 * An RGB LED can be used in PWM mode
 * 
 */
#include "Arduino.h"
#include "LED_Flash.h"

LED_Flash_Single::LED_Flash_Single (uint8_t pin, bool invert){

	// map the arguments to private variables
  _pin = pin;
  _invert = invert;
  
  // turn the LED off to start
  // the "off" value depends on if _invert is true or false
  pinMode(_pin, OUTPUT);
  digitalWrite(_pin, _invert);
}

LED_Flash_PWM::LED_Flash_PWM (uint8_t pin, bool invert){

	// map the arguments to private variables
  _pin = pin;
  _invert = invert;
    
  // turn the LED off to start
  // the "off" value depends on if _invert is true or false
  pinMode(_pin, OUTPUT);
  if (_invert){
  	analogWrite(_pin, 255);
  }
 	else {
  	analogWrite(_pin, 0);
 	}

}

LED_Flash_RGB::LED_Flash_RGB (uint8_t pin_r, uint8_t pin_g, uint8_t pin_b, bool invert){

	// map the arguments to private variables
  _pin_r = pin_r;
  _pin_g = pin_g;
  _pin_b = pin_b;
  _invert = invert;
    
  // turn the LED off to start
  // the "off" value depends on if _invert is true or false
  pinMode(_pin_r, OUTPUT);
  pinMode(_pin_g, OUTPUT);
  pinMode(_pin_b, OUTPUT);
  if (_invert){
  	analogWrite(_pin_r, 255);
  	analogWrite(_pin_g, 255);
  	analogWrite(_pin_b, 255);
  }
 	else {
  	analogWrite(_pin_r, 0);
  	analogWrite(_pin_g, 0);
  	analogWrite(_pin_b, 0);
 	}

}

///////////////////////////////////////////////
//  Single LED in DIGITAL mode               //
///////////////////////////////////////////////

// This function is for pre-defined flash types
void LED_Flash_Single::flash (uint8_t flash_type){
  uint32_t _flashTimer = 0;
  _flash_type = flash_type;
  
  switch (_flash_type){
  	case FLASH_BLIP:
  		_time_on  = FLASH_BLIP_ON_MS;
  		_time_off = FLASH_BLIP_OFF_MS;
  		break;

  	case FLASH_SLOW:
  		_time_on  = FLASH_SLOW_ON_MS;
  		_time_off = FLASH_SLOW_OFF_MS;
  		break;

  	case FLASH_FAST:
  		_time_on  = FLASH_FAST_ON_MS;
  		_time_off = FLASH_FAST_OFF_MS;
  		break;
  }
  
  _flashTimer = millis() % (_time_on + _time_off);
  if (_flashTimer <= _time_on){
  	_LED_state = 1;
  }
  else {
  	_LED_state = 0;
  }
}

// This function is for custom on/off times
void LED_Flash_Single::flash (uint16_t time_on, uint16_t time_off){
  uint32_t _flashTimer = 0;
  _time_on  = time_on;
  _time_off = time_off;
  
    
  _flashTimer = millis() % (_time_on + _time_off);
  if (_flashTimer <= _time_on){
  	_LED_state = 1;
    //digitalWrite(_pin, !_invert);
  }
  else {
  	_LED_state = 0;
    //digitalWrite(_pin, _invert);
  }
}

///////////////////////////////////////////////
//  Single LED in PWM mode                   //
///////////////////////////////////////////////

void LED_Flash_PWM::flash (uint8_t flash_type){
  uint32_t _flashTimer = 0;
  _flash_type = flash_type;
  
  switch (_flash_type){
  	case FLASH_BLIP:
  		_time_on  = FLASH_BLIP_ON_MS;
  		_time_off = FLASH_BLIP_OFF_MS;
  		break;

  	case FLASH_SLOW:
  		_time_on  = FLASH_SLOW_ON_MS;
  		_time_off = FLASH_SLOW_OFF_MS;
  		break;

  	case FLASH_FAST:
  		_time_on  = FLASH_FAST_ON_MS;
  		_time_off = FLASH_FAST_OFF_MS;
  		break;
  }
  
  _flashTimer = millis() % (_time_on + _time_off);
  if (_flashTimer <= _time_on){
  	_LED_val = 255;
  }
  else {
  	_LED_val = 0;
  }
}

void LED_Flash_PWM::flash (uint8_t flash_type, uint8_t onValByte, uint8_t offValByte){
  uint32_t _flashTimer = 0;
  _flash_type = flash_type;
  _onValByte = onValByte;
  _offValByte = offValByte;
  
  switch (_flash_type){
  	case FLASH_BLIP:
  		_time_on  = FLASH_BLIP_ON_MS;
  		_time_off = FLASH_BLIP_OFF_MS;
  		break;

  	case FLASH_SLOW:
  		_time_on  = FLASH_SLOW_ON_MS;
  		_time_off = FLASH_SLOW_OFF_MS;
  		break;

  	case FLASH_FAST:
  		_time_on  = FLASH_FAST_ON_MS;
  		_time_off = FLASH_FAST_OFF_MS;
  		break;
  }
  
  _flashTimer = millis() % (_time_on + _time_off);
  if (_flashTimer <= _time_on){
  	_LED_val = _onValByte;  
  }
  else {
  	_LED_val = _offValByte;
  }
}

void LED_Flash_PWM::flash (uint16_t time_on, uint16_t time_off){
  uint32_t _flashTimer = 0;
  _time_on  = time_on;
  _time_off = time_off;
  
    
  _flashTimer = millis() % (_time_on + _time_off);
  if (_flashTimer <= _time_on){
  	_LED_val = 255;  
  }
  else {
  	_LED_val = 0;
  }
}

void LED_Flash_PWM::flash (uint16_t time_on, uint16_t time_off, uint8_t onValByte, uint8_t offValByte){
  uint32_t _flashTimer = 0;
  _time_on  = time_on;
  _time_off = time_off;
  _onValByte = onValByte;
  _offValByte = offValByte;
  
    
  _flashTimer = millis() % (_time_on + _time_off);
  if (_flashTimer <= _time_on){
  	_LED_val = _onValByte;  
  }
  else {
  	_LED_val = _offValByte;
  }
}

///////////////////////////////////////////////
//  RGB LED in PWM mode                      //
///////////////////////////////////////////////

void LED_Flash_RGB::flash (uint8_t flash_type){
  uint32_t _flashTimer = 0;
  _flash_type = flash_type;
  
  switch (_flash_type){
  	case FLASH_BLIP:
  		_time_on  = FLASH_BLIP_ON_MS;
  		_time_off = FLASH_BLIP_OFF_MS;
  		break;

  	case FLASH_SLOW:
  		_time_on  = FLASH_SLOW_ON_MS;
  		_time_off = FLASH_SLOW_OFF_MS;
  		break;

  	case FLASH_FAST:
  		_time_on  = FLASH_FAST_ON_MS;
  		_time_off = FLASH_FAST_OFF_MS;
  		break;
  }
  
  _flashTimer = millis() % (_time_on + _time_off);
  if (_flashTimer <= _time_on){
  	_LED_val_r = 255;
  	_LED_val_g = 255;
  	_LED_val_b = 255;
  }
  else {
  	_LED_val_r = 0;
  	_LED_val_g = 0;
  	_LED_val_b = 0;
  }
}

void LED_Flash_RGB::flash (uint8_t flash_type, uint32_t onValLong, uint32_t offValLong){
  uint32_t _flashTimer = 0;
  _flash_type = flash_type;
  _onValLong = onValLong;
  _offValLong = offValLong;


  
  switch (_flash_type){
  	case FLASH_BLIP:
  		_time_on  = FLASH_BLIP_ON_MS;
  		_time_off = FLASH_BLIP_OFF_MS;
  		break;

  	case FLASH_SLOW:
  		_time_on  = FLASH_SLOW_ON_MS;
  		_time_off = FLASH_SLOW_OFF_MS;
  		break;

  	case FLASH_FAST:
  		_time_on  = FLASH_FAST_ON_MS;
  		_time_off = FLASH_FAST_OFF_MS;
  		break;
  }
  
  _flashTimer = millis() % (_time_on + _time_off);
  if (_flashTimer <= _time_on){
  	_LED_val_r = ((_onValLong >> 16) & 0xFF);
  	_LED_val_g = ((_onValLong >>  8) & 0xFF);
  	_LED_val_b = ((_onValLong      ) & 0xFF);
  }
  else {
  	_LED_val_r = ((_offValLong >> 16) & 0xFF);
  	_LED_val_g = ((_offValLong >>  8) & 0xFF);
  	_LED_val_b = ((_offValLong      ) & 0xFF);
  }
}

void LED_Flash_RGB::flash (uint16_t time_on, uint16_t time_off){
  uint32_t _flashTimer = 0;
  _time_on  = time_on;
  _time_off = time_off;
  
    
  _flashTimer = millis() % (_time_on + _time_off);
  if (_flashTimer <= _time_on){
  	_LED_val_r = 255;
  	_LED_val_g = 255;
  	_LED_val_b = 255;
  }
  else {
  	_LED_val_r = 0;
  	_LED_val_g = 0;
  	_LED_val_b = 0;
  }
}

void LED_Flash_RGB::flash (uint16_t time_on, uint16_t time_off, uint32_t onValLong, uint32_t offValLong){
  uint32_t _flashTimer = 0;
  _time_on  = time_on;
  _time_off = time_off;
  _onValLong = onValLong;
  _offValLong = offValLong;
  
    
  _flashTimer = millis() % (_time_on + _time_off);
  if (_flashTimer <= _time_on){
  	_LED_val_r = ((_onValLong >> 16) & 0xFF);
  	_LED_val_g = ((_onValLong >>  8) & 0xFF);
  	_LED_val_b = ((_onValLong      ) & 0xFF);
  }
  else {
  	_LED_val_r = ((_offValLong >> 16) & 0xFF);
  	_LED_val_g = ((_offValLong >>  8) & 0xFF);
  	_LED_val_b = ((_offValLong      ) & 0xFF);
  }

}


///////////////////////////////////////////////
//  UPDATE functions                         //
///////////////////////////////////////////////

// This function should be called every loop
// and takes care of the actual output
void LED_Flash_Single::update (){
	if (_invert){
		_LED_state = !_LED_state;
	}
	digitalWrite(_pin, _LED_state);
	// make sure the LED turns OFF if not flashing
	_LED_state = 0;
}

void LED_Flash_PWM::update (){
	if (_invert){
		_LED_val = 255 - _LED_val;
	}
	analogWrite(_pin, _LED_val);
	// make sure the LED turns OFF if not flashing
	_LED_val = 0;
}

void LED_Flash_RGB::update (){
	if (_invert){
  	_LED_val_r = 255 - _LED_val_r;
  	_LED_val_g = 255 - _LED_val_g;
  	_LED_val_b = 255 - _LED_val_b;
  }
	analogWrite(_pin_r, _LED_val_r);
	analogWrite(_pin_g, _LED_val_g);
	analogWrite(_pin_b, _LED_val_b);

	// make sure the LED turns OFF if not flashing
	_LED_val_r = 0;
  _LED_val_g = 0;
  _LED_val_b = 0;
}




