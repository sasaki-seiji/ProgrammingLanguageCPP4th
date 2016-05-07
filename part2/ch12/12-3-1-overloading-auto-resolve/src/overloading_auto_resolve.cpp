/*
 * overloading_auto_resolve.cpp
 *
 *  Created on: 2016/05/08
 *      Author: sasaki
 */


#include <iostream>
using namespace std;

void print(double);
void print(long);

void f()
{
	print(1L);
	print(1.0);
	//print(1);
		// 'print' is ambiguous 'Candidates are: void print(long int) void print(double)'
}

void print(int);
void print(const char*);
void print(double);
void print(long);
void print(char);

void h(char c, int i, short s, float f)
{
	print(c);
	print(i);
	print(s);
	print(f);

	print('a');
	print(49);
	print(0);
	print("a");
	print(nullptr);
}

void print_int(int);
void print_char(char);
void print_string(const char*);

void g(int i, char c, const char* p, double d)
{
	print_int(i);
	print_char(c);
	print_string(p);

	print_int(c);
	print_char(i);
	//print_string(i);
		// invalid conversion from 'int' to 'const char*' [-fpermissive]
	print_int(d);
}

int main()
{
	f();

	char	c = 'z';
	int		i = 12345678;
	short	s = 12345;
	float	f = 1.234f;

	h(c, i, s, f);

	double d = 1.23456789;
	g(i, c, "a string", d);
}

// undefs
void print(double d)
{
	cout << "print(double: " << d << ")\n";
}
void print(long l)
{
	cout << "print(long: " << l << ")\n";
}
void print(int i)
{
	cout << "print(int: " << i << ")\n";
}
void print(const char* p)
{
	if (p)
		cout << "print(const char*: \"" << p << "\")\n";
	else
		cout << "print(const char*: nullptr)\n";
}
void print(char c)
{
	cout << "print(char: '" << c << "')\n";
}

void print_int(int i)
{
	cout << "print_int(int: " << i << ")\n";
}
void print_char(char c)
{
	cout << "print_int(char: '" << c << "')\n";
}
void print_string(const char* p)
{
	cout << "print_string(const char*: \"" << p << "\")\n";
}
