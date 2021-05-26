/*
 예제 7.2
 서보모터 구동
*/

// 서보모터 라이브러리 불러오기
#include <Servo.h> 

// 서보모터 이름 설정
Servo motor1; 

const int inputPin0 = 0;
const int inputPin2 = 2; 
// 서보 모터 신호핀 설정
int servoMotorPin = 9;

// 포텐쇼미터 핀 설정
int potentioMeterPin = 0;

// 모터 각도 변수 설정
int motorAngle;
int motorAngleOld;

void setup() {
  
  // 서보모터 설정. 0.6ms 부터 2.4ms 범위로 설정
  motor1.attach(servoMotorPin,600,2400);
  pinMode(inputPin0, INPUT_PULLUP);
  pinMode(inputPin2, INPUT_PULLUP);
  // 시리얼 통신 설정  
  Serial.begin(9600);
}

void loop(){
  // 포텐쇼미터 값을 읽어옴

  int swInput0 = digitalRead(inputPin0); 
  int swInput2 = digitalRead(inputPin2);
  
  int potentioMeter = analogRead(potentioMeterPin);

  if (swInput0 == LOW){
    motor1.write(0);
    delay(100);
  }

  else if(swInput2 == LOW){
    motor1.write(290);
    delay(100);
  }

  // 이전각도와 현재 각도가 같지 않으면 시리얼 모니터에 각도를 출력한다.  
  if(motorAngle != motorAngleOld){
    Serial.print("Servo Motor Angle is: ");
    Serial.println(motorAngle);
  }

  // 현재의 모터 각도를 저장한다.
  motorAngleOld = motorAngle;
  
  delay(20);

}
