// include the library code:
#include <LiquidCrystal.h>
 
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(6, 7, 5, 4, 3, 2); //LCD RS=6 ,EN=7, D4=5, D5=4, D6=3, D7=2

void LCD_setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("****WELCOME****");
  delay(1000);
  lcd.clear();
/*
  lcd.setCursor(15, 0);
  lcd.print("Smart Virtual Doctor !!");
  for(int i=0;i<30; i++)//loop for scrolling the LCD text
  {
    lcd.scrollDisplayLeft();//builtin command to scroll left the text
    delay(500);// delay of 150 msec
  }
  lcd.clear();*/
}
 
void LCD_loop() {
  // set the cursor to column 0, line 0
  static int cnt = 0;
  lcd.setCursor(2, 0);
  lcd.print("Hello World");
  lcd.setCursor(7, 1);
  lcd.print(cnt++);
  delay(5000);
  //lcd.noDisplay();//turn off the display of LCD
  //delay(250);//delay to 0.25 seconds
  //lcd.display();//turning on the LCD display
  //delay(250); //delay of 0.25 seconds again
}
void LCD_Print(int no, int data){
  //lcd.noDisplay();
  lcd.clear();
  lcd.setCursor(0, 0);
  switch(no)
  {
    case 1:
      lcd.print("Temprature : ");
      lcd.setCursor(7, 1);
      lcd.print(data);
      lcd.print(" C");
      break;
    case 2:
      lcd.print("Humidity : ");
      lcd.setCursor(7, 1);
      lcd.print(data);
      lcd.print(" %");
      break;
    case 3:
      lcd.print("GAS Status :");
      lcd.setCursor(0, 1);
      lcd.print("GAS Detected");
      break;
    case 4:
      lcd.print("GAS Status :");
      lcd.setCursor(0, 1);
      lcd.print("GAS Not Detected");
      break;
    case 5:
      lcd.print("ECG Enabled Open");
      lcd.setCursor(0, 1);
      lcd.print("Serial Plotter");
      break;
    case 6:
      lcd.print("Sensor Error");
      break;
    case 7:
      lcd.print("Connecting WIFI");
      break;
    case 8:
      lcd.print("WIFI CONNECTED");
      break;
    //delay(2000);
  }
  
  
}