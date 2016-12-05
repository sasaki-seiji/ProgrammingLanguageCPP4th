/*
 * array.cpp
 *
 *  Created on: 2016/12/05
 *      Author: sasaki
 */


#include <array>
#include <algorithm>
#include <iostream>
using namespace std;

template<typename T, size_t N>
ostream& operator<<(ostream& os, array<T,N>& a)
{
	for ( auto& x : a)
		os << x << ',';
	return os;
}

void f()
{
	cout << "-- f() --\n";

	array<int,3> a1 = { 1, 2, 3 };
	cout << "a1: " << a1 << endl;

	array<string, 4> aa = {"Churchil", "Clare"};
	cout << "aa: " << aa << endl;

	//array<int> ax = { 1, 2, 3 };
		// error: wrong number of template arguments (1, should be 2)

	array<int,0> a0;
	cout << "a0: " << a0 << endl;

	array<int,8> a8;
	a8.fill(99);
	cout << "a8: " << a8 << endl;
}

void f(int n)
{
	//array<string,n> aa = {"John's", "Queen' "};
		// error: 'n' is not a constant expression
}

void f(int* p, int sz);

void g()
{
	cout << "-- g() --\n";

	array<int,10> a;

	//f(a, a.size());
		// error: no matching function for call to 'f(std::array<int, 10ull>&, std::array<int, 10ull>::size_type)'
	f(&a[0], a.size());
	f(a.data(), a.size());

	auto p = find(a.begin(), a.end(), 777);
	if (p!=a.end())
		cout << "found: 777\n";
	else
		cout << "not found: 777\n";
}

class Shape {
public:
	virtual void draw() = 0;
	virtual ~Shape() { }
};

class Circle : public Shape {
private:
	int x, y;
	unsigned r;
public:
	Circle(int xx=0, int yy=0, unsigned rr=0) :x{xx}, y{yy}, r{rr} { }
	void draw() { cout << "Circle::draw()\n"; }
};

void h()
{
	cout << "-- h() --\n";

	Circle a1[10];
	array<Circle,10> a2;

	Shape* p1 = a1;
	//Shape* p2 = a2;
		// error: cannot convert 'std::array<Circle, 10ull>' to 'Shape*' in initialization
	p1[3].draw();
	//p1[4].draw(); // crash
}

void tuple_interface()
{
	cout << "-- tuple_interface() --\n";

	array<int,7> a = {1,2,3,5,8,13,25};
	auto x1 = get<5>(a);
	cout << "x1: " << x1 << endl;

	auto x2 = a[5];
	cout << "x2: " << x2 << endl;

	auto sz = tuple_size<decltype(a)>::value;
	cout << "sz: " << sz << endl;

	typename tuple_element<5,decltype(a)>::type x3 = 13;
	cout << "x3: " << x3 << endl;
}

// undefs

void f(int* p, int sz)
{
	cout << "f(int*:" << p << ", int:" << sz << ")\n";
}

// main

int main()
{
	f();
	g();
	h();

	tuple_interface();
}
