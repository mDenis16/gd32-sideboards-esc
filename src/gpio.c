#include "gd32f1x0.h"
#include "gpio.h"
#include "pinout.h"



void setup_buzzer(){
    gpio_mode_set(BUZZER_PORT , GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, BUZZER_PIN);	
	gpio_output_options_set(BUZZER_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, BUZZER_PIN);
	

}
void setup_button(){

	gpio_mode_set(BUTTON_PORT , GPIO_MODE_INPUT, GPIO_PUPD_NONE, BUTTON_PIN);	

}

void setup_self_hold(){
    gpio_mode_set(SELF_HOLD_PORT , GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, SELF_HOLD_PIN);	
	gpio_output_options_set(SELF_HOLD_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_10MHZ, SELF_HOLD_PIN);
}
void gpio_setup(){
    setup_buzzer();
    setup_self_hold();
    setup_button();
}


void gpio_setup_usart1(){
	#define USART1_PUPD	GPIO_PUPD_NONE
    //pinModeAF(USART_MB1_TX_PORT, GPIO_AF_4, USART1_PUPD, GPIO_OSPEED_50MHZ);	// // GD32F130: GPIO_AF_1 = USART
	//pinModeAF(USART_MB1_RX_PORT, GPIO_AF_4, USART1_PUPD, GPIO_OSPEED_50MHZ);	

    rcu_periph_clock_enable(RCU_GPIOA);

    /* connect port to USARTx_Tx */
    gpio_af_set(GPIOA, GPIO_AF_4, USART_MB1_TX_PIN);

    /* connect port to USARTx_Rx */
    gpio_af_set(GPIOA, GPIO_AF_4, USART_MB1_TX_PIN);

    /* configure USART Tx as alternate function push-pull */
    gpio_mode_set(GPIOA, GPIO_MODE_AF, GPIO_PUPD_PULLUP, USART_MB1_TX_PIN);
    gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_10MHZ, USART_MB1_TX_PIN);

    /* configure USART Rx as alternate function push-pull */
    gpio_mode_set(GPIOA, GPIO_MODE_AF, GPIO_PUPD_PULLUP, USART_MB1_RX_PIN);
    gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_10MHZ, USART_MB1_RX_PIN);
}


