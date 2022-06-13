// NetId: malnim3
// UIN: 658699977
// Lab4
// Youtube link: https://youtu.be/Vjb6nvvwoVg
// In this lab, I created a device which detected the 
// amount of light in a particular room. To do this I used
// the same arduino set up from our last lab and added a photoresister to dectect 
// how much light was being exposed. Once I created the setup, I determined what was 
// the range that would be identifed as dark, partically dark, etc. I then created 
// a bunch of if statements which would determine what type strenght of light was detected.
// Once the program determined what level of light was detected, it would display the
// results on the lcd.

#include <LiquidCrystal.h>
//This code was the sample code  
int lightPin = 0;  //define a pin for Photo resistor
int ledPin=11;     //define a pin for LED


// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int amountLight = 0;

void setup()
{
    //This code was the sample code    
    Serial.begin(9600);  //Begin serial communcation
    pinMode( ledPin, OUTPUT );

    //Sets up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    //Sets up the cursor for the LCD
    lcd.setCursor(0,0);
    lcd.print("Mashel Al-Nimer");
    //delay(100);
}

void loop()
{
    //This code was the sample code  
    Serial.println(analogRead(lightPin)); //Write the value of the photoresistor to the serial monitor.
    analogWrite(ledPin, analogRead(lightPin)/2);  //send the value to the ledPin. Depending on value of resistor 
                                                //you have  to divide the value. for example, 
                                                //with a 10k resistor divide the value by 2, for 100k resistor divide by 4.
   
  //Dark is going to include the range from 100 - 300
  //Partially dark is going to include the ranege from 300 - 500
  //Medium is going to include therange from 500 - 700
  //Partially light is going to include the range form 700 - 900
  //Full light is going to include the range from 900+  

  //This reads in the values of the photoresistor 
  amountLight = analogRead(lightPin/2);

  //These if statements are going to determine what strenght of light is being detected and display it on the lcd
  if(amountLight >= 900){
    lcd.setCursor(0,0);
    lcd.clear();
    lcd.print("Full Light");
    }
  if(amountLight >= 700 && amountLight < 900){
    lcd.setCursor(0,0);
    lcd.clear();
    lcd.print("Partial Light");
    } 
  if(amountLight >= 500 && amountLight < 700){
    lcd.setCursor(0,0);
    lcd.clear();
    lcd.print("Medium Light");
    }
  if(amountLight >= 300 && amountLight < 500){
    lcd.setCursor(0,0);
    lcd.clear();
    lcd.print("Partcially Dark");
    }
  if (amountLight <= 300){
    lcd.setCursor(0,0);
    lcd.clear();
    lcd.print("Dark");
    }

  delay(500); //short delay for faster response to light.
  
}
