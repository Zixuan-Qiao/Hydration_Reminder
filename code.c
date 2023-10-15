#include<LiquidCrystal.h>

const int sensorPin = A0;	// input pin for temperature sensor
int switch_state = 0;	// default switch state

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(6, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop()
{
  unsigned long base = millis();
  
  // get temperature
  float temp = get_temp();
  
  // get corresponding interval number
  int intervals = get_interval(temp);
  for(int i = 0; i < intervals; i++){
  	lcd.clear();
  	lcd.setCursor(0, 1);
    lcd.print("Room temp:");
    lcd.print(temp);
  	lcd.print("C");
    temp = get_temp();    // update temperature data in each interval
    delay(5 * 60 * 1000);  // delay 5 mins for each interval
  }
  
  // send notification
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Go drink water!");
  
  int select = 0;
  unsigned long current;
  
  // make LEDs blink in sequence to catch attention
  // wait until user responds
  while(1){
  // measure time without pausing the program to monitor switch state in real-time
  	current = millis();
    if(current - base > 100){
      switch(8 + select){
      	case 8:
          digitalWrite(8, HIGH);
      	  digitalWrite(9, LOW);
      	  digitalWrite(10, LOW);
          break;
        case 9:
          digitalWrite(8, LOW);
      	  digitalWrite(9, HIGH);
      	  digitalWrite(10, LOW);
          break;
        case 10:
          digitalWrite(8, LOW);
      	  digitalWrite(9, LOW);
      	  digitalWrite(10, HIGH);
          break;
      }
      ++select;
      select %= 3;
      base = current;
    }
    // user responds to the notification by pushing the button
    switch_state = digitalRead(6);
    if(switch_state == HIGH){
      	digitalWrite(8, LOW);
      	digitalWrite(9, LOW);
      	digitalWrite(10, LOW);
    	break;
    }
  }
}

float get_temp(){
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor value: ");
  Serial.print(sensorVal);

  float voltage = (sensorVal / 1024.0) * 5.0;
  Serial.print(" Voltage value: ");
  Serial.print(voltage);

  float temp = (voltage - 0.5) * 100;
  Serial.print(" Tempture value: ");
  Serial.println(temp);
  return temp;
}

// ideal water hydration interval for me
int get_interval(float temp){
  if(temp < 15.0){
  	return 12;
  } else if(temp < 20.0){
  	return 9;
  } else if(temp < 25.0){
  	return 6;
  } else if(temp < 30.0){
  	return 4;
  } else{
  	return 3;
  }
}