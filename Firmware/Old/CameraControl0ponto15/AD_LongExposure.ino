void LongExposure()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(">Long Exposure");

  // Não deixao o LEdelay maior que 30 segundos
  if (LEdelay > 120)
  {
    LEdelay = 120;
    EEPROM.write(02, LEdelay);
  }

  while (ReadKeypad() != 'L')
  {
    lcd.setCursor(0, 1);
    lcd.print("Time:");
    lcd.print(LEdelay);
    lcd.print("s        ");

    btn_push = ReadKeypad();


    if ((btn_push == 'D') && (LEdelay > 0))
    {
      WaitBtnRelease();
      LEdelay--;
      EEPROM.write(02, LEdelay);
    }


    if (btn_push == 'U')
    {
      WaitBtnRelease();
      LEdelay++;
      EEPROM.write(02, LEdelay);
    }


    if (btn_push == 'R')
    {
      WaitBtnRelease();
      digitalWrite(readyPin, HIGH);
      delay(5000);
      lcd.setCursor(0, 1);
      lcd.print("T:");
      lcd.print(LEdelay);
      lcd.print("s  ");
      digitalWrite(cameraPin, HIGH);
      lastDebounceTime = millis();
      TotalTime = LEdelay * 1000;
      while ((millis() - lastDebounceTime) < TotalTime)
      {
        lcd.setCursor(6, 1);
        lcd.print(" D:");
        lcd.print(((TotalTime - (millis() - lastDebounceTime)) / 1000) + 1);
        lcd.print("s  ");
        delay(100);
        digitalWrite(cameraPin, HIGH);
      }
      digitalWrite(cameraPin, LOW);
      digitalWrite(readyPin, LOW);
    }
  }
  delay(10);
}
