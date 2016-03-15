/*
 * main.cpp
 *
 *  Created on: 2016/03/15
 *      Author: sasaki
 */
#include <iostream>
using namespace std;

double square(double x)
{
	return x * x;
}

void print_square(double x)
{
	cout << "the square of " << x << " is " << square(x) << "\n";
}

int main()
{
	print_square(1.234);
}
