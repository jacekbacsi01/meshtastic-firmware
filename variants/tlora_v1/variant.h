#define I2C_SDA 21 // I2C pins for this board
#define I2C_SCL 22

//#define RESET_OLED 16 // If defined, this pin will be used to reset the display controller

//#define VEXT_ENABLE 21 // active low, powers the oled display and the lora antenna boost
//#define VEXT_ON_VALUE LOW
#define LED_PIN 2    // If defined we will blink this LED
#define BUTTON_PIN 34 // If defined, this will be used for user button presses
#define BUTTON_NEED_PULLUP
//#define EXT_NOTIFY_OUT 13 // Default pin to use for Ext Notify Module.

#define USE_RF95
#define LORA_DIO0 27 // a No connect on the SX1262 module
#define LORA_RESET 26
#define LORA_DIO1 12 // Must be manually wired: https://www.thethingsnetwork.org/forum/t/big-esp32-sx127x-topic-part-3/18436
#define LORA_DIO2 14 // Not really used
#define LORA_CS 5
#define LORA_SCK 18
#define LORA_MOSI 23
#define LORA_MISO 19