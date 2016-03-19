/*
 * constant.cpp
 *
 *  Created on: 2016/03/19
 *      Author: sasaki
 */

#include <vector>
#include <iostream>
using namespace std;

constexpr double square(double x) { return x*x; }

int main()
{
	const int dmv = 17;
	int var = 17;
	constexpr double max1 = 1.4*square(dmv);
	//constexpr double max2 = 1.4*square(var);
		//	the value of 'var' is not usable in a constant expression
	const double max3 = 1.4*square(var);
	double sum(const vector<double>&);
	vector<double> v {1.2, 3.4, 4.5};
	const double s1 = sum(v);
	//constexpr double s2 = sum(v);
		// call to non-constexpr function 'double sum(const std::vector<double>&)'

	cout << "dmv = " << dmv << ", var = " << var << ", max1 = " << max1
			<< ", max3 = " << max3 << ", s1 = " << s1 << endl;
}

double sum(const vector<double>& v)
{
	double sum = 0;
	for(auto val : v) {
		sum += val;
	}
	return sum;
}
