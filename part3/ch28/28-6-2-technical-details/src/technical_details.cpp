/*
 * technical_details.cpp
 *
 *  Created on: 2016/10/16
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

template<typename... Types>
void f(Types... args);


void print_args()
{
}

template<typename T, typename... Args>
void print_args(T t, Args... args)
{
	cout << t;
	if (sizeof...(args) > 0) cout << ',';
	print_args(args...);
}

template<typename... Args>
void f(Args... args)
{
	cout << "f(";
	print_args(args...);
	cout << ")\n";
}

template<typename... Bases>
class X : public Bases... {
public:
	X(const Bases&... b) : Bases(b)... { }
};

struct Bx {
	int x;
	Bx(int i) : x(i) { }
};

struct By {
	int y;
	By(int i) : y(i) { }
};

struct Bz {
	int z;
	Bz(int i) : z(i) { }
};

X<> x0;
X<Bx> x1(1);
X<Bx,By> x2(2,3);
X<Bx,By,Bz> x3(2,3,4);

int main()
{
	f();
	f(1);
	f(2, 1.0);
	f(2, 1.0, "Hello");

	cout << x1.x << '\n';
	cout << x2.x << ',' << x2.y << '\n';
	cout << x3.x << ',' << x3.y << ',' << x3.z << '\n';
}

