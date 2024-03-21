#include "mbed.h"

// LED1 PA_8
PwmOut pwm(D7);

int main() 
{
    int count = 0;
    pwm.period_us(25);    // 40KHz
    while(1)
    {
        pwm = count / 100.;
        count++;
        count %= 101;
        ThisThread::sleep_for(100ms);
    }
}
