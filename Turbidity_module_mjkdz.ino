/***************************************************
* Techeonics
* Turbidity module mjkdz
* @author - Gaurav Kumar (Techeonics) 

<thetecheonics@gmail.com>
Youtube- https://www.youtube.com/c/THETECHEONICS
See <http://www.techeonics.com> for details.

* ****************************************************/
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 16);

int sensorPin = A0; //A0 FOR ARDUINO/ 36 FOR ESP

void setup()
{ 
  Serial.begin(9600);
  // initialize LCD
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();
}
void loop() {
  int sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  int turbidity = map(sensorValue, 0, 750, 100, 0);
  delay(100);
  lcd.setCursor(0, 0);
  lcd.print("Turbidity:");
  lcd.print("   ");
  lcd.setCursor(10, 0);
  lcd.print(turbidity);
  
  delay(100);
  if (turbidity < 20) {
    lcd.setCursor(0, 1);
    lcd.print(" its CLEAR ");
    Serial.print(" its CLEAR ");
  }
  if ((turbidity > 20) && (turbidity < 50)) {
    lcd.setCursor(0, 1);
    lcd.print(" its CLOUDY ");
    Serial.print(" its CLOUDY ");
  }
  if (turbidity > 50) {
    lcd.setCursor(0, 1);
    lcd.print(" its DIRTY ");
    Serial.print(" its DIRTY ");
  }
}
