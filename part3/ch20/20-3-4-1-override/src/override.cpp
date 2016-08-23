/*
 * override.cpp
 *
 *  Created on: 2016/08/23
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

struct B0 {
	void f(int) const;
	virtual void g(double);
};

struct B1 : B0 { };
struct B2 : B1 { };
struct B3 : B2 { };
struct B4 : B3 { };
struct B5 : B4 { };

struct D : B5 {
	//void f(int) const override;
		// error: 'void D::f(int) const' marked 'override', but does not override
	//void g(int) override;
		// error: 'void D::g(int)' marked 'override', but does not override
	//virtual int h() override;
		// error: 'virtual int D::h()' marked 'override', but does not override
};

struct Base {
	virtual void f(int) const;
	virtual void f();
	virtual void g();
};

class Derived : public Base {
public:
	void f(int) const noexcept override;
	//override void f(int) const noexcept;
		// error: 'override' does not name a type
	//void f(int) override const noexcept;
		// error: 'void Derived::f(int)' marked 'override', but does not override

	void f() override;
	void g() override;
};

//void Derived::f() override
	// error: virt-specifiers in 'f' not allowed outside a class definition
void Derived::f()
{
	cout << "Derived::f()\n";
}

// contextual keyword

int override = 7;

struct Base2 {
	virtual int f() { return 0; }
};

struct Dx : Base2 {
	int override;

	int f() override
	{
		return override + ::override;
	}
};

// add undefs

void Derived::g()
{
	cout << "Derived::g()\n";
}

void Derived::f(int) const noexcept
{
	cout << "Derived::f(int) const noexcept\n";
}

// add main

int main()
{
	Derived d;
	Base* bp = &d;

	bp->f(10);
	bp->f();
	bp->g();

	Dx dx;
	dx.override = 13;
	Base2* bp2 = &dx;
	int n = bp2->f();

	cout << "bp->f() returns " << n << '\n';
}
