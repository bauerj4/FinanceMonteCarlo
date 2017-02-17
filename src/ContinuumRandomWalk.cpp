#include "../include/Process.h"
#include <vector>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <time.h>


/*
  This code uses the Brownian Motion class
  to do a random walk.
*/

int main(int argc, char ** argv){
  double dx,dt;
  int nSteps, nWalks;
  std::pair<double,double> p;
  std::vector<double> terminalPoints;
  BrownianMotion<double> * randomWalk;
  std::stringstream ss(std::string(argv[1]));

  std::cerr << "nWalks?" << std::endl;
  std::cin >> nWalks;

  std::cerr << "nSteps?" << std::endl;
  std::cin >> nSteps;

  std::cerr << "dx?" << std::endl;
  std::cin >> dx;

  std::cerr << "dt?" << std::endl;
  std::cin >> dt;


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
