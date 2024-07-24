#include <Servo.h>
#include <bits/stdc++.h> 
#include <stdexcept>

using namespace std;  

//defines servo objects
Servo servo1;

//defines pin for led used for testing
int pinNum = 10;

void setup() 
{ 
  //sets light led pin as output
  pinMode(pinNum, OUTPUT);

  //sets pins for servo objects

  servo1.attach(22);
  // Initialize the Serial
  Serial.begin(9600);
  
}

void loop() {
  
  // Check to see if Serial data is being received
  if (Serial.available() > 0) {
    
    // Create a new string variable to receive Serial data
    String receivedString = "";
    
    // Loop through received data and append to the receivedString variable
    while (Serial.available() > 0) {
      receivedString += Serial.readString();
    }
    
    //kinda undoes the thing from before ill make this better later
    char input[receivedString.length()+1]= strcpy(receivedString.c_str());

    //goes through the array to find the strings for each command
    for(int i =0; i<input.length(); i+=6){
      //ensures its reading it properly
      if(input[i] != '!'){
        throw std::invalid_argument("received incompatible data");
      }
      //finds what command
      switch(intput[i+1]){
        //control servo 1
        case '1':
          String str = input[i+3] + intout[i+4]+input[i+5];
          moveServo1(atoi(str));
          break;
        //control the led
        case 'L':
          if(input[i+3] == 'I'){
            digitalWrite(pinNum, HIGH);
          }else{
            digitalWrite(pinNum, LOW);
          }
      }
    }

    // Print received Serial data
    //Serial.println(receivedString);
    
  }

}

boolean moveServo1(int degree){
  servo1.write(degree);
  return true;
}