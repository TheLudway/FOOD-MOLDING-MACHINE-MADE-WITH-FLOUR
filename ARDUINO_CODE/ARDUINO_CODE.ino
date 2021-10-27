#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <LiquidCrystal.h>    

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  
int led = 13;
int boton = 8 ;
int pulsador = 10;
int contador = 0;
int estadoAnterior = 0;     
int SENSOR;  
const int led1 = 10;
int val;
Adafruit_MLX90614 termometroIR = Adafruit_MLX90614();

void setup() {
  lcd.begin(16, 2); 
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(boton, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(pulsador, INPUT);
  termometroIR.begin();
}

void loop() {
  float temperaturaObjeto = termometroIR.readObjectTempC();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperaturaObjeto);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("Arepas:");
  lcd.setCursor(7, 1);
  lcd.print(contador);
  lcd.print("        ");
  int Lectura = digitalRead(boton);
  if (Lectura != estadoAnterior) {
    if (Lectura == HIGH)
    {
      contador++;
      Serial.println(contador);
    }
  }
  estadoAnterior = Lectura;

  if (contador == 15)
  {
    digitalWrite(led, HIGH);
  }
  if (contador == 999999999)
  {
    digitalWrite(led, LOW);
    contador = 0;
  }
  if (pulsador == HIGH)
  {
    digitalWrite(led, LOW);
    contador = 0;
  }
  val = digitalRead(pulsador);
  if (val == HIGH) {
    digitalWrite(led, LOW);
    contador = 0;
  }
  val = digitalRead(pulsador);
  if (val == HIGH) {
    digitalWrite(led, LOW);
    contador = 00;
  }
}

/*
⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣶⣄⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣦⣄⣀⡀⣠⣾⡇⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀
⠀⠀⠀⠀⢀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⢿⣿⣿⡇⠀⠀⠀⠀
⠀⣶⣿⣦⣜⣿⣿⣿⡟⠻⣿⣿⣿⣿⣿⣿⣿⡿⢿⡏⣴⣺⣦⣙⣿⣷⣄⠀⠀⠀
⠀⣯⡇⣻⣿⣿⣿⣿⣷⣾⣿⣬⣥⣭⣽⣿⣿⣧⣼⡇⣯⣇⣹⣿⣿⣿⣿⣧⠀⠀
⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠸⣿⣿⣿⣿⣿⣿⣿⣷⠀
*/
