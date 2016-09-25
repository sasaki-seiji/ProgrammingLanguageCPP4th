/*
 * user.cpp
 *
 *  Created on: 2016/09/25
 *      Author: sasaki
 */


#include "Matrix.h"
#include <iostream>
using namespace std;

int main()
{
	Matrix<double, 2> m2{2,3};
	Matrix<double, 3> m3{2,3,4};
	cout << "2 dimension:\n";
	cout << "data(): " << m2.data() << ", size(): " << m2.size() << '\n';
	cout << "3 dimension:\n";
	cout << "data(): " << m3.data() << ", size(): " << m3.size() << '\n';
}
