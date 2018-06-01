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

enum class Pins{
  P0=  3,
  P1=  2,
  P2=  1,
  P3=  4,
  P4=  5,
  P5=  17,
  P6=  12,
  P7=  11,
  P8=  18,
  P9=  10,
  P10= 6,
  P11= 26,
  P12= 20,
  P13= 23,
  P14= 22,
  P15= 21,
  P16= 16,
  P19= 0,
  P20= 30
};

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
    int16_t Temperature(int InPin, int OutPin) {
        
        switch (InPin) {
            case 0: ReadPin = uBit.io.P0; break;
            case 1: ReadPin = uBit.io.P1; break;
            case 2: ReadPin = uBit.io.P2; break;
            case 3: ReadPin = uBit.io.P3; break;
            case 4: ReadPin = uBit.io.P4; break;
            case 5: ReadPin = uBit.io.P5; break;
            case 6: ReadPin = uBit.io.P6; break;
            case 7: ReadPin = uBit.io.P7; break;
            case 8: ReadPin = uBit.io.P8; break;
            case 9: ReadPin = uBit.io.P9; break;
            case 10: ReadPin = uBit.io.P10; break;
            case 11: ReadPin = uBit.io.P11; break;
            case 12: ReadPin = uBit.io.P12; break;
            case 13: ReadPin = uBit.io.P13; break;
            case 14: ReadPin = uBit.io.P14; break;
            case 15: ReadPin = uBit.io.P15; break;
            case 16: ReadPin = uBit.io.P16; break;
            case 19: ReadPin = uBit.io.P19; break;
            case 20: ReadPin = uBit.io.P20; break;
            //default: ReadPin = uBit.io.P12;
        }
        switch (OutPin) {
            case 0: WritePin = uBit.io.P0; break;
            case 1: WritePin = uBit.io.P1; break;
            case 2: WritePin = uBit.io.P2; break;
            case 3: WritePin = uBit.io.P3; break;
            case 4: WritePin = uBit.io.P4; break;
            case 5: WritePin = uBit.io.P5; break;
            case 6: WritePin = uBit.io.P6; break;
            case 7: WritePin = uBit.io.P7; break;
            case 8: WritePin = uBit.io.P8; break;
            case 9: WritePin = uBit.io.P9; break;
            case 10: WritePin = uBit.io.P10; break;
            case 11: WritePin = uBit.io.P11; break;
            case 12: WritePin = uBit.io.P12; break;
            case 13: WritePin = uBit.io.P13; break;
            case 14: WritePin = uBit.io.P14; break;
            case 15: WritePin = uBit.io.P15; break;
            case 16: WritePin = uBit.io.P16; break;
            case 19: WritePin = uBit.io.P19; break;
            case 20: WritePin = uBit.io.P20; break;
            //default: WritePin = uBit.io.P13;
        }


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
