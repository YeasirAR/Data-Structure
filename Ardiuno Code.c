#include <LiquidCrystal.h>
#include <DHT.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
DHT dht(0,DHT22);
int rainPin = 1;
int buzzer = 2;
int raindetect;
float temparature;
int humidity;
int rain;

void setup() {
  lcd.begin(16, 2);
  dht.begin();
  pinMode(buzzer,OUTPUT);
}

void loop() {
  temparature = dht.readTemperature();
  humidity = dht.readHumidity();
  lcd.setCursor(0, 0);
  String str = "T: "+String(temparature,1)+String((char)223)+ "C";
  str = str+" H:"+String(humidity)+"%";
  lcd.print(str);
  lcd.setCursor(0, 1);
  rain = digitalRead(rainPin);
  String str2;
  if(rain==1){
    str2 = "R: Its Raining";
  }
  else{
    str2 = "R: Not Raining";
  }
  
  lcd.print(str2);
  
  if(temparature<32 && temparature>23 && humidity>30 && humidity<60){
    noTone(buzzer);
  }
  else{
    tone(buzzer,1000);
  }
  delay(1000);
}
