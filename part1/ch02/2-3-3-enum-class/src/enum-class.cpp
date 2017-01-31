/*
 * enum-class.cpp
 *
 *  Created on: 2016/03/20
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

enum class Color { red, blue, green };
enum class Traffic_light { green, yellow, red  };

Traffic_light& operator++(Traffic_light& t)
{
	switch(t) {
	case Traffic_light::green:	return t = Traffic_light::yellow;
	case Traffic_light::yellow:	return t = Traffic_light::red;
	case Traffic_light::red:	return t = Traffic_light::green;
	}
}

// 2016.03.20 add
int main()
{
	Color col = Color::red;
	Traffic_light light = Traffic_light::red;

	cout << "col == Color::red ? " << ( col == Color::red )
			<< ", light == Traffic_light::red ? " << ( light == Traffic_light::red )<< endl;

	//Color x = red;
		// 'red' was not declared in this scope
	//Color y = Traffic_light::red;
		// cannot convert 'Traffic_light' to 'Color' in initialization
	Color z = Color::red;
	//int i = Color::red;
		// cannot convert 'Color' to 'int' in initialization
	//Color c = 2;
		// cannot convert 'int' to 'Color' in initialization

	Traffic_light next = ++light;
	cout << "next == Traffic_light::green ? " << (next == Traffic_light::green) << endl;
}

