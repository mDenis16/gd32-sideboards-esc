#include "gd32f1x0.h"
#include "pinout.h"
#include "gpio.h"
#include "usart.h"
#include "clock.h"
#include "it.h"

int main(){

  

    systick_config();

    setup_clock();


    gpio_setup();
    setup_intrerupts();

    gpio_bit_write(SELF_HOLD_PORT, SELF_HOLD_PIN, SET);
    
    usart1_setup();

    while(true){
        Delay(16);
    }
}