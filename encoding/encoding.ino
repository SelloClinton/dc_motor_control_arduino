#define s1 3
 volatile byte half_revolutions;
 unsigned int rpm;
 unsigned long timeold;
 unsigned int previous;
 unsigned int count = 0;
 void setup()
 {
   Serial.begin(9600);
   attachInterrupt(digitalPinToInterrupt(s1), rpm_fun, RISING);
   half_revolutions = 0;
   rpm = 0;
   timeold = 0;
   //Serial.println(rpm,DEC)
 }
 void loop()
 {  
  if(half_revolutions >= 80) { 
     //Update RPM every 20 counts, increase this for better RPM resolution,
     //decrease for faster update
      rpm = (30*1000/(millis() - timeold)*half_revolutions)/(40);
      timeold = millis();
      Serial.println(rpm,DEC);
      count = half_revolutions; 
      half_revolutions = 0;     
  }
  
 // Serial.println(count,DEC);
 
}

void rpm_fun()
{
   half_revolutions++;
   //Each rotation, this interrupt function is run twice
   
}

//optimal control by bell upto ch6
