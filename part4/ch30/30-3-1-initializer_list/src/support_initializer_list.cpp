/*
 * support_initializer_list.cpp
 *
 *  Created on: 2017/07/30
 *      Author: sasaki
 */


#include <initializer_list>
#include <iostream>
using namespace std;

void f(initializer_list<int> lst)
{
	cout << "-- f(initializer_list<int>) --\n";

#if 0
	for(int i=0; i<lst.size(); ++i)
		cout << lst[i] << '\n';
			// error: no match for ‘operator[]’ (operand types are ‘std::initializer_list<int>’ and ‘int’)
#endif
	const int* p = lst.begin();
	for(int i=0; i<lst.size(); ++i)
		cout << p[i] << '\n';
}

void f2(initializer_list<int> lst)
{
	cout << "-- f2(initializer_list<int>) --\n";
	for (auto x : lst)
		cout << x << '\n';
}

int main()
{
	f({1,2,3,4,5,6,7});
	f2({1,2,3,4,5,6,7});
}
