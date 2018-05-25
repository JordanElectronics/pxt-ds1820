/**
* Jordan Electronics
* May, 2018
* Based on Weatherbit code from Sparkfun:
* https://github.com/sparkfun/pxt-weather-bit
*
* Development environment specifics:
* Written in Microsoft PXT
*
* This code is released under the [MIT License](http://opensource.org/licenses/MIT).
* Distributed as-is; no warranty is given.
*/

//% color=#5042f4 icon="\uf491"
namespace DS1820 {

    // Functions for interfacing with the DS1820

    /**
     * Reads the temperature from the one-wire temperature sensor.
	 * Returns a 4 digit number. value should be divided by 100 to get 
	 *temperature in hundreths of a degree centigrade. 
     */
    //% weight=10 blockId="DS1820_soilTemp" block="Temperature(C)"
    //% shim=DS1820::tempFunc
    export function Temperature(): number {
        // Fake function for simulator
        return 0
    }
}
