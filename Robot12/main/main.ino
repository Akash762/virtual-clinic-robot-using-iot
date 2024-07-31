/*New blynk app project
 * https://srituhobby.com
 */

//#define BLYNK_AUTH_TOKEN "s8RvcHXjVxQ2vtMrc3HKIQ32rPCQp-eJ" //Enter your blynk auth token
#define BLYNK_TEMPLATE_ID "TMPL3QRPXOiLW"
#define BLYNK_TEMPLATE_NAME "VIRTUAL DOCTOR"
#define BLYNK_AUTH_TOKEN "IBTv33_v7WygirtDxp57A4LMaj-H2BZJ"

#include <Servo.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define Speed 100

Servo servo;

int ENA1 = D0; //Left
int IN11 = D1;
int IN12 = D2;

int ENA2 = D7; //Right
int IN21 = D6;
int IN22 = D5;

int dir = 0;
int servo_ed = 0;

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Welcome";//Enter your WIFI name
char pass[] = "Welcome123";//Enter your WIFI password


BLYNK_WRITE(V2) {
  forward(500); //delay
  stop();
}
BLYNK_WRITE(V3) {
  back(500);
  stop();
}
BLYNK_WRITE(V0) {
  left(1000);
  stop();
}
BLYNK_WRITE(V1) {
  right(1000);
  stop();
}
BLYNK_WRITE(V4) {
  servo_fun();
}

void setup() {
  //pinMode(D0, OUTPUT);
  pinMode(ENA1, OUTPUT);
  pinMode(IN11, OUTPUT);
  pinMode(IN12, OUTPUT);
  
  pinMode(ENA2, OUTPUT);
  pinMode(IN21, OUTPUT);
  pinMode(IN22, OUTPUT); 
  
  digitalWrite(IN11, LOW);
  digitalWrite(IN12, LOW);
  digitalWrite(IN21, LOW);
  digitalWrite(IN22, LOW);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);

  servo.attach(2); //D4
  servo.write(0);
}

void loop() {
  Blynk.run();
}
void back(int delay1)
{
  digitalWrite(IN11, HIGH);
  digitalWrite(IN12, LOW);
  digitalWrite(IN21, HIGH);
  digitalWrite(IN22, LOW);
  
  analogWrite(ENA1, Speed);
  analogWrite(ENA2, Speed);
  delay(delay1);
}

void forward(int delay1)
{
  digitalWrite(IN11, LOW);
  digitalWrite(IN12, HIGH);
  digitalWrite(IN21, LOW);
  digitalWrite(IN22, HIGH);
  
  analogWrite(ENA1, Speed);
  analogWrite(ENA2, Speed);
  delay(delay1);
}

void right(int delay1)
{
  digitalWrite(IN11, LOW);
  digitalWrite(IN12, HIGH);
  digitalWrite(IN21, HIGH);
  digitalWrite(IN22, LOW);
  
  analogWrite(ENA1, Speed);
  analogWrite(ENA2, Speed);
  delay(delay1);
}

void left(int delay1)
{
  digitalWrite(IN11, HIGH);
  digitalWrite(IN12, LOW);
  digitalWrite(IN21, LOW);
  digitalWrite(IN22, HIGH);
  
  analogWrite(ENA1, Speed);
  analogWrite(ENA2, Speed);
  delay(delay1);
}

void stop()
{
  digitalWrite(IN11, LOW);
  digitalWrite(IN12, LOW);
  digitalWrite(IN21, LOW);
  digitalWrite(IN22, LOW);
}

void servo_fun()
{
  if(servo_ed)
  {  
    servo.write(0);
    delay(3000);
    servo_ed = 0;
  }
  else
  {
    servo.write(150);
    delay(10000);
    servo_ed = 1;    
  }
}
