#define s1 3
volatile double revolution = 0;
int lastState;
volatile int counter = 0;
int time;
int oldTime = 0;
double capTime = 0;
double prevRev = 0;
int degrees_ = 0;
double rpm;
void setup(){
    pinMode(s1,INPUT);
    pinMode(10,OUTPUT);
    pinMode(A0,INPUT);
    pinMode(A1,INPUT);
    Serial.begin(9600);
    prevRev = revolution; 
    attachInterrupt(digitalPinToInterrupt(s1), printS, RISING);
    
 }
//
void loop(){

    Serial.print("revolutions: ");
    Serial.println(revolution);
    prevRev = revolution;

}
void printS(){
  
  counter++;
  revolution = counter/3.0;
}
