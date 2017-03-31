/*
 * using_initializer_list.cpp
 *
 *  Created on: 2016/07/27
 *      Author: sasaki
 */

#include <initializer_list>
#include <iostream>
#include <memory>
using namespace std;


void f(initializer_list<int> args)
{
	cout << "-- f(initializer_list<int>) --\n";

	for (int i = 0; i != args.size(); ++i)
		cout << args.begin()[i] << "\n";
}

void f2(initializer_list<int> args)
{
	cout << "-- f2(initializer_list<int>) --\n";

	for (auto p = args.begin(); p != args.end(); ++p)
		cout << *p << "\n";
}

void f3(initializer_list<int> args)
{
	cout << "-- f3(initializer_list<int>) --\n";

	for (auto x : args)
		cout << x << "\n";
}

int fx(std::initializer_list<int> x, int val)
{
	//*x.begin() = val;
		// error: assignment of read-only location '* x.std::initializer_list<_E>::begin<int>()'
	return *x.begin();
}

void g()
{
	for (int i=0; i!=10; ++i)
		cout << fx({1,2,3}, i) << '\n';
}


template<typename E>
class Vector {
public:
	Vector(initializer_list<E> s);
	~Vector() { a.deallocate(elem, sz); }
	void print(ostream& os);
private:
	allocator<E> a;
	void reserve(int n)
	{ a.deallocate(elem, sz) ; elem = a.allocate(n); }

	int sz;
	E* elem {nullptr};
};

template<typename E>
Vector<E>::Vector(initializer_list<E> s) :sz{s.size()}
{
	reserve(sz);
	uninitialized_copy(s.begin(), s.end(), elem);
}

template<typename E>
void Vector<E>::print(ostream& os)
{
	os << "[";
	for (int i=0; i<sz; ++i)
		os << elem[i] << ',';
	os << "]\n";
}

// add main

int main()
{
	f({1,2,3,4});
	f2({9,8,7});
	f3({11,22,33});
	g();

	cout << "- vector<int> -\n";
	Vector<int> vi = {1,2,3,4};
	vi.print(cout);

	cout << "- vector<string> -\n";
	Vector<string> vs = {"abc", "XYZ", "123"};
	vs.print(cout);
}
