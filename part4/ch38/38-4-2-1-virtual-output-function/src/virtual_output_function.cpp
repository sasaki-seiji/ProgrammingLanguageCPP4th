/*
 * virtual_output_function.cpp
 *
 *  Created on: 2016/12/26
 *      Author: sasaki
 */


#include <iostream>
using namespace std;

class My_base {
public:
	virtual ostream& put(ostream& s) const = 0;
	virtual ~My_base() { }
};

ostream& operator<<(ostream& s, const My_base& r)
{
	return r.put(s);
}

class Sometype : public My_base {
public:
	ostream& put(ostream& s) const override { return s << val << '\n'; }
	Sometype(int i) : val{i} { }

private:
	int val;
};

void f(const My_base& r, Sometype& s)
{
	cout << r << s;
}


int main()
{
	Sometype s1{100}, s2{1000};
	f(s1, s2);
}
