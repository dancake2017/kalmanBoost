SimpleKalmanFilter simpleKalmanFilterInput(2, 2, 0.01);

void initialiseSensors()
{
  Serial.begin(115200);
  SERIAL_refreshTime = 100;
}

void readMap() {
  // read a reference value from A0 and map it from 0 to 250 (*kpa)
  rawMap = analogRead(A0) / 1024.0 * 250.0;


  // calculate the estimated value with Kalman Filter
  filteredMap = simpleKalmanFilterInput.updateEstimate(rawMap);

  // send to Serial output every 100ms
  // use the Serial Ploter for a good visualization
  if (millis() > refreshTime) {
    Serial.print(Output, 4);
    Serial.print(",");

    Serial.print(filteredMap, 4);
    Serial.println();

    refreshTime = millis() + SERIAL_refreshTime;
  }
}
