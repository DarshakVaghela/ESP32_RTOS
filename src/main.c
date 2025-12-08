#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"     // <<< important
#include "esp_system.h"
#include "esp_log.h"

static const char *TAG = "rtos_demo";

void blink_task(void *pvParameter) {
    gpio_reset_pin(GPIO_NUM_2);
    gpio_set_direction(GPIO_NUM_2, GPIO_MODE_OUTPUT);
    while (1) {
        gpio_set_level(GPIO_NUM_2, 1);
        ESP_LOGI(TAG, "LED ON");
        vTaskDelay(pdMS_TO_TICKS(3000));
        gpio_set_level(GPIO_NUM_2, 0);
        ESP_LOGI(TAG, "LED OFF");
        vTaskDelay(pdMS_TO_TICKS(3000));
    }
}

void app_main(void) {
    xTaskCreate(&blink_task, "blink_task", 2048, NULL, 5, NULL);
}
