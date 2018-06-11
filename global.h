//Anything that should go in a User interface should go here
//Until then, modify the firmware here for tuning

int boostPin ; // PWM output pin for boost solenoid
int SERIAL_refreshTime ;// Data to serial Plotter
int fixedLoopTime ; // nail loops to fixed time per loop. might be bollocks
double Setpoint, Input, Output; // Variables for PID control
int kP ; //Proportional Variable
int kI ; //Integral Variable
int kD ; // Derivative variale

//For dynamic tunings where you have an agressive control under setpoint and finer control near setpoint
int kP_agressive;
int kI_agressive;
int kD_agressive;
int kP_fine;
int kI_fine;
int kD_fine;
int fineControlZone ; // how many KPA under setpoint do we switch from agressive to fine PID control

int safeBoost; //kpa  limit at which boost valve changes from fully closed to PID control
int overBoost; //upper kpa limit where solenoid valve will open and cut boost completely. Set below the spark/ fuel cut safety kpa in speeduino

bool smoothOutput;
bool smoothInput;
 
