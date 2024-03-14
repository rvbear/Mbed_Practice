#include "mbed.h"

DigitalOut myled(LED1);

int main() 
{
    while (1) 
    {
        // 원래 코드
        // 현재 wait 함수 사용이 막힘
        // myled = 1;
        // wait(0.2);
        // myled = 0;
        // wait(1.0);

        myled = 1;  // LED ON
        ThisThread::sleep_for(200ms);   // wait 함수 대용
        myled = 0;  // LED OFF
        ThisThread::sleep_for(1s);      // wait 함수 대용
    }
}
