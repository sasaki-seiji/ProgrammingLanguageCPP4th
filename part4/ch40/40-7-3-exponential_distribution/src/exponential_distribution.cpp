/*
 * exponential_distribution.cpp
 *
 *  Created on: 2017/01/15
 *      Author: sasaki
 */

// exponential_distribution
#include <iostream>
#include <random>

int main()
{
  const int nrolls=10000;  // number of experiments
  const int nstars=100;    // maximum number of stars to distribute
  const int nintervals=10; // number of intervals

  std::default_random_engine generator;
  std::exponential_distribution<double> distribution(3.5);

  int p[nintervals]={};
  int over_1 = 0;

  for (int i=0; i<nrolls; ++i) {
    double number = distribution(generator);
    if (number<1.0) ++p[int(nintervals*number)];
    else ++over_1;
  }

  std::cout << "exponential_distribution (3.5):" << std::endl;
  std::cout << std::fixed; std::cout.precision(1);

  for (int i=0; i<nintervals; ++i) {
    std::cout << float(i)/nintervals << "-" << float(i+1)/nintervals << ": ";
    std::cout << std::string(p[i]*nstars/nrolls,'*') << std::endl;
  }

  std::cout << "over 1.0 time interval: " << over_1 << std::endl;

  return 0;
}


