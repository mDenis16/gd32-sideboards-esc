#include "gd32f1x0.h"
#include "gpio.h"
#include "pinout.h"

void setup_clock(){
    rcu_periph_clock_enable(RCU_GPIOA);
 	rcu_periph_clock_enable(RCU_USART1);
}