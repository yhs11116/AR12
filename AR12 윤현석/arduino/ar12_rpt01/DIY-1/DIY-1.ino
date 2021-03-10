int number = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print(number);
  Serial.println(" msec");
  delay(200);
  number += 200;

  if (number > 5000) {
    number = 0;
  }
}
