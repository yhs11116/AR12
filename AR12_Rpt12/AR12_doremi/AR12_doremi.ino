/*
 예제 9.1
 피에조 부저를 이용한 소리 출력
*/
const int b1 = 1;
const int b2 = 2;
const int b3 = 3;

int buzzerPin = 9;
int songLength = 16;

// 노래의 빠르기를 설정한다.
int tempo = 200;

void setup() 
{
  // 부저핀을 출력으로 설정한다
  pinMode(buzzerPin, OUTPUT);

  pinMode(b1,INPUT_PULLUP);
  pinMode(b2,INPUT_PULLUP);
  pinMode(b3,INPUT_PULLUP);
}


void loop() 
{
  // 부저 출력 시간에 사용할 변수 설정
  int duration;

  int a1 = digitalRead(b1);
  int a2 = digitalRead(b2);
  int a3 = digitalRead(b3);

  if(a1 == LOW){
    tone(buzzerPin,262,100);
  }

  if(a2 == LOW){
    tone(buzzerPin,330,100);
  }

  if(a3 == LOW){
    tone(buzzerPin,392,100);
  }

}

int frequency(char note){
  // 노래 데이터를 주파수 값으로 변경하기 위한 함수

  int i;
  // 음계의 갯수 설정
  int notes = 8;

  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523};

  // 노래 데이터를 주파수 값으로 변경하기 위해 반복하여 비교한다  
  for (i = 0; i < notes; i++){
    if (names[i] == note){
      // 맞는 값을 찾았을 경우 이 값을 회신한다
      return(frequencies[i]);
    };
  };
  // 앞의 for문에서 맞는 값을 못찾았을 경우 0을 회신한다
  return(0);
}
