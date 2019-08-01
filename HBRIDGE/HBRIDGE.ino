#define mos_swLeft 3
#define mos_swRight 11
#define mos_onRight 6
#define mos_onLeft 9
void setup() {
 pinMode(mos_swLeft,OUTPUT);
 pinMode(mos_swRight,OUTPUT);
 pinMode(mos_onRight,OUTPUT);
 pinMode(mos_onLeft,OUTPUT);
 digitalWrite(mos_swRight,HIGH);
 digitalWrite(mos_swLeft,HIGH);
 TCCR2B = TCCR2B & B11111000 | B00000001;
}

void loop() {

   speed_cw();
//    speed_c_cw();

}

void cw_rotation(){//analog swRight to vary speed in this direction
  
     digitalWrite(mos_onRight,LOW);
     digitalWrite(mos_onLeft,HIGH);  

 }

 void c_cw_rotation(){//swLeft varies speed in this direction
     digitalWrite(mos_onRight,HIGH);
     digitalWrite(mos_onLeft,LOW);
 }

void speed_cw(){
  cw_rotation();
  digitalWrite(mos_swLeft,HIGH);
  analogWrite(mos_swRight,255);
  delay(3000);
  analogWrite(mos_swRight,190);
  delay(3000);
  }

  void speed_c_cw(){
    c_cw_rotation();
  digitalWrite(mos_swRight,HIGH);
  analogWrite(mos_swLeft,255);
  delay(3000);
  analogWrite(mos_swLeft,200);
  delay(3000);
  }
