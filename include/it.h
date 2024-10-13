#ifndef H_IT
#define H_IT

extern uint32_t msTicks;

void setup_intrerupts();
void systick_config();

uint32_t millis();
void Delay (uint32_t dlyTicks);
void SysTick_Handler();
#endif
