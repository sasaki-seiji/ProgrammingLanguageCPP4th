/*
 * cauchy_distribution.cpp
 *
 *  Created on: 2017/01/15
 *      Author: sasaki
 */


// cauchy_distribution
#include <iostream>
#include <random>

int main()
{
  const int nrolls=10000;  // number of experiments
  const int nstars=100;    // maximum number of stars to distribute

  std::default_random_engine generator;
  std::cauchy_distribution<double> distribution(5.0,1.0);

  int p[10]={};
  int under_0 =0, over_10 =0;

  for (int i=0; i<nrolls; ++i) {
    double number = distribution(generator);
    if ((number>=0.0)&&(number<10.0)) ++p[int(number)];
    else if (number < 0.0) ++under_0;
    else ++over_10;
  }

  std::cout << "cauchy_distribution (5.0,1.0):" << std::endl;

  for (int i=0; i<10; ++i) {
    std::cout << i << "-" << (i+1) << ": ";
    std::cout << std::string(p[i]*nstars/nrolls,'*') << std::endl;
  }

  std::cout << "under 0.0: " << under_0 << ", over 10.0: " << over_10 << std::endl;

  return 0;
}

