/*
 * old_error_handler.cpp
 *
 *  Created on: 2017/03/09
 *      Author: sasaki
 */

#include <cmath>
#include <cerrno>
#include <iostream>
using namespace std;

int main()
{
	double d = sqrt(-1.0);
	cout << "d = " << d << endl;
	cout << "errno = " << errno << endl;
}


