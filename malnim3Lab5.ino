// NetId: malnim3
// UIN: 658699977
//Lab 5
//YouTube Video Link: https://youtu.be/X8NyxPlv4ZI
//In this lab we will be using the values of out sensor to change the number of
//led lights that will light up. We will then use the photoresistor to control 
//the buzzer. I burned my buzzer and it stopped working so I could not complete part 2 of this lab


int lightPin = 0;  //define a pin for Photo resistor
int ledPin=11;     //define a pin for LED
int potValue = 0; 
int potPin = 1; //defines the oin for potent.
int buzzerPin = 9; //The pin the actual buzzer is connected to
int realPotValue = 0;  

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzerPin,OUTPUT);
  
  //Setting all the pins for the led lights
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {

  //pushing the value of the sensor to potValue
  analogWrite(ledPin, analogRead(lightPin)/2); 
  potValue = analogRead(lightPin/2);
  
 //pushes the value of the photoresistor to realPotValue
  analogWrite(ledPin, analogRead(potPin));
  realPotValue = analogRead(potPin/2);

  //This was what I was testing before my buzzer burn out
  if(realPotValue < 1000){
    noTone(buzzerPin);
    }
  if(realPotValue >= 700){
      tone(buzzerPin,1000);
      }
  //tone(buzzerPin, 1000);

  //Dark is going to include the range from 100 - 300 aka all led light are lit
  //Partially dark is going to include the ranege from 300 - 500 aka 3 leds are lit
  //Medium is going to include therange from 500 - 700 aka 2 leds are lit
  //Partially light is going to include the range form 700 - 900 aka 1 led is lit
  //Full light is going to include the range from 900+  aka no leds are lit
  
  //No lights will be on 
  if(potValue >= 900 ){
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13,LOW);
    }

  //Only 1 LED will light up  
  if(potValue >= 700 && potValue < 900){
    digitalWrite(10,HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13,LOW);
    }

  //2 LED lights will light up
  if(potValue >=500 && potValue < 700){
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    }

  //3 LED lights will light up
  if(potValue >= 300 && potValue < 500){
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    }

  //4 LED lights will light up   
  if(potValue < 300){
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
    }

  
}
