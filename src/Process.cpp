//#include "../include/Process.h"
//#include <cstdlib>

/*
  Process is an abstract class which describes a general
  container for generating Monte Carlo time series data.
*/

/*
template <typename T>
std::pair<T,T> BrownianMotion<T>::GetNextValue(T dx, T dt){
  double random;
  random = std::rand();

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
  }*/
