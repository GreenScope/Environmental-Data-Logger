#include "GLOBALS.h"

void InsertionSort(float arr[], int n) {
  for (int i = 1; i < n; i++) {
    float key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

float Average(int sensorIndex) {
  float temp[100];

  for (int i = 0; i < 100; i++) {
    temp[i] = Sensor[sensorIndex]();
    delay(10);
  }

  // Median calculation
  InsertionSort(temp, 100);
  return (temp[49] + temp[50]) / 2.0;
}

void Readings() {
  for (int i = 0; i < No_Of_Sensors; i++) {
    Reading[i] = Average(i);
  }
}