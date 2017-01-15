/*
 * geometric_distribution.cpp
 *
 *  Created on: 2017/01/15
 *      Author: sasaki
 */


// geometric_distribution
#include <iostream>
#include <random>

int main()
{
  const int nrolls = 10000; // number of experiments
  const int nstars = 100;   // maximum number of stars to distribute

  std::default_random_engine generator;
  std::geometric_distribution<int> distribution(0.3);

  int p[10]={};
  int over_9 = 0;
  for (int i=0; i<nrolls; ++i) {
    int number = distribution(generator);
    if (number<10) ++p[number];
    else ++over_9;
  }

  std::cout << "geometric_distribution (0.3):" << std::endl;
  for (int i=0; i<10; ++i)
    std::cout << i << ": " << std::string(p[i]*nstars/nrolls,'*') << std::endl;

  std::cout << "over 9 count: " << over_9 << std::endl;

  return 0;
}

