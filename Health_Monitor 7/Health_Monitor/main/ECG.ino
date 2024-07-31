void ECG_setup() {
// initialize the serial communication:
//Serial.begin(9600);
pinMode(10, INPUT); // Setup for leads off detection LO +
pinMode(11, INPUT); // Setup for leads off detection LO -
 
}
 
void ECG_loop() 
{ 
  Serial.println(analogRead(A5));
 /* if((digitalRead(10) == 1)||(digitalRead(11) == 1))
  {
    Serial.println('!');
  }
  else
  {
  // send the value of analog input 0:
    wifi_ecg = analogRead(A0);
    Serial.println(wifi_ecg);
  }*/
  //Wait for a bit to keep serial data from saturating
  delay(100);
}