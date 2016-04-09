/*
 * declaration.cpp
 *
 *  Created on: 2016/04/09
 *      Author: sasaki
 */

#include <string>
#include <vector>
#include <complex>
#include <iostream>
using namespace std;

char ch;
string s;
auto count = 1;
const double pi {3.14159};
extern int error_number;

const char* name ="Njal";
const char* season[] = {"spring", "summer", "fall", "winter" };
vector<string> peole {name, "Skarphedin", "Gunnar" };

struct Date { int d, m, y; };
int day(Date* p) { return p->d; }
double sqrt(double);
template<typename T> T abs(T a) { return a < 0 ? -a : a; }

constexpr int fac(int n) { return (n<2) ? 1 : n * fac(n-1); }

constexpr double zz { 11 * fac(7) };

using Cmplx = std::complex<double>;
struct User;
enum class Beer { Carlsberg, Tuborg, Thor };
namespace NS { int a; }

void f()
{
	int count {1};
	const char* name = {"Bjarne"};
	count = 2;
	name = "Marian";

	cout << "count = " << count << '\n';
	cout << "name = " << name << '\n';
}

int main()
{
	cout << "int{::ch} = " << int{::ch} << '\n';
	cout << "::count = " << ::count << '\n';

	f();
}
