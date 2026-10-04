#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <SoftwareSerial.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
SoftwareSerial BT(9, 8);

#define SERVOMIN 250
#define SERVOMAX 500

// CADERAS
#define CAD_ADEL_DER 0
#define CAD_ADEL_IZQ 1
#define CAD_ATR_DER 5
#define CAD_ATR_IZQ 4

// RODILLAS
#define ROD_ADEL_IZQ 6
#define ROD_ADEL_DER 8
#define ROD_ATR_DER 11
#define ROD_ATR_IZQ 7

int t = 100;
char comando = 'S';

// ---------------- SERVO ----------------
void setServo(int canal, int angulo) {
  angulo = constrain(angulo, 0, 180);
  int pulso = map(angulo, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(canal, 0, pulso);
}

// ---------------- BASE ----------------
void posturaBase() {
  setServo(CAD_ADEL_DER, 0);
  setServo(CAD_ADEL_IZQ, 150);
  setServo(CAD_ATR_DER, 160);
  setServo(CAD_ATR_IZQ, 0);

  setServo(ROD_ADEL_IZQ, 90);  //160
  setServo(ROD_ADEL_DER, 90);   //0
  setServo(ROD_ATR_DER, 90);//0
  setServo(ROD_ATR_IZQ, 90);//160
}

// ---------------- ADELANTE ----------------
void adelante() {
  delay (t);
  setServo(CAD_ADEL_IZQ, 150);
  setServo(ROD_ADEL_IZQ, 160);
  setServo(CAD_ATR_DER, 90);
  setServo(ROD_ATR_DER, 0);
   setServo(CAD_ADEL_DER, 70);
   setServo(CAD_ATR_IZQ, 0);
  delay (t);
  setServo(ROD_ADEL_IZQ, 90);
  setServo(ROD_ATR_DER, 90);
   setServo(ROD_ADEL_DER, 45);
   setServo(ROD_ATR_IZQ, 125);
  delay (t);
  setServo(CAD_ADEL_IZQ, 80);
  setServo(CAD_ATR_DER, 160);
   setServo(CAD_ADEL_DER, 0);
   setServo(ROD_ADEL_DER, 0);
   setServo(CAD_ATR_IZQ, 70);
   setServo(ROD_ATR_IZQ, 160);
  delay (t);
  setServo(ROD_ADEL_IZQ, 125);
  setServo(ROD_ATR_DER, 45);
   setServo(ROD_ADEL_DER, 90);
   setServo(ROD_ATR_IZQ, 90);

}

// ---------------- ATRÁS ----------------
void atras() {
  delay(t);
  setServo(CAD_ADEL_IZQ, 80);
  setServo(ROD_ADEL_IZQ, 160);
  setServo(CAD_ATR_DER, 160);
  setServo(ROD_ATR_DER, 0);
  setServo(CAD_ADEL_DER, 0);
  setServo(CAD_ATR_IZQ, 70);

  delay(t);
  setServo(ROD_ADEL_IZQ, 90);
  setServo(ROD_ATR_DER, 90);
  setServo(ROD_ADEL_DER, 45);
  setServo(ROD_ATR_IZQ, 125);

  delay(t);
  setServo(CAD_ADEL_IZQ, 150);
  setServo(CAD_ATR_DER, 90);
  setServo(CAD_ADEL_DER, 70);
  setServo(ROD_ADEL_DER, 0);
  setServo(CAD_ATR_IZQ, 0);
  setServo(ROD_ATR_IZQ, 160);

  delay(t);
  setServo(ROD_ADEL_IZQ, 125);
  setServo(ROD_ATR_DER, 45);
  setServo(ROD_ADEL_DER, 90);
  setServo(ROD_ATR_IZQ, 90);
}

// ---------------- IZQUIERDA ----------------
void izquierda(){
  delay(t);

  // IZQUIERDA (atrás)
  setServo(CAD_ADEL_IZQ, 80);
  setServo(ROD_ADEL_IZQ, 160);
  setServo(CAD_ATR_IZQ, 70);

  // DERECHA (adelante)
  setServo(CAD_ATR_DER, 90);
  setServo(ROD_ATR_DER, 0);
  setServo(CAD_ADEL_DER, 70);

  delay(t);
  setServo(ROD_ADEL_IZQ, 90);
  setServo(ROD_ATR_DER, 90);
  setServo(ROD_ADEL_DER, 45);
  setServo(ROD_ATR_IZQ, 125);

  delay(t);

  // IZQUIERDA (atrás)
  setServo(CAD_ADEL_IZQ, 150);
  setServo(CAD_ATR_IZQ, 0);
  setServo(ROD_ATR_IZQ, 160);

  // DERECHA (adelante)
  setServo(CAD_ATR_DER, 160);
  setServo(CAD_ADEL_DER, 0);
  setServo(ROD_ADEL_DER, 0);

  delay(t);
  setServo(ROD_ADEL_IZQ, 125);
  setServo(ROD_ATR_DER, 45);
  setServo(ROD_ADEL_DER, 90);
  setServo(ROD_ATR_IZQ, 90);
}

// ---------------- DERECHA ----------------
void derecha(){
  delay(t);

  // IZQUIERDA (adelante)
  setServo(CAD_ADEL_IZQ, 150);
  setServo(ROD_ADEL_IZQ, 160);
  setServo(CAD_ATR_IZQ, 0);

  // DERECHA (atrás)
  setServo(CAD_ATR_DER, 160);
  setServo(ROD_ATR_DER, 0);
  setServo(CAD_ADEL_DER, 0);

  delay(t);
  setServo(ROD_ADEL_IZQ, 90);
  setServo(ROD_ATR_DER, 90);
  setServo(ROD_ADEL_DER, 45);
  setServo(ROD_ATR_IZQ, 125);

  delay(t);

  // IZQUIERDA (adelante)
  setServo(CAD_ADEL_IZQ, 80);
  setServo(CAD_ATR_IZQ, 70);
  setServo(ROD_ATR_IZQ, 160);

  // DERECHA (atrás)
  setServo(CAD_ATR_DER, 90);
  setServo(CAD_ADEL_DER, 70);
  setServo(ROD_ADEL_DER, 0);

  delay(t);
  setServo(ROD_ADEL_IZQ, 125);
  setServo(ROD_ATR_DER, 45);
  setServo(ROD_ADEL_DER, 90);
  setServo(ROD_ATR_IZQ, 90);
}
// ---------------- LEER BT ----------------
void leerBT() {
  if (BT.available()) {
    comando = BT.read();
  }
}

// ---------------- SETUP ----------------
void setup() {
  pwm.begin();
  pwm.setPWMFreq(50);
  BT.begin(9600);
  posturaBase();
}

// ---------------- LOOP ----------------
void loop() {

  leerBT();

  switch (comando) {

    case 'F':
      adelante();
      break;

    case 'B':
      atras();
      break;

    case 'L':
      izquierda();
      break;

    case 'R':
      derecha();
      break;

    default:
      posturaBase();
      break;
  }
}