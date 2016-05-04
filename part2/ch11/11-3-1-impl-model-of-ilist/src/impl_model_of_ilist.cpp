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
	vector<double> v1 = {1, 2, 3.14};

	//const double temp[] = {double{1}, double{2}, 3.14};
	//const initializer_list<double> tmp(temp, sizeof(temp)/sizeof(double));
		// private constructor!!!
	//vector<double> v2(tmp);

	//cout << "v1 == v2 ? " << (v1 == v2) << '\n';

	initializer_list<int> lst {1,2,3};
	cout << *lst.begin() << '\n';
	//*lst.begin() = 2;
		// assignment of read-only location '* lst.std::initializer_list<_E>::begin<int>()'

	cout << *lst.begin() << '\n';
}

int main()
{
	f();
}
