void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  const uint8_t temp[5] = {'1', '2', '3', '4', '5'};
  Serial.write(1);  // write()함수로 1 전송
  delay(500);
  Serial.write(49); // write()함수로 49 전송
  delay(500);
  Serial.print(1);  // print()함수로 1 전송
  delay(500);
  Serial.write('a');  // write()함수로 'a' 전송
  delay(500);
  Serial.write(temp, 5);  // write()함수로 temp배열을 5만큼 전송
  delay(500);
  Serial.write("12345"); // write()함수로 string값 전송
  delay(500);
  Serial.write('\n');  // 줄바꿈
  delay(500);

}
