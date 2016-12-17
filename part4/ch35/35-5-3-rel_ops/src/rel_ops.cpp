/*
 * rel_ops.cpp
 *
 *  Created on: 2016/12/17
 *      Author: sasaki
 */


#include <utility>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	for (auto x : v)
		os << x << ", ";
	return os;
}

struct Val {
	bool operator==(Val v) const { return x == v.x; }
	bool operator<(Val v) const { return x < v.x; }

	Val(int v) :x{v} { }
	operator int() { return x; }

private:
	int x;
};

void my_algo(vector<Val>& vv)
{
	using namespace std::rel_ops;

	for (size_t i=0; i<vv.size(); ++i)
		if (Val{0}>vv[i])
			vv[i] = abs(vv[i]);
}

int main()
{
	vector<Val> v {1, -2, 3, -4, 5, -6};
	my_algo(v);

	cout << "v: " << v << endl;
}
