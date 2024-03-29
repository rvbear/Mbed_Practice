#include "mbed.h"

class CounterUD {
    InterruptIn _upBot, _downBot;
    volatile uint16_t _count;
    volatile bool _updated;

    void plus() {
        _count++;
        _updated = true;
    }

    void minus() {
        _count--;
        _updated = true;
    }

    public:
    CounterUD(PinName p1, PinName p2): _upBot(p2, PullUp), _downBot(p1, PullUp) {
        _count = 0;
        _updated = false;
        _upBot.fall(callback(this, &CounterUD::plus));
        _downBot.fall(callback(this, &CounterUD::minus));
    }
    int read() {
        _updated = false;
        return _count;
    }
    bool isUpdated() {
        return _updated;
    }
};

CounterUD cnt(D2, D3);

int main() {
    while(1) {
        if(cnt.isUpdated()) {
            printf("count = %3d\n", cnt.read());
            ThisThread::sleep_for(100ms);
        }
    }
}
