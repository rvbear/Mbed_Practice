#include "mbed.h"

DigitalOut led(LED1);
DigitalIn but(D2, PullUp);

int main() 
{
    while(1)
    {
        // Button을 누르지 않는다면 LED를 켜줌
        // led.write(!but.read()); 와 동일한 코드
        led = !but;
    }
}
