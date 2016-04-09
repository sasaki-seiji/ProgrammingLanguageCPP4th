/*
 * user.cpp
 *
 *  Created on: 2016/03/20
 *      Author: sasaki
 */

#include "Vector.h"
#include <cmath>
#include <iostream> // 2016.03.20 add
using namespace std;

double sqrt_sum(Vector& v)
{
	double sum = 0;
	for( int i = 0 ; i != v.size() ; ++i ) {
		sum += sqrt(v[i]);
	}
	return sum;
}

// 2016.03.20 add
int main()
{
	Vector v(5);
	for( int i = 0 ; i != v.size() ; ++i ) {
		cin >> v[i];
	}
	double sum = sqrt_sum(v);
	cout << "sum: " << sum << endl;
}


