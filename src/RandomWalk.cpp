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
  double dx,dt;
  int nSteps;
  std::pair<double,double> p;

  dx = 1.0;
  dt = 1.0;
  nSteps = 1000;

  std::srand(time(NULL));
  BrownianMotion<double> * randomWalk = new BrownianMotion<double>();

  for (int i = 0; i < 1000;  i++){
    p = randomWalk->GetNextValue(dx,dt);
    std::cout << p.first << " "<< p.second << std::endl;
  }

  

  return 0;
}
