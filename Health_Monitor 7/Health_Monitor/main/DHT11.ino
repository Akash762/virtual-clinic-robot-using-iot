#include <DHT11.h>

// Create an instance of the DHT11 class and set the digital I/O pin.
DHT11 dht11(12);//Digital Pin 12

void dht11_setup()
{
    // Initialize serial communication at 115200 baud.
    //Serial.begin(9600);
}

void dht11_loop()
{
    // Read the humidity from the sensor.
    float humidity = dht11.readHumidity();

    // Read the temperature from the sensor.
    float temperature = dht11.readTemperature();

    // If the temperature and humidity readings were successful, print them to the serial monitor.
    if (temperature != -1 && humidity != -1)
    {
        /*Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.println(" C");*/
        LCD_Print(1, temperature);
        wifi_temp = temperature;
        delay(2000);
        /*Serial.print("Humidity: ");
        Serial.print(humidity);
        Serial.println(" %");*/
        LCD_Print(2, humidity);
        wifi_humidity = humidity;
    }
    else
    {
        // If the temperature or humidity reading failed, print an error message.
        //Serial.println("Error reading data");
        LCD_Print(6, 0);
    }

    // Wait for 2 seconds before the next reading.
    delay(2000);
}
