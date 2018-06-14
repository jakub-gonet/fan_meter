# Fan meter

This project was written to achieve a simple tachometer. It measures the voltage on fan and outputs appropriate voltage to a symmetrical voltage meter.

It was also a test to try using OOP and C++ on embedded project. It works suprisingly well after some tweaks.
Unfortunately, I couldn't force the avr-gcc to automatically inline some methods, so I had to mark them as inline by myself.


## Compiling

This project is written to work on Atmega8, but it should work on uCs from atmega family.
Compiling requires having avr-gcc and avr-objcopy packages installed.
After having that ready commands are pretty simple:

```
avr-gcc -Os -mmcu=atmega8 $(find ./src -type f -name '*.cpp'  ) -o ./bin/program.elf

avr-objcopy -O ihex -j .text -j .data ./bin/program.elf ./bin/program.hex 
```

Additionally, `program.hex` file size can be checked for fitting in uC memory by using:
```
wc -c < ./bin/program.hex
```
