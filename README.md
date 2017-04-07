# Arduino AT Command Control
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
| `ATDOH+<PIN>`| Write in HIGH in digital output. | `OK` |
| `ATDOL+<PIN>`| Write in LOW in digital output. | `OK` |
| `ATDIN+<PIN>`| Read digital input. | value |
| `ATDIP+<PIN>`| Read digital input with internal pullup resistor. {0,1}| value |
| `ATAI+<PIN>`| Read analog input. | value |

# Examples

```
ATDOH+13  //change status pin 13 to HIGH

ATDOL+13 //change status pin 13 to LOW

```


# License

MIT
