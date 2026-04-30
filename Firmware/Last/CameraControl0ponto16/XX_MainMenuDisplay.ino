void MainMenuDisplay()
{
  lcd.clear();
  digitalWrite(BacklightPin, HIGH);
  lcd.setCursor(0, 0);
  switch (mainMenuPage)
  {
    case 1:
      lcd.print("Select:");
      lcd.setCursor(0, 1);
      lcd.print("1> Time Lapse");
      break;
    case 2:
      lcd.print("Select:");
      lcd.setCursor(0, 1);
      lcd.print("2> Timer");
      break;
    case 3:
      lcd.print("Select:");
      lcd.setCursor(0, 1);
      lcd.print("3> Lightning Manual");
      break;
    case 4:
      lcd.print("Select:");
      lcd.setCursor(0, 1);
      lcd.print("4> Lightning Auto");
      break;
    case 5:
      lcd.print("Select:");
      lcd.setCursor(0, 1);
      lcd.print("5> Long Exposure");
      break;
    case 6:
      lcd.print("Select:");
      lcd.setCursor(0, 1);
      lcd.print("6> Sound sensor");
      break;
    case 7:
      lcd.print("Select:");
      lcd.setCursor(0, 1);
      lcd.print("7> Manual mode");
      break;
  }
}
