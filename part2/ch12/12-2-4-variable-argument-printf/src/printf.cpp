/*
 * printf.cpp
 *
 *  Created on: 2016/05/07
 *      Author: sasaki
 */

#include <cstdio>
using namespace std;

int main()
{
	printf("Hello, world!\n");
	const char *first_name = "seiji", *second_name = "sasaki";
	printf("My name is %s %s\n", first_name, second_name);
	printf("%d + %d = %d\n", 2, 3, 5);

	printf("My name is %s %s\n", 2);	// crash!!! on Windows, terminated on Ubuntu
		// warning: format '%s' expects a matching 'char*' argument [-Wformat=]
		// warning: format '%s' expects argument of type 'char*', but argument 2 has type 'int' [-Wformat=]
}
