/*
 * user.cpp
 *
 *  Created on: 2016/10/13
 *      Author: sasaki
 */


#include "Tuple.h"
#include <iostream>
using namespace std;

int main()
{
	Tuple<double,int,char> x {1.1, 42, 'a'};
	cout << x << "\n";
	cout << Tuple<double,int,int,int>{1.2,3,5,7} << "\n";
	cout << Tuple<double,int,int>{1.2,3,5} << "\n";
	cout << Tuple<double,int>{1.2,3} << "\n";
	cout << Tuple<double>{1.2} << "\n";
	cout << Tuple<>{} << "\n";
}
