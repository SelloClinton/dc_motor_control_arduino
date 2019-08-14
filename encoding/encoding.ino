#define s1 3
volatile int revolution = 0;
volatile int counter = 0;
volatile int timing = 0;
void setup(){
    pinMode(s1,INPUT);
    pinMode(10,OUTPUT);
    pinMode(A0,INPUT);
    pinMode(A1,INPUT);
    Serial.begin(9600); 
    attachInterrupt(digitalPinToInterrupt(s1), printS, CHANGE);
 }
//
void loop(){
    millis();
}
//
void printS(){
  if(digitalRead(s1) == 0){
      counter++; 
   }
    revolution = counter / 80;
    
   if(counter == 80){
        revolution++;
        counter = 0;
        Serial.print(revolution);
        Serial.println(" REVOLUTIONS");
    }

   
}
