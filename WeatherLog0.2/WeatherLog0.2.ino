#include <SPI.h>
#include <Seeed_FS.h>
#include "SD/Seeed_SD.h"
#include "Seeed_BME280.h"
#include <Wire.h>
#include "TFT_eSPI.h"

// Initialize necessary objects and variables
File Array;                     // File object for handling SD card
BME280 Sensor;                  // BME280 sensor object
String name = "WeatherLog.csv"; // File name for storing sensor data
TFT_eSPI lcd;                   // LCD display object
bool x = 0;                     // Boolean variable, not currently used

void setup() {
  // Initialize Serial communication for debugging
  Serial.begin(115200);
  pinMode(WIO_LIGHT, INPUT); // Set pin mode for light sensor

  // Wait for Serial connection to be established
  while (!Serial) {
    Serial.begin(115200); // Attempt to begin Serial communication again if not established
  }

  // Initialize LCD display
  lcd.begin();
  lcd.setRotation(3); // Set display rotation
  lcd.fillScreen(TFT_BLACK); // Clear display screen
  lcd.setTextColor(TFT_WHITE, TFT_BLACK); // Set text color

  // Print initialization messages for SD card
  Serial.println("Initialize SDCARD");
  lcd.println("Initialize SDCARD");

  // Attempt to initialize SD card, if failed, print error message and stop program
  while (!SD.begin(SDCARD_SS_PIN, SDCARD_SPI)) {
    Serial.println("SDCARD initialization failed. Reset Wio Terminal");
    lcd.println("SDCARD initialization failed. Check SDCARD and reset device");
    while(1); // Infinite loop, stop program
  }
  // Print success message for SD card initialization
  Serial.println("SDCARD initialized");
  lcd.println("SDCARD initialized");

  // Print initialization messages for sensor
  Serial.println("Initialize Sensor");
  lcd.println("Initialize Sensor");

  // Attempt to initialize sensor, if failed, print error message and stop program
  while (!Sensor.init()) {
    Serial.println("Sensor Error ");
    lcd.println("Sensor Error ");
    while (1); // Infinite loop, stop program
  }
  // Print success message for sensor initialization
  Serial.println("Sensor initialized");
  lcd.println("Sensor initialized");

  // Print initialization completion message
  Serial.println("Initialization Done");
  lcd.println("Initialization Done");

  // Clear display screen
  lcd.fillScreen(TFT_BLACK);
}

void loop() {
  // Read sensor data
  float temp = Sensor.getTemperature();
  float pressure = Sensor.getPressure();
  float Altitude = Sensor.calcAltitude(pressure);
  byte Hum = Sensor.getHumidity();
  byte light = analogRead(WIO_LIGHT); // Read light sensor value

  // Open the data file on SD card in append mode
  Array = SD.open(name, FILE_APPEND);
  
  // Write sensor data to the file on SD card
  Array.print(temp);
  Array.print(",");
  Array.print(pressure);
  Array.print(",");
  Array.print(Altitude);
  Array.print(",");
  Array.print(Hum);
  Array.print(",");
  Array.println(light);
  
  // Close the data file
  Array.close();

  // Print sensor data to Serial monitor
  Serial.print(temp);
  Serial.print("C ,");
  Serial.print(pressure);
  Serial.print("PA,");
  Serial.print(Altitude);
  Serial.print(" M,");
  Serial.print(Hum);
  Serial.print("% ,");
  Serial.print(light);
  Serial.println("(0-255) ,");

  // Display sensor data on LCD screen
  lcd.setFreeFont(&FreeMono12pt7b);
  lcd.drawString("Temperature: " + String(temp) + "C    ", 10, 20);
  lcd.drawString("Pressure: " + String(pressure) + "Pa   ", 10, 40);
  lcd.drawString("Altitude: " + String(Altitude) + "m     ", 10, 60);
  lcd.drawString("Humidity: " + String(Hum) + "%    ", 10, 80);
  lcd.drawString("Light: " + String(light) + "(0-255)   ", 10, 100);

  // Delay for 2 seconds
  delay(2000);
}