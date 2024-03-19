#include "mbed.h"

DigitalIn but(BUTTON1);

int main() 
{
    srand(time(NULL));
    while(1)
    {
        if(!but)
        {
            printf("%u \n", rand() % 6 + 1);
            ThisThread::sleep_for(2000ms);
        }
    }
}
