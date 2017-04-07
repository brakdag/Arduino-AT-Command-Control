
/*
Arduino serial-remote control.

commands
=========
separator ;

AT

*/
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
}

void loop() {
  // print the string when a newline arrives:
  if (stringComplete) {
    command_listener();
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}
void command_listener()
{
  char buf[50];
  if (inputString=="AT\r\n") Serial.println("OK");
  if (inputString=="AT+CCLK\r\n"){
    unsigned long tiempo = millis();
    sprintf(buf, "%lu", tiempo); 
    Serial.println( buf );
    Serial.println("OK");
    }
  
  
}
    
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
 


