# Arduino AT Command Control
[![Build Status](https://travis-ci.org/brakdag/Arduino-AT-Command-Control.svg?branch=master)](https://travis-ci.org/brakdag/Arduino-AT-Command-Control)

The purpose of this project is remote control from AT commands using serial comunication. AT commands have been used by different hardware companies, and it's easy to use.
# Getting Started
Clone this project
`git clone https://github.com/brakdag/Arduino-AT-Command-Control.git`

* Download the latest version of the arduino ide, from the official page,
* Open in Arduino IDE the file in `/src/arduino.at.firmware.ino`.
* Connect the Arduino, compile and upload.
* Open Serial Monitor, change to `Both LN & CR` and `9600baud`

Now you just have to write the commands and see how it works. It's very simple.

* Type `AT` if will be return `OK`   

# AT command list

| AT command | Description | return |
|-|-|-|
| `AT` | Check status comunication. | `OK` |
| `AT+RESET` | Restart Arduino. | `OK` 
| `AT+CCLK` | Get time in milliseconds after Arduino start. | value |
| `ATDOH+<PIN>`| Set pin to HIGH. | `OK` |
| `ATDOL+<PIN>`| Set pin to LOW. | `OK` |
| `ATDIN+<PIN>`| Read pin digital input. | value |
| `ATDIP+<PIN>`| Read pin digital input with internal pull up resistor. | value |
| `ATAI+<PIN>`| Read analog input. | value |

# Examples

```
ATDOH+13  //change status pin 13 to HIGH

ATDOL+13 //change status pin 13 to LOW

```

# Example with Nodejs
Install `nodejs` and `npm` then run the follow code.

```shell
npm install
node node/blink.js
```
# License

MIT
