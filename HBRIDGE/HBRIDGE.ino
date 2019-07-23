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

        analogWrite(pwmPin3,0);
        analogWrite(pwmPin5,255);
        delay(3000);
        analogWrite(pwmPin5,200);
        delay(3000);
        analogWrite(pwmPin5,150);
        delay(3000);
        analogWrite(pwmPin5,135);
        delay(3000);
        analogWrite(pwmPin5,0);
        delay(3000);
        
}
