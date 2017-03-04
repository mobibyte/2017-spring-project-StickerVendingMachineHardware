#include <Servo.h>
#include <Wire.h>
#include <String.h>
#include "rgb_lcd.h"


rgb_lcd lcd;

const int colorR = 255;
const int colorG = 0;
const int colorB = 0;
const int pinButton = 3;

boolean touchStarted = false;
boolean b = false;

//Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
Servo servo1;
void setup() {
  servo1.attach(9);
  
  Serial.begin(9600);
  pinMode(pinButton, INPUT);            // set button INPUT
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
  //lcd.setRGB(colorR, colorG, colorB);
  
  // Print a message to the LCD.
  lcd.print("FUCK YOU");
  
  lcd.setCursor(3, 16);
  lcd.print("FUCKS GIVEN");

  delay(1000);
}

void loop() {
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    if (digitalRead(pinButton)) {
     
      if (!touchStarted){
          
          b = !b;
          Serial.write( b ? "FUCK " : "YOU\n");
          lcd.setCursor(0, 1);
          lcd.setRGB(random(255),random(255),random(255));
          // print the number of seconds since reset:
          lcd.print(millis()/1000);
          
          //Resets servo position
          if (servo1.read() == 180) {
            servo1.write(0);
            delay(1000);
            Serial.write(servo1.read());
          }
          //
          else {
            Serial.write(servo1.read());
            servo1.write(180);
            delay(1000);
            servo1.write(0);
           
           
          }
          
    }
//  servo1.attach(77);
//  delay(1000);
//    Serial.print(servo1.read());
   

    delay(100);
    }
}
