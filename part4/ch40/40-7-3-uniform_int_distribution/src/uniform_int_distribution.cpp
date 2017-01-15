/*
 * uniform_int_distribution.cpp
 *
 *  Created on: 2017/01/15
 *      Author: sasaki
 */

#include <random>
#include <iostream>
using namespace std;

void result()
{
	uniform_int_distribution<> uid3 {0,5};
	default_random_engine e;
	for (int i=0; i<20; ++i)
		cout << uid3(e) << ' ';
	cout << endl;
}

void dist()
{
	  const int nrolls = 10000; // number of experiments
	  const int nstars = 500;    // maximum number of stars to distribute

	  std::default_random_engine generator;
	  std::uniform_int_distribution<int> distribution(0,9);

	  int p[10]={};

	  for (int i=0; i<nrolls; ++i) {
	    int number = distribution(generator);
	    ++p[number];
	  }

	  std::cout << "uniform_int_distribution (0,9):" << std::endl;
	  for (int i=0; i<10; ++i)
	    std::cout << i << ": " << std::string(p[i]*nstars/nrolls,'*') << std::endl;
}

int main()
{
	result();
	dist();
}

