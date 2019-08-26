#define sign_bit 7
#define volt 6


void setup() {
  // put your setup code here, to run once:
pinMode(sign_bit,OUTPUT);
pinMode(volt,OUTPUT);

}

void loop(){
  // put your main code here, to run repeatedly:
//  digitalWrite(sign_bit,HIGH);
//  analogWrite(volt,200);
//  delay(5000);
//  analogWrite(volt,0);
//  delay(3000);
//  digitalWrite(sign_bit,LOW);
//  analogWrite(volt,200);
//  delay(3000);
    for(int i = 150; i < 200; i = i+10){
        digitalWrite(sign_bit,HIGH);
        analogWrite(volt,i);
        delay(3000);
      }
    analogWrite(volt,0);
    delay(3000);

    for(int i = 150; i < 200; i = i+10){
        digitalWrite(sign_bit,LOW);
        analogWrite(volt,i);
        delay(3000);
      }

      delay(3000);
    
    

}
