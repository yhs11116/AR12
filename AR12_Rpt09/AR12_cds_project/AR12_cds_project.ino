/*
 예제 6.2
 빛 입력
*/
 
// I2C 통신 라이브러리 설정 
#include <Wire.h>
// I2C LCD 라리브러리 설정
#include <LiquidCrystal_I2C.h>

// LCD I2C address 설정: 0x3F or 0x27
LiquidCrystal_I2C lcd(0x27,16,2);

// 0번 아날로그핀을 CdS 셀 입력으로 설정한다.
const int CdSPin = 0;

int led = 3; 

void setup() {
  
// 16X2 LCD 모듈 설정하고 백라이트를 켠다.
  lcd.init(); // LCD 설정
  lcd.backlight();

// 메세지를 표시한다.
  lcd.print("ex 6.2");
  lcd.setCursor(0,1);
  lcd.print("CdS Cell Test");
// 3초동안 메세지를 표시한다.
  delay(3000);

// 모든 메세지를 삭체한 뒤
// 숫자를 제외한 부분들을 미리 출력시킨다.
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ADC :  ");
  lcd.setCursor(0,1);
  lcd.print("Illuminance:");
  lcd.setCursor(15,1);
  lcd.print("%");

  pinMode(led, OUTPUT);
}

void loop(){

  int adcValue; // 실제 센서로부터 읽은 값 (0~1023)
  int illuminance; // 현재의 밝기. 0~100%
    
  // CdS cell을 통하여 입력되는 전압을 읽는다.
  adcValue = analogRead(CdSPin);
  // 아날로그 입력 값을 0~100의 범위로 변경한다.
  illuminance = map(adcValue, 0, 1023, 100, 0);

  // 전에 표시했던 내용을 지우고
  // LCD에 ADC 값과 밝기를 출력한다.
  // 지우지 않으면 이전에 표시했던 값이 남게 된다.

  // 전에 표시했던 내용을 지운다.  
  lcd.setCursor(9,0);
  lcd.print("   ");
  // ADC 값을 표시한다  
  lcd.setCursor(9,0);
  lcd.print(adcValue);

  // 전에 표시했던 내용을 지운다.
  lcd.setCursor(0,1);
  lcd.print("  ");
  // 밝기를 표시한다  
  lcd.setCursor(12,1);  
  lcd.print(illuminance);

  delay(1000);

  int cdsValue = analogRead(CdSPin);
 
        // 측정된 밝기 값를 시리얼 모니터에 출력합니다.
  Serial.print("cds =  ");
  Serial.println(cdsValue);
 
        // 조도센서로 부터 측정된 밝기 값이 220보다 크다면, 아래의 블록을 실행합니다.
  if (cdsValue > 220) {    
                // LED가 연결된 핀의 로직레벨을 HIGH (5V)로 설정하여, LED가 켜지도록 합니다.
          digitalWrite(led, HIGH);
          lcd.noBacklight();
                
        // 조도센서로 부터 측정된 밝기 값이 50보다 작면, 아래의 블록을 실행합니다.
  } else {    
                // LED가 연결된 핀의 로직레벨을 LOW (0V)로 설정하여, LED가 꺼지도록 합니다.
          digitalWrite(led, LOW);      
  }
  
}
