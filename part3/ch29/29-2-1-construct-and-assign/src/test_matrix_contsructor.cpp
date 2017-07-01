/*
 * test_matrix_contructor.cpp
 *
 *  Created on: 2017/06/28
 *      Author: sasaki
 */

#include "Matrix_impl.h"
#include "Matrix_ref_impl.h"

void construct_from_extents()
{
	cout << "-- construct_from_extents() --\n";

	Matrix<double,0> m0;
	Matrix<double,1> m1(3);
	Matrix<double,2> m2(3,4);
	Matrix<double,3> m3(3,4,5);

	cout << "m0.desc: " << m0.descriptor() << endl;
	cout << "m0: " << m0 << endl;

	cout << "m1(3).desc: " << m1.descriptor() << endl;
	cout << "m1(3): " << m1 << endl;

	cout << "m2(3,4).desc: " << m2.descriptor() << endl;
	cout << "m2(3,4): " << m2 << endl;

	cout << "m3(3,4,5).desc: " << m3.descriptor() << endl;
	cout << "m3(3,4,5): " << m3 << endl;
}

void construct_from_matrix_initializer()
{
	cout << "-- construct_from_matrix_initializer() --\n";

	Matrix<double,0> m0;
	Matrix<double,1> m1 {1,2,3};
	Matrix<double,2> m2 {{1,2},{3,4},{5,6}};
	Matrix<double,3> m3 { {{1,2},{2,3}}, {{4,5},{6,7}} };

	cout << "m0.desc: " << m0.descriptor() << endl;
	cout << "m0: " << m0 << endl;
	cout << "m1.desc: " << m1.descriptor() << endl;
	cout << "m1: " << m1 << endl;
	cout << "m2.desc: " << m2.descriptor() << endl;
	cout << "m2: " << m2 << endl;
	cout << "m3.desc: " << m3.descriptor() << endl;
	cout << "m3: " << m3 << endl;
}

enum class Piece { none, cross, naght };
ostream& operator<<(ostream& os, Piece piece)
{
	switch (piece) {
	case Piece::none: os << "none"; break;
	case Piece::cross: os << "cross"; break;
	case Piece::naght: os << "naght"; break;
	}

	return os;
}

void Matrix_Piece()
{
	cout << "-- Matrix_Piece() --\n";

	Matrix<Piece,2> board1 {
		{Piece::none, Piece::none, Piece::none},
		{Piece::none, Piece::none, Piece::none},
		{Piece::none, Piece::none, Piece::cross}
	};
	Matrix<Piece,2> board2(3,3);
	//Matrix<Piece,2> board3 {3,3};
		//error: use of deleted function ‘Matrix<T, N>::Matrix(std::initializer_list<U>) [with U = int; long unsigned int NN = 2ul; <template-parameter-2-3> = void; T = Piece; long unsigned int N = 2ul]’

	cout << "board1.desc: " << board1.descriptor() << endl;
	cout << "board1: " << board1 << endl;
	cout << "board2.desc: " << board2.descriptor() << endl;
	cout << "board2: " << board2 << endl;
}

void construct_from_matrix_ref()
{
	cout << "-- construct_from_matrix_ref() --\n";

	Matrix<double,1> m1 {1,2,3};
	auto m1r = m1(slice(1));
	Matrix<double,2> m2 {{1,2,3},{4,5,6},{7,8,9}};
	auto m2r = m2(slice(1),slice(0,2));
	Matrix<double,3> m3 { {{1,2},{3,4},{5,6}}, {{7,8},{9,0},{1,2}} };
	auto m3r = m3(slice(0),slice(0,2),slice(0));


	Matrix<double,1> m1c = m1r;
	Matrix<double,2> m2c = m2r;
	Matrix<double,3> m3c = m3r;

	cout << "m1: " << m1 << endl;
	cout << "auto m1r = m1(slice(1)): " << m1r << endl;
	cout << "auto m1c = m1r: " << m1c << endl;
	cout << "m2: " << m2 << endl;
	cout << "auto m1r = m2(slice(1),slice(0,2)): " << m2r << endl;
	cout << "auto m2c = m2r: " << m2c << endl;
	cout << "m3: " << m3 << endl;
	cout << "auto m3r = m3(slice(0),slice(0,2),slice(0)): " << m3r << endl;
	cout << "auto m3c = m3r: " << m3c << endl;
}

void assign_from_matrix_ref()
{
	cout << "-- assign_from_matrix_ref() --\n";

	Matrix<double,1> m1 {1,2,3};
	auto m1r = m1(slice(1));
	Matrix<double,2> m2 {{1,2,3},{4,5,6},{7,8,9}};
	auto m2r = m2(slice(1),slice(0,2));
	Matrix<double,3> m3 { {{1,2},{3,4},{5,6}}, {{7,8},{9,0},{1,2}} };
	auto m3r = m3(slice(0),slice(0,2),slice(0));


	Matrix<double,1> m1a;
	Matrix<double,2> m2a;
	Matrix<double,3> m3a;

	m1a = m1r;
	m2a = m2r;
	m3a = m3r;

	cout << "m1: " << m1 << endl;
	cout << "auto m1r = m1(slice(1)): " << m1r << endl;
	cout << "m1a = m1r: " << m1a << endl;
	cout << "m2: " << m2 << endl;
	cout << "auto m1r = m2(slice(1),slice(0,2)): " << m2r << endl;
	cout << "m2a = m2r: " << m2a << endl;
	cout << "m3: " << m3 << endl;
	cout << "auto m3r = m3(slice(0),slice(0,2),slice(0)): " << m3r << endl;
	cout << "m3a = m3r: " << m3a << endl;
}
