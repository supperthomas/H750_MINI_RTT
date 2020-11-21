#include "stm32h7xx.h"
#include "rtthread.h"
#define GPIO_PIN_8                 ((uint16_t)0x0100)  /* Pin 8 selected    */
struct rt_semaphore dynamic_sem;

int main(void)
{
    int i;
    rt_sem_init(&dynamic_sem, "dsem", 0, RT_IPC_FLAG_FIFO);
    static rt_err_t result;
    RCC->AHB4ENR |= RCC_AHB4ENR_GPIOIEN;
    GPIOI->MODER = 0xFFFDFFFF;
    while(1)
    {
        result = rt_sem_take(&dynamic_sem, RT_WAITING_FOREVER);
        if(i%2 == 0)
        {
            GPIOI->BSRR = GPIO_PIN_8;
        }
        else
        {
            GPIOI->BSRR = GPIO_PIN_8 << 16;
        }
        i++;
    }
}

