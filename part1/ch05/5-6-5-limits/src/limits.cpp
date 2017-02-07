/*
 * limits.cpp
 *
 *  Created on: 2016/04/08
 *      Author: sasaki
 */


#include <limits>
#include <iostream>
using namespace std;

static_assert(numeric_limits<char>::is_signed, "unsigned characters!");
static_assert(100000 < numeric_limits<int>::max(), "small ints!");

int main()
{
	cout << "compile ok!\n";
}
