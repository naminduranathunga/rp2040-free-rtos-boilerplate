#include <pico/stdlib.h>
#include <pico/stdio.h>
#include <stdio.h>
#include <pico/time.h>

#include <FreeRTOS.h>
#include <task.h>
#include <FreeRTOSConfig.h>


void TaskBlinkFunc1(void *params){
    int pin = 21;
    int delay = 2000;
    gpio_init(pin);
    gpio_set_dir(pin, GPIO_OUT);
    while(1){
        gpio_put(pin, 1);
        vTaskDelay(pdMS_TO_TICKS(delay));
        gpio_put(pin, 0);
        vTaskDelay(pdMS_TO_TICKS(delay));
    }
}

void TaskBlinkFunc2(void *params){
    int pin = 22;
    int delay = 1000;
    gpio_init(pin);
    gpio_set_dir(pin, GPIO_OUT);
    while(1){
        gpio_put(pin, 1);
        vTaskDelay(pdMS_TO_TICKS(delay));
        gpio_put(pin, 0);
        vTaskDelay(pdMS_TO_TICKS(delay));
    }
}


void TaskDoSerialPrint(void *params){
    //init
    //initilize the serial port
    stdio_init_all();

    while(1){
        printf("Hello World\n");
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}

int main(){
    //blink(PICO_DEFAULT_LED_PIN, 150); // Blink the onboard LED

    // Create a task to blink the onboard LED
    int pin1 = 21;
    int pin2 = 22;
    xTaskCreate(TaskBlinkFunc1, "Blink1", 128, (void *)pin1, 1, NULL);
    xTaskCreate(TaskBlinkFunc2, "Blink2", 128, (void *)pin2, 1, NULL);
    xTaskCreate(TaskDoSerialPrint, "print", 255, (void *)pin2, 1, NULL);

    vTaskStartScheduler();

    return 0;
}