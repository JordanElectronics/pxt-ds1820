// tests go here; this will not be compiled when this package is used as a library
input.onButtonPressed(Button.AB, () => {
    basic.showNumber(DS1820.Temperature())
    serial.writeValue("Temperature", DS1820.Temperature())
})
