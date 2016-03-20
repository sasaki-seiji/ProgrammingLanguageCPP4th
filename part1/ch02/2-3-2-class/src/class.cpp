/*
 * class.cpp
 *
 *  Created on: 2016/03/20
 *      Author: sasaki
 */


#include <iostream>
using namespace std;

class Vector {
public:
	Vector(int s) :elem{new double[s]}, sz{s} { }
	double& operator[](int i) { return elem[i]; }
	int size() { return sz; }
private:
	int sz;
	double* elem;
};

double read_and_sum(int s)
{
	Vector v(s);
	for(int i = 0 ; i != v.size(); ++i) {
		cin >> v[i];
	}

	double sum = 0;
	for(int i = 0 ; i != v.size(); ++i) {
		sum += v[i];
	}

	return sum;
}

// 2016.03.20 add
int main()
{
	double sum;
	sum = read_and_sum(5);
	cout << "sum is " << sum << endl;
}



