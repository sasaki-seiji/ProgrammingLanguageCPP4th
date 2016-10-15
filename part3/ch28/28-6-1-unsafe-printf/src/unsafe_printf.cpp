/*
 * unsafe_printf.cpp
 *
 *  Created on: 2016/10/15
 *      Author: sasaki
 */


#include <cstdio>
#include <string>
using namespace std;

struct Point {
	int x,y;
};

int main()
{
	printf("The value of %s is %g\n", "x", 3.14);
	string name = "target";
	printf("The value of %s is %P\n", name, Point{34,200});

	// crash
	//printf("The value of %s is %g\n", 7);
}
