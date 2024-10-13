#include "gd32f1x0.h"
#include "it.h"

void systick_config()
{
    /* setup systick timer for 1000Hz interrupts */
    if (SysTick_Config(SystemCoreClock / 1000U))
    {
        /* capture error */
        while (1)
        {
        }
    }
    /* configure the systick handler priority */
    NVIC_SetPriority(SysTick_IRQn, 0x00U);
}


uint32_t msTicks;
void SysTick_Handler()
{
  msTicks++;
}

uint32_t millis()
{
	return msTicks;
}


void Delay (uint32_t dlyTicks)
{
  uint32_t curTicks;

  curTicks = msTicks;
  while ((msTicks - curTicks) < dlyTicks)
	{
		__NOP();
	}
}


void setup_intrerupts() {
    nvic_irq_enable(USART1_IRQn, 0, 1);
    usart_interrupt_enable(USART1, USART_INT_TBE);
}

 uint8_t tx_size;
 uint8_t rx_size;
 __IO uint8_t txcount;
 __IO uint16_t rxcount;
 uint8_t rxbuffer[32];
 uint8_t txbuffer[];

/*!
    \brief      this function handles USART RBNE interrupt request and TBE interrupt request
    \param[in]  none
    \param[out] none
    \retval     none
*/
void USART1_IRQHandler(void)
{
    if(RESET != usart_interrupt_flag_get(USART1, USART_INT_FLAG_RBNE)){
        /* receive data */
        rxbuffer[rxcount++] = usart_data_receive(USART1);
        if(rxcount == rx_size){
            usart_interrupt_disable(USART1, USART_INT_RBNE);
        }
    }
    if(RESET != usart_interrupt_flag_get(USART0, USART_INT_FLAG_TBE)){
        /* transmit data */
        usart_data_transmit(USART1, txbuffer[txcount++]);
        if(txcount == tx_size){
            usart_interrupt_disable(USART1, USART_INT_TBE);
        }
    }
}
