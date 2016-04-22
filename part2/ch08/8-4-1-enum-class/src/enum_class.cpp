/*
 * enum_class.cpp
 *
 *  Created on: 2016/04/23
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

enum class Traffic_light { red, yellow, green };
enum class Warning { green, yellow, orange, red };

//Warning a1 = 7;
	// cannot convert 'int' to 'Warning' in initialization
//int a2 = green;
	// 'green' was not declared in this scope
//int a3 = Warning::green;
	// cannot convert 'Warning' to 'int' in initialization
Warning a4 = Warning::green;

void f(Traffic_light x)
{
	//if (x) { }
		// could not convert 'x' from 'Traffic_light' to 'bool'
	//if (x == 9) { }
		// no match for 'operator==' (operand types are 'Traffic_light' and 'int')
	//if (x == red) { }
		// 'red' was not declared in this scope
	//if (x == Warning::red) { }
		// no match for 'operator==' (operand types are 'Traffic_light' and 'Warning')
	if (x == Traffic_light::red) { }
}

enum class Warning2 : int { green, yellow, orange, red };
enum class Warning3 : char { green, yellow, orange, red };

void f(Warning key)
{
	switch (key) {
		// enumeration value 'yellow' not handled in switch [-Wswitch]
	case Warning::green:
		cout << "Warning::green\n";
		break;
	case Warning::orange:
		cout << "Warning::orange\n";
		break;
	case Warning::red:
		cout << "Warning::red\n";
		break;
	}
}

enum class Printer_flags {
	none=0,
	acknowledge=1,
	paper_empty=2,
	busy=4,
	out_of_black=8,
	out_of_color=16,
};

constexpr Printer_flags operator|(Printer_flags a, Printer_flags b)
{
	return static_cast<Printer_flags>(static_cast<int>(a)|static_cast<int>(b));
}

constexpr Printer_flags operator&(Printer_flags a, Printer_flags b)
{
	return static_cast<Printer_flags>(static_cast<int>(a)&static_cast<int>(b));
}

void try_to_print(Printer_flags x)
{
	if ((x&Printer_flags::acknowledge) != Printer_flags::none) {
		cout << "acknowledge\n";
	}
	else if ((x&Printer_flags::busy) != Printer_flags::none) {
		cout << "busy\n";
	}
	else if ((x&(Printer_flags::out_of_black|Printer_flags::out_of_color))
			!= Printer_flags::none) {
		cout << "out_of_black or out_of_color\n";
	}
}

void g(Printer_flags x)
{
	switch (x) {
		// enumeration value 'none' not handled in switch [-Wswitch]
		// enumeration value 'paper_empty' not handled in switch [-Wswitch]
	case Printer_flags::acknowledge:
		cout << "acknowledge\n";
		break;
	case Printer_flags::busy:
		cout << "busy\n";
		break;
	case Printer_flags::out_of_black:
		cout << "out_of_black\n";
		break;
	case Printer_flags::out_of_color:
		cout << "out_of_color\n";
		break;
	case Printer_flags::out_of_black|Printer_flags::out_of_color:
		// case value '24' not in enumerated type 'Printer_flags' [-Wswitch]
		cout << "out_of_color and out_of_color\n";
		break;
	}
}

enum class Color_code : char;
void foobar(Color_code* p) { }

enum class Color_code : char {
	red, yellow, green, blue
};

enum class Flag : char { x=1, y=2, z=4, e=8 };

Flag f0{ };
//Flag f1 = 5;
	// cannot convert 'int' to 'Flag' in initialization
//Flag f2 = Flag{5};
	// cannot convert 'int' to 'Flag' in initialization
Flag f3 = static_cast<Flag>(5);
Flag f4 = static_cast<Flag>(999);

int main()
{
	cout << "sizeof(Warning2) = " << sizeof(Warning2) << '\n';
	cout << "sizeof(Warning3) = " << sizeof(Warning3) << '\n';

	cout << "static_cast<int>(Warning::green) = " << static_cast<int>(Warning::green) << '\n';
	cout << "static_cast<int>(Warning::yellow) = " << static_cast<int>(Warning::yellow) << '\n';
	cout << "static_cast<int>(Warning::orange) = " << static_cast<int>(Warning::orange) << '\n';
	cout << "static_cast<int>(Warning::red) = " << static_cast<int>(Warning::red) << '\n';

	f(Warning::orange);
	f(Warning::yellow);

	try_to_print(Printer_flags::busy);
	try_to_print(Printer_flags::acknowledge);
	try_to_print(Printer_flags::out_of_color);

	g(Printer_flags::busy);
	g(Printer_flags::out_of_black|Printer_flags::out_of_color);

	cout << "f0 = " << static_cast<int>(f0) << '\n';
	cout << "f3 = " << static_cast<int>(f3) << '\n';
	cout << "f4 = " << static_cast<int>(f4) << '\n';

	int i = static_cast<int>(Flag::y);
	char c = static_cast<char>(Flag::e);

	cout << "i = " << i << '\n';
	cout << "int{c} = " << int{c} << '\n';
}

