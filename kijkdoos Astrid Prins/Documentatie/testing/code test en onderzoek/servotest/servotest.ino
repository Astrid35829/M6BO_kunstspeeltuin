// Include the servo library:
#include "Servo.h"

//create a new servo object 
Servo servoArray[6]; //create array of servo object

//assign button to pin 7
#define BUTTON_PIN 7

//make buttonstate variable
int lastButtonState;

void setup() {
  //start serial monitor
  Serial.begin(115200);
  
  //servo
  // attach the servo variable to a pin:
  servoArray[1].attach(9);
  servoArray[2].attach(10);
  servoArray[3].attach(11);
  servoArray[4].attach(8);
  servoArray[5].attach(12);
  servoArray[6].attach(13);
  
  //button
  //enable internal pullup resistor
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  lastButtonState = digitalRead(BUTTON_PIN);
}

void loop() {
  //button
  //read the value of the button
  int buttonState = digitalRead(BUTTON_PIN);

  if(lastButtonState != buttonState){ //state change
    delay(50); // debounce time
    
    if(buttonState == LOW){
      Serial.println("button pressed");
      //random
      for(int i = 0; i < 6; i++){
        int random_Number = random(0,14);
        Serial.println(random_Number);
        servoArray[random_Number].write(0);
      }
      servoArray[6].write(0);
      delay(3000);
      for(int i = 0; i < 6; i++){
        servoArray[i].write(90);
      }
    }
    lastButtonState = buttonState;
  }
}

/*
  LDR_ON = (lichtHoeveelheid[1] + lichtHoeveelheid[2] + lichtHoeveelheid[3] + lichtHoeveelheid[4] + lichtHoeveelheid[5] + lichtHoeveelheid[6] + lichtHoeveelheid[7] + lichtHoeveelheid[8] + lichtHoeveelheid[9] + lichtHoeveelheid[10]) / 10;
  if(lichtHoeveelheid < 300){
      //Turn off led
      for(int i = 0; i < ledInArray[i]; i++){
        digitalWrite(ledInArray[i], LOW);
      }
    //first position Servo's
      for(int i = 0; i < 6; i++){
        servoArray[i].write(90);
      }
  }
  else{
    for(int i = 0; i < 3; i++){
        //random LED  
         int randomNumber = random(0,4);
         Serial.println("Led lamp " + randomNumber);
         digitalWrite(ledInArray[randomNumber], HIGH);
      }
      //random Servo
      for(int i = 0; i < 6; i++){
        int random_Number = random(0,14);
        Serial.println("Servo :" + random_Number);
        servoArray[random_Number].write(0);
      }     
  }

  for(int i = 0; i < 3; i++){
        //random LED  
         int randomNumber = random(0,4);
         Serial.println("Led lamp " + randomNumber);
         digitalWrite(ledInArray[randomNumber], HIGH);
      }
      //Turn off led
      for(int i = 0; i < ledInArray[i]; i++){
        digitalWrite(ledInArray[i], LOW);
      }
  


  bool value = digitalRead(sensor);

  if(on != value){
    delay(50); // debounce time

    if(value == 0){
      //first position Servo's
      for(int i = 0; i < 6; i++){
        servoArray[i].write(90);
      }
      Serial.println("laser connected");
    }
    if(value == 1){
      for(int i = 0; i < 6; i++){
        int random_Number = random(0,14);
        Serial.println(random_Number);
        servoArray[random_Number].write(0);
      } 
      Serial.println("loop end"); 
    }
    on = value;
  }
  */
