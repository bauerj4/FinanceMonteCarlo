#ifndef PROCCES_HEADER
#define PROCESS_HEADER

#include <vector>
#include <cstdlib>
#include <time.h>
#include <iostream>
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
  virtual std::pair<T,T> GetNextValue(T dx, T dt)=0;

};

template <class T> class BrownianMotion : public Process<T>{
 public:
  // There are no objects that need to be 
  // handled for mem management.  Use empty constructor/destructor

  BrownianMotion<T>() : Process<T>(){};
  ~BrownianMotion(){};

  std::pair<T,T> GetNextValue(T dx, T dt);
};



// template class declarations
//Process<double>         p_d;
//Process<int>            p_i;
BrownianMotion<double>  br_d;
BrownianMotion<int>     br_i;


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




#endif
