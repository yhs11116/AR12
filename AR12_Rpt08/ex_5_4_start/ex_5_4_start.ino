/*
 예제 5.4
 4X4 키패드 입력
*/

// 열의 수를 설정
const int numRows = 4;
// 행의 수를 설정
const int numCols = 4;

// 열과 행에 대하여 문자를 할당한다
char keys[numRows][numCols]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}};

// 열에 연결된 핀번호  	
int rowPins[] = {6, 7, 8, 9};  	
// 행에 연결된 핀번호
int colPins[] = {5, 4, 3, 2};


void setup() {
  // 열을 입력 풀업 모드로 설정한다.
  for(int i = 0; i < numRows; i++){
    pinMode(rowPins[i], INPUT_PULLUP);
  }
  // 행을 출력 모드로 설정한다. 초기값을 HIGH로 설정한다.
  for(int i = 0; i < numCols; i++){
    pinMode(colPins[i], OUTPUT);
    digitalWrite(colPins[i], HIGH);
  }
// 시리얼 통신을 설정한다.  
  Serial.begin(9600);
}

void loop(){

// key 변수에 키패드 입력 값을 읽어서 저장한다
  char key = keypadRead();

// key 변수가 0일때는 입력이 없는 것이고
// 그외의 값에서는 입력이 발생한 것이다.  
  if(key != 0){
// 메세지와 눌린 키를 출력한다  	
    Serial.print("You push ");
    Serial.print(key);
    Serial.println(" Key");
  };
}

char keypadRead(){
	
	char key = 0;
  
  for(int i = 0; i < numCols; i++){
// 행 중에 하나를 LOW로 설정한다.
    digitalWrite(colPins[i], LOW);
// 열을 하나씩 바꿔가면서 값을 읽는다.
    for(int j = 0; j < numRows; j++){
// 열의 입력이 LOW 일 때 키 입력이 발생한 것이다.
    	if(digitalRead(rowPins[j]) == LOW){
      delay(10);
    	 // 바운싱 방지를 위해 10ms 대기한다.
        
// 키를 놓을 때 까지 기다린다.
        while(digitalRead(rowPins[j]) == LOW);
        
// keys 상수에서 위치에 맞는 값을 가져온다.

        key = keys[j][i];
    	};
    }
// LOW로 설정했던 행을 다시 HIGH로 설정한다.
    digitalWrite(colPins[i], HIGH);
  }
  return key;  
}
