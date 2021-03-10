/*
 DIY-3
*/

// start number
int number = 0;
int sum = 0;

void setup() {
  // 9600bps로 시리얼 통신 설정
  Serial.begin(9600);
}

void loop() {

  number++;
  sum += number;
  Serial.print("Number = ");
  Serial.print(number);
  Serial.print(", Sum = ");
  Serial.println(sum);  
  
  if(number == 100) {
    Serial.println();
    Serial.println("AR12: 1 + 2 + ... + 100 = 5050");
    delay(500);
    exit(0); 
  }
  
  delay(100);  // 0.1초동안 지연시킨다.
}
