#ifndef _BOARD_CONFIG_H_
#define _BOARD_CONFIG_H_

#include <driver/gpio.h>

#define AUDIO_INPUT_SAMPLE_RATE  16000
#define AUDIO_OUTPUT_SAMPLE_RATE 24000

// Раскомментируем Duplex (убираем SIMPLEX), чтобы разгрузить пины и объединить такты I2S
//#define AUDIO_I2S_METHOD_SIMPLEX

#ifdef AUDIO_I2S_METHOD_SIMPLEX
// Этот блок пропустится
#else
// ЗВУК ДЛЯ ESP32-C3:
#define AUDIO_I2S_GPIO_WS   GPIO_NUM_6  // LRC / WS
#define AUDIO_I2S_GPIO_BCLK GPIO_NUM_5  // BCLK / SCK
#define AUDIO_I2S_GPIO_DIN  GPIO_NUM_4  // SD (Микрофон)
#define AUDIO_I2S_GPIO_DOUT GPIO_NUM_7  // DIN (Усилитель MAX98357A)
#endif

// КНОПКИ ДЛЯ ESP32-C3 SUPERMINI
#define BOOT_BUTTON_GPIO        GPIO_NUM_0  // Встроенная кнопка BOOT
#define TOUCH_BUTTON_GPIO       GPIO_NUM_2  // Твой сенсор TTP223
#define VOLUME_UP_BUTTON_GPIO   GPIO_NUM_NC // Отключено (NC - Not Connected)
#define VOLUME_DOWN_BUTTON_GPIO GPIO_NUM_NC // Отключено

// ЭКРАН SH1106 НА РОДНОЙ АППАРАТНОЙ ШИНЕ I2C ESP32-C3
#define DISPLAY_SDA_PIN GPIO_NUM_8   // SDA экрана -> GPIO 8
#define DISPLAY_SCL_PIN GPIO_NUM_9   // SCL экрана -> GPIO 9
#define DISPLAY_WIDTH   128
#define DISPLAY_HEIGHT  64

// ПРИНУДИТЕЛЬНО ВКЛЮЧАЕМ SH1106
#define SH1106

#define DISPLAY_MIRROR_X true
#define DISPLAY_MIRROR_Y true

#endif // _BOARD_CONFIG_H_