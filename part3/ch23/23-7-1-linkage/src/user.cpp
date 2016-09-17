/*
 * linkage.cpp
 *
 *  Created on: 2016/09/17
 *      Author: sasaki
 */


#include "accum.h"
#include <iostream>
using namespace std;

int main()
{
	vector<double> v {1.1, 1.2, 1.3, 1.4, 1.5, 1.6};
	cout << accum(v) << '\n';
}

