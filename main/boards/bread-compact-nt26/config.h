#ifndef _BOARD_CONFIG_H_
#define _BOARD_CONFIG_H_

#include <driver/gpio.h>

#define AUDIO_INPUT_SAMPLE_RATE  16000
#define AUDIO_OUTPUT_SAMPLE_RATE 24000

//#define AUDIO_I2S_METHOD_SIMPLEX

#ifdef AUDIO_I2S_METHOD_SIMPLEX
// Этот блок пропустится
#else
// ЗВУК ДЛЯ ESP32-C3 (сдвинули, так как GPIO 6 и 7 ушли на экран)
#define AUDIO_I2S_GPIO_WS   GPIO_NUM_3  // LRC / WS
#define AUDIO_I2S_GPIO_BCLK GPIO_NUM_2  // BCLK / SCK
#define AUDIO_I2S_GPIO_DIN  GPIO_NUM_4  // SD (Микрофон INMP441)
#define AUDIO_I2S_GPIO_DOUT GPIO_NUM_5  // DIN (Усилитель MAX98357A)
#endif

// КНОПКИ ДЛЯ ESP32-C3 SUPERMINI
#define BOOT_BUTTON_GPIO        GPIO_NUM_9  // Кнопка BOOT на SuperMini (на плате это GPIO9)
#define TOUCH_BUTTON_GPIO       GPIO_NUM_1  // Сенсор TTP223 (перенесли с GPIO2)
#define VOLUME_UP_BUTTON_GPIO   GPIO_NUM_NC // Отключено
#define VOLUME_DOWN_BUTTON_GPIO GPIO_NUM_NC // Отключено

// ИНДИКАЦИЯ И СВЕТОДИОДЫ (То, из-за чего падала сборка)
#define BUILTIN_LED_GPIO        GPIO_NUM_8  // Встроенный синий светодиод SuperMini
#define LAMP_GPIO               GPIO_NUM_NC // Лампа не используется

// МОДЕМ NT26 (То, из-за чего падала сборка)
#define NT26_TX_PIN             GPIO_NUM_20 // UART TX
#define NT26_RX_PIN             GPIO_NUM_21 // UART RX
#define NT26_DTR_PIN            GPIO_NUM_NC // Не задействован
#define NT26_RI_PIN             GPIO_NUM_NC // Не задействован

// ЭКРАН SH1106 (Перенесен на твои GPIO 6 и 7)
#define DISPLAY_SDA_PIN         GPIO_NUM_6  // SDA -> GPIO 6
#define DISPLAY_SCL_PIN         GPIO_NUM_7  // SCL -> GPIO 7
#define DISPLAY_WIDTH           128
#define DISPLAY_HEIGHT          64

#define SH1106

#define DISPLAY_MIRROR_X        true
#define DISPLAY_MIRROR_Y        true

#endif // _BOARD_CONFIG_H_
