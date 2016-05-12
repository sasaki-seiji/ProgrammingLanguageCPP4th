/*
 * macro.cpp
 *
 *  Created on: 2016/05/12
 *      Author: sasaki
 */

#include <cstdio>
#include <iostream>
using namespace std;

#define err_print(...) fprintf(stderr, "error: %s %d\n", __VA_ARGS__)

int main()
{
	err_print("The answer", 54);

	cout << __func__ << "() in file " << __FILE__ << " on line " << __LINE__ << "\n";
}
