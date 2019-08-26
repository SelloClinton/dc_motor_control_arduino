#define ENC_REV 400
#define ENC_IN 2
#define PID_OUT 6
#define ENC_COUNT_REV 400
#define BUTTON 7

volatile long encoderValue = 0;
volatile long counter = 0;
unsigned long currentTime, previousTime;
double elapsedTime;
double error;
double lastError;
double input,output,setPoint;
double cum_error, rateError;
double lastOut = 255.0;
double eps = 8854e-12; 
double max = 255.0;
double min = 160.0;
// Counters for milliseconds during interval
long previousMillis = 0;
long currentMillis = 0;
int interval = 100;


int rpm = 0;

double rpm_array[] = {124.0,150.0,154.0,166.0,168.0,188.0,190.0,200.0};
  


//P gain
double Kp = 0.0708;
double Ki = 0;
double Kd = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(BUTTON,INPUT_PULLUP);
  pinMode(ENC_IN,INPUT_PULLUP);
  pinMode(PID_OUT,OUTPUT);
  setPoint = 23532; // 1.59 pinion_revs
  previousMillis = millis();
  attachInterrupt(digitalPinToInterrupt(ENC_IN), updateEncoder, RISING);  
 // digitalWrite(7,0);

}

void loop() {
  // put your main code here, to run repeatedly:
 //    computeRPM();

    
 //   pickController();
//    Serial.print("counter: ");
//    Serial.println(counter);
 //   volt_command();  
    while(digitalRead(BUTTON) == HIGH){
        Serial.println("WAITING FOR BUTTON PRESS...");
      }
      Serial.println("BUTTON PRESSED...");
      counter = 1;
      while(setPoint - counter > 0){
          computePID(counter);
          volt_command();
          Serial.print("counter: ");
          Serial.print(counter);
          Serial.print(" --- PWM_OUT: ");
          Serial.println(output);
        }
//Serial.println()
    
}

double computePID(double inp){

    currentTime = millis();
    elapsedTime = (double)(currentTime - previousTime);
    
//
    error = setPoint - counter;
    cum_error += error * elapsedTime;
    rateError = (error - lastError)/elapsedTime; 
    double out = Kp*error; + Ki*cum_error + Kd*rateError;
    

    return out;
    
 }
void volt_command(){
  

  output = computePID(counter);

  delay(100);
  if((counter - eps < 0) || (setPoint  - counter < eps )){
    output = 0;
    }
   else if(output > 255.0){
      output = max;
   }
   else if (output < 160.0){
        output = min;
    }
  analogWrite(PID_OUT,output); 
//  Serial.print("counter value : ");
//  Serial.print(counter);
  Serial.print(" --- PID_OUTPUT : ");
  Serial.println(output);
 
  
//  delay(1000);
 
}

void pickController(){
  
      if((rpm >= 120.0)&&(rpm <= 150.0)){
            Kp = 1;
            Kd = 0.5;
            Ki = 0.005;
        }
       else if((rpm >= 154.0)&&(rpm <= 166.0)){
            Kp = 2;
            Kd = 1;
            Ki = -1;
        }
       else if((rpm >= 168.0)&&(rpm <= 188.0)){
        
            Kp = 0.5;
            Kd = 2.5;
            Ki = 0;
        }
       else if((rpm >= 190.0)&&(rpm <= 200.0)){
        
          Kp = 10;
          Kd = 4;
          Ki = 14;
        }
        Serial.println("*************");
        Serial.print("GAINS: ");
        Serial.print("Kp: ");
        Serial.print(Kp);
        Serial.print(", Kd: ");
        Serial.print(Kd);
        Serial.print(", Ki: ");
        Serial.println(Ki);
        Serial.println("**************");
  
  }

void computeRPM(){
  
    currentMillis = millis();

  if (currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;


//     Calculate RPM
        rpm = (float)(encoderValue * 60 / ENC_COUNT_REV);
        encoderValue = 0;
//        Serial.print("RPM: ");
//        Serial.println(rpm);
      }
}

void updateEncoder(){

  encoderValue++;
  counter++;

}
