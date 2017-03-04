#ifndef PROCCES_HEADER
#define PROCESS_HEADER

#include <vector>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include "Distribution.h"
//#include <pair>

/*
  Header for abstract process class
*/

template <class T> class Process{
 protected:
  std::vector<T> values;
  std::vector<T> times;
 public:
  // Empty constructor and destructor
  Process(){}
  ~Process(){}

  // Function to get next value (returns (time, value))
  //virtual std::pair<T,T> GetNextValue(T dx, T dt)=0;
  //virtual std::pair<T,T> GetNextValue(T dt)=0;

};


/*
  Simple random walk header
*/

template <class T> class BrownianMotion : public Process<T>{
 public:
  // There are no objects that need to be 
  // handled for mem management.  Use empty constructor/destructor

  BrownianMotion<T>() : Process<T>(){};
  ~BrownianMotion(){};

  std::pair<T,T> GetNextValue(T dx, T dt);
  std::pair<T,T> GetNextValue(T dt);
};


/*
  Geometric Brownian motion header.  Must specify
  initial value in constructor.
*/
class GeometricBrownianMotion : public Process<double>{
 private:
  double std;
  double drift;
 public:
  // Constructor 
 GeometricBrownianMotion(double t0, double x0, double mu, double s) : Process<double>(){values.push_back(x0); 
    times.push_back(t0); std = s; drift = mu;};
  ~GeometricBrownianMotion(){};

  std::pair<double,double> GetNextValue(double dt);

};



// template class declarations
//Process<double>         p_d;
//Process<int>            p_i;
BrownianMotion<double>  br_d;
BrownianMotion<int>     br_i;


/*
  Class function declarations
*/

template <typename T>
std::pair<T,T> BrownianMotion<T>::GetNextValue(T dx, T dt){
  double random;
  random = (double)std::rand()/((double) RAND_MAX);

  if (random < 0.5)
    dx *= -1;

  if (this->values.size() == 0){
    this->values.push_back(dx);
    this->times.push_back((T)0);
  }

  else{
    this->times.push_back(this->times.back() + dt);
    this->values.push_back(this->values.back() + dx);
  }

  return std::pair<T,T>(this->times.back(), this->values.back());
}

// empty function. not valid for SRW.
template <typename T>
std::pair<T,T> BrownianMotion<T>::GetNextValue(T dt){
  
  return std::pair<T,T>();
}

// empty function. not valid for GRW
std::pair<double,double> GetNextValue(double dx, double dt){
  return std::pair<double, double>();
}

std::pair<double,double> GeometricBrownianMotion::GetNextValue(double dt){
  double normalSample, nextValue, nextTime;

  nextTime = times.back() + dt;
  normalSample = UnivariateNormal::getSample();
  //std::cout << normalSample << std::endl;
  nextValue = values.back() * (1.0 + drift * dt + std * sqrt(dt) * normalSample);

  values.push_back(nextValue);
  times.push_back(nextTime);

  return std::pair<double, double>(nextTime, nextValue);
}


#endif
