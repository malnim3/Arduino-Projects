
//Link to YouTube Video: https://youtu.be/S5SeVBpgC7E
// Mashel Al-Nimer
// malnim3
// 658699977
// Lab 2 
const int incButtonPin = 2; // Button for increasing count
const int decButtonPin = 3; // Button for decreasing count
const int greenLedPin =  13; // 2^2
const int redLedPin = 11; // 2^0
const int blueLedPin = 12; //2^1   

int count = 0; // counter
boolean incButtonState = 0; // state of increasing button    
boolean decButtonState = 0; // state of decreasing button
boolean currInc = 0; // what digital reading gives us for decreasing button
boolean currDec = 0; // what digital reading gives us for decreasing button

//Defining what are the outputs and inputs
void setup() {
  // initialize the LED pin as an output:
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
  pinMode(incButtonPin, INPUT);
  pinMode(decButtonPin, INPUT);
  
}

void loop() {
  currInc = digitalRead(incButtonPin);
  currDec = digitalRead(decButtonPin);

  //Checks for which button was clicked
  if (currInc != incButtonState && currInc == 1 && count < 7) {
    count += 1;
  } 
  if(currDec != decButtonState && currDec == 1 && count > 0 ){
    count -= 1;
  }

  //Lights up different LED's depending on value of count
  if(count % 2 == 1){
    digitalWrite(redLedPin,HIGH);
    }else{
      digitalWrite(redLedPin, LOW);
      }
  if(count > 3){
    digitalWrite(greenLedPin,HIGH);
    }else{
      digitalWrite(greenLedPin,LOW);
      }
  if(count > 1 && count != 4 && count!= 5){
    digitalWrite(blueLedPin,HIGH);
    }else{
      digitalWrite(blueLedPin,LOW);
      }
      
  incButtonState = currInc;
  decButtonState = currDec;
}
