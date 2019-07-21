int sensor 3
volatile int counter = 0;
volatile int revolution = 0;

void setup(){
  
  pinMode(s1,INPUT);
  attachInterrupt(digitalPinToInterrupt(sensor),gap,CHANGE);
  Serial.begin(9600);
}

void loop(){
  
}

void gap(){
    if(digitalRead(sensor) == 0){
        counter++;
      }
    if(counter == 80){
        revolution++
        Serial.print(revolution);
        Serial.println("REVOLUTIONS");
      
      }
  
}
