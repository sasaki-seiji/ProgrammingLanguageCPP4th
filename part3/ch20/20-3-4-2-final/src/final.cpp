/*
 * final.cpp
 *
 *  Created on: 2016/08/23
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

struct Type {
	const char* name;
};

struct Node {
	virtual Type type() = 0;
};

class If_statement : public Node {
public:
	Type type() override final;
};

class Modified_if_statement : public If_statement {
public:
	//Type type() override;
		// error: virtual function 'virtual Type Modified_if_statement::type()'
		// error: overriding final function 'virtual Type If_statement::type()'
};

class For_statement final : public Node {
public:
	Type type() override;
};

#if 0
class Modified_for_statement : public For_statement {
public:
	Type type() override;
};
#endif
// error: cannot derive from 'final' base 'For_statement' in derived type 'Modified_for_statement'


// final is not included in function signature

class Base {
public:
	virtual void f() { }
	virtual void g() { }
};

class Derived : public Base {
public:
	void f() final;
	void g() final;
};

//void Derived::f() final
	// error: virt-specifiers in 'f' not allowed outside a class definition
void Derived::f()
{
	cout << "Derived::f()\n";
}

void Derived::g()
{
	cout << "Derived::g()\n";
}

// contextual keyword

int final = 7;

struct Base2 {
	virtual int f() { return 0; }
};

struct Dx : Base2 {
	int final;

	int f() final
	{
		return final + ::final;
	}
};

// add undef

Type If_statement::type()
{
	return Type{"if_statement"};
}

Type For_statement::type()
{
	return Type{"for_statement"};
}

// add main

int main()
{
	If_statement ifs;
	Node* nodep = &ifs;

	Type type = nodep->type();
	cout << "type.name: " << type.name << '\n';

	For_statement fors;
	nodep = &fors;

	type = nodep->type();
	cout << "type.name: " << type.name << '\n';

	Derived d;
	Base* bp = &d;
	bp->f();
	bp->g();

	Dx dx;
	dx.final = 10;
	Base2* bp2 = &dx;
	int n = bp2->f();
	cout << "bp2->f() returns " << n << '\n';
}
