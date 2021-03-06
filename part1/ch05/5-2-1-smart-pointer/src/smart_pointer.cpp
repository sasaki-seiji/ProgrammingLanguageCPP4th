/*
 * smart_pointer.cpp
 *
 *  Created on: 2016/04/03
 *      Author: sasaki
 */

#include <memory>
#include <iostream>
#include <fstream>
using namespace std;

struct X {
	int val;
	X() : val{0} { cout << "X::X()\n"; }
	X(int i) : val{i} { cout << "X::X(" << i << ")\n"; }
	void do_something() { cout << "do_something() called\n"; }

	// 2017.02.05 add
	~X() { cout << "X::~X(" << val << ")\n" ; }
};

class Z { };

void f(int i, int j)
{
	cout << "f(" << i << "," << j << ")\n";

	X* p = new X;
	unique_ptr<X> sp {new X};

	if (i < 99) throw Z{};
	if (j < 77) return;
	p->do_something();
	sp->do_something();

	delete p;
}

unique_ptr<X> make_X(int i)
{
	cout << "make_X(" << i << ")\n";

	return unique_ptr<X>{new X{i}}; // move
}

// 2016.04.03 add exception class and function body of f, g
struct No_file { };
void f(shared_ptr<fstream> fp)
{
	*fp << "f(shared_ptr<fstream> called\n";
}
void g(shared_ptr<fstream> fp)
{
	*fp << "g(shared_ptr<fstream> called\n";
}

void user(const string& name, ios_base::openmode mode)
{
	cout << "user(" << name << "," << mode << ")\n";

	shared_ptr<fstream> fp {new fstream(name, mode)};
	if (!*fp) throw No_file { };

	f(fp); // copy fp
	g(fp); // copy fp
}

int main()
{
	try
	{
		f(100, 100);
		f(100, 0);
		f(0, 100);
	}
	catch (...)
	{
		cout << "error occurs!\n";
	}

	unique_ptr<X> sp = make_X(10);
	sp->do_something();

	user("test.txt", ios_base::out);
}
