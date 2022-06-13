
// NetId: malnim3
// UIN: 658699977
// Lab 3
// YouTube Video: https://www.youtube.com/watch?v=v6XcbkS4PV8
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.setCursor(0,0);
  lcd.print("Mashel Al-Nimer");
  lcd.setCursor(0,1);
  lcd.print("There's a lot of beauty in ordinary things."); //Last line of the Office, said by Pam
  delay(500);
}

void loop() {

  //Moves quote to right
  for(int i = 0; i < 59; i ++){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Mashel Al-Nimer");
    lcd.setCursor(i,1);
    lcd.print("There's a lot of beauty in ordinary things.");
    //curXPos += 1;
    delay(200);
    }

  //Moves quote the beginning 
  for(int i = 59; i > -3; i--){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Mashel Al-Nimer");
    lcd.setCursor(i,1);
    lcd.print("There's a lot of beauty in ordinary things.");
    delay(200);
    }

}
