// Video to Youtube: https://youtu.be/J6m2S_DmM44
bool status = false;
long count = 0;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  if(count == 0){
    if(status){
      digitalWrite(12, HIGH);
      digitalWrite(11, LOW); 
      status = false;
      }else{
        digitalWrite(12, LOW);
        digitalWrite(11, HIGH); 
        status = true;
        }
        count = 160000;
    }
    count--;
}
