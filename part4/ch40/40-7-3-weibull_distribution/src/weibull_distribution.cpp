/*
 * weibull_distribution.cpp
 *
 *  Created on: 2017/01/15
 *      Author: sasaki
 */

// weibull_distribution
#include <iostream>
#include <random>

int main()
{
  const int nrolls=10000;  // number of experiments
  const int nstars=100;    // maximum number of stars to distribute

  std::default_random_engine generator;
  std::weibull_distribution<double> distribution(2.0,4.0);

  int p[10]={};
  int over_10 = 0;

  for (int i=0; i<nrolls; ++i) {
    double number = distribution(generator);
    if (number<10) ++p[int(number)];
    else ++over_10;
  }

  std::cout << "weibull_distribution (2.0,4.0):" << std::endl;

  for (int i=0; i<10; ++i) {
    std::cout << i << "-" << (i+1) << ": ";
    std::cout << std::string(p[i]*nstars/nrolls,'*') << std::endl;
  }

  std::cout << "over 10.0 time interval: " << over_10 << std::endl;

  return 0;
}


