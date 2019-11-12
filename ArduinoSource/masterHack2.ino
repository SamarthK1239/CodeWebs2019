#include <DS3231.h>
DS3231  rtc(SDA, SCL);
void setup() {
  rtc.begin();
  Serial.begin(9600); 
}

void loop() {
  Serial.print("Temp: ");
  Serial.print(rtc.getTemp());
  Serial.print(" C");
  Serial.println("          ");
  delay(100);
}
