// #define BUTTON_NEED_PULLUP // if set we need to turn on the internal CPU pullup during sleep

#define I2C_SDA 21
#define I2C_SCL 22

#define BUTTON_PIN 34 // The user button (information button) GPIO on the Nano G1 explorer
#define LED_PIN 2     // If defined we will blink this LED
// #define BUTTON_PIN_ALT 13 // Alternate GPIO for an external button if needed. Does anyone use this? It is not documented
//  anywhere.
#define EXT_NOTIFY_OUT 13 // Default pin to use for Ext Notify Module.
//#define PIN_BUZZER 13
// common pinout for their SX1262 vs RF95 modules - both can be enabled and we will probe at runtime for RF95 and if
// not found then probe for SX1262
//#define USE_RF95
#define USE_SX1262

//#define GPS_RX_PIN 33
//#define GPS_TX_PIN 32

#define SX126X_CS 5     //  NSS pin
#define SX126X_SCK 18   //  SCK pin
#define SX126X_MOSI 23  //  MOSI pin
#define SX126X_MISO 19  //  MISO pin
#define SX126X_RESET 26 //  NRST pin
#define SX126X_BUSY 14  //  BUSY pin
#define SX126X_DIO1 12  //  DIO1 pin

#define LORA_CS SX126X_CS     // Compatibility with variant file configuration structure
#define LORA_SCK SX126X_SCK   // Compatibility with variant file configuration structure
#define LORA_MOSI SX126X_MOSI // Compatibility with variant file configuration structure
#define LORA_MISO SX126X_MISO // Compatibility with variant file configuration structure
#define LORA_DIO1 SX126X_DIO1 // Compatibility with variant file configuration structure

// Not really an E22
#define SX126X_DIO2_AS_RF_SWITCH
#define SX126X_DIO3_TCXO_VOLTAGE 1.8
// Internally the module hooks the SX1262-DIO2 in to control the TX/RX switch (which is the default for the sx1262interface
// code)


#define BATTERY_PIN 36 // A battery voltage measurement pin, voltage divider connected here to measure battery voltage
#define ADC_CHANNEL ADC1_GPIO36_CHANNEL
#define BATTERY_SENSE_SAMPLES 15 // Set the number of samples, It has an effect of increasing sensitivity.
#define ADC_MULTIPLIER 1.95

#define USE_SSD1306
