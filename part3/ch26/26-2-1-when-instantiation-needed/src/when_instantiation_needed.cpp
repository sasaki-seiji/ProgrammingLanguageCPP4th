/*
 * when_instantiation_needed.cpp
 *
 *  Created on: 2016/09/23
 *      Author: sasaki
 */

#include "List.h"
#include <string>
#include <iostream>
using namespace std;

class X;
X* p;
//X a;
	// error: aggregate 'X a' has incomplete type and cannot be defined

Link<int>* pl;

Link<int> lnk;

class Glob {
	int v;
public:
	Glob(int i) : v{i} { }
	int value() const { return v; }
};
ostream& operator<<(ostream& os, Glob b)
{
	return os << b.value();
}

void f(List<Glob>& lb, List<string>& ls)
{
	lb.print(cout);
	ls.print(cout);

	ls.sort();
	ls.print(cout);
}

// add main

int main()
{
	List<Glob> lb {1,2,3,4};
	List<string> ls {"this", "is", "a", "string", "list"};
	f(lb,ls);
}


