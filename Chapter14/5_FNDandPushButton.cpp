#include "mbed.h"

BusIn pbs(D10, D11, D12, D13);
BusOut fnd(D2, D3, D4, D5, D6, D7, D8, D9);
uint16_t num[] = {0x77, 0x41, 0x3B, 0x6B, 0x4D, 0x6E, 0x7E, 0x43, 0x7F,
                    0x4F, 0x7B, 0x7C, 0x38, 0x79, 0x3E, 0x1E};      //FND DATA

int main() {
    pbs.mode(PullUp);
    fnd = 0xFF;     // all off
    uint16_t cnt = 0;
    while(true) {
        fnd = num[pbs^0x0F];
        ThisThread::sleep_for(100ms);
    }
}
