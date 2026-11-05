//Definicón de pines de los sensores y los motores

#define ENB 6
#define ENA 11
#define motorIzqA 2
#define motorIzqB 3
#define motorDerA 4
#define motorDerB 5
#define Sensor0 12
#define Sensor1 13
#define Sensor2 8
#define Sensor3 7

int SIzq1 = 0;
int SDer1 = 0;
int SIzq = 0;
int SDer = 0;
int vel = 200;
int sw = 0;
int sw1 = 0;

//Lógica de movimiento

//Velocidad para que gire con ambas ruedas sobre su propio eje

void derechaa(){
  analogWrite(ENA, vel);
  analogWrite(ENB, vel);
  digitalWrite(motorIzqA, LOW);
  digitalWrite(motorIzqB, HIGH);
  digitalWrite(motorDerA, LOW);
  digitalWrite(motorDerB, HIGH);
}

void izquierdaa(){
  analogWrite(ENA, vel);
  analogWrite(ENB, vel);
  digitalWrite(motorIzqA, HIGH);
  digitalWrite(motorIzqB, LOW);
  digitalWrite(motorDerA, HIGH);
  digitalWrite(motorDerB, LOW);
}

//Velocidad para que gire una rueda sobre la otra estática 

void izquierda(){
  //analogWrite(ENA, 255);
  //analogWrite(ENB, 255);
  digitalWrite(motorIzqA, LOW);
  digitalWrite(motorIzqB, LOW);
  digitalWrite(motorDerA, HIGH);
  digitalWrite(motorDerB, LOW);
  //delay(10);
  analogWrite(ENA, vel);
  analogWrite(ENB, vel);
}

void derecha(){
  digitalWrite(motorIzqA, LOW);
  digitalWrite(motorIzqB, HIGH);
  digitalWrite(motorDerA, LOW);
  digitalWrite(motorDerB, LOW);
  //analogWrite(ENA, 255);
  //analogWrite(ENB, 255);
  //delay(10);
  analogWrite(ENA, vel);
  analogWrite(ENB, vel);
}

void go(){
  digitalWrite(motorIzqA, LOW);
  digitalWrite(motorIzqB, HIGH);
  digitalWrite(motorDerA, HIGH);
  digitalWrite(motorDerB, LOW);
  //analogWrite(ENA, 255);
  //analogWrite(ENB, 255);
  //delay(10);
  analogWrite(ENA, vel);
  analogWrite(ENB, vel);
}

//void back(){
  digitalWrite(motorIzqA, HIGH);
  digitalWrite(motorIzqB, LOW);
  digitalWrite(motorDerA, LOW);
  digitalWrite(motorDerB, HIGH);
  analogWrite(ENA, vel);
  analogWrite(ENB, vel);
}

void stop(){
  digitalWrite(motorIzqA, LOW);
  digitalWrite(motorIzqB, LOW);
  digitalWrite(motorDerA, LOW);
  digitalWrite(motorDerB, LOW);
}

void setup() {

  Serial.begin(9600);
 // Configuración de pines de motores como salida
  pinMode(motorIzqA, OUTPUT);
  pinMode(motorIzqB, OUTPUT);
  pinMode(motorDerA, OUTPUT);
  pinMode(motorDerB, OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(Sensor0, INPUT);
  pinMode(Sensor1, INPUT);
  pinMode(Sensor2, INPUT);
  pinMode(Sensor3, INPUT);
}

void loop() {

//Lectura de las señales "blancos y negros" de los sensores IR
  SDer1 = digitalRead(Sensor0);
  SDer = digitalRead(Sensor1);
  SIzq = digitalRead(Sensor2);
  SIzq1 = digitalRead(Sensor3);

//Lógica para seguir la linea
  if(SIzq1 == 0 and SIzq == 0 and SDer == 0 and SDer1 == 0){
    go();
    Serial.println("go");
  }
    if(SIzq1 == 0 and SIzq == 1 and SDer == 0 and SDer1 == 0){
    izquierda();
    Serial.println("izquierda");
  }
  if(SIzq1 == 0 and SIzq == 0 and SDer == 1 and SDer1 == 0){
    derecha();
    Serial.println("derecha");    
  }
  if(SIzq1 == 0 and SIzq == 0 and SDer == 1 and SDer1 == 1){
    derecha();
    delay(100);
    Serial.println("derecha");
  }
  if(SIzq1 == 1 and SIzq == 1 and SDer == 0 and SDer1 == 0){
    izquierda();
    delay(100);
    Serial.println("izquierda");
  }
  if(SIzq1 == 1 and SIzq == 1 and SDer == 1 and SDer1 == 1){
    stop();
    Serial.println("stop");
  }
  if(SIzq1 == 0 and SIzq == 0 and SDer == 0 and SDer1 == 1){
    derechaa();
    delay(500);
  }
  if(SIzq1 == 1 and SIzq == 0 and SDer == 0 and SDer1 == 0){
    izquierdaa();
    delay(500);
  }
}