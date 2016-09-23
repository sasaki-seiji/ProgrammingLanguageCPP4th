/*
 * explicit_instantiation.cpp
 *
 *  Created on: 2016/09/24
 *      Author: sasaki
 */

#include <vector>
#include <iostream>
using namespace std;

template class vector<int>;
//template int& vector<int>::operator[](int);
//template int& vector<int>::operator[](size_t);
	// error: duplicate explicit instantiation of 'std::vector<_Tp, _Alloc>::reference std::vector<_Tp, _Alloc>::operator[](std::vector<_Tp, _Alloc>::size_type) [with _Tp = int; _Alloc = std::allocator<int>; std::vector<_Tp, _Alloc>::reference = int&; std::vector<_Tp, _Alloc>::size_type = long long unsigned int]' [-fpermissive]
template char& vector<char>::operator[](size_t);

template<typename T, typename S>
T convert(S s)
{
	return static_cast<T>(s);
}
//template int convert<int,double>(double);
template int convert<int>(double);

// add main

int main()
{
	vector<int> vi{1,2,3,4,5};

	for (auto x : vi)
		cout << x << ' ';
	cout << '\n';

	vector<char> vc{'A', 'B', 'C', 'D'};
	for (size_t i = 0; i!=vc.size(); ++i)
		cout << vc[i] << ' ';
	cout << '\n';

	double	d = 12.3;
	int i = convert<int>(d);
	cout << "i: " << i << '\n';
}

