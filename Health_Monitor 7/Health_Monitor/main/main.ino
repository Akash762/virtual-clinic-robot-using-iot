int ev=1 ; //EGG Enable and Disable (1=ECG ON, 0=ECG OFF)

int wifi_temp = 0;
int wifi_humidity = 0;
int wifi_gas = 0;
int wifi_ecg = 0;

int button_status()
{
  //Serial.println(analogRead(A1));
  //if(analogRead(A1) > 100)
  if(ev)
  {
    return 1;
  }
  else 
  {
    return 0;
  }
}
void setup() 
{
  Serial.begin(9600);
  LCD_setup();
  //pinMode (A1,INPUT);
  
  ECG_setup();   //ECG
  dht11_setup(); //Temp & Humidity
  MQ135_setup(); //MQ-135 Gas Sensor
  wifi_setup();
}

void loop() 
{
  if(button_status()){
    LCD_Print(5, 0);
    delay(50);
    ECG_loop();   //ECG
  }
  else
  {
    dht11_loop(); //Temp & Humidity
    MQ135_loop(); //MQ-135 Gas Sensor
    wifi_loop();  //ThingSpeak
  }
}
