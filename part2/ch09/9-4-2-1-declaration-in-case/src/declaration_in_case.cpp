/*
 * declaration_in_case.cpp
 *
 *  Created on: 2016/04/24
 *      Author: sasaki
 */

#include <string>
using namespace std;

void f(int i)
{
	switch (i){
	case 0:
		int x;
		int y = 3;
		string s;
		break;
	//case 1:
		// jump to case label [-fpermissive]
		++x;
		++y;
		s = "nastry!";
	}
}

