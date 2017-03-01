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
	cout << "-- algo(vector<int>&) --\n";

	sort(v.begin(), v.end());
	cout << v << '\n';
	sort(v.begin(), v.end(), [](int x, int y){ return abs(x)<abs(y); });
	cout << v << '\n';
}

void f(vector<int>& v)
{
	cout << "-- f(vector<int>&) --\n";

	bool sensitive = true;
	sort(v.begin(), v.end(),
			//[](int x, int y){ return sensitive ? x<y : abs(x)<abs(y); });
				// error: 'sensitive' is not captured
			[sensitive](int x, int y){ return sensitive ? x<y : abs(x)<abs(y); });
	cout << v << '\n';

	sensitive = false;
	sort(v.begin(), v.end(),
			//[](int x, int y){ return sensitive ? x<y : abs(x)<abs(y); });
				// error: 'sensitive' is not captured
			[sensitive](int x, int y){ return sensitive ? x<y : abs(x)<abs(y); });
	cout << v << '\n';
}

int h1() { return 0; }
template<typename... Var>
int h1(int s, Var... v)
{
	return s + h1(v...);
}

int h2() { return 1; }
template<typename... Var>
int h2(int s, Var... v)
{
	return s * h2(v...);
}

template<typename... Var>
void algo(int s, Var... v)
{
	cout << "-- algo(int,Var...) --\n";

	auto helper = [&s,&v...] { return s*(h1(v...)+h2(v...)); };

	auto res = helper();
	cout << "res = " << res << endl;
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

	algo(4, 3, 2, 1);
}

