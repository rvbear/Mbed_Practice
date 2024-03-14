#include "mbed.h"

DigitalOut myled(LED1);

int main() 
{
    srand(time(NULL));
    while (1) 
    {
        // 랜덤한 수를 생성하고
        // 0.1 미만일 경우 LED ON, 이상일 경우 LED OFF
        float v = (float)rand() / (float)RAND_MAX;
        myled = (v < 0.1f) ? 1 : 0;
        ThisThread::sleep_for(100ms);
    }
}
