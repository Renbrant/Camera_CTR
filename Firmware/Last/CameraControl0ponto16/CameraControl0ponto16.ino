/*+++++++++++++++++++++++++++++++++++++++++++++++++++
  Author      : Renato Brant
  Date        : 14 May 2016
  Project     : Camera CTR
  Version     : 0.15
  Description : 0.1 Ccontador do Time Lapse funcionando
                0.2 Contador do Long Exposure funcionando
                0.3 Contador Timer funcionando
                    Melhorias no contador do Time Lapse
                    Melhorias no MainMenuDisplay
                0.4 Habilitaçao do Pin1 como camera
                0.5 lightining photo funcionando
                    Não é mais possivel seleceionar valores negativos
                    Acrescentada opção de saida do LE
                0.6 Led de duas cores
                0.7 Luz min e max
                0.8 Inculindo Sound Sensor
                0.8b voltando a mexer depois de um tempo
                0.9 Alterado os valores do keypad
                0.10 Colocado limite dos delays
                     Alterando a logica focus+shot
                     Corrigido problema dos tempos (long)
                0.11 alteração das portas do ATmega para facilitar trilhas da placa
                0.12  correcao dos textos
                      correcao do LED durante lightning/Time Lapse/Timer
                      Acrescentado modo Manual
                0.13 Controle de backlight no A5
                0.14 Abertura durante o Lightning
                0.15 Acresentando Lightning auto
                     Inverte o estado do backlight nos Lightning



  +++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <EEPROM.h>
#include <LiquidCrystal.h>

//LiquidCrystal lcd (<pino RS>, <pino enable>, <pino D4>, <pino D5>, <pino D6>, <pino D7>)
//    RS=D2    Vss=GND
//    E =D3    Vdd=5v
//    D4=D4    Vo =potenciometro
//    D5=D5    R/W=GND
//    D6=D6    A  =GND c/ 220ohm
//    D7=D7    K  =5v

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

//caracteres da maquina fotografica
byte CAM1[8] = {0b00000, 0b00000, 0b00000, 0b01111, 0b11111, 0b11111, 0b11111, 0b11111};
byte CAM2[8] = {0b00111, 0b01111, 0b11111, 0b11111, 0b11110, 0b11000, 0b10001, 0b10000};
byte CAM3[8] = {0b11100, 0b11110, 0b11111, 0b11111, 0b01111, 0b00011, 0b11001, 0b01101};
byte CAM4[8] = {0b00000, 0b00000, 0b00000, 0b11110, 0b11111, 0b10011, 0b10011, 0b11111};
byte CAM5[8] = {0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b01111};
byte CAM6[8] = {0b00000, 0b00000, 0b10000, 0b10000, 0b11000, 0b11110, 0b11111, 0b11111};
byte CAM7[8] = {0b00100, 0b00100, 0b00001, 0b00001, 0b00011, 0b01111, 0b11111, 0b11111};
byte CAM8[8] = {0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11110};

//pins
int keypad_pin = A0;
int cameraPin = 10;
int readyPin = 9;
int photometroPin = A1;
int somPin = A2;
int BacklightPin = A5;

//Valores do keypad
int keypad_value = 0;
int keypad_value_old = 0;

// Valores do Keypad
//Botao 1 = 0
//Botao 2 = 141
//Botao 3 = 341
//Botao 4 = 713
// Resistencias: 2k, 330, 690, 3.6k

//Valores da luz
int luzAtual1023 = 0;
int luzAtual100 = 0;
int luzPhoto = 0;
int luzMin = 100;
int luzMax = 0;

//Valores do som
int somAtual1023 = 0;
int somAtual100 = 0;
int somPhoto = 0;
int somMin = 100;
int somMax = 0;

//Variaveis de tempo
long TLdelay = 0;
long LEdelay = 5;
long TIdelay = 5;
long TotalTime = 0;
long lastDebounceTime = 0;

char btn_push;

byte mainMenuPage = 1;
byte mainMenuPageOld = 1;
byte mainMenuTotal = 7;

//#####################################################################################################################
void setup()
{
  lcd.begin(16, 2); //Initialize a 2x16 type LCD
  pinMode(cameraPin, OUTPUT);
  pinMode(readyPin, OUTPUT);
  pinMode(BacklightPin, OUTPUT);
  pinMode(photometroPin, INPUT);
  Abertura();
  MainMenuDisplay();
  delay(1000);

  TLdelay = EEPROM.read(01);
  LEdelay = EEPROM.read(02);
  TIdelay = EEPROM.read(03);
  luzPhoto = EEPROM.read(04);
  somPhoto = EEPROM.read(05);

}


//#####################################################################################################################
void loop()
{
  btn_push = ReadKeypad();

  MainMenuBtn();

  if (btn_push == 'R') //enter selected menu
  {
    WaitBtnRelease();
    switch (mainMenuPage)
    {
      case 1:
        TimeLapse();
        break;
      case 2:
        Timer();
        break;
      case 3:
        Lightning();
        break;
      case 4:
        Lightning_auto();
        break;
      case 5:
        LongExposure();
        break;
      case 6:
        Sound();
        break;
      case 7:
        Manual();
        break;
    }

    MainMenuDisplay();
    WaitBtnRelease();
  }

  delay(10);
}




