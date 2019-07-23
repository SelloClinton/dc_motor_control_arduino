#define pwmPin3 3
#define pwmPin5 5
int sensor 3
volatile int counter = 0;
volatile int revolution = 0;
float timer = 0.0;


void setup(){
  pinMode(pwmPin3,OUTPUT);
  pinMode(pwmPin5,OUTPUT);
  pinMode(s1,INPUT);
  attachInterrupt(digitalPinToInterrupt(sensor),gap,CHANGE);
  Serial.begin(9600);
}

void loop(){
//  analogWrite(pwmPin3,0);
//  analogWrite(pwmPin5,255);
    timer = milis();
  
  
}

void gap(){
    if(digitalRead(sensor) == 0){
        counter++;
      }
    if(counter % 80 == 0){
        revolution++
        Serial.print(revolution);
        Serial.println("REVOLUTIONS");
      
      }
  
}
