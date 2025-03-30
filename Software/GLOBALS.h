#pragma once          // Force header file to be processed only once
#include "SENSORS.h"  // Include sensor functions

// Constants
const int No_Of_Sensors = 8;                // Number of sensors
const int SD_Chip_Select = 10;              // SD card chip select pin
const int preheat = 48 * (60 * 60 * 1000);  // Preheat duration in milliseconds (48 hours)
const int upload_interval = 60000;          // Upload interval in milliseconds (1 minute)
const String record_file = "RECORDS.csv";   // SD card file name for records

// Array of Sensor Functions
float (*Sensor[])() = { DHT11, BMP280, BH1750, MQ2, MQ4, MQ7, MQ135, PMS5003 };

// Data Container
float Reading[No_Of_Sensors];