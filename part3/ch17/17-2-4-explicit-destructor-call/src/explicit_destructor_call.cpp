/*
 * explicit_destructor_call.cpp
 *
 *  Created on: 2017/03/29
 *      Author: sasaki
 */


#include <string>
#include <iostream>
using namespace std;

struct X { int i; double d; string s; };

class C {
public:
	C() : sz{0} { }
	void push_back(const X& a);
	void pop_back();
	size_t size() const { return sz; }

private:
	static const size_t space = 100;
	X elem[space];
	size_t sz;
};

void C::push_back(const X& a)
{
	X* p = &elem[sz];
	new(p) X{a};
	++sz;
}

void C::pop_back()
{
	--sz;
	X* p = &elem[sz];
	p->~X();
}

int main()
{
	X x {1, 12.3, "abc"};
	C c;

	c.push_back(x);
	cout << "c.size() = " << c.size() << endl;
	c.pop_back();
	cout << "c.size() = " << c.size() << endl;
}
