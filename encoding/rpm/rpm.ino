
#define dt 2

volatile int dt_pulse = 0;
volatile int lastC = 0; 

void setup() {
  pinMode(dt,INPUT);
  // put your setup code here, to run once:
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(dt), angle, CHANGE);
  lastC = digitalRead(dt);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Pulses read: ");
  Serial.println(dt_pulse);
 // delay(500);
}

void angle(){

//  if(digitalRead(dt) == HIGH){
//      dt_pulse--; 
//    }
//   else{
//      dt_pulse++;
//    }
  Serial.println("inside int");
  
}
