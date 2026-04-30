void Manual()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(">Manual Mode");


  //################################################################################################
  if (btn_push == 'R')
  {
    WaitBtnRelease();
    digitalWrite(readyPin, HIGH);
    while (ReadKeypad() != 'L') {
      btn_push = ReadKeypad();

      if (btn_push == 'R')
      {

        digitalWrite(cameraPin, HIGH);
        delay(1000);
        digitalWrite(cameraPin, LOW);
      }
    }
  }
  digitalWrite(readyPin, LOW);
}
