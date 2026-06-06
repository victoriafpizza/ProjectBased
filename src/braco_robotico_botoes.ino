#include <Servo.h>

// ==========================
// Pinos dos botões
// ==========================
// Conforme você informou:
// Amarelo = D2
// Azul    = D3
// Verde   = D4
// Vermelho= D5

const int BOTAO_AMARELO = 2;   // D - Descer braço
const int BOTAO_AZUL = 3;      // O - Abrir garra
const int BOTAO_VERDE = 4;     // U - Subir braço
const int BOTAO_VERMELHO = 5;  // C - Fechar garra

// ==========================
// Pinos dos servos
// ==========================

const int SERVO_GARRA = 9;
const int SERVO_BRACO = 10;

// ==========================
// LED de status
// ==========================

const int LED_STATUS = 12;

// ==========================
// Objetos Servo
// ==========================

Servo servoBraco;
Servo servoGarra;

// ==========================
// Posições iniciais
// ==========================

int posBraco = 90;
int posGarra = 90;

// Limites de segurança
const int BRACO_MIN = 30;
const int BRACO_MAX = 150;

const int GARRA_ABERTA = 30;
const int GARRA_FECHADA = 110;

// Velocidade do movimento
const int PASSO = 10;
const int TEMPO = 25;

// Para módulos de botão com VCC, GND e OUT:
// normalmente apertado = HIGH
const int BOTAO_APERTADO = HIGH;

void setup() {
  Serial.begin(9600);

  // Como seus botões são módulos com VCC, GND e OUT,
  // usamos INPUT normal.
  pinMode(BOTAO_AMARELO, INPUT);
  pinMode(BOTAO_AZUL, INPUT);
  pinMode(BOTAO_VERDE, INPUT);
  pinMode(BOTAO_VERMELHO, INPUT);

  pinMode(LED_STATUS, OUTPUT);

  servoBraco.attach(SERVO_BRACO);
  servoGarra.attach(SERVO_GARRA);

  servoBraco.write(posBraco);
  servoGarra.write(posGarra);

  digitalWrite(LED_STATUS, LOW);

  Serial.println("Sistema iniciado.");
  Serial.println("Verde: U - Subir braço");
  Serial.println("Amarelo: D - Descer braço");
  Serial.println("Azul: O - Abrir garra");
  Serial.println("Vermelho: C - Fechar garra");
}

void loop() {
  bool algumBotao = false;

  // ==========================
  // Verde - Subir braço
  // ==========================
  if (digitalRead(BOTAO_VERDE) == BOTAO_APERTADO) {
    algumBotao = true;

    if (posBraco > BRACO_MIN) {
      posBraco -= PASSO;
      servoBraco.write(posBraco);
    }

    Serial.println("U - Subindo braço");
    delay(TEMPO);
  }

  // ==========================
  // Amarelo - Descer braço
  // ==========================
  if (digitalRead(BOTAO_AMARELO) == BOTAO_APERTADO) {
    algumBotao = true;

    if (posBraco < BRACO_MAX) {
      posBraco += PASSO;
      servoBraco.write(posBraco);
    }

    Serial.println("D - Descendo braço");
    delay(TEMPO);
  }

  // ==========================
  // Azul - Abrir garra
  // ==========================
  if (digitalRead(BOTAO_AZUL) == BOTAO_APERTADO) {
    algumBotao = true;

    if (posGarra > GARRA_ABERTA) {
      posGarra -= PASSO;
      servoGarra.write(posGarra);
    }

    Serial.println("O - Abrindo garra");
    delay(TEMPO);
  }

  // ==========================
  // Vermelho - Fechar garra
  // ==========================
  if (digitalRead(BOTAO_VERMELHO) == BOTAO_APERTADO) {
    algumBotao = true;

    if (posGarra < GARRA_FECHADA) {
      posGarra += PASSO;
      servoGarra.write(posGarra);
    }

    Serial.println("C - Fechando garra");
    delay(TEMPO);
  }

  // ==========================
  // LED de status
  // ==========================
  if (algumBotao) {
    digitalWrite(LED_STATUS, HIGH);
  } else {
    digitalWrite(LED_STATUS, LOW);
  }
}