#define sensorPin A0

void MQ135_setup() 
{
  //Serial.begin(9600);
  pinMode(9, INPUT);
}


void MQ135_loop() 
{
  //unsigned int sensorValue = analogRead(sensorPin);  // Read the analog value from sensor
  //unsigned int outputValue = map(sensorValue, 0, 1023, 0, 255); // map the 10-bit data to 8-bit data
  
  //Serial.print("Sensor output: ");
  //Serial.print(outputValue);
  int digitalValue = digitalRead(9);
  //Serial.print(digitalValue);

  if (!digitalValue){//(outputValue > 95)
    //Serial.print("  GAS Detected");
    LCD_Print(3, 0);
    wifi_gas = 1;
  }
  else{
    //Serial.print("  GAS Not Detected");
    LCD_Print(4, 0);
    wifi_gas = 0;
  //Serial.println(); 
  //delay(2000);
  }

  //delay(500);
}