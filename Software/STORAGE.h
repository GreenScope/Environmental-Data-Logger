#include "GLOBALS.h"
#include <SPI.h>
#include <SD.h>

void initSD() {
  if (!SD.begin(SD_Chip_Select)) {
    Serial.println("SD Card initialization failed!");
  } else {
    Serial.println("SD Card initialized successfully.");

    if (!SD.exists(record_file)) {
      File dataFile = SD.open(record_file, FILE_WRITE);
      if (dataFile) {
        dataFile.println("Time,Temperature,Relative Humidity,Absolute Humidity,Dew Point,Atmospheric Pressure,Light Intensity,MQ135 Raw Voltage,CO concentration,CH4 concentration,Smoke concentration,PM2.5 concentration,Air Quality Index (Estimate)");
        dataFile.close();
        Serial.println("File created with headers.");
      } else {
        Serial.println("Error creating file.");
      }
    } else {
      Serial.println("File already exists. Remove and upload contents if not already uploaded");
    }
  }
}

void LocalStore() {
  File RECORDS = SD.open(record_file, FILE_WRITE);
  if (RECORDS) {
    RECORDS.print(CurrentTime());
    for (int i = 0; i < No_Of_Sensors; i++) {
      RECORDS.print(",");
      RECORDS.print(Reading[i]);
    }
    RECORDS.println();
    RECORDS.close();
    Serial.println("Data stored locally.");
  } else {
    Serial.println("Error opening file for writing.");
  }
}

bool Upload() {}

// TODO: Create Function to upload the data to the server