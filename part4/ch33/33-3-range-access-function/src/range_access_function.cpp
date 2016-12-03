/*
 * range_access_function.cpp
 *
 *  Created on: 2016/12/04
 *      Author: sasaki
 */

#include <iterator>
#include <vector>
#include <iostream>
using namespace std;


template<typename Cont>
void print(Cont& c)
{
	for (auto p = begin(c); p!=end(c); ++p)
		cout << *p << '\n';
}

void f()
{
	vector<int> v {1,2,3,4,5};
	print(v);

	int a[] {1,2,3,4,5};
	print(a);
}

int main()
{
	f();
}
