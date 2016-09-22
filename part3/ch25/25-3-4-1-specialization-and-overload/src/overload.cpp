/*
 * overload.cpp
 *
 *  Created on: 2016/09/22
 *      Author: sasaki
 */


//#include "sort.h"
#include <cstring>
#include <iostream>
//using namespace std;

bool less(const char* a, const char* b)
{
	//std::cout << "less(" << a << "," << b << ")\n";
	return strcmp(a,b)<0;
}

#include "sort.h"
void overload()
{
	Vector<int> vi{10,2,20,5,2,2,4};
	Vector<const char*> vcc{"this", "is", "a", "const", "char*", "Vector"};

	sort(vi);
	std::cout << "vi: " << vi << '\n';
	sort(vcc);
	std::cout << "vcc: " << vcc << '\n';
}


