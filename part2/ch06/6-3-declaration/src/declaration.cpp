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
vector<string> people {name, "Skarphedin", "Gunnar" };

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

// must be defined
double sqrt(double d) { return 0.1; }// dummy
int error_number = 1;
struct User { int id; string name; };


void f()
{
	cout << "-- f() --\n";

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
	cout << "s = " << s << '\n';
	cout << "::count = " << ::count << '\n';
	cout << "pi = " << pi << '\n';
	cout << "error_number = " << error_number << '\n';
	cout << "name = " << name << '\n';

	cout << "season: ";
	for (auto x : season) cout << x << ' ';
	cout << endl;

	cout << "people: ";
	for (auto x : people) cout << x << ' ';
	cout << endl;

	Date date{10, 2, 2017};
	cout << "day(&date) = " << day(&date) << '\n';

	cout << "sqrt(10.0) = " << sqrt(10.0) << '\n';
	cout << "zz = " << zz << '\n';

	Cmplx z {1.1, 2.2};
	cout << "Cmplx z = " << z << '\n';

	cout << "static_cast<int>(Beer::Carlsberg) = " << static_cast<int>(Beer::Carlsberg) << '\n';
	cout << "NS::a = " << NS::a << '\n';

	f();
}
