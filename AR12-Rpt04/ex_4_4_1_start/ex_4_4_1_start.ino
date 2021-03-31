/*
 예제 4.4.1
 FND 제어 0~9까지 1초단위로 표시하기
*/
 
 // 0~9까지 LED 표시를 위한 상수 설정
const byte number[10] = {
//dot  gfedcba
  B11000000,  //0
  B11111001,  //1
  B10100100,  //2
  B10110000,  //3
  B10011001,  //4
  B10010010,  //5
  B10000010,  //6
  B11111000,  //7
  B10000000,  //8
  B10010000,  //9
 };

void setup()
{
  // 2~9번 핀을 a b c d e f g dot 의 순서로 사용한다
  // 2~9번핀을 출력으로 초기화 시킨다.
  for(int i = 2; i <= 9; ++i){
    pinMode(i,OUTPUT);
  };
  	// 점은 표시하지 않는다
    digitalWrite(9,LOW);
}

void loop()
{
   // k값을 0~9로 변화시킨다.
  for(int k = 0; k <= 9; ++k){
   fndDisplay(k);  // k값을 출력한다
   delay(1000);
  };
} 

// LED 점등
void fndDisplay(int displayValue){
  // bitValue 변수를 선언한다.
  boolean bitValue;
  	
  for(int i=2; i<=9; ++i){	
    // 2~9번핀에 모두 LOW 신호를 줘서 소등시킨다
    digitalWrite(i, LOW);
  };
  for(int i=0; i<=7; ++i){
    // number 상수의 하나의 비트값을 읽는다
    bitValue = bitRead(number[displayValue],i);
    // 앞서 읽은 비트값을 2~9번핀에 출력시킨다
    digitalWrite(i+2, bitValue);
  };
}
