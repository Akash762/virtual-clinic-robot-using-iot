#include <SoftwareSerial.h>
String apiKey = "FNVR3IF6JO751O8H"; //CHANGE

//ESP TX PIN - Arduino PIN 10 RX
//ESP RX PIN - Arduino PIN 11 TX
SoftwareSerial ESP8266(8, 13); // RX, TX   //CHANGE

int humi,temp;
int cnt;

void wifi_setup()
{
  //Serial.begin(9600);  
  ESP8266.begin(115200);
  
  unsigned char check_connection=0;
  unsigned char times_check=0;
  
  Serial.println("Connecting to Wifi");
  LCD_Print(7, 0);
  while(check_connection==0)
  {
    Serial.print("..");
    ESP8266.print("AT+CWJAP=\"Welcome\",\"Welcome123\"\r\n");
    ESP8266.setTimeout(5000);
	  if(ESP8266.find("WIFI CONNECTED\r\n")==1 )
	  {
	    Serial.println("WIFI CONNECTED");
      LCD_Print(8, 0);
	    break;
	  }
	  times_check++;
	  if(times_check>3) 
	  {
	    times_check=0;
	    Serial.println("Trying to Reconnect..");
	  }
  }
  delay(1000);
}

void wifi_loop()
{
  // TCP connection
  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += "184.106.153.149"; // api.thingspeak.com
  cmd += "\",80";
  ESP8266.println(cmd);
  if(ESP8266.find("Error")){
    Serial.println("AT+CIPSTART error");
    return;
  }
  // prepare GET string
  String getStr = "GET /update?api_key=";
  getStr += apiKey;
  getStr +="&field1=";
  getStr += String(wifi_gas); 
  getStr +="&field2=";
  getStr += String(wifi_temp);
  getStr +="&field3=";
  getStr += String(wifi_humidity);
  getStr +="&field4=";
  getStr += String(wifi_ecg);
  getStr += "\r\n\r\n";

  // send data length
  cmd = "AT+CIPSEND=";
  cmd += String(getStr.length()); //Calculate String Length
  ESP8266.println(cmd);

  if(ESP8266.find(">")){ //wait till '>' symbol come, then through the 
    ESP8266.print(getStr);
    Serial.println(getStr);
  }
  else{
    ESP8266.println("AT+CIPCLOSE");
    Serial.println("CIPCLOSE");
  }
    
// thingspeak needs 15 sec delay between updates
 //delay(16000);  
 //delay(16000);
}

int get_sensor_data()
{
  return cnt++;
}