#include "mbed.h"

DigitalOut led1(LED1);
DigitalOut led2(D7);
InterruptIn btn(BUTTON1);

void flip() {
    led2 = !led1;
}

int main() 
{
    btn.fall(&flip);
    while(1)
    {
        led1 = !led1;
        ThisThread::sleep_for(100ms);
    }
}
