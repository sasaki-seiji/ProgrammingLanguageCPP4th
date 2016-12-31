/*
 * time_put.cpp
 *
 *  Created on: 2016/12/31
 *      Author: sasaki
 */


#include <locale>
#include <iostream>
#include <sstream>
using namespace std;

#include "Date.h"
using namespace Chrono;

int main()
{
	Date d {25, Month::dec, 1959};
	cout << d << endl;
}
