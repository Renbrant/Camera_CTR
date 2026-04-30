void TimeLapse()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(">Time Lapse");


  // Não deixao o TLdelay maior que 30 segundos
  if (TLdelay > 30)
  {
    TLdelay = 30;
    EEPROM.write(01, TLdelay);
  }



  while (ReadKeypad() != 'L')
  {
    lcd.setCursor(0, 1);
    lcd.print("Time: ");
    lcd.print(TLdelay);
    lcd.print("s  ");

    btn_push = ReadKeypad();


    if ((btn_push == 'D') && (TLdelay > 0))
    {
      WaitBtnRelease();
      TLdelay--;
      EEPROM.write(01, TLdelay);
    }


    if (btn_push == 'U')
    {
      WaitBtnRelease();
      TLdelay++;
      EEPROM.write(01, TLdelay);
    }


    if (btn_push == 'R')
    {
      WaitBtnRelease();
      digitalWrite(readyPin, HIGH);
      lcd.setCursor(0, 1);
      lcd.print("Running:");
      lastDebounceTime = millis();
      TotalTime = 0;
      while (ReadKeypad() != 'L')
      {
        TotalTime = (millis() - lastDebounceTime);
        lcd.setCursor(8, 1);
        lcd.print("         ");
        lcd.setCursor(9, 1);
        lcd.print(TLdelay - (TotalTime / 1000));
        lcd.print("s");
        delay(200);

        if (TotalTime > ((TLdelay * 1000) - 500)) {
          lcd.setCursor(0, 1);
          lcd.print("#####CLICK#####");
          //          digitalWrite(readyPin, LOW);
          digitalWrite(cameraPin, HIGH);
          delay(500);
          digitalWrite(cameraPin, LOW);
          //         digitalWrite(readyPin, HIGH);
          lcd.setCursor(0, 1);
          lcd.print("Running: ");
          lastDebounceTime = millis();

        }
      }
      digitalWrite(readyPin, LOW);
    }
  }
  delay(10);
}
