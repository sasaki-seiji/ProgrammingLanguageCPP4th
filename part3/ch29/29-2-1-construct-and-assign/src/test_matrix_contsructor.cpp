/*
 * test_matrix_contructor.cpp
 *
 *  Created on: 2017/06/28
 *      Author: sasaki
 */

#include "Matrix_impl.h"


void construct_from_extents()
{
	cout << "-- construct_from_extents() --\n";

	//Matrix<double,0> m0;
	Matrix<double,1> m1(3);
	Matrix<double,2> m2(3,4);
	Matrix<double,3> m3(3,4,5);

	//cout << "m0.desc: " << m0.descriptor() << endl;
	cout << "m1(3).desc: " << m1.descriptor() << endl;
//	cout << "m1(3): " << m1 << endl;

	cout << "m2(3,4).desc: " << m2.descriptor() << endl;
	cout << "m3(3,4,5).desc: " << m3.descriptor() << endl;
}

void construct_from_matrix_initializer()
{
	cout << "-- construct_from_extents() --\n";

	//Matrix<double,0> m0;
	Matrix<double,1> m1 {1,2,3};
		// error: use of deleted function ‘Matrix<T, N>::Matrix(std::initializer_list<U>) [with U = int; T = double; long unsigned int N = 1ul]’
	Matrix<double,2> m2 {{1,2},{3,4},{5,6}};
	Matrix<double,3> m3 { {{1,2},{2,3}}, {{4,5},{6,7}} };

	//cout << "m0.desc: " << m0.descriptor() << endl;
	cout << "m1(3).desc: " << m1.descriptor() << endl;
	cout << "m2(3,4).desc: " << m2.descriptor() << endl;
	cout << "m3(3,4,5).desc: " << m3.descriptor() << endl;
}
