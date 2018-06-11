SimpleKalmanFilter simpleKalmanFilterOutput(2, 2, 0.01);
void initialiseBoostControl ()
{
  //initialize the variables we're linked to
  Input = filteredMap;
  Setpoint = 80;
  kP = 3;
  kI = 5;
  kD = 1;
  boostPin=3;
  //turn the PID on
  boostPID.SetMode(AUTOMATIC);
  boostPID.SetSampleTime(30);
  pinMode (boostPin, OUTPUT);
  boostPID.SetTunings (kP,kI,kD);
  safeBoost = 150;
  overBoost = 190;
  
  smoothOutput = true;
  smoothInput = true;
}

void boostControl ()
{

  
  //adaptiveTunings here . kI_agressive and kI_fine etc
  
  Input = filteredMap;
  if (filteredMap > overBoost )
  {
    Output = 0;
  }

  else if (safeBoost > filteredMap > 100 ) 
  {
    Output = 255;
  }

  else 
  {
  boostPID.Compute();
  filteredOutput = simpleKalmanFilterOutput.updateEstimate(Output);
  }
  if (smoothOutput == true)
  {
    
    analogWrite(boostPin,filteredOutput);
  }

  else
  {
    analogWrite(boostPin,Output);
  }
  
}

