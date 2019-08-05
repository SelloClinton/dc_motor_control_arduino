//for direction control
#define c_wise_gates   9
#define a_c_wise_gates 10
//for speed control
#define c_wise_pwm     3
#define a_c_wise_pwm   11
//for rotary encoder
#define clk            A1
#define dt             A2
//for voltage commands
#define sign_bit       A3
#define mag_git        A4

//read in and process magnitude and sign information
void readVoltageCommand();
void driveMotor();
void computeSpeed();


//rotate motor at given speed
void rotateCW();
void rotateCCW();
void stopMotor();
//generate output data based on input signal
double motorPosition();

double lastState;
double volt_command = 0;
double volt_sign = 0;

void setup(){
  // put your setup code here, to run once:
  pinMode(input_data,INPUT);
  pinMode(clk, INPUT);
  pinMode(dt, INPUT);
  pinMode(sign_bit,INPUT);
  pinMode(mag_bit,INPUT);
  //read in the last state
 lastState = digitalRead(clk);
}

void loop(){
  // put your main code here, to run repeatedly:
  //read in voltage command
  readVoltageCommand();
  //drive motor based on received voltage command
  driveMotor();
  //compute speed
//  computeSpeed();
}

//read in and process magnitude and sign information
void readVoltageCommand(){
  volt_sign = digitalRead(sign_bit);
  //a high on this pin means that value is positive
  volt_command = map(analogRead(mag_bit),0,1023,0,255);
}

void driveMotor(){
//if desired speed is zero stop motor
  if(volt_command >= 100){
    stopMotor();
  }
  //if sign is negative, run the motor counter-clockwise at desired speed
  else if(volt_sign == LOW){
    rotateCCW();
  }
  //else rotate motor clockwise at desired speed
  else
      rotateCW();
}

//command to rate clockwise at given speed
void rotateCW()
{
  //to rotate motor clockwise...
  //send low to right channel gates
  analogWrite(a_c_wise_gates,0);
  //send high to left channel gates
  analogWrite(c_wise_gates,255);
  //hold left switch high i.e keep it on
  digitalWrite(a_c_wise_pwm,HIGH);
  //run at desired speed
  analogWrite(c_wise_pwm,volt_command);
}

void rotateCCW()
{
  //to rotate motor counter clockwise...
  //send low to left channel gates
  analogWrite(c_wise_gates,0);
  //send high to right channel gates
  analogWrite(a_c_wise_gates,255);
  //hold g2 high
  digitalWrite(c_wise_pwm,HIGH);
  //run at one speed for 3 seconds and move to lower
  analogWrite(a_c_wise_pwm,volt_command);
}

void stopMotor(){
  //clockwise and anti-clockwise gates off 
  analogWrite(c_wise_gates,0);
  analogWrite(a_c_wise_gates,0);
  //turn the switching mosfets off
  analogWrite(c_wise_pwm,0);
  analogWrite(a_c_wise_pwm,0);
}

//the speed of the motor is its response to the input voltage
//to calculate the speed we need to read from the rotary encoder
void motorPosition(){
  //read in the current state of clk pin
  int cur_state = digitalRead(clk);
  //compare it to its last state
  if(cur_state != lastState){
    //change in state means movement
    if(cur_state != digitalRead(dt)){
      //non-matching states means clockwise
      counter--;
      if(counter % 38 == 0){
          rev_ccw();
        }
    }
    else{
      //non-matching states means
      counter++;
      if(counter % 38 == 0){
          rev();
      }  
    }
  }
  //update last variable
  lastState = cur_state;
}
