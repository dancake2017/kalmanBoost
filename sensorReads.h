#include <SimpleKalmanFilter.h>
/*
 This sample code demonstrates how to use the SimpleKalmanFilter object. 
 
 SimpleKalmanFilter(e_mea, e_est, q);
 e_mea: Measurement Uncertainty 
 e_est: Estimation Uncertainty 
 q: Process Noise
 */


// Serial output refresh time

long refreshTime; 
void initialiseSensors();
void readMap();
