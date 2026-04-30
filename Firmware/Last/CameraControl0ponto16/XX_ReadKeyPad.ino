char ReadKeypad()
{
  // Keypad button analog Value no button pressed 1023
  // Valores do Keypad
  //Botao 1 = 0     <20
  //Botao 2 = 141   <240
  //Botao 3 = 341   <693
  //Botao 4 = 713   <900
  // Resistencias: 2k, 330, 690, 3.6k


  keypad_value = analogRead(keypad_pin);

  if(keypad_value < 20)
    return 'L';
  else if(keypad_value < 240)
    return 'U';
  else if(keypad_value < 693)
    return 'D';
  else if(keypad_value < 900)
    return 'R';
  else
    return 'N';

  }
