#define ENC_REV 400
#define ENC_IN 2
#define PID_OUT 6
#define ENC_COUNT_REV 400

volatile long encoderValue = 0;
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
double Ki = 1;
double Kd = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ENC_IN,INPUT_PULLUP);
  pinMode(PID_OUT,OUTPUT);
  setPoint = 3600;
  previousMillis = millis();
  attachInterrupt(digitalPinToInterrupt(ENC_IN), updateEncoder, RISING);  

}

void loop() {
  // put your main code here, to run repeatedly:
//  pickController();
//  volt_command();  
    computeRPM();
}

double computePID(double inp){

    currentTime = millis();
    elapsedTime = (double)(currentTime - previousTime);
    
//
    error = setPoint - encoderValue;
    cum_error += error * elapsedTime;
    rateError = (error - lastError)/elapsedTime; 
    double out = Kp*error; + Ki*cum_error + Kd*rateError;
    

    return out;
    
 }
void volt_command(){
  
//   updateEncoder();
  output = computePID(encoderValue);

  delay(100);
  if((encoderValue - eps < 0) || (setPoint  - encoderValue < eps )){
    output = 0;
 //     analogWrite(PID_OUT,output);
      
    }
   else if(output > 255.0){
   //   lastOut = 255.0;
      output = max;
//      analogWrite(PID_OUT,output);
       
   }
   else if (output < 160.0){
        output = min;
    }
  analogWrite(PID_OUT,output); 
  Serial.print("encoder value : ");
  Serial.print(encoderValue);
  Serial.print(" --- PID_OUTPUT : ");
  Serial.println(output);
 
  
  delay(1000);
 
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
        Serial.print("RPM: ");
        Serial.println(rpm);
      }
}

void updateEncoder(){

  encoderValue++;

}
