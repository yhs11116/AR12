#include <Wire.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  
Servo motor;

const int inputPin0 = 0;
const int inputPin2 = 2;
int servoMotorPin = 7;

int potentioMeterPin = 0;
int motorAngle;
int motorAngleOld;


const int led1 = 8;
const int led2 = 9;

const int waterLevelPin = 0;
const int waterFullAdcValue = 798;


int buzzer = 12;
int Length = 5;

char note1[] = "c    ";
char note2[] = "c c c";
int beats[] = {1,1,1,1,1};
int tempo = 200;

void setup() {
  pinMode(buzzer, OUTPUT);
  
  motor.attach(servoMotorPin,600,2400);
  pinMode(inputPin0, INPUT_PULLUP);
  pinMode(inputPin2, INPUT_PULLUP);
  
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  
  lcd.init(); 
  lcd.backlight(); 

  lcd.print("ex 6.4");
  lcd.setCursor(0,1);
  lcd.print("Water Level");

  delay(2000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ADC :  ");
  lcd.setCursor(0,1);
  lcd.print("Water Level:");
  lcd.setCursor(15,1);
  lcd.print("%");
}

void loop(){
  int duration;

  int swInput0 = digitalRead(inputPin0); 
  int swInput2 = digitalRead(inputPin2);
  int potentioMeter = analogRead(potentioMeterPin);

  int adcValue; 
  int waterLevel; 
    
  adcValue = analogRead(waterLevelPin);
  waterLevel = map(adcValue, 0, waterFullAdcValue, 0, 100);
 
  lcd.setCursor(9,0);
  lcd.print("    "); 
  lcd.setCursor(9,0);
  lcd.print(adcValue);
  lcd.setCursor(13,1);  
  lcd.print("  ");
  lcd.setCursor(12,1);  
  lcd.print(waterLevel);

  delay(200);

  if (adcValue <= 450){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }
  else if (adcValue >= 450 && adcValue <= 600){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);

    for (int i = 0; i < Length; i++){
      duration = beats[i] *tempo;
      if (note1[i] == ' '){
        delay(duration);
      }
      else{
        tone(buzzer, frequency(note1[i]),duration);
        delay(duration);
      }
    }
  }
  else if (adcValue >= 600){
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);

    for (int i = 0; i < Length; i++){
      duration = beats[i] *tempo;
      if (note2[i] == ' '){
        delay(duration);
      }
      else{
        tone(buzzer, frequency(note2[i]),duration);
        delay(duration);
      }
    }
  }


  if (adcValue <= 300){
    motor.write(0);
  }
  else if (adcValue >= 670){
    motor.write(90);
  }


  if (swInput0 == LOW){
    motor.write(0);
  }
  else if (swInput2 == LOW){
    motor.write(90);
  }
}

int frequency(char note){
  int i;
  int note1 = 8;
  int note2 = 8;

  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523};
  for (i = 0; i < (note1 && note2); i++){
    if (names[i] == note){
      return(frequencies[i]);
    };
  };
  return(0);
}
