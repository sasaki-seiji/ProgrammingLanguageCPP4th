/*
 * large_char_set.cpp
 *
 *  Created on: 2016/04/14
 *      Author: sasaki
 */

#include <iostream>
using namespace std;


int main()
{
	cout << "folder\\file" << '\n';
	cout << R"(folder\file)" << '\n';
	cout << u8"folder\\file" << '\n';
	cout << u8R"(folder\file)" << '\n';
	cout << u"folder\\file" << '\n';
	cout << uR"(folder\file)" << '\n';
	cout << U"folder\\file" << '\n';
	cout << UR"(folder\file)" << '\n';

	cout << u8"The official vowels in Danish are: a, e, i, o, u, \u00E6, \u00F8, \u00E5 and y." << '\n';
}

