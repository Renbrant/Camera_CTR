void Sound()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(">Sound Sensor");

  int somMin = 100;
  int somMax = 0;

  while (ReadKeypad() != 'L')
  {
    lcd.setCursor(0, 1);
    somAtual1023 = analogRead(somPin);
    somAtual100 = map(somAtual1023, 0, 1023, 0, 100);

    if (somAtual100 > somMax) {
      somMax = somAtual100;
    }

    if (somAtual100 < somMin) {
      somMin = somAtual100;
    }

    // Imprime a luz atual
    lcd.write(B00100011);
    lcd.print(somAtual100);
    lcd.print(" ");

    //Imprime a luz max
    lcd.setCursor(4, 1);
    lcd.write(B00101011);
    lcd.print(somMax);
    lcd.print(" ");

    //Imprime a luz min
    lcd.setCursor(8, 1);
    lcd.write(B00101101);
    lcd.print(somMin);
    lcd.print(" ");

    //Imprime a luz set
    lcd.setCursor(12, 1);
    lcd.write(B01111110);
    lcd.print(somPhoto);
    lcd.print(" ");

    btn_push = ReadKeypad();

    if ((btn_push == 'D') && (somPhoto > 0))
    {
      WaitBtnRelease();
      somPhoto--;
      EEPROM.write(05, somPhoto);
    }

    if ((btn_push == 'U') && (somPhoto < 99))
    {
      WaitBtnRelease();
      somPhoto++;
      EEPROM.write(05, somPhoto);
    }


    //################################################################################################
    if (btn_push == 'R')
    {
      WaitBtnRelease();
      digitalWrite(readyPin, HIGH);
      while (ReadKeypad() != 'L')
      {
        lcd.setCursor(0, 1);
        somAtual1023 = analogRead(somPin);
        somAtual100 = map(somAtual1023, 0, 1023, 0, 100);

        if (somAtual100 > somMax) {
          somMax = somAtual100;
        }

        if (somAtual100 < somMin) {
          somMin = somAtual100;
        }

        // Imprime a luz atual
        lcd.write(B00100011);
        lcd.print(somAtual100);
        lcd.print(" ");

        //Imprime a luz max
        lcd.setCursor(4, 1);
        lcd.write(B00101011);
        lcd.print(somMax);
        lcd.print(" ");

        //Imprime a luz min
        lcd.setCursor(8, 1);
        lcd.write(B00101101);
        lcd.print(somMin);
        lcd.print(" ");

        //Imprime a luz set
        lcd.setCursor(12, 1);
        lcd.write(B01111110);
        lcd.print(somPhoto);
        lcd.print(" ");

        if (somPhoto < somAtual100) {
          lcd.setCursor(11, 1);
          digitalWrite(readyPin, LOW);
          digitalWrite(cameraPin, HIGH);

        }
        else {

          digitalWrite(cameraPin, LOW);
          digitalWrite(readyPin, HIGH);
        }

        
        btn_push = ReadKeypad();

        if ((btn_push == 'D') && (somPhoto > 0))
        {
          WaitBtnRelease();
          somPhoto--;
          EEPROM.write(05, somPhoto);
        }

        if ((btn_push == 'U') && (somPhoto < 99))
        {
          WaitBtnRelease();
          somPhoto++;
          EEPROM.write(05, somPhoto);
        }
      }

      digitalWrite(cameraPin, LOW);
      digitalWrite(readyPin, HIGH);
    }
    digitalWrite(readyPin, LOW);
  }
}
