/*
 * impl_model_of_ilist.cpp
 *
 *  Created on: 2016/05/01
 *      Author: sasaki
 */

#include <vector>
#include <iostream>
using namespace std;

void f()
{
	cout << "-- f() --\n";

	vector<double> v1 = {1, 2, 3.14};
	cout << "v1: ";
	for (size_t i = 0 ; i!=v1.size(); ++i) cout << v1[i] << ' ';
	cout << endl;

	const double temp[] = {double{1}, double{2}, 3.14};
	//const initializer_list<double> tmp(temp, sizeof(temp)/sizeof(double));
		// private constructor!!!
		// error: ‘constexpr std::initializer_list<_E>::initializer_list(std::initializer_list<_E>::const_iterator, std::initializer_list<_E>::size_type) [with _E = double; std::initializer_list<_E>::const_iterator = const double*; std::initializer_list<_E>::size_type = long unsigned int]’ is private
	//vector<double> v2(tmp);

	//cout << "v1 == v2 ? " << (v1 == v2) << '\n';

	initializer_list<int> lst {1,2,3};
	cout << *lst.begin() << '\n';
	//*lst.begin() = 2;
		// error: assignment of read-only location '* lst.std::initializer_list<_E>::begin<int>()'

	cout << *lst.begin() << '\n';
}

int main()
{
	f();
}
