/*
 * specialize1.cpp
 *
 *  Created on: 2016/09/22
 *      Author: sasaki
 */

#include "sort.h"
#include <cstring>
//using namespace std;

template<>
bool less<>(const char* a, const char* b)
{
	return strcmp(a,b)<0;
}

int main()
{
	Vector<int> vi{10,2,20,5,2,4};
	Vector<const char*> vcc{"this", "is", "a", "const", "char*", "Vector"};

	sort(vi);
	sort(vcc);
	std::cout << "vi: " << vi << '\n';
	std::cout << "vcc: " << vcc << '\n';
}
