/*
 * sequence_predicate.cpp
 *
 *  Created on: 2016/11/27
 *      Author: sasaki
 */


#include <algorithm>
#include <vector>
#include <cassert>
#include <iostream>
using namespace std;

vector<double> scale(const vector<double>& val, const vector<double>& div)
{
	assert(val.size()<=div.size());
	assert(all_of(div.begin(),div.end(),[](double x){ return 0<x; }));

	vector<double> res(val.size());
	for (size_t i = 0; i<val.size(); ++i)
		res[i] = val[i]/div[i];
	return res;
}

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	for (auto x : v)
		os << x << ", ";
	return os;
}

int main()
{
	vector<double> val { 1.0, 1.1, 1.2, 1.3, 1.4, 1.5 },
			div { 0.01, 0.1, 1.0, 10, 100, 1000, 10000 };
	cout << "val: " << val << endl;
	cout << "div: " << div << endl;

	vector<double> res = scale(val, div);
	cout << "res: " << res << endl;

}
