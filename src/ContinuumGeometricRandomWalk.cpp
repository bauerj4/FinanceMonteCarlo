#include "../include/Process.h"
#include <vector>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <time.h>


/*
  This code uses the Geometric Brownian Motion class
  to do a random walk to recover the lognormal distribution.
*/

int main(int argc, char ** argv){
  double dx,dt,mu,x0,std;
  int nSteps, nWalks;
  std::pair<double,double> p;
  std::vector<double> terminalPoints;
  GeometricBrownianMotion * randomWalk;
  std::stringstream ss(std::string(argv[1]));

  std::cerr << "nWalks?" << std::endl;
  std::cin >> nWalks;

  std::cerr << "nSteps?" << std::endl;
  std::cin >> nSteps;

  std::cerr << "x0?" << std::endl;
  std::cin  >> x0;


  std::cerr << "dt?" << std::endl;
  std::cin >> dt;

  std::cerr << "drift?" << std::endl;
  std::cin >> mu;

  std::cerr << "volatility?" << std::endl;
  std::cin >> std;


  std::srand(time(NULL));

  for (int i = 0; i < nWalks; i++ ){
    randomWalk  = new GeometricBrownianMotion(0.0, x0, mu, std);
    for (int j = 0; j < nSteps;  j++){
      p = randomWalk->GetNextValue(dt);
    }
    terminalPoints.push_back(p.second);
  }

  for (auto val: terminalPoints)
    std::cout << val << std::endl;

  

  return 0;
}
