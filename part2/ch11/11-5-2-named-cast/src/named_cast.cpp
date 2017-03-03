/*
 * named_cast.cpp
 *
 *  Created on: 2016/05/04
 *      Author: sasaki
 */


#include <iostream>
using namespace std;

struct IO_device {
	unsigned short cmd;
	unsigned short stat;
};

IO_device* d1 = reinterpret_cast<IO_device*>(0xff00);

void* my_allocator(size_t);

void f()
{
	cout << "-- f() --\n";

	int* p = static_cast<int*>(my_allocator(100));
	cout << "p = " << p << '\n';
}

void g()
{
	cout << "-- g() --\n";

	char x = 'a';
	//int* p1 = &x;
		// error: cannot convert 'char*' to 'int*' in initialization
	//int* p2 = static_cast<int*>(&x);
		// error: invalid static_cast from type 'char*' to type 'int*'
	int* p3 = reinterpret_cast<int*>(&x);
	cout << "p3 = " << p3 << '\n';
	*p3 = 12345679; // dangerous
}

struct B { };
struct D : B { };

void h()
{
	cout << "-- h() --\n";

	B* pb = new D;
	//D* pd = pb;
		// error: invalid conversion from 'B*' to 'D*' [-fpermissive]
	D* pd2 = static_cast<D*>(pb);
	cout << "pd2 = " << pd2 << '\n';
}

int main()
{
	cout << "d1 = " << d1 << '\n';
	f();
	g();
	h();
}

// undefs
void* my_allocator(size_t sz)
{
	return operator new(sz);
}
