/*
 * capture.cpp
 *
 *  Created on: 2016/05/02
 *      Author: sasaki
 */

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

ostream& operator<<(ostream& os, const vector<int>& v)
{
	os << "[ ";
	for (auto x : v)
		os << x << ' ';
	os << "]";
	return os;
}

void algo(vector<int>& v)
{
	sort(v.begin(), v.end());
	cout << v << '\n';
	sort(v.begin(), v.end(), [](int x, int y){ return abs(x)<abs(y); });
	cout << v << '\n';
}

void f(vector<int>& v)
{
	bool sensitive = true;

	sort(v.begin(), v.end(),
			//[](int x, int y){ return sensitive ? x<y : abs(x)<abs(y); });
			[sensitive](int x, int y){ return sensitive ? x<y : abs(x)<abs(y); });
				// 'sensitive' is not captured

}

int main()
{
	vector<int> v;
	for (int i = 0; i != 10; ++i) {
		v.push_back(i);
		v.push_back(-i);
	}
	algo(v);
	f(v);
	cout << v << '\n';
}

