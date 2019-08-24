 /*
  Gearmotor Rotary Encoder Test
  motor-encoder-rpm.ino
  Read pulses from motor encoder to calculate speed
  Control speed with potentiometer
  Displays results on Serial Monitor
  Use Cytron MD10C PWM motor controller
  DroneBot Workshop 2019
  https://dronebotworkshop.com
*/

// Motor encoder output pulse per rotation (change as required)
#define ENC_COUNT_REV 400
#define mag A0
#define sign_bit 6
#define compare 7
#define org A1
#define inv A2
double voltage = 0.0;
#define dt 3

// Encoder output to Arduino Interrupt pin
#define ENC_IN 2 

// MD10C PWM connected to pin 10
#define PWM 10 
// MD10C DIR connected to pin 12
#define DIR 12 

// Analog pin for potentiometer
int speedcontrol = 0;

// Pulse count from encoder
volatile long encoderValue = 0;

// One-second interval for measurements
int interval = 100;
         
// Counters for milliseconds during interval
long previousMillis = 0;
long currentMillis = 0;

// Variable for RPM measuerment
int rpm = 0;

// Variable for PWM motor speed output
int motorPwm = 0;
volatile double direct = 0.0; 
volatile int lastState;
int time = 0;


void setup()
{
  // Setup Serial Monitor
  Serial.begin(9600); 
  
  // Set encoder as input with internal pullup  
  pinMode(ENC_IN, INPUT_PULLUP); 

  // Set PWM and DIR connections as outputs
  pinMode(PWM, OUTPUT);
  pinMode(DIR, OUTPUT);
  pinMode(mag,INPUT);
  pinMode(sign_bit,OUTPUT);
  pinMode(dt,INPUT_PULLUP);
  pinMode(compare,INPUT);

  
  // Attach interrupt 
  attachInterrupt(digitalPinToInterrupt(ENC_IN), updateEncoder, RISING);
  
  // Setup initial values for timer
  previousMillis = millis();
  lastState = digitalRead(dt);
  
}

void loop()
{
  
    digitalWrite(sign_bit,analogRead(mag));
//
    if(analogRead(mag) > 0){
      voltage = 2.0*(analogRead(org)/400.0);
    }
  else if(analogRead(mag) == 0){
      voltage = -2.0*((analogRead(org)/400.0));
    }

  currentMillis = millis();

  if (currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;


//     Calculate RPM
//   if(voltage >= 0.0){
        rpm = (float)(encoderValue * 60 / ENC_COUNT_REV);
//    }
//    else if(voltage < 0.0){
//        rpm = (float)(-1.0*encoderValue * 60 / ENC_COUNT_REV);
//      } 
//  }  
////
   
    encoderValue = 0;

//    Serial.print("V: ");
//    Serial.print(voltage);
//    Serial.print('\t');
    Serial.print(" RPM: ");
    Serial.println(rpm);
    


}
}

void updateEncoder(){

  encoderValue++;

}
