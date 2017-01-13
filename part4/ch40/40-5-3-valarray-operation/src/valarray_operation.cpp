/*
 * valarray_operation.cpp
 *
 *  Created on: 2017/01/13
 *      Author: sasaki
 */


#include <valarray>
#include <iostream>
using namespace std;

template<typename T>
ostream& operator<<(ostream& os, const valarray<T>& v)
{
	for (auto x : v)
		os << x << ", ";
	return os;
}

void f(valarray<double>& v, valarray<double>& v2, double d)
{
	valarray<double> v3 = v*v2;
	valarray<double> v4 = v*d;
	valarray<double> v5 = d*v2;
	valarray<double> v6 = cos(v);

	cout << "v3: " << v3 << endl;
	cout << "v4: " << v4 << endl;
	cout << "v5: " << v5 << endl;
	cout << "v6: " << v6 << endl;
}

double incr(double d) { return d+1; }

void f(valarray<double>& v)
{
	valarray<double> v2 = v.apply(incr);

	cout << "v2: " << v2 << endl;
}

void f()
{
	int alpha[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	valarray<int> v(alpha,8);
	valarray<int> v2 = v.shift(2);
	valarray<int> v3 = v << 2;
	valarray<int> v4 = v.shift(-2);
	valarray<int> v5 = v >> 2;
	valarray<int> v6 = v.cshift(2);
	valarray<int> v7 = v.cshift(-2);

	cout << "v2: " << v2 << endl;
	cout << "v3: " << v3 << endl;
	cout << "v4: " << v4 << endl;
	cout << "v5: " << v5 << endl;
	cout << "v6: " << v6 << endl;
	cout << "v7: " << v7 << endl;
}

void f(valarray<int> vi, valarray<double> vd)
{
	vi <<= 2;
	//vd <<= 2;
		// error: invalid operands of types ‘double’ and ‘double’ to binary ‘operator<<’

	cout << "vi: " << vi << endl;
}

int main()
{
	valarray<double> v {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
	valarray<double> v2 {1, 2, 3, 4, 5, 6};

	f(v,v2,2.0);
	f(v);
	f();

	valarray<int> vi {1, 2, 3, 4, 5, 6, 7, 8};
	f(vi, v2);
}
