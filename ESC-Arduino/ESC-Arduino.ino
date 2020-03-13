


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
int tiempo = 50;

int mx = 50;


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
        analogWrite(AA1, 0);
        analogWrite(AA2, 0);
        analogWrite(BB1, 0);
        analogWrite(CC2, 0);
        analogWrite(BB2, mx);
        analogWrite(CC1, mx);
        break;

      //Phase2 A-B
      case 2:
        analogWrite(AA2, 0);
        analogWrite(BB1, 0);
        analogWrite(CC1, 0);
        analogWrite(CC2, 0);
        analogWrite(AA1, mx);
        analogWrite(BB2, mx);
        break;

      //Phase3 A-C
      case 3:
        analogWrite(AA2, 0);
        analogWrite(BB1, 0);
        analogWrite(BB2, 0);
        analogWrite(CC1, 0);
        analogWrite(CC2, mx);
        analogWrite(AA1, mx);
        break;

      //Phase4 B-C
      case 4:
        analogWrite(AA1, 0);
        analogWrite(AA2, 0);
        analogWrite(BB2, 0);
        analogWrite(CC1, 0);
        analogWrite(BB1, mx);
        analogWrite(CC2, mx);
        break;

      //Phase5 B-A
      case 5:
        analogWrite(AA1, 0);
        analogWrite(BB2, 0);
        analogWrite(CC1, 0);
        analogWrite(CC2, 0);
        analogWrite(AA2, mx);
        analogWrite(BB1, mx);
        break;

      //Phase6 C-A
      case 6:
        analogWrite(AA1, 0);
        analogWrite(BB1, 0);
        analogWrite(BB2, 0);
        analogWrite(CC2, 0);
        analogWrite(CC1, mx);
        analogWrite(AA2, mx);
        break;



    }




  }
}
