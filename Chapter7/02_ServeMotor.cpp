#include "mbed.h"

PwmOut rcServo(D6);
AnalogIn POT(A0);

void turn(PwmOut &rc, float deg);
template <class T>
T map(T x, T in_min, T in_max, T out_min, T out_max);

int main() 
{
    float ang = 0., inc = 0.1;
    rcServo.period_ms(10);
    turn(rcServo, 0);
    while(1)
    {
        inc = 2.0f * POT - 1.0f;
        ang += inc;

        if(ang > 180.0f) {
            ang = 180.0f;
        } else if(ang < 0.0f) {
            ang = 0.0f;
        }

        turn(rcServo, ang);
        ThisThread::sleep_for(1000ms);
    }
}

void turn(PwmOut &rc,float deg) // RC모터 구동
{
    uint16_t pulseW=map<float>(deg,0.,180.,600.,2400.);
    rc.pulsewidth_us(pulseW);
}

template <class T> // map함수
T map(T x, T in_min, T in_max, T out_min, T out_max) 
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
