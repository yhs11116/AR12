



const int ledR = 3;
const int ledG = 5;
const int ledB = 6;
const int ledY = 9;

int dimTime = 20;

void setup() { 
  
}

void loop() {

  dimLed(ledR);
  
  dimLed(ledG);
  
  dimLed(ledB);
  
  dimLed(ledY);
}

void dimLed(int led) {
  
  for(int fadeValue = 0; fadeValue <= 255; fadeValue += 5) {

    analogWrite(led, fadeValue);

    delay(dimTime);
  }
  for(int fadeValue = 255; fadeValue >= 0; fadeValue -= 5) {

    analogWrite(led, fadeValue);

    delay(dimTime);
  }
}
