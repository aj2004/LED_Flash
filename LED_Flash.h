/* LED_Flash.h - Library Header file
 *
 *  by Kevin W. <aj2004@shaw.ca>
 *
 * This library will allow a convenient way to flash
 * an LED with pre-defined or custom patterns.
 *
 * This library currently supports a single digital LED.
 */
#include "Arduino.h"
#ifndef LED_Flash_h
#define LED_Flash_h

#define FLASH_FAST_ON_MS  300
#define FLASH_FAST_OFF_MS 300

#define FLASH_SLOW_ON_MS  900
#define FLASH_SLOW_OFF_MS 900

#define FLASH_BLIP_ON_MS  150
#define FLASH_BLIP_OFF_MS 1650

#define SOLID_OFF  0
#define FLASH_BLIP 1
#define FLASH_SLOW 2
#define FLASH_FAST 3
#define SOLID_ON   4


class LED_Flash_Single{

  public:

    

    LED_Flash_Single (uint8_t pin, bool invert);

    void flash (uint8_t flash_type);
   
    void flash (uint16_t time_on, uint16_t time_off);
    
    void update (void);
        
  private:

    bool _LED_state;
        
    uint8_t _pin;
    bool _invert;

    uint8_t _flash_type;

    uint16_t _time_on;
    uint16_t _time_off;

    
   
};

class LED_Flash_PWM{

  public:

    LED_Flash_PWM (uint8_t pin, bool invert);

    

    void flash (uint8_t flash_type);
    void flash (uint8_t flash_type, uint8_t onValByte, uint8_t offValByte);
   
    void flash (uint16_t time_on, uint16_t time_off);
    void flash (uint16_t time_on, uint16_t time_off, uint8_t onValByte, uint8_t offValByte);
    
    void update (void);
        
  private:

    uint8_t _LED_val;
        
    uint8_t _pin;
    bool _invert;

    uint8_t _onValByte;
    uint8_t _offValByte;

    uint8_t _flash_type;

    uint16_t _time_on;
    uint16_t _time_off;

    
   
};


class LED_Flash_RGB{

  public:

    LED_Flash_RGB (uint8_t pin_r, uint8_t pin_g, uint8_t pin_b, bool invert);

    void flash (uint8_t flash_type);
    void flash (uint8_t flash_type, uint32_t onValLong, uint32_t offValLong);
   
    void flash (uint16_t time_on, uint16_t time_off);
    void flash (uint16_t time_on, uint16_t time_off, uint32_t onValLong, uint32_t offValLong);
    
    void update (void);
        
  private:
        
    uint8_t _pin_r;
    uint8_t _pin_g;
    uint8_t _pin_b;
    bool _invert;

    uint32_t _onValLong;
    uint32_t _offValLong;

    uint8_t _flash_type;

    uint16_t _time_on;
    uint16_t _time_off;

    uint8_t _LED_val_r;
    uint8_t _LED_val_g;
    uint8_t _LED_val_b;
   
};

#endif
