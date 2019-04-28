//temperature, celsius
const int hotC = 25;
const int coldC = 20;

//temperature, fahrenheit
const int coldF = 68;
const int hotF = 77;
const int temperaturePin = 0;

// Load the LiquidCrystal library, which will give us
// commands to interface to the LCD:

#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

void setup()
{
  lcd.begin(16, 2);

  lcd.clear();

  //lcd.print("Temp, Sensor");

  Serial.begin(9600);
}

void loop()
{
  /*
   * Calculating celsius % fahrenheit
   * Coverting temperature
   */
  float voltage, degreesC, degreesF;
  voltage = getVoltage(temperaturePin);
  degreesC = (voltage - 0.5) * 100.0;
  degreesF = degreesC * (9.0/5.0) + 32.0;

  Serial.print("voltage: ");
  Serial.print(voltage);
  Serial.print("  deg C: ");
  Serial.print(degreesC);
  Serial.print("  deg F: ");
  Serial.println(degreesF);

  /*
   * checking temp in celsius
   */
  if (degreesC < coldC)
  {
    //lcd.setCursor(0,0);
    //lcd.write ("Temp: ");
    //lcd.setCursor(7,0);
    //lcd.print (degreesC, 2);
    //lcd.setCursor (13, 0);
    //lcd.write (" Cold");
    lcd.setCursor(0,0);
    lcd.write("It's Cold");
  }
  else if (degreesC > hotC)
  {
    lcd.setCursor(0,0);
    lcd.write("It's Hot");
  }
  else
  {
    lcd.setCursor(0,0);
    lcd.write("It's Fine");
  }
  
  lcd.setCursor(0,1);
  lcd.write ("Temp: ");
  lcd.setCursor(7,1);
  lcd.print (degreesC, 2);
  lcd.setCursor (13, 1);
  lcd.write ("C");
  
  delay(1000);

  /*
   * Checking temperature in fahrenheit
   */
    if (degreesF < coldF)
  {
    //lcd.setCursor(0,0);
    //lcd.write ("Temp: ");
    //lcd.setCursor(7,0);
    //lcd.print (degreesC, 2);
    //lcd.setCursor (13, 0);
    //lcd.write (" Cold");
    lcd.setCursor(0,0);
    lcd.write("It's Cold");
  }
  else if (degreesF > hotF)
  {
    lcd.setCursor(0,0);
    lcd.write("It's Hot");
  }
  else
  {
    lcd.setCursor(0,0);
    lcd.write("It's Fine");
  }
  
  lcd.setCursor(0,1);
  lcd.write ("Temp: ");
  lcd.setCursor(7,1);
  lcd.print (degreesF, 2);
  lcd.setCursor (13, 1);
  lcd.write ("F");
  
  delay(1000);
}

float getVoltage(int pin)
{
  return (analogRead(pin) * 0.004882814);
}
