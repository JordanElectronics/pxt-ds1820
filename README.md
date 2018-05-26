# DS1820 Temperature Sensor MakeCode Package for Microbit 

## Supported Hardware
![](https://github.com/JordanElectronics/pxt-ds1820/blob/master/icon.png)

DS18B20 digital temperature sensor

or 

DS18B20 Pre-wired waterproof digital temperature sensor

## Hardware Details
For the pre-wired sensor: Red connects to 3V-5V, Blue/Black connects to ground, and Yellow/White is data.

## Hardware Connections
Use a 4.7K resistor as pull-up for the data pin.

The Microbit has to both read from and write to the data pin of the DS1820. Although the DS1820 has only a single pin for data, it is necessary to use two pins on the Microbit. One for reading and one for writing data. This is due to the strict timing requirements of the DS1820. Each time a pin on the Microbit is transitioning from read-mode to write-mode it takes a certain time. Using two pins - one or reading and one for writing - the transitioning between read-mode and write-mode is avoided.

The two pins on the Microbit are connected to the single data pin on the DS1820 with a 4.7K pull-up resistor.

Connect 3V and GND to the DS1820 as well.

## Block

After adding the DS1820 package in MakeCode, the block "Temperature(C)" is used to retrieve the temperature from the DS1820.

The "Temperature(C)" takes two parameters: Pin1 and Pin2. These are the two pins on the Microbit which are connected to the DS1820 sensor.

The value returned by the "Tempareature(C)" block is the temparature *100.

## Acknowledgements
The DS1820 read/write code is developed by Sparkfun for their [weatherbit](https://www.sparkfun.com/products/14214)

This is a generalized version of the code that can be used for any project with a DS1820 sensor on any two Microbit pins.

## Supported Targets
for PXT/microbit

## License
MIT
