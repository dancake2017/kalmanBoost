#include "global.h"
#include "sensorReads.h"
#include "boostControl.h"

unsigned long timeThen;
unsigned long loopTime;
float rawMap;
float filteredMap;


void setup() 
{
 pinMode (LED_BUILTIN, OUTPUT);
 initialiseSensors(); 
 initialiseBoostControl();
 fixedLoopTime = 5;
 
}

void loop() 
{

 digitalWrite (LED_BUILTIN, HIGH);
 unsigned long timeNow = millis();
 
 readMap();
 boostControl();
 //do stuff

 
 // fix the loop time to defined parameter
 digitalWrite (LED_BUILTIN, LOW);
 unsigned long timeNow2 = millis();
 loopTime = timeNow2 - timeNow ;
 if (loopTime < fixedLoopTime )
 {
  delay (fixedLoopTime - loopTime);
 }
 
}
