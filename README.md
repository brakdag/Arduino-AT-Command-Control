# Arduino AT Command Control
The purpose of this project is remote control from AT commands using serial comunication. AT commands have been used by different hardware companies, and is easy to use.
# Getting Started
Clone this project
`git clone https://github.com/brakdag/Arduino-AT-Command-Control.git`

* Download the latest version of the arduino ide, from the official page,
* Open in Arduino IDE the file in `/src/arduino.at.firmware.ino`.
* Connect the Arduino, compile and upload.
* Open Serial Monitor, change to `Both LN & CR` and `9600baud`

Now you just have to write the commands and see how it works. It's very simple.

* Type `AT` if will be return `OK`   

# AT command List

| AT command | Description | return |
|-|-|-|
| AT | Check status comunication. | OK |
| AT+CCLK | Get time in milliseconds after arduino start | Value |

# License

MIT
