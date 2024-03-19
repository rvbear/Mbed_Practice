#include "mbed.h"

DigitalOut led(LED1);
DigitalIn but(D2, PullUp);

int main() 
{
    while(1)
    {
        // 내부 pull up으로 반전되기 때문에 눌리면 Low
        if(!but)
        {
            // LED 반전
            // led.write(!led.read()); 와 동일한 코드
            led = !led;
            ThisThread::sleep_for(3000ms);
        }
    }
}
