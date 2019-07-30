#define pwmPin3 3
#define pwmPin11 11
#define pwmPin6 6
#define pwmPin9 9
void setup() {
 pinMode(pwmPin3,OUTPUT);
 pinMode(pwmPin11,OUTPUT);
 pinMode(pwmPin6,OUTPUT);
 pinMode(pwmPin9,OUTPUT);
 TCCR2B = TCCR2B & B11111000 | B00000001;
}

void loop() {

      analogWrite(pwmPin9,255);
      analogWrite(pwmPin6,0);
      digitalWrite(pwmPin11,HIGH);
      analogWrite(pwmPin3,255);
      delay(3000);
      analogWrite(pwmPin3,180);
      delay(3000);

      
}
