void Timer()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(">Timer");


  // Não deixao o TIdelay maior que 30 segundos
  if (TIdelay > 30)
  {
    TIdelay = 30;
    EEPROM.write(03, TIdelay);
  }


  while (ReadKeypad() != 'L')
  {
    lcd.setCursor(0, 1);
    lcd.print("Time: ");
    lcd.print(TIdelay);
    lcd.print("s            ");

    btn_push = ReadKeypad();


    if ((btn_push == 'D') && (TIdelay > 0))
    {
      WaitBtnRelease();
      TIdelay--;
      EEPROM.write(03, TIdelay);
    }


    if (btn_push == 'U')
    {
      WaitBtnRelease();
      TIdelay++;
      EEPROM.write(03, TIdelay);
    }


    if (btn_push == 'R')
    {
      WaitBtnRelease();
      lcd.setCursor(0, 1);
      lcd.print("Waiting     ");
      lastDebounceTime = millis();
      TotalTime = TIdelay * 1000;
      while ((millis() - lastDebounceTime) < TotalTime)
      {
        digitalWrite(readyPin, HIGH);
        lcd.setCursor(9, 1);
        lcd.print("      ");
        lcd.setCursor(9, 1);
        lcd.print(((TotalTime - (millis() - lastDebounceTime)) / 1000) + 1);
        lcd.print("s   ");
        delay(100);
      }
      lcd.setCursor(0, 1);
      lcd.print("#####CLICK#####");
//      digitalWrite(readyPin, LOW);
      digitalWrite(cameraPin, HIGH);
      delay(500);
      digitalWrite(cameraPin, LOW);
      digitalWrite(readyPin, LOW);
    }
  }
  delay(10);
}
