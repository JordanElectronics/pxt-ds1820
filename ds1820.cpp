/**
* Jordan Electronics
* May, 2018
* Based on Weatherbit code from Sparkfun:
* https://github.com/sparkfun/pxt-weather-bit

* Development environment specifics:
* Written in Microsoft PXT
*
* This code is released under the [MIT License](http://opensource.org/licenses/MIT).
* Distributed as-is; no warranty is given.
*/

#include "pxt.h"
#include <cstdint>
#include <math.h>

using namespace pxt;

namespace DS1820 {
    MicroBitPin WritePin = uBit.io.P12;
    MicroBitPin ReadPin = uBit.io.P13;

    uint8_t init() {
        WritePin.setDigitalValue(0);
        for (volatile uint16_t i = 0; i < 600; i++);
        WritePin.setDigitalValue(1);
        for (volatile uint8_t i = 0; i < 30; i++);
        int b = ReadPin.getDigitalValue();
        for (volatile uint16_t i = 0; i < 600; i++);
        return b;
    }

    void sendZero() {
        WritePin.setDigitalValue(0);
        for (volatile uint8_t i = 1; i < 75; i++);
        WritePin.setDigitalValue(1);
        for (volatile uint8_t i = 1; i < 6; i++);
    }

    void sendOne() {
        WritePin.setDigitalValue(0);
        for (volatile uint8_t i = 1; i < 1; i++);
        WritePin.setDigitalValue(1);
        for (volatile uint8_t i = 1; i < 80; i++);
    }

    void writeBit(int b) {
        int delay1, delay2;
        if (b == 1) {
            delay1 = 1;
            delay2 = 80;
        } else {
            delay1 = 75;
            delay2 = 6;
        }
        WritePin.setDigitalValue(0);
        for (uint8_t i = 1; i < delay1; i++);
        WritePin.setDigitalValue(1);
        for (uint8_t i = 1; i < delay2; i++);
    }

    void sendskip() {
        writeBit(0);
        writeBit(0);
        writeBit(1);
        writeBit(1);
        writeBit(0);
        writeBit(0);
        writeBit(1);
        writeBit(1);
    }

    void writeByte(int byte) {
        int i;
        for (i = 0; i < 8; i++) {
            if (byte & 1) {
                writeBit(1);
            } else {
                writeBit(0);
            }
            byte = byte >> 1;
        }
    }

    int readBit() {
        volatile int i;
        WritePin.setDigitalValue(0);
        WritePin.setDigitalValue(1);
        for (i = 1; i < 20; i++);
        int b = ReadPin.getDigitalValue();
        for (i = 1; i < 60; i++);
        return b;
    }

    int convert() {
        volatile int i;
        int j;
        writeByte(0x44);
        for (j = 1; j < 1000; j++) {
            for (i = 1; i < 900; i++) {
        };
        if (readBit() == 1)
            break;
        };
        return (j);
    }

    int readByte() {
        int byte = 0;
        int i;
        for (i = 0; i < 8; i++) {
            byte = byte | readBit() << i;
        };
        return byte;
    }

    //%
    int16_t Temperature() {
        init();
        writeByte(0xCC);
        convert();
        init();
        writeByte(0xCC);
        writeByte(0xBE);
        int b1 = readByte();
        int b2 = readByte();

        int16_t temp = (b2 << 8 | b1);
        return temp * 100 / 16;
    }
 
}
