

//Type Initialisation
int ThermistorPin = 0;
int Vo;

//type init for MathematicsCalcul
float R1 = 10000;
float refT = 32.00;
float logR2, R2, T, Tc, Tf;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

//Setup Analog
void setup() {
  Serial.begin(9600);
}

//Print Methode
void printOut(float Tf, float Tc) {
 Serial.print("Temperature: "); 
  Serial.print(Tc);
  Serial.println(" C");   
}


void loop() {

  // set the Good Analog use
  Vo = analogRead(ThermistorPin);

  // myCalc 
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  
  Tc = T - 273.15;

  //Print
  printOut(Tf, Tc); 
  delay(500);
}

