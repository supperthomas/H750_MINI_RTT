#include "stm32h7xx.h"
#define GPIO_PIN_8                 ((uint16_t)0x0100)  /* Pin 8 selected    */

int main(void)
{
    int i;
    uint8_t abc = 0;
    RCC->AHB4ENR |= RCC_AHB4ENR_GPIOIEN;
    i++;
    GPIOI->MODER = 0xFFFDFFFF;
    for(i=0;;)
    {
        if(i == 1000000)
        {
            if(abc == 1)
            {
                GPIOI->BSRR = GPIO_PIN_8;
                abc =0;
            }
            else
            {
                abc = 1;
                GPIOI->BSRR = GPIO_PIN_8 << 16;
            }
            i = 0;
        }

        i++;
    }
}

