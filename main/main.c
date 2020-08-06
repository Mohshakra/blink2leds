#include <stdio.h>
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"



#define PIN1 2
#define PIN2 4
int ison= 0;

void task1(){
  while(true){
    ison = !ison;
    gpio_set_level(PIN1 , ison);
    vTaskDelay(1000/ portTICK_PERIOD_MS);
    printf("led2\n");
  }
}


void task2(){
    while(true){
    ison = !ison;
    gpio_set_level(PIN2 , ison);
    vTaskDelay(4000/ portTICK_PERIOD_MS);
    printf("led4\n");
    }
}


void app_main(void)
{
  gpio_pad_select_gpio(PIN1);
  gpio_pad_select_gpio(PIN2);
  gpio_set_direction(PIN1, GPIO_MODE_OUTPUT);
  gpio_set_direction(PIN2, GPIO_MODE_OUTPUT);
    

  xTaskCreate(&task1,"task1", 2048 , NULL, 1 , NULL);
  xTaskCreate(&task2,"task2", 2048 , NULL, 1 , NULL);

}
