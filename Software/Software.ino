#include "CONTROL.h"
#include "STORAGE.h"

void setup() {
  Serial.begin(9600);
  initSD();
  delay(preheat);
}

void loop() {
  Readings();
  if (!Upload()) LocalStore();
  delay(upload_interval);
}