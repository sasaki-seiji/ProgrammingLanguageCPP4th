/*
 * constructor_destructor_assign.cpp
 *
 *  Created on: 2016/11/25
 *      Author: sasaki
 */

#include <vector>
#include <string>
#include <utility>
#include <iostream>
using namespace std;

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	for (auto x : v)
		os << x << ' ';
	return os;
}

void use()
{
	vector<int> vi {1,3,5,6,9};
	cout << "vi: " << vi << endl;

	vector<string> vs(7);
	cout << "vs: " << vs << endl;

	vector<int> vi2;
	vi2 = {2,4,6,8};
	cout << "vi2: " << vi2 << endl;

	vi2.assign(&vi[1],&vi[4]);
	cout << "vi2: " << vi2 << endl;

	vector<string> vs2;
	vs2 = {"The Eagle", "The Bird and Baby"};
	cout << "vs2: " << vs2 << endl;
	//vs2.assign("The Bear", "The Bull an Vet");
		// C:/pleiades-e4.5-cpp-jre_20160312/pleiades/eclipse/mingw/x86_64-w64-mingw32/include/c++/bits/stl_construct.h:75:7: error: no matching function for call to 'std::__cxx11::basic_string<char>::basic_string(const char&)'
    	// 	{ ::new(static_cast<void*>(__p)) _T1(std::forward<_Args>(__args)...); }
}

void task(vector<int>&& v)
{
	cout << "in task() - v: " << v << endl;
}

vector<int> user(vector<int>& large)
{
	vector<int> res;

	task(move(large));

	res = {1,2,3,4,5,6,7,8,9};
	return res;
}

int main()
{
	use();

	vector<int> large, res;
	for (int i=0; i < 500; ++i)
		large.push_back(i);
	res = user(large);
	cout << "res: " << res << endl;
}
