#include "mbed.h"
#include <string>

DigitalOut led1(LED1);
UnbufferedSerial pc(USBTX, USBRX);
volatile bool gotPacket = false;
volatile float data[3];

void onSerialRx() {
    static char serialInBuffer[32];
    static int data_cnt = 0, buff_cnt = 0;
    if(pc.readable()) {
        char byteIn;
        pc.read(&byteIn, 1);

        if(byteIn==',') {
            serialInBuffer[buff_cnt] = '\0';
            data[data_cnt++] = atof(serialInBuffer);
            buff_cnt = 0;
        } else if(byteIn == '\n') {
            serialInBuffer[buff_cnt] = '\0';
            data[data_cnt] = atof(serialInBuffer);
            buff_cnt = 0; data_cnt = 0;
            gotPacket = true;
        } else {
            serialInBuffer[buff_cnt++] = byteIn;
        }
    }
}

int main () {
    pc.attach(&onSerialRx);
    while(true) {
        if(gotPacket) {
            gotPacket = false;
            printf("data= %d.%d, %d.%d, %d.%d\n\r", (int)data[0], (int)((data[0] - (int)data[0])),
                                                    (int)data[1], (int)((data[1] - (int)data[1])),
                                                    (int)data[2], (int)((data[2] - (int)data[2])));
        }
        led1=!led1;
        ThisThread::sleep_for(200ms);
    }
}
