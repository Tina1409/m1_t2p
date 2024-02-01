//constants
const int pirPin = 2;   
const int ledPin = 13;  

volatile int pirState = LOW;
int val = 0;            

//setup (only runs once)
void setup() {
  pinMode(ledPin, OUTPUT); 
  pinMode(pirPin, INPUT);  
  Serial.begin(9600);      
  attachInterrupt(digitalPinToInterrupt(pirPin), pirInterrupt, CHANGE);
}


void loop() {
}

//Interrupt 
void pirInterrupt() {
  val = digitalRead(pirPin); 

  if (val == HIGH) {  
    digitalWrite(ledPin, HIGH); 
    if (pirState == LOW) {
      Serial.println("Motion detected!");
      pirState = HIGH;
    }
  } else {
    digitalWrite(ledPin, LOW);
    if (pirState == HIGH){
      Serial.println("Motion stopped!");
      pirState = LOW;
    }
  }
}
