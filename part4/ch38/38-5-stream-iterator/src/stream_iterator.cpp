/*
 * stream_iterator.cpp
 *
 *  Created on: 2016/12/27
 *      Author: sasaki
 */


#include <iterator>
#include <iostream>
using namespace std;

int main()
{
	copy(istream_iterator<double>{cin}, istream_iterator<double,char>{},
			ostream_iterator<double>{cout,";\n"});
}

