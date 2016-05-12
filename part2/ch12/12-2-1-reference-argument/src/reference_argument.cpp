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
	int i = 1;
	int j = 1;
	f(i, j);
	cout << "i: " << i << '\n';
	cout << "j: " << j << '\n';
}

float fsqrt(const float& f)
{
	float res = sqrt(f);
	cout << "fsqrt(" << f << ") -> " << res << '\n';
	return res;
}

void g(double d)
{
	float r = fsqrt(2.0f);
	r = fsqrt(r);
	r = fsqrt(d);
}

void update(float& i)
{
	cout << "update(" << i;
	i += 10.0f;
	cout << "->" << i << ")\n";
}

void g(double d, float r)
{
	//update(2.0f);
		// invalid initialization of non-const reference of type 'float&' from an rvalue of type 'float'
	update(r);
	//update(d);
		// invalid initialization of non-const reference of type 'float&' from an rvalue of type 'float'
}

void f(vector<int>&) { cout << "f(vector<int>&)\n"; }
void f(const vector<int>&) { cout << "f(const vector<int>&)\n"; }
void f(vector<int>&&) { cout << "f(vector<int>&&)\n"; }

void g(vector<int>& vi, const vector<int>& cvi)
{
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

