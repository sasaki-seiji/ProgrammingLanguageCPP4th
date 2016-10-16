/*
 * user.cpp
 *
 *  Created on: 2016/10/15
 *      Author: sasaki
 */


#include "printf.h"
#include <string>
using namespace std;

struct Point {
	int x,y;
};

ostream& operator<<(ostream& os, const Point& pt)
{
	os << '(' << pt.x << ',' << pt.y << ')';
	return os;
}

int main()
{

	try {
		vt_printf("The value of %s is %g\n", "x", 3.14);
		vt_printf("The value of %% is %g\n", 3.14);
		string name = "target";
		vt_printf("The value of %s is %P\n", name, Point{34,200});

		vt_printf("The value of %s is %g\n", 7);

	} catch (runtime_error& e) {
		cout << '\n' << e.what() << '\n' << flush;
	}

	try {
		vt_printf("ends with %", 10, 20);
	} catch (runtime_error& e) {
		cout << '\n' << e.what() << '\n'<< flush;
	}

	try {
		vt_printf("ends with %", 10, 20, 30);
	} catch( runtime_error& e) {
		cout << '\n' << e.what() << '\n'<< flush;
	}
}
