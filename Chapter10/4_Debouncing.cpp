#include "mbed.h"

class Debounce {
    InterruptIn _btn;
    Timeout _tmo;
    int _intval, _state, _ready;

    void btnISR() {
        if(_ready) {
            _ready = 0;
            _tmo.attach_us(callback(this, &Debounce::decide), _intval);
        }
    }

    void decide() {
        _state = 0;
        _ready = 1;
        _tmo.detach();
    }

    public:
        Debounce(PinName pin, int intv=100000) : _btn(pin) {
            _btn.fall(callback(this, &Debounce::btnISR));
            _state = 1;
            _ready = 1;
            _intval = intv;
        }

        int read() {
            int state = _state;
            _state = 1;
            return state;
        }

        operator int() {
            return read();
        }
};

int main() {
    Debounce dbc(BUTTON1, 100000);
    int count = 0;
    while(true) {
        if(!dbc) {
            count++;
            printf("count = %d", count);
        }
    }
}
