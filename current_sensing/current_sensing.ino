
#define VIN A0
#define pwmPin 3

void setup() {
  pinMode(VIN,INPUT);
  pinMode(pwmPin,OUTPUT);
  Serial.begin(9600);

}

void loop() {
//  float voltage = (5.0/1023)*analogRead(VIN);
//  float v_out = voltage - 2.5 + 0.012;
//  Serial.print("v_out = ");
//  Serial.println(v_out);
  analogWrite(pwmPin,0);
}
