/*
 * reference_argument.cpp
 *
 *  Created on: 2016/05/05
 *      Author: sasaki
 */

#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

void f(int val, int& ref)
{
	++val;
	++ref;
}

void g()
{
	cout << "-- g() --\n";

	int i = 1;
	int j = 1;

	cout << "before f(i,j), i = " << i << ", j = " << j << endl;
	f(i, j);
	cout << "after f(i,j), i = " << i << ", j = " << j << endl;
}

float fsqrt(const float& f)
{
	float res = std::sqrt(f);
	cout << "fsqrt(const float&:" << f << ") -> " << res << '\n';
	return res;
}

void g(double d)
{
	cout << "-- g(double:" << d << ") --\n";

	float r = fsqrt(2.0f);
	r = fsqrt(r);
	r = fsqrt(d);
}

void update(float& i)
{
	cout << "update(float&:" << i << ")\n";

	i += 10.0f;
}

void g(double d, float r)
{
	cout << "-- g(double:" << d << ", float:" << r << ") --\n";

	//update(2.0f);
		// error: invalid initialization of non-const reference of type 'float&' from an rvalue of type 'float'
	update(r);
	//update(d);
		// error: invalid initialization of non-const reference of type 'float&' from an rvalue of type 'float'

	cout << "float r = " << r << endl;
}

void f(vector<int>&) { cout << "f(vector<int>&)\n"; }
void f(const vector<int>&) { cout << "f(const vector<int>&)\n"; }
void f(vector<int>&&) { cout << "f(vector<int>&&)\n"; }

void g(vector<int>& vi, const vector<int>& cvi)
{
	cout << "-- g(vector<int>&, const vector<int>&) --\n";

	f(vi);
	f(cvi);
	f(vector<int>{1,2,3,4});
}

int main()
{
	g();
	g(12.3);
	g(12.3, 12.3f);

	vector<int> vi {1, 10, 100, 1000};
	const vector<int> cvi {100, 10, 1};
	g(vi, cvi);
}

