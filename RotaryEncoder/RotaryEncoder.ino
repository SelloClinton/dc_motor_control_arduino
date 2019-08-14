#define clk A0
#define dt  A1
#define mos_swLeft 3
#define mos_swRight 11
#define mos_onRight 6
#define mos_onLeft 9
//initialize counter
int counter = 0;
int degrees_ = 0;
int lastState;
int revolution = 0;
int encoder = 0;
int oldTime = 0;
int time;
double capTime = 0;
double rev = 0;
double rpm;




void setup() {
  // put your setup code here, to run once:
  //configure clk and dt as digital inputs
 pinMode(mos_swLeft,OUTPUT);
 pinMode(mos_swRight,OUTPUT);
 pinMode(mos_onRight,OUTPUT);
 pinMode(mos_onLeft,OUTPUT);
 pinMode(clk, INPUT);
 pinMode(dt, INPUT);
 TCCR2B = TCCR2B & B11111000 | B00000010;
 //setup serial monitor
 Serial.begin(9600);
 //read in the last state
 lastState = digitalRead(clk);
 Serial.println("check");
 // attachInterrupt(0,ISR,RISING);  
}

void loop() {
 cw_rotation();
 //  delay(1000);
//  detachInterrupt(0);
 // time= millis()-oldTime;
  rpm = ((0.05)*(60000))/(capTime*1000.0);
//  oldTime = millis();
  rev = 0;
//  time = 0;
 // attachInterrupt(0,ISR,RISING);
  
  
  // put your main code here, to run repeatedly:
  //read in the current state of clk pin
  int cur_state = digitalRead(clk);
  //compare it to its last state
  if(cur_state != lastState){
    //change in state means movement
    if(cur_state != digitalRead(dt)){
      time= millis()-oldTime;
      //non-matching states means clockwise
      counter--;
      degrees_ = degrees_-18;
      if(counter % 20 == 0){
          isr();
        }
    }
    else{
      //non-matching states means
      counter++;
      degrees_ = degrees_+18;
      if(counter % 20 == 0){
          isr();
        }
      

    }
      oldTime = millis();
      capTime = time/1000.0;
  }
  //update last variable
  lastState = cur_state;
  delay(5);
//  Serial.print("time: ");
//  Serial.print(time);
//  Serial.print(" --- oldTime: ");
//  Serial.println(oldTime);
  Serial.print("RPM: ");
  Serial.println(rpm);
//  Serial.print(" --- Angle: ");
//  Serial.println(degrees_);
    Serial.print(" --- captime: ");
    Serial.println(capTime);
    Serial.print("counter: ");
    Serial.println(counter);
    //delay(500);
    time = 0;
}
//
void isr(){
    rev = counter/20.0;
    Serial.print("rev: ");
    Serial.println(rev);
    
}

void cw_rotation(){//analog swRight to vary speed in this direction
  
     analogWrite(mos_onRight,0);
     analogWrite(mos_onLeft,255);
     digitalWrite(mos_swLeft,HIGH);
     analogWrite(mos_swRight,200);  

 }



  
