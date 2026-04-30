void Lightning()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(">Lightning Manual");


  // Não deixao o luzPhoto maior que 30 segundos
  if (luzPhoto > 80)
  {
    luzPhoto = 80;
    EEPROM.write(04, luzPhoto);
  }

  int luzMin = 100;
  int luzMax = 0;

  while (ReadKeypad() != 'L')
  {
    lcd.setCursor(0, 1);
    luzAtual1023 = analogRead(photometroPin);
    luzAtual100 = map(luzAtual1023, 0, 1023, 0, 100);

    if (luzAtual100 > luzMax) {
      luzMax = luzAtual100;
    }

    if (luzAtual100 < luzMin) {
      luzMin = luzAtual100;
    }

    // Imprime a luz atual
    lcd.write(B00100011);
    lcd.print(luzAtual100);
    lcd.print(" ");

    //Imprime a luz max
    lcd.setCursor(4, 1);
    lcd.write(B00101011);
    lcd.print(luzMax);
    lcd.print(" ");

    //Imprime a luz min
    lcd.setCursor(8, 1);
    lcd.write(B00101101);
    lcd.print(luzMin);
    lcd.print(" ");

    //Imprime a luz set
    lcd.setCursor(12, 1);
    lcd.write(B01111110);
    lcd.print(luzPhoto);
    lcd.print(" ");

    //ajuste do luzPhoto
    btn_push = ReadKeypad();

    if ((btn_push == 'D') && (luzPhoto > 0))
    {
      WaitBtnRelease();
      luzPhoto--;
      EEPROM.write(04, luzPhoto);
    }

    if ((btn_push == 'U') && (luzPhoto < 99))
    {
      WaitBtnRelease();
      luzPhoto++;
      EEPROM.write(04, luzPhoto);
    }


    //################################################################################################
    if (btn_push == 'R')
    {
      WaitBtnRelease();
      digitalWrite(readyPin, HIGH);
      //     analogWrite(BacklightPin,100);
      while (ReadKeypad() != 'L')
      {
        lcd.setCursor(0, 1);
        luzAtual1023 = analogRead(photometroPin);
        luzAtual100 = map(luzAtual1023, 0, 1023, 0, 100);

        if (luzAtual100 > luzMax) {
          luzMax = luzAtual100;
        }

        if (luzAtual100 < luzMin) {
          luzMin = luzAtual100;
        }

        // Imprime a luz atual
        lcd.write(B00100011);
        lcd.print(luzAtual100);
        lcd.print(" ");

        //Imprime a luz max
        lcd.setCursor(4, 1);
        lcd.write(B00101011);
        lcd.print(luzMax);
        lcd.print(" ");

        //Imprime a luz min
        lcd.setCursor(8, 1);
        lcd.write(B00101101);
        lcd.print(luzMin);
        lcd.print(" ");

        //Imprime a luz set
        lcd.setCursor(12, 1);
        lcd.write(B01111110);
        lcd.print(luzPhoto);
        lcd.print(" ");

        //Tira foto
        if (luzPhoto < luzAtual100) {
          lcd.setCursor(11, 1);
          digitalWrite(cameraPin, HIGH);
          //enquanto fica aberto
          while (luzPhoto < luzAtual100) {
            lcd.setCursor(13, 0);
            lcd.print("CLK");
            luzAtual1023 = analogRead(photometroPin);
            luzAtual100 = map(luzAtual1023, 0, 1023, 0, 100);
          }
          // quando acaba a foto
          lcd.setCursor(13, 0);
          delay(2000);
          lcd.print("   ");
          digitalWrite(readyPin, LOW);
          digitalWrite(cameraPin, LOW);
          delay(2000);
        }
        else {

          digitalWrite(readyPin, HIGH);
        }


        btn_push = ReadKeypad();

        if ((btn_push == 'D') && (luzPhoto > 0))
        {
          WaitBtnRelease();
          luzPhoto--;
          EEPROM.write(04, luzPhoto);
        }

        if ((btn_push == 'U') && (luzPhoto < 99))
        {
          WaitBtnRelease();
          luzPhoto++;
          EEPROM.write(04, luzPhoto);
        }


        //inverte o estado do backlight
        if (btn_push == 'R')
        {
          WaitBtnRelease();
          //Comando para inverter o estado do backligt
          digitalWrite(BacklightPin, !digitalRead(BacklightPin));
        }


      }

      digitalWrite(cameraPin, LOW);

    }
    digitalWrite(readyPin, LOW);
    digitalWrite(BacklightPin, HIGH);
    //    digitalWrite(BacklightPin,HIGH);
  }
}
