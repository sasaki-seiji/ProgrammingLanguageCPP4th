/*
 * struct_layout.cpp
 *
 *  Created on: 2016/04/17
 *      Author: sasaki
 */


#include <iostream>
using namespace std;

struct Readout {
	char hour;
	int value;
	char seq;
};

struct Readout2 {
	int value;
	char hour;
	char seq;
};

int main()
{
	cout << "sizeof(Readout) = " << sizeof(Readout) << '\n';
	cout << "sizeof(Readout2) = " << sizeof(Readout2) << '\n';
}
