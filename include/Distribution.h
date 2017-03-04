#include <cmath>
#include <random>
#include <vector>

#ifndef DISTRIBUTION_HEADER
#define DISTRIBUTION_HEADER

class PDF;
class UnivariateNormal;

/*
  Algorithms for distribution sampling
*/


class PDF{
 public:
  static double getSample();
  static std::vector<double> getSample(int n);
};


class UnivariateNormal : public PDF{
 public:
  static double getSample(){
    double u1, u2, z1;

    /*
      To sample the 1D Gaussian, use Box-Muller algorithm
    */
    
    u1 = (double)rand() / (double)RAND_MAX;
    u2 = (double)rand() / (double)RAND_MAX;

    z1 = cos(2. * M_PI * u1) * sqrt(-2. *log(u2));
 
    return z1;
  }
};


#endif
