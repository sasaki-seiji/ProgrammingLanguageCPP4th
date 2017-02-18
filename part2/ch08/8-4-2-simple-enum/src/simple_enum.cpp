/*
 * simple_enum.cpp
 *
 *  Created on: 2016/04/23
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

//enum Traffic_light { red, yellow, green };
enum Traffic_light { tl_red, tl_yellow, tl_green };
enum Warning { green, yellow, orange, red };
	// redeclaration of 'green'
	// redeclaration of 'red'
	// redeclaration of 'yellow'

//Warning a1 = 7;
	// error: invalid conversion from 'int' to 'Warning' [-fpermissive]
int a2 = green;
int a3 = Warning::green;
Warning a4 = Warning::green;

void f(Traffic_light x)
{
	cout << "-- f(Traffic_light) --\n";

	if (x == 9) { cout << "hit: x == 9\n"; }
	if (x == red) { cout << "hit: x == red\n"; }
		// warning: comparison between 'enum Traffic_light' and 'enum Warning' [-Wenum-compare]
	if (x == Warning::red) { cout << "hit: x == Warning::red\n"; }
		// warning: comparison between 'enum Traffic_light' and 'enum Warning' [-Wenum-compare]
	if (x == Warning::green) { cout << "hit: x == Warning::green\n"; }
		// warning: comparison between 'enum Traffic_light' and 'enum Warning' [-Wenum-compare]
	if (x == Traffic_light::tl_red) { cout << "hit: x == Traffic_light::tf_red\n"; }
}

enum Traffic_light2 : char { tl2_red, tl2_yellow, tl2_green };

enum Color_code : char;
void foobar(Color_code* p);

enum Color_code : char {
	cc_red, cc_yellow, cc_green, cc_blue
};

void foobar(Color_code* p)
{
	cout << "-- foobar(Color_code* p) --\n";
	cout << "  *p = " << *p << endl;
}

enum E1 { dark, light };
enum E2 { a = 3, b = 9 };
enum E3 { min = -10, max = 1000000 };

enum Flag { x=1, y=2, z=4, e=8 };

Flag f0{ };
//Flag f1 = 5;
	// error: invalid conversion from 'int' to 'Flag' [-fpermissive]
//Flag f2 = Flag{5};
	// error: invalid conversion from 'int' to 'Flag' [-fpermissive]
Flag f3 = static_cast<Flag>(5);
Flag f4 = static_cast<Flag>(z|e);
Flag f5 = static_cast<Flag>(99);

enum { arrow_up = 1, arrow_down, arrow_sideways };

int main()
{
	f(Traffic_light::tl_red);

	Color_code cc;
	cc = cc_red;
	foobar(&cc);
	cc = cc_yellow;
	foobar(&cc);
	cc = cc_green;
	foobar(&cc);
	cc = cc_blue;
	foobar(&cc);

	cout << "::f0 = " << ::f0 << '\n';
	cout << "::f3 = " << ::f3 << '\n';
	cout << "::f4 = " << ::f4 << '\n';
	cout << "::f5 = " << ::f5 << '\n';

	cout << "sizeof(E1) = " << sizeof(E1) << '\n';
}
