#define ENC_REV 400
#define ENC_IN 3
#define PID_OUT 6

volatile int encoderValue = 0;
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
  


//P gain
double Kp = 0.0708;
double Ki = 1;
double Kd = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ENC_IN,INPUT);
  pinMode(PID_OUT,OUTPUT);
  setPoint = 3600;
  
//  attachInterrupt(digitalPinToInterrupt(ENC_IN), updateEncoder, RISING);  

}

void loop() {
  // put your main code here, to run repeatedly:
  updateEncoder();
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

double computePID(double inp){

    currentTime = millis();
    elapsedTime = (double)(currentTime - previousTime);
    
//
    error = setPoint - encoderValue;
    cum_error += error * elapsedTime;
    rateError = (error - lastError)/elapsedTime; 
    double out = Kp*error;// + Ki*cum_error + Kd*rateError;
    

    return out;
    
 }


void updateEncoder(){

  encoderValue+=100;

}
