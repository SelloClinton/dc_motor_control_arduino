
#define j1 4
#define j2 2
#define pwmPin3 3
#define pwmPin11 11

void setup() {
  pinMode(j1,OUTPUT);
  pinMode(j2,OUTPUT);
  pinMode(pwmPin3,OUTPUT);
  pinMode(pwmPin11,OUTPUT); 
  TCCR2B = TCCR2B & B11111000 | B00000001; 
  Serial.begin(9600);
  
}

void loop() {
//  analogWrite(pwmPin3,255);
//  analogWrite(pwmPin11,255);
//  if(digitalRead(7) == HIGH){
//      cw();
//    }
//  else if(digitalRead(2) == LOW){
//      ccw();
//    }
    

}

void cw(){
 digitalWrite(j1,HIGH);
 digitalWrite(j2,LOW); 
 }
void ccw(){
 digitalWrite(j1,LOW);
 digitalWrite(j2,HIGH);  
}
