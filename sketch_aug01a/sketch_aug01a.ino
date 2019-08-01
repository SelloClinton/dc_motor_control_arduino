#define input A0
#define output 10
int comp_value = 0;
int store = 0;

void setup() {
  pinMode(input,INPUT);
  pinMode(output,OUTPUT);  

}

void loop() {
  //  store = analogRead(input);
//  //  store = map(analogRead(input),0,1023,0,255);
    digitalWrite(output,digitalRead(input));
    

}
