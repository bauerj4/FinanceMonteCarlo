#ifndef ASSET_HEADER
#define ASSET_HEADER


/*
  Asset serves as the base class for Derivative
  and other asset classes
*/

class Asset{

 public:
  static double rRiskFree; // The risk free rate as defined elsewhere.
  double value;            // The current value of the asset

  virtual inline double getNextValue(double dt){return value;}; // virtual value function to be defined

};


/*
  Basic stock class.  Extends Asset
*/

class Stock : public Asset{
 public:
  // Constructor
  Stock(){}
  
  // Destructor
  ~Stock(){}

  // Get next stock value
  inline double getNextValue(double dt){return 0.;}
};

/*
  Zero coupon bond class.  Extends Asset
*/

class ZeroCouponBond : public Asset{
 public:

  double parValue;        // Face value of the ZCB
  double timeToMaturity;  // Time left until maturity.

  // Constructor
  ZeroCouponBond(){}
  
  // Destructor
  ~ZeroCouponBond(){}
  
  inline double getNextValue(double dt);
};


/*
  ETF meant to hold information about the market
  averages.  Can be used to correlate certain assets with.
*/

class MarketETF : public Asset{

  // Constructor
  MarketETF(){}

  // Destructor
  ~MarketETF(){}

  inline double getNextValue(double dt);
};


#endif // ASSET_HEADER
