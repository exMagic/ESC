


int AA1 = 13;
int AA2 = 12;
int BB1 = 11;
int BB2 = 10;
int CC1 = 9;
int CC2 = 8;

int enable = 2;
int emfA = A0;
int emfB = A1;
int emfC = A2;

int fase = 1;

int IN = A3;
int tiempo = 1000;

int mx = 125;


unsigned long previousMillis = millis();

void setup() {
  Serial.begin(9600);
  pinMode(AA1, OUTPUT);
  pinMode(AA2, OUTPUT);
  pinMode(BB1, OUTPUT);
  pinMode(BB2, OUTPUT);
  pinMode(CC1, OUTPUT);
  pinMode(CC2, OUTPUT);

  pinMode(enable, OUTPUT);

  pinMode(IN, INPUT);
  pinMode(emfA, INPUT);
  pinMode(emfB, INPUT);
  pinMode(emfC, INPUT);


  digitalWrite(enable, HIGH);
  previousMillis = micros();




}

void loop() {

  unsigned long currentMillis = millis();


  //Serial.println(currentMillis - previousMillis);
  //Serial.println(tiempo);
  
  if (currentMillis - previousMillis >= tiempo) {

    previousMillis = currentMillis;
    if (fase < 6) {
      fase = fase + 1;
    }
    else {
      fase = 1;

    }
    
    Serial.println(fase);
    
    //Phase1 C-B
    switch (fase) {
      case 1:
        digitalWrite(AA1, LOW);
        digitalWrite(AA2, LOW);
        digitalWrite(BB1, LOW);
        digitalWrite(CC2, LOW);
        digitalWrite(BB2, HIGH);
        digitalWrite(CC1, HIGH);
        break;

      //Phase2 A-B
      case 2:
        digitalWrite(AA2, LOW);
        digitalWrite(BB1, LOW);
        digitalWrite(CC1, LOW);
        digitalWrite(CC2, LOW);
        digitalWrite(AA1, HIGH);
        digitalWrite(BB2, HIGH);
        break;

      //Phase3 A-C
      case 3:
        digitalWrite(AA2, LOW);
        digitalWrite(BB1, LOW);
        digitalWrite(BB2, LOW);
        digitalWrite(CC1, LOW);
        digitalWrite(CC2, HIGH);
        digitalWrite(AA1, HIGH);
        break;

      //Phase4 B-C
      case 4:
        digitalWrite(AA1, LOW);
        digitalWrite(AA2, LOW);
        digitalWrite(BB2, LOW);
        digitalWrite(CC1, LOW);
        digitalWrite(BB1, HIGH);
        digitalWrite(CC2, HIGH);
        break;

      //Phase5 B-A
      case 5:
        digitalWrite(AA1, LOW);
        digitalWrite(BB2, LOW);
        digitalWrite(CC1, LOW);
        digitalWrite(CC2, LOW);
        digitalWrite(AA2, HIGH);
        digitalWrite(BB1, HIGH);
        break;

      //Phase6 C-A
      case 6:
        digitalWrite(AA1, LOW);
        digitalWrite(BB1, LOW);
        digitalWrite(BB2, LOW);
        digitalWrite(CC2, LOW);
        digitalWrite(CC1, HIGH);
        digitalWrite(AA2, HIGH);
        break;



    }




  }
}
