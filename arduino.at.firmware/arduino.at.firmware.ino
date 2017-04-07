
/*
Arduino serial-remote control.

commands
=========
separator ;

AT

*/
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

// RESET PUT ALL OUTPUT IN LOW AND GOTO START CODE.
void reset(){
  
  for(int i=0; i<=13 ; i++)   
  {
    pinMode(i,OUTPUT);
    digitalWrite(i,LOW); 
  }
  asm volatile ("  jmp 0");
}
void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  
  inputString.reserve(200);
  Serial.println("# Arduino AT command Control 1.0. RUNNING #");
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
  if (inputString.substring(0,6)=="ATDOH+"){
    String strPin =  inputString.substring(6);
    pinMode(strPin.toInt(),OUTPUT);
    digitalWrite(strPin.toInt(),HIGH);
    Serial.println("OK");
    }
  if (inputString.substring(0,6)=="ATDOL+"){
    String strPin =  inputString.substring(6);
    pinMode(strPin.toInt(),OUTPUT);
    digitalWrite(strPin.toInt(),LOW);
    Serial.println("OK");
    }
  
  if (inputString.substring(0,6)=="ATDIN+"){
    String strPin =  inputString.substring(6);
    pinMode(strPin.toInt(),INPUT);
    Serial.println(digitalRead(strPin.toInt()));
    Serial.println("OK");
    }
      
  if (inputString.substring(0,6)=="ATDIP+"){
    String strPin =  inputString.substring(6);
    pinMode(strPin.toInt(),INPUT_PULLUP);
    Serial.println(digitalRead(strPin.toInt()));
    Serial.println("OK");
    }
      
  if (inputString.substring(0,6)=="ATAI+"){
    String strPin =  inputString.substring(5);
    Serial.println(analogRead(strPin.toInt()));
    Serial.println("OK");
    } 
      
  if (inputString=="AT+RESET\r\n"){
    reset();
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
 


