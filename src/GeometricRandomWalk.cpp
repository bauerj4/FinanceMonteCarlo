#include "../include/Process.h"
#include <vector>
#include <cstdlib>
#include <iostream>
#include <time.h>


/*
  This code uses the Brownian Motion class
  to do a random walk.
*/

int main(){
  double drift,std,dt,x0;
  int nSteps;
  std::pair<double,double> p;

  x0    = 100.;
  drift = 0.03;
  std   = 0.4;
  dt = 0.01;
  nSteps = 1000;

  std::srand(time(NULL));
  GeometricBrownianMotion * GOOG = new GeometricBrownianMotion(0.0, x0, drift,std);

  for (int i = 0; i < 1000;  i++){
    p = GOOG->GetNextValue(dt);
    std::cout << p.first << " "<< p.second << std::endl;
  }

  

  return 0;
}
