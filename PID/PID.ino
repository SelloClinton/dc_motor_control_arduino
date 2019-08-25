#define ENC_REV 400
#define ENC_IN 2
#define PID_OUT 6

volatile int encoderValue = 0;
unsigned long currentTime, previousTime;
double elapsedTime;
double error;
double lastError;
double input,output,setPoint;

//P gain
double Kp = 0.0708;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ENC_IN,INPUT);
  pinMode(PID_OUT,OUTPUT);
  setPoint = 3600;
  
  attachInterrupt(digitalPinToInterrupt(ENC_IN), updateEncoder, RISING);  

}

void loop() {
  // put your main code here, to run repeatedly:

  output = computePID(encoderValue);
  delay(100);
  analogWrite(PID_OUT,output);
  Serial.print("encoder value : ");
  Serial.print(encoderValue);
  Serial.print(" --- PID_OUTPUT : ");
  Serial.println(output);
  

}

double computePID(double inp){
  
//    currentTime = millis();
//    elapsedTime = (double)(currentTime - previousTime);

    error = setPoint - encoderValue;
    double out = Kp*error;
    
    return out;
    
 }


void updateEncoder(){

  encoderValue++;

}
