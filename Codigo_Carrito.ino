///Codigo para carrito

int m1a = 10;  //motor 1, pin 10 al pin 15
int m1b = 9;   //motor 1, pin 9 al pin 10
int m2a = 12;  //motor 2, pin 12 al pin 2
int m2b = 11;  //motor 2, pin 11 al pin 7
int ledD = 5;  //Luces delanteras
int ledT = 6; //Luces traseras
int claxon = 3; //Claxon carro 
char val;

void setup() {
  pinMode(m1a, OUTPUT);
  pinMode(m1b, OUTPUT);
  pinMode(m2a, OUTPUT);
  pinMode(m2b, OUTPUT);
  pinMode(ledD, OUTPUT);
  digitalWrite(ledD, LOW);
  pinMode(ledT, OUTPUT);
  digitalWrite(ledT, LOW);
  pinMode(claxon,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  while (Serial.available() > 0) {
    val = Serial.read();
    Serial.println(val);
  }
  if (val == 'V'){ // Claxon
    tone(claxon,4000);
    delay(500); // Enciende el zumbador
  }
  if (val == 'V'){ // Claxon
    noTone(claxon); // Apaga el zumbador
  }
  else if (val == 'F') {  //Hacia delante
    digitalWrite(m1a, HIGH);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, HIGH);
    digitalWrite(m2b, LOW);
    digitalWrite(ledD, HIGH);
    digitalWrite(ledT, LOW);
  }
  else if(val == 'B') {  //Hacia atras
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, HIGH);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, HIGH);
    digitalWrite(ledD, LOW);
    digitalWrite(ledT, HIGH);
    digitalWrite(claxon, LOW);
  }
  else if(val == 'L') {  //Izquierda
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, HIGH);
    digitalWrite(m2b, LOW);
    digitalWrite(claxon, LOW);
  }
  else if(val == 'R') {  //Derecha
    digitalWrite(m1a, HIGH);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW);
    digitalWrite(claxon, LOW);
  }
  else if(val == 'S') {  //STOP
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW);
    digitalWrite(ledD, LOW);
    digitalWrite(ledT, LOW);
    digitalWrite(claxon, LOW);
  }
}
