/*
 * pointer_to_overloaded_function.cpp
 *
 *  Created on: 2016/05/11
 *      Author: sasaki
 */


#include <iostream>
using namespace std;

void f(int);
int f(char);

void (*pf1)(int) = &f;
int (*pf2)(char) = &f;
//void (*pf3)(char) = &f;
	// error: no matches converting function 'f' to type 'void (*)(char)'

void ff(int) noexcept;
void gg(int);

void (*p1)(int) = ff;
void (*p2)(int) noexcept = ff;
void (*p3)(int) noexcept = gg;	// 2017.03.07 エラーとならない

//using Pc = extern "C" void(int);
	// error: expected type-specifier before ‘extern’
using Pn = void(int) noexcept;	//　2017.03.07　エラーとならない

int main()
{
	pf1(12);
	int ret = pf2('x');
	cout << "pf2('x') returns " << ret << '\n';

	p1(123);
	p2(456);
	p3(789);
}

// undefs
void f(int i)
{
	cout << "f(int: " << i << ")\n";
}
int f(char c)
{
	cout << "f(char: " << c << ")\n";
	return int{c};
}
void ff(int i) noexcept
{
	cout << "ff(int: " << i << ")\n";
}
void gg(int i)
{
	cout << "gg(int: " << i << ")\n";
}

