#include <SPI.h>
#include <SD.h>

const int No_Of_Sensors = 3; // Adjust based on your sensors
const int ChipSelect = 4;     // SD card CS pin
int data[No_Of_Sensors];

void setup() {
  Serial.begin(9600);
  while (!Serial); // Wait for serial connection
  
  // Preheat phase
  delay(86400000); // 24-hour preheat (86,400,000 ms)
  
  // SD Card initialization
  if (!SD.begin(ChipSelect)) {
    Serial.println("SD Card initialization failed!");
  }
  
  // Sensor check
  if (!CheckSensors()) {
    Serial.println("Sensor check failed!");
    while(1); // Halt if sensors not detected
  }
  
  Serial.println("System initialized");
}

void loop() {
  Reading();
  
  if (!Upload()) {
    LocalStore();
  }
  
  delay(60000); // Wait 1 minute between cycles
}

bool CheckSensors() {
  // Implement actual sensor detection logic here
  return true; // Placeholder
}

void Reading() {
  for (int i = 0; i < No_Of_Sensors; i++) {
    data[i] = Average(i);
  }
}

int Average(int sensorIndex) {
  int temp[100];
  
  for (int j = 0; j < 100; j++) {
    temp[j] = analogRead(sensorIndex); // Replace with actual read logic
    // Add any processing here
    delay(10); // Short delay between readings
  }
  
  // Median calculation
  bubbleSort(temp, 100);
  return temp[50]; // Median of 100 values
}

bool Upload() {
  Serial.println("Attempting upload...");
  
  // Try sending all sensor values
  for (int i = 0; i < No_Of_Sensors; i++) {
    Serial.print("Sensor");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(data[i]);
    
    // Add actual transmission logic here
    // Return false if any transmission fails
  }
  
  // Simulate random upload success
  return (random(0, 2) == 1); // Replace with actual success check
}

void LocalStore() {
  File dataFile = SD.open("datalog.txt", FILE_WRITE);
  
  if (dataFile) {
    dataFile.print("Local Store: ");
    for (int i = 0; i < No_Of_Sensors; i++) {
      dataFile.print(data[i]);
      dataFile.print(" ");
    }
    dataFile.println();
    dataFile.close();
  }
}

void bubbleSort(int arr[], int n) {
  for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < n-i-1; j++) {
      if (arr[j] > arr[j+1]) {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}