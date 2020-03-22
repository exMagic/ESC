
int AH = 13;
int AL = 12;
int BH = 11;
int BL = 10;
int CH = 9;
int CL = 8;

int f_max = 100;
int f_delay = 3 ;
int loopSpeed = 1;

void setup() {
  Serial.begin(9600);
  pinMode(AH, OUTPUT);//RED - OSC_ORANGE
  pinMode(AL, OUTPUT);//RED
  pinMode(BH, OUTPUT);//GREEN - OSC_BROWN
  pinMode(BL, OUTPUT);//GREEN
  pinMode(CH, OUTPUT);//BLUE - OSC_WHITE
  pinMode(CL, OUTPUT);//BLUE

  analogWrite(AH, 0);
  analogWrite(AL, 0);
  analogWrite(BH, 0);
  analogWrite(BL, 0);
  analogWrite(CH, 0);
  analogWrite(CL, 0);
}
void phase(int off_1, int off_2, int off_3, int on, int up, int down) {

  digitalWrite(off_1, LOW);// !IMPORTANT
  digitalWrite(off_2, LOW);// !IMPORTANT
  digitalWrite(off_3, LOW);// !IMPORTANT

  digitalWrite(on, HIGH); //ON
  analogWrite(up, f_max); //GO UP
  digitalWrite(down, 0);//OFF
  delay(f_delay);

  //  for (int i = 0; i <= f_max; i = i + loopSpeed) {
  //
  //    analogWrite(up, i); //GO UP
  //    analogWrite(down, f_max - i);//GO DOWN
  //
  //    delay(f_delay);
  //
  //  }


}
void loop() {




    //  ///////////  -- 1 --  ///////////////////////////////////////////////////
    phase(AL, BH, CH, AH, BL, CL);
    //  ///////////  -- 2 --  ///////////////////////////////////////////////////
    phase(AL, BH, CL, BL, CH, AH);
    //  //  ///////////  -- 3 --  ///////////////////////////////////////////////////
    phase(AH, BH, CL, CH, AL, BL);
    //  //  ///////////  -- 4 --  ///////////////////////////////////////////////////
    phase(AH, BL, CL, AL, BH, CH);
    //  //  ///////////  -- 5 --  ///////////////////////////////////////////////////
    phase(AH, BL, CH, BH, CL, AL);
    //  //  ///////////  -- 6 --  ///////////////////////////////////////////////////
    phase(AL, BL, CH, CL, AH, BH);

}
