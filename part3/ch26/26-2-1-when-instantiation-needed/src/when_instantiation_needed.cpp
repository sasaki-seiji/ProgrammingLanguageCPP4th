/*
 * when_instantiation_needed.cpp
 *
 *  Created on: 2016/09/23
 *      Author: sasaki
 */

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class X;
X* p;
//X a;
	// error: aggregate 'X a' has incomplete type and cannot be defined

template<typename T>
class Link {
	Link* suc;
};

Link<int>* pl;

Link<int> lnk;

template<typename T>
class List {
	vector<T> arr;
public:
	void sort() { std::sort(arr.begin(), arr.end()); }

	List() { }
	List(initializer_list<T> il) : arr{il} { }
	void print(ostream& os)
	{
		os << "[ ";
		for (auto& x : arr)
			os << x << ' ';
		os << "]\n";
	}
};

class Glob {

};

void f(List<Glob>& lb, List<string>& ls)
{
	ls.sort();

	ls.print(cout);
}

// add main

int main()
{
	List<Glob> lb;
	List<string> ls {"this", "is", "a", "string", "list"};
	f(lb,ls);
}


