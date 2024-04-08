#define S0_PIN 3
#define S1_PIN 4
#define S2_PIN 5
#define S3_PIN 6
#define OUT_PIN  2
short przel1 = 8;  //ustawianie pinow z przelacznikami
short przel2 = 9;
short przel3 = 10;
short przelm1 = 13;
short przelm2 = 1;
short przelm3 = 7;
short przelm4 = 11;
short przelm5 = 12;
void setup() {
  // Set the S0, S1, S2, S3 Pins as Output
  pinMode(S0_PIN, OUTPUT);
  pinMode(S1_PIN, OUTPUT);
  pinMode(S2_PIN, OUTPUT);
  pinMode(S3_PIN, OUTPUT);
  //Set OUT_PIN as Input
  pinMode(OUT_PIN, INPUT);
  // Set Pulse Width scaling to 20%
  digitalWrite(S0_PIN, HIGH);
  digitalWrite(S1_PIN, LOW);
  pinMode(przel1, OUTPUT);
  pinMode(przel2, OUTPUT);
  pinMode(przel3, OUTPUT);
  pinMode(przelm1, OUTPUT);
  pinMode(przelm2, OUTPUT);
  pinMode(przelm3, OUTPUT);
  pinMode(przelm4, OUTPUT);
  pinMode(przelm5, OUTPUT);
  delay(3000);  
        digitalWrite(przel2, HIGH);
        digitalWrite(przel3, HIGH);
        delay(1000); 
        digitalWrite(przel2, LOW);
          delay(1000);
          digitalWrite(przel3, LOW); 
        digitalWrite(przel2, HIGH);
        delay(1000); 
        digitalWrite(przel2, LOW);
  // digitalWrite(przel1, HIGH);       // wlacz przelacznik
  //digitalWrite(przel3, HIGH);
   // delay(300);  
   //   digitalWrite(przel3, LOW);        // wylacz przelacz
 // digitalWrite(przel2, HIGH);
  //delay(60);  
 // digitalWrite(przel1, LOW);
  //  delay(100);  
 // digitalWrite(przel2, LOW);
delay(20000);  
}
short del = 3000;
short colour = 4;
short czyjech = 0;
  int tablicakolorkow[4][5]={{0,0,0,0,0},{1,2,1,2,1},{2,3,2,3,2},{1,2,1,2,1}};
  short zap2 = 0;
short zap1 = 0;
short zap = 0;
short fin = 0;
void loop(){
    zap2=zap1;
    zap1=zap;
     
    czyjech=0;
 int r, g, b, rt, gt, bt;     // declare red,green,blue as integers
rt=0,gt=0,bt=0;
/*
 digitalWrite(przel1, HIGH);       // wlacz przelacznik
  digitalWrite(przel3, HIGH);
    delay(300);  
      digitalWrite(przel3, LOW);        // wylacz przelacz
  digitalWrite(przel2, HIGH);       // wlacz przelacznik
  delay(80);  
  digitalWrite(przel1, LOW);        // wylacz przelacz
    delay(120);  
  digitalWrite(przel2, LOW);        // wylacz przelaczniknik
*/
 digitalWrite(przel1, HIGH);       // wlacz przelacznik
  digitalWrite(przel3, HIGH);
    delay(500);  
 digitalWrite(przel1, LOW);        // wylacz przelacz
  digitalWrite(przel2, HIGH);       // wlacz przelacznik
        
        delay(200);
  digitalWrite(przel3, LOW);        // wylacz przelacz
    delay(120);  
  digitalWrite(przel2, LOW);        // wylacz przelaczniknik
  delay(250);                       // czekaj 3 sekundy
  for (int i=0;i<10;i++){
  r = process_red_value();
  g = process_green_value();
  b = process_blue_value();
  rt=rt+r;
  gt=gt+g;
  bt=bt+b;

}/*
Serial.println("red ");
Serial.print(rt/10);
Serial.println("green ");
Serial.print(gt/10);
Serial.println("blue ");
Serial.print(bt/10);
*/
switch(zap2) {
            case 0:
            del = 3500;             
            break;
            case 1:
            digitalWrite(przelm1, HIGH);      
            del = 2000;     
            break; 
            case 2:
            delay(400);
            del = 2000; 
            digitalWrite(przelm2, HIGH);          
            break;
            case 3:
            delay(1000);
            del = 2500; 
            digitalWrite(przelm3, HIGH);          
            break;
            case 4:
            delay(1300);
            del = 3500; 
            digitalWrite(przelm4, HIGH);          
            break;
            case 5:
            delay(1750);
            del = 3000; 
            digitalWrite(przelm5, HIGH);            
            break;
            case 6:
            delay(1000000);        
            break;
     }
  if (int(rt/10) < 175 & int(rt/10) > 120)
  {
   // Serial.println("red Block");
    colour=1;
  }
    else if (int(rt/10) < 230 & int(rt/10) > 195 & int(gt/10) < 270 & int(gt/10) > 234)
  {
  //  Serial.println("blue Block");
    colour=2;
  }
    else if (int(rt/10) < 210 & int(rt/10) > 195 & int(gt/10) < 235 & int(gt/10) > 220)
  {
   // Serial.println("green Block");
    colour=3;
  }
    else
  {
    ///Serial.println("no");
    colour=4;
  }
      for (int i=1;i<4;i++){
	     for (int j=0;j<5;j++){
	     	if (tablicakolorkow[i][j]==colour && tablicakolorkow[(i-1)][j]==0 && czyjech==0){
            switch(j) {
            case 0:
            zap=1;               
            break; 
            case 1:
            zap=2;               
            break;
            case 2:
            zap=3;               
            break;
            case 3:
            zap=4;           
            break;
            case 4:
            zap=5;            
            break;
                  } //switch end
	      	  tablicakolorkow[i][j]=0;
             //   Serial.println("rzad ");
             //   Serial.print(i);
            //    Serial.println("kolumna");
            //    Serial.print(j);

	      		czyjech=1;
	      	}
	     }
      }
      if (czyjech==0){
        zap=0;
        for (int j=0;j<5;j++){
            if (tablicakolorkow[3][j]==0){
              fin=fin+1;
            }
            if (fin==5){
              zap=6;
            }
        }
}
delay(del);
del = 3500; 
  switch(zap2) {
            case 0:
            delay(100);              
            break;
            case 1:
            digitalWrite(przelm1, LOW);             
            break; 
            case 2:
            digitalWrite(przelm2, LOW);            
            break;
            case 3:
            digitalWrite(przelm3, LOW);        
            break;
            case 4:
            digitalWrite(przelm4, LOW);           
            break;
            case 5:
            digitalWrite(przelm5, LOW);            
            break;
     }     
digitalWrite(przelm1, LOW); 
digitalWrite(przelm2, LOW); 
digitalWrite(przelm3, LOW); 
digitalWrite(przelm4, LOW); 
digitalWrite(przelm5, LOW); 
  rt=0,gt=0,bt=0;

}
int process_red_value()
{
  digitalWrite(S2_PIN, LOW);
  digitalWrite(S3_PIN, LOW);
  int pulse_length = pulseIn(OUT_PIN, LOW);
  return pulse_length;
}
int process_green_value()
{
  digitalWrite(S2_PIN, HIGH);
  digitalWrite(S3_PIN, HIGH);
  int pulse_length = pulseIn(OUT_PIN, LOW);
  return pulse_length;
}
int process_blue_value()
{
  digitalWrite(S2_PIN, LOW);
  digitalWrite(S3_PIN, HIGH);
  int pulse_length = pulseIn(OUT_PIN, LOW);
  return pulse_length;
}