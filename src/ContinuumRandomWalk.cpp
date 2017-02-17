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
  int nSteps, nWalks;
  std::pair<double,double> p;
  std::vector<double> terminalPoints;
  BrownianMotion<double> * randomWalk;

  dx = 1.0;
  dt = 1.0;
  nSteps = 1000;
  nWalks = 1000;

  std::srand(time(NULL));

  for (int i = 0; i < nWalks; i++ ){
    randomWalk  = new BrownianMotion<double>();
    for (int j = 0; j < nSteps;  j++){
      p = randomWalk->GetNextValue(dx,dt);
      //std::cout << p.first << " "<< p.second << std::endl;
    }
    terminalPoints.push_back(p.second);
  }

  for (auto val: terminalPoints)
    std::cout << val << std::endl;

  

  return 0;
}
