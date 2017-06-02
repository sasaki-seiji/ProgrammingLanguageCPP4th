/*
 * valarray_adl.cpp
 *
 *  Created on: 2017/06/03
 *      Author: sasaki
 */


// ADL

#include <valarray>
using std::valarray;

valarray<double> fct(valarray<double> v1, valarray<double>v2, double d)
{
	return v1+v2*d;
}


// add main

#include <iostream>

int main()
{
	valarray<double> v1 {1.1, 2.2, 3.3, 4.4};
	valarray<double> v2 {1.0, 1.0, 2.0, 3.0};
	valarray<double> ans = fct(v1, v2, 0.5);
	for (auto x : ans)
		std::cout << x << ' ';
	std::cout << '\n';
}



