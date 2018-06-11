

/********************************************************
 * PID Proportional on measurement Example
 * Setting the PID to use Proportional on measurement will 
 * make the output move more smoothly when the setpoint 
 * is changed.  In addition, it can eliminate overshoot
 * in certain processes like sous-vides.
 ********************************************************/

#include <PID_v1.h>
#include <SimpleKalmanFilter.h>

PID boostPID(&Input, &Output, &Setpoint,kP,kI,kD,P_ON_M, DIRECT); //P_ON_M specifies that Proportional on Measurement be used
                                                            //P_ON_E (Proportional on Error) is the default behavior
//Define Variables we'll be connecting to


//Specify the links and initial tuning parameters
int filteredOutput;
void boostControl();
void initialiseBoostControl();

