# WeatherLogger0.2

## Overview

This project is a weather monitoring system implemented on an Arduino-compatible platform, specifically designed for the Wio Terminal. The system utilizes various sensors to collect environmental data such as temperature, pressure, humidity, and ambient light. The collected data is logged onto an SD card and simultaneously displayed on an LCD screen for real-time monitoring.

## Components Used

- **Wio Terminal**: Arduino-compatible platform with built-in display and connectivity options.
- **BME280 Sensor**: Sensor for measuring temperature, pressure, and humidity.
- **Ambient Light Sensor**: Sensor for measuring ambient light intensity.
- **MicroSD Card Module**: Module for interfacing with a microSD card for data logging.
- **TFT LCD Display**: Display for real-time visualization of sensor data.

## Dependencies

- **Seeed_FS Library**: Library for accessing the file system on the microSD card.
- **Seeed_SD Library**: Library for interfacing with the microSD card module.
- **Seeed_BME280 Library**: Library for interacting with the BME280 sensor.
- **TFT_eSPI Library**: Library for driving TFT LCD displays.

## Setup and Installation

1. Connect the Wio Terminal to your computer via USB.
2. Install the required libraries listed above using the Arduino Library Manager.
3. Upload the provided code to the Wio Terminal using the Arduino IDE.
4. Ensure that all sensors are properly connected to the Wio Terminal.
5. Insert a microSD card into the microSD card module for data logging.

## Usage

1. Upon power-up, the system initializes the SD card and sensors.
2. Sensor data (temperature, pressure, humidity, and light intensity) is logged onto the microSD card in CSV format.
3. Real-time sensor readings are displayed on the TFT LCD screen.
4. The system continuously loops, collecting and logging data until powered off.

## Troubleshooting

- If the SD card initialization fails, ensure that the microSD card is properly inserted and formatted correctly.
- Check the wiring connections of all sensors to ensure they are correctly connected to the Wio Terminal.
- Verify that the required libraries are installed correctly in the Arduino IDE.

## License

This project is licensed under the [MIT License](LICENSE).
