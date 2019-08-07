#define clk A0
#define dt  A1

//initialize counter
int counter = 0;
int degrees_ = 0;
int lastState;
int revolution = 0;
int encoder = 0;
int oldTime = 0;
int time;
double rev = 0;
double rpm;




void setup() {
  // put your setup code here, to run once:
  //configure clk and dt as digital inputs
 pinMode(clk, INPUT);
 pinMode(dt, INPUT);
 //setup serial monitor
 Serial.begin(9600);
 //read in the last state
 lastState = digitalRead(clk);
 Serial.println("check");
 // attachInterrupt(0,ISR,RISING);  
}

void loop() {
//   delay(1000);
//  detachInterrupt(0);
 // time= millis()-oldTime;
  rpm = rev/(time*60000);
//  oldTime = millis();
  rev = 0;
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
  }
  //update last variable
  lastState = cur_state;
  delay(5);
//  Serial.print("time: ");
//  Serial.print(time);
//  Serial.print(" --- oldTime: ");
//  Serial.println(oldTime);
  Serial.print("counter: ");
  Serial.print(counter);
//  Serial.print(" --- Angle: ");
//  Serial.println(degrees_);
    Serial.print(" --- rpm: ");
    Serial.println(rpm);
//    Serial.print("rev: ");
//    Serial.println(rev);
    //delay(500);
}
//
void isr(){
    rev = counter/20.0;
    Serial.print("rev: ");
    Serial.println(rev);
    
}



  
