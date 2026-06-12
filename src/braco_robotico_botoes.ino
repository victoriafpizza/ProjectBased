#include <Servo.h>
 
// Instanciando os Servos 
Servo Base;
Servo Braco;
Servo Ombro;
Servo Garra;
 
// Pinos dos Potenciômetros
const int pinoPot1 = A0;
const int pinoPot2 = A1;
const int pinoPot3 = A2;
const int pinoPot4 = A3;
 
// Variáveis para armazenar as leituras ATUAIS e ANTERIORES (declaradas corretamente)
int valorPot1Atu = 0, valorPot1Ati = 0;
int valorPot2Atu = 0, valorPot2Ati = 0;
int valorPot3Atu = 0, valorPot3Ati = 0;
int valorPot4Atu = 0, valorPot4Ati = 0;
 
const int tolerancia = 3;
 
int anguloServoBase;
int anguloServoBraco;
int anguloServoOmbro;
int anguloServoGarra;
 
const int pinoLED = 53;
 
void setup() {
  Serial.begin(9600);
 
 
  // Conectando os servos aos pinos
  Base.attach(8);
  Braco.attach(9);
  Ombro.attach(10);
  Garra.attach(11);
 
  Base.write(90);
  delay(150);
  Braco.write(90);
  Ombro.write(90);
  Garra.write(90);
 
  pinMode(pinoLED, OUTPUT);
 
  // Leitura inicial para evitar movimentos bruscos ao ligar
  valorPot1Ati = analogRead(pinoPot1);
  valorPot2Ati = analogRead(pinoPot2);
  valorPot3Ati = analogRead(pinoPot3);
  valorPot4Ati = analogRead(pinoPot4);
}
 
void loop() {
  // Variável para controlar se o LED deve acender neste ciclo
  bool algumMovimento = false;
 
  // Lê o valor atual de cada potenciômetro
  valorPot1Atu = analogRead(pinoPot1);
  valorPot2Atu = analogRead(pinoPot2);
  valorPot3Atu = analogRead(pinoPot3);
  valorPot4Atu = analogRead(pinoPot4);
 
  // Calcula a diferença absoluta
  int diferenca1 = abs(valorPot1Atu - valorPot1Ati);
  int diferenca2 = abs(valorPot2Atu - valorPot2Ati);
  int diferenca3 = abs(valorPot3Atu - valorPot3Ati);
  int diferenca4 = abs(valorPot4Atu - valorPot4Ati);
 
  // --- SERVO 1: BASE ---
  if (diferenca1 > tolerancia) {
    algumMovimento = true;
    valorPot1Ati = valorPot1Atu;
    anguloServoBase = map(valorPot1Atu, 0, 1023, 0, 180); // Corrigido para valorPot1Atu
    Base.write(anguloServoBase);
    delay(15); // Um pequeno delay ajuda na estabilidade do servo
  }
 
  // --- SERVO 2: BRAÇO ---
  if (diferenca2 > tolerancia) {
    algumMovimento = true;
    valorPot2Ati = valorPot2Atu;
    anguloServoBraco = map(valorPot2Atu, 0, 1023, 0, 180); // Corrigido para valorPot2Atu e anguloServoBraco
    Braco.write(anguloServoBraco);
    delay(15);
  }
 
  // --- SERVO 3: OMBRO ---
  if (diferenca3 > tolerancia) {
    algumMovimento = true;
    valorPot3Ati = valorPot3Atu;
    anguloServoOmbro = map(valorPot3Atu, 0, 1023, 0, 180); // Corrigido para valorPot3Atu
    Ombro.write(anguloServoOmbro);
    delay(15);
  }
 
  // --- SERVO 4: GARRA ---
  if (diferenca4 > tolerancia) {
    algumMovimento = true;
    valorPot4Ati = valorPot4Atu;
    anguloServoGarra = map(valorPot4Atu, 0, 1023, 0, 180); // Corrigido para valorPot4Atu
    Garra.write(anguloServoGarra);
    delay(15);
  }
 
  // Controla o LED com base no movimento geral
  if (algumMovimento) {
    digitalWrite(pinoLED, HIGH);
  } else {
    digitalWrite(pinoLED, LOW);
  }
 
  Serial.print("Pot Base: ");
  Serial.print(valorPot1Atu);
  Serial.print("\t| Pot 2: "); // O "\t" serve para dar um espaço (Tab)
  Serial.print(valorPot2Atu);
  Serial.print("\t| Pot 3: ");
  Serial.print(valorPot3Atu);
  Serial.print("\t| Pot Garra: ");
  Serial.println(valorPot4Atu);
 
  // Delay reduzido para o braço responder mais rápido aos comandos
  delay(30);
}
