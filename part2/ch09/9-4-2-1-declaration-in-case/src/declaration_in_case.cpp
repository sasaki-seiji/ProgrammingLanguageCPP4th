/*
 * declaration_in_case.cpp
 *
 *  Created on: 2016/04/24
 *      Author: sasaki
 */

#include <string>
#include <iostream>
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
		// error: jump to case label [-fpermissive]
		// note:   crosses initialization of ‘std::__cxx11::string s’string s;
		// note:   crosses initialization of ‘int y’int y = 3;
		++x;
		++y;
		s = "nastry!";
	}
}

void g(int i)
{
	switch (i){
	case 0:
	{
		break;
	}
	case 1:
	{
		int x;
		int y = 3;
		string s;
		++x;	// warning: ‘x’ may be used uninitialized in this function [-Wmaybe-uninitialized]
		++y;
		s = "nastry!";
		cout << "x = " << x << ", y = " << y << ", s = " << s << endl;
		break;
	}
	}
}

int main()
{
	g(1);
}
