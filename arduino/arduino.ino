#include <Servo.h>
#include <bits/stdc++.h> 
using namespace std;  

Servo servo1;
int pinNum = 10;

void setup() 
{ 
  pinMode(pinNum, OUTPUT);

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
    
    char input[receivedString.length()+1]= strcpy(receivedString.c_str());

    // Print received Serial data
    //Serial.println(receivedString);
    
    // status based on received data
    if(receivedString == "1"){
      servo1.write(180); 
      Serial.print(receivedString);
    } 
    else if(receivedString == "0"){
      servo1.write(0);
      Serial.print(receivedString);
    } 
    else if(receivedString == "I"){
      digitalWrite(pinNum, HIGH);
    } 
    else if(receivedString == "O"){
      digitalWrite(pinNum, LOW);
    } 
  }

}
