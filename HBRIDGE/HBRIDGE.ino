#define pwmPin3 3
#define pwmPin5 5
#define pwmPin6 6
#define pwmPin9 9
void setup() {
 pinMode(pwmPin3,OUTPUT);
 pinMode(pwmPin5,OUTPUT);
 pinMode(pwmPin6,OUTPUT);
 pinMode(pwmPin9,OUTPUT);
}

void loop() {

      analogWrite(pwmPin3,255);
      analogWrite(pwmPin5,0);

}
