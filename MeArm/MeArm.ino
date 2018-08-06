// importa a biblioteca de servo motores
#include <Servo.h>

// Mapeamento dos Joysticks
#define joystick1X A0
#define joystick1Y A1
#define joystick2X A2
#define joystick2Y A3

//Mapeamento dos Servos
Servo motorBase;
Servo motorBraco1;
Servo motorBraco2;
Servo motorGarra;

//Definir Posição inicial
#define ANGULO_INICIAL_MOTOR 90

//Mapear motores e controles
void mapearPinosDosMotores() {
  motorBase.attach(7);
  motorBraco1.attach(8);
  motorBraco2.attach(9);
  motorGarra.attach(10);
}

void mapearJoysticksComoInput() {
  pinMode(joystick1X, INPUT);
  pinMode(joystick1Y, INPUT);
  pinMode(joystick2X, INPUT);
  pinMode(joystick2Y, INPUT);
}

//Definir angilos iniciais dos motores
void inicializarAngulosDosMotores() {
  motorBase.write(ANGULO_INICIAL_MOTOR);
  motorBraco1.write(ANGULO_INICIAL_MOTOR);
  motorBraco2.write(ANGULO_INICIAL_MOTOR);
  motorGarra.write(ANGULO_INICIAL_MOTOR);
}

//Funções de movimento
void moverBase() {
  int posX = analogRead(joystick1X);
  posX = map(posX, 0, 1023, 0, 180);
  motorBase.write(posX);
}

void moverBraco1() {
  int posY = analogRead(joystick1Y);
  posY = map(posY, 0, 1023, 45, 135);
  motorBraco1.write(posY);
}

void moverBraco2() {
  int posX = analogRead(joystick2X);
  posX = map(posX, 0, 1023, 50, 90);
  motorBraco2.write(posX);
}

void moverGarra() {
  int posY = analogRead(joystick2Y);
  posY = map(posY, 0, 1023, 90, 130);
  motorGarra.write(posY);
}

//iniciar servo motores
void setup() {
  mapearPinosDosMotores();
  inicializarAngulosDosMotores();
  mapearJoysticksComoInput();
}

void loop() {
  moverBase();
  moverBraco1();
  moverBraco2();
  moverGarra();
  delay(100);
}


