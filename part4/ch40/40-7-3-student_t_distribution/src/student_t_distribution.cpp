/*
 * student_t_distribution.cpp
 *
 *  Created on: 2017/01/15
 *      Author: sasaki
 */


// student_t_distribution
#include <iostream>
#include <random>

int main()
{
  const int nrolls=10000;  // number of experiments
  const int nstars=100;    // maximum number of stars to distribute

  // intervals definitions:
  const int nintervals=12;
  const double first=-3.0;
  const double span=0.5;

  std::default_random_engine generator;
  std::student_t_distribution<double> distribution(10.0);

  int p[nintervals]={};
  int under_minus_3 = 0, over_3 = 0;

  for (int i=0; i<nrolls; ++i) {
    double number = distribution(generator);
    if ((number>=first)&&(number<first+nintervals*span))
      ++p[int((number-first)/span)];
    else if (number < first) ++under_minus_3;
    else ++over_3;
  }

  std::cout << "student_t_distribution (10.0):" << std::endl;
  std::cout << std::fixed; std::cout.precision(1);

  for (int i=0; i<nintervals; ++i) {
    std::cout.width(4); std::cout << (first+i*span) << "..";
    std::cout.width(4); std::cout << (first+(i+1)*span) << ": ";
    std::cout << std::string(p[i]*nstars/nrolls,'*') << std::endl;
  }

  std::cout << "under -3.0: " << under_minus_3 << ", over 3.0: " << over_3 << std::endl;
  return 0;
}

