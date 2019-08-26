#define mos_swLeft 3
#define mos_swRight 11
#define mos_onRight 6
#define mos_onLeft 9
#define sign_bit A0
#define magnitude_bit A1
#define toS0 10

int volt_command = 0;
int volt_sign = 0;

void setup() {
 pinMode(mos_swLeft,OUTPUT);
 pinMode(mos_swRight,OUTPUT);
 pinMode(mos_onRight,OUTPUT);
 pinMode(mos_onLeft,OUTPUT);
 pinMode(toS0,OUTPUT);
 pinMode(sign_bit,INPUT);
// Serial.begin(9600);
 
// digitalWrite(mos_swRight,HIGH);
// digitalWrite(mos_swLeft,HIGH);
 TCCR2B = TCCR2B & B11111000 | B00000010;
}
// 084 589 7807
void loop() {
//   c_cw_rotation();  //left
//   delay(1500);
//   c_cw_less();
//   delay(3000);
//   stopMotor();
//   delay(3000);
   cw_rotation();   //right
//   delay(1500);
//   cw_less();
//   delay(3000);
//   stopMotor();
//   delay(3000);

}

void readVoltCommand(){
//  digitalWrite(toS0,digitalRead(sign_bit));
  volt_sign = digitalRead(sign_bit);
  digitalWrite(toS0,volt_sign);
//  volt_command = map(analogRead(magnitude_bit),0,1023,0,255);
  volt_command = analogRead(magnitude_bit);
 }
 void drive(){
    if(volt_command <=0){
        stopMotor();
      }
     else if(volt_sign == LOW){
        cw_rotation();
      }
      else
        c_cw_rotation();
 }
 void stopMotor(){
  analogWrite(mos_onRight,0);
  analogWrite(mos_onLeft,0);
  //turn the switching mosfets off
  analogWrite(mos_swLeft,0);
  analogWrite(mos_swRight,0);
 }

void cw_rotation(){//analog swRight to vary speed in this direction
  
     analogWrite(mos_onRight,0);
     analogWrite(mos_onLeft,255);
     digitalWrite(mos_swLeft,HIGH);
     analogWrite(mos_swRight,255);  

 }


 void c_cw_rotation(){//swLeft varies speed in this direction
     analogWrite(mos_onRight,255);
     analogWrite(mos_onLeft,0);
     digitalWrite(mos_swRight,HIGH);
     analogWrite(mos_swLeft,255);
 }
void c_cw_less(){
     digitalWrite(mos_onRight,HIGH);
     digitalWrite(mos_onLeft,LOW);
     digitalWrite(mos_swRight,HIGH);
     analogWrite(mos_swLeft,255);
  }
void  cw_less(){
     digitalWrite(mos_onRight,LOW);
     digitalWrite(mos_onLeft,HIGH);
     digitalWrite(mos_swLeft,HIGH);
     analogWrite(mos_swRight,130);   
 }
