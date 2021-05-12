/*
 예제 5.2.2
 스위치 입력마다 LED On/Off 바꾸기
 바운싱 없는 스위치 입력 받기
 스위치 입력 횟수를 시리얼 통신으로 전송하기
 */

// 내장된 LED 사용을 위해 13번핀을 출력으로 설정
const int ledPin = 13;   
// 2번핀을 스위치 입력으로 설정
const int inputPin = 2;
// 실제 스위치가 눌린 후 지연되는 시간
const int swCountTime = 10;
// 스위치 입력 횟수 저장 변수
int count = 0;
// 실제 스위치가 눌린 시간을 계산하기 위한 변수
int swCountTimer = 0;

void setup() {
  // 13번 핀에 내장된 LED를 출력으로 설정한다
  pinMode(ledPin, OUTPUT);
  // 스위치 입력을 위하여 2번핀을 입력으로 설정하고 풀업시킨다
  pinMode(inputPin, INPUT_PULLUP);
  // 시리얼 통신을 설정한다  
  Serial.begin(9600);  
}

void loop(){

  // LED의 출력 상태를 확인한다
  int ledOutput = digitalRead(ledPin);
  
  // swCheck(핀번호) 루틴에서 HIGH, LOW 값을 받는다.
  if (swCheck(inputPin)){
    if (ledOutput)  digitalWrite(ledPin, LOW);// LED가 점등되어 있으면 소등
    else   digitalWrite(ledPin, HIGH);// LED가 소등되어 있으면 점등
    ++count;
    Serial.println(count);  // 스위치 입력 횟수를 시리얼 통신으로 전송한다.
  };
}

boolean swCheck(int pin){  // 스위치 입력을 정확하게 조사.
  
  // 스위치 입력을 받는다
  boolean swInput = digitalRead(pin);
  // 스위치 입력을 리턴할 변수
  boolean state;

  // 실제 스위치가 입력되었을 경우  
  if(swInput == LOW){
    // swCountTimer 변수가 swCountTime 보다 클 때
    if(swCountTimer >= swCountTime){

      // 두 값이 같아지면 state에 HIGH를 저장
      if(swCountTimer ==  swCountTime)  state = HIGH;
      else state = LOW;  // 아닐경우 LOW를 저장

          // 다음번 실행 시 LOW에 고정되도록 swCountTimer를 조정함
	  swCountTimer = swCountTime + 1;
     }
     else{
       // 실제 스위치 입력 시간이 swCountTime보다 작을때 
       // swCountTime을 증가시켜준다.
       ++swCountTimer;  
     }
  }
  else{
    // 실제 스위치 입력이 없을 때 state에 LOW를 저장한다.
    state = LOW;
    // 실제 스위치 입력이 없을 때 swCountTimer를 초기화 한다.
    swCountTimer = 0;
  }
  // 이 루틴이 끝날 때 state 값을 리턴한다.
  return state;
}
