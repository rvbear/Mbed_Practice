#include "mbed.h"

Timer watch;

int main() {
    while(true) {
        watch.reset();
        watch.start();
        printf("PRINT 15bytes! \n");
        watch.stop();
        printf("It takes about %5u us\n", watch.read_us());
        ThisThread::sleep_for(1s);
    }
}
