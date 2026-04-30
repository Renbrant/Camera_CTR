void Abertura()
{

  // criando os caracteres especiais
  lcd.createChar(1, CAM1);
  lcd.createChar(2, CAM2);
  lcd.createChar(3, CAM3);
  lcd.createChar(4, CAM4);
  lcd.createChar(5, CAM5);
  lcd.createChar(6, CAM6);
  lcd.createChar(7, CAM7);
  lcd.createChar(8, CAM8);

  // Inprimindo a camera do lado esquerdo
  lcd.setCursor(0, 0);
  lcd.write(uint8_t(1));
  lcd.write(uint8_t(2));
  lcd.write(uint8_t(3));
  lcd.write(uint8_t(4));
  lcd.setCursor(0, 1);
  lcd.write(uint8_t(5));
  lcd.write(uint8_t(6));
  lcd.write(uint8_t(7));
  lcd.write(uint8_t(8));

  lcd.setCursor(5, 0);
  lcd.print("Camera CTR");
  lcd.setCursor(5, 1);
  lcd.print("Ver 0.15");
  digitalWrite(BacklightPin,HIGH);

  delay(4000);


}
