#include "mbed.h"

AnalogIn POT(A0);

int main() 
{
    while(1)
    {
        float voltage = POT * 3.3f;
        uint16_t value = POT.read_u16();
        // %f가 지원은 하지만 현재 보드로 출력에 문제가 있음
        // 따라서 정수 부분과 실수 부분을 따로 구해서 정수형으로 출력
        printf("POT Value = %u, Voltage = %u.%-2u \n", value, (int)voltage, (int)((voltage - (int)voltage) * 100.));
        ThisThread::sleep_for(500ms);
    }
}
