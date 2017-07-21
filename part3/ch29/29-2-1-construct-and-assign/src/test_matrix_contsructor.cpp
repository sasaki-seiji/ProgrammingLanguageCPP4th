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

	cout << "Matrix<double,0> m0;\n";
	cout << "  m0.desc: " << m0.descriptor() << endl;
	cout << "  m0: " << m0 << endl;

	cout << "Matrix<double,1> m1(3);\n";
	cout << "  m1.desc: " << m1.descriptor() << endl;
	cout << "  m1: " << m1 << endl;

	cout << "Matrix<double,2> m2(3,4);\n";
	cout << "  m2.desc: " << m2.descriptor() << endl;
	cout << "  m2: " << m2 << endl;

	cout << "Matrix<double,3> m3(3,4,5);\n";
	cout << "  m3.desc: " << m3.descriptor() << endl;
	cout << "  m3: " << m3 << endl;
}

void construct_from_matrix_initializer()
{
	cout << "-- construct_from_matrix_initializer() --\n";

	Matrix<double,0> m0 {1};
	Matrix<double,1> m1 {1,2,3};
	Matrix<double,2> m2 {{1,2},{3,4},{5,6}};
	Matrix<double,3> m3 { {{1,2},{2,3}}, {{4,5},{6,7}} };

	cout << "Matrix<double,0> m0 {1};\n";
	cout << "  m0.desc: " << m0.descriptor() << endl;
	cout << "  m0: " << m0 << endl;

	cout << "Matrix<double,1> m1 {1,2,3};\n";
	cout << "  m1.desc: " << m1.descriptor() << endl;
	cout << "  m1: " << m1 << endl;

	cout << "Matrix<double,2> m2 {{1,2},{3,4},{5,6}};\n";
	cout << "  m2.desc: " << m2.descriptor() << endl;
	cout << "  m2: " << m2 << endl;

	cout << "Matrix<double,3> m3 { {{1,2},{2,3}}, {{4,5},{6,7}} };\n";
	cout << "  m3.desc: " << m3.descriptor() << endl;
	cout << "  m3: " << m3 << endl;
}

void copy_constructor()
{
	cout << "-- copy_constructor() --\n";

	Matrix<double,0> m0 {1};
	Matrix<double,1> m1 {1,2,3};
	Matrix<double,2> m2 {{1,2},{3,4},{5,6}};
	Matrix<double,3> m3 { {{1,2},{2,3}}, {{4,5},{6,7}} };

	Matrix<double,0> m0_1 {m0};
	Matrix<double,0> m0_2 (m0);
	Matrix<double,0> m0_3 = m0;

	Matrix<double,1> m1_1 {m1};
	Matrix<double,1> m1_2 (m1);
	Matrix<double,1> m1_3 = m1;

	Matrix<double,2> m2_1 {m2};
	Matrix<double,2> m2_2 (m2);
	Matrix<double,2> m2_3 = m2;

	Matrix<double,3> m3_1 {m3};
	Matrix<double,3> m3_2 (m3);
	Matrix<double,3> m3_3 = m3;

	cout << "Matrix<double,0> m0 {1};\n";
	cout << "Matrix<double,0> m0_1 {m0};\n";
	cout << "Matrix<double,0> m0_2 (m0);\n";
	cout << "Matrix<double,0> m0_3 = m0;\n";
	cout << "  m0: " << m0 << endl;
	cout << "  m0_1: " << m0_1 << endl;
	cout << "  m0_2: " << m0_2 << endl;
	cout << "  m0_3: " << m0_3 << endl;

	cout << "Matrix<double,1> m1 {1,2,3};\n";
	cout << "Matrix<double,1> m1_1 {m1};\n";
	cout << "Matrix<double,1> m1_2 (m1);\n";
	cout << "Matrix<double,1> m1_3 = m1;\n";
	cout << "  m1: " << m1 << endl;
	cout << "  m1_1: " << m1_1 << endl;
	cout << "  m1_2: " << m1_2 << endl;
	cout << "  m1_3: " << m1_3 << endl;

	cout << "Matrix<double,2> m2 {{1,2},{3,4},{5,6}};\n";
	cout << "Matrix<double,2> m2_1 {m2};\n";
	cout << "Matrix<double,2> m2_2 (m2);\n";
	cout << "Matrix<double,2> m2_3 = m2;\n";
	cout << "  m2: " << m2 << endl;
	cout << "  m2_1: " << m2_1 << endl;
	cout << "  m2_2: " << m2_2 << endl;
	cout << "  m2_3: " << m2_3 << endl;

	cout << "Matrix<double,3> m3 { {{1,2},{2,3}}, {{4,5},{6,7}} };\n";
	cout << "Matrix<double,3> m3_1 {m3};\n";
	cout << "Matrix<double,3> m3_2 (m3);\n";
	cout << "Matrix<double,3> m3_3 = m3;\n";
	cout << "  m3: " << m3 << endl;
	cout << "  m3_1: " << m3_1 << endl;
	cout << "  m3_2: " << m3_2 << endl;
	cout << "  m3_3: " << m3_3 << endl;
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

	cout << "Matrix<Piece,2> board1 {...};\n";
	cout << "  board1.desc: " << board1.descriptor() << endl;
	cout << "  board1: " << board1 << endl;

	cout << "Matrix<Piece,2> board2(3,3);\n";
	cout << "  board2.desc: " << board2.descriptor() << endl;
	cout << "  board2: " << board2 << endl;
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

	cout << "Matrix<double,1> m1 {1,2,3};\n";
	cout << "  m1: " << m1 << endl;
	cout << "  auto m1r = m1(slice(1)); " << m1r << endl;
	cout << "  Matrix<double,1> m1c = m1r; " << m1c << endl;

	cout << "Matrix<double,2> m2 {{1,2,3},{4,5,6},{7,8,9}};\n";
	cout << "  m2: " << m2 << endl;
	cout << "  auto m2r = m2(slice(1),slice(0,2)); " << m2r << endl;
	cout << "  Matrix<double,2> m2c = m2r; " << m2c << endl;

	cout << "Matrix<double,3> m3 { {{1,2},{3,4},{5,6}}, {{7,8},{9,0},{1,2}} };\n";
	cout << "  m3: " << m3 << endl;
	cout << "  auto m3r = m3(slice(0),slice(0,2),slice(0)); " << m3r << endl;
	cout << "  Matrix<double,3> m3c = m3r; " << m3c << endl;
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

	cout << "Matrix<double,1> m1 {1,2,3};\n";
	cout << "Matrix<double,1> m1a;\n";
	cout << "  m1: " << m1 << endl;
	cout << "  auto m1r = m1(slice(1)); " << m1r << endl;
	cout << "  m1a = m1r; " << m1a << endl;

	cout << "Matrix<double,2> m2 {{1,2,3},{4,5,6},{7,8,9}};\n";
	cout << "Matrix<double,2> m2a;\n";
	cout << "  m2: " << m2 << endl;
	cout << "  auto m1r = m2(slice(1),slice(0,2)); " << m2r << endl;
	cout << "  m2a = m2r; " << m2a << endl;

	cout << "Matrix<double,3> m3 { {{1,2},{3,4},{5,6}}, {{7,8},{9,0},{1,2}} };\n";
	cout << "Matrix<double,3> m3a;\n";
	cout << "  m3: " << m3 << endl;
	cout << "  auto m3r = m3(slice(0),slice(0,2),slice(0)); " << m3r << endl;
	cout << "  m3a = m3r; " << m3a << endl;
}

void construct_from_other_type_matrix()
{
	cout << "-- construct_from_other_type_matrix() --\n";

	Matrix<int,1> mi1 {1,2,3};
	Matrix<double,1> md1 {mi1};
	Matrix<int,2> mi2 {{1,2,3},{4,5,6},{7,8,9}};
	Matrix<double,2> md2 {mi2};
	Matrix<int,3> mi3 { {{1,2},{3,4},{5,6}}, {{7,8},{9,0},{1,2}} };
	Matrix<double,3> md3 {mi3};

	cout << "Matrix<int,1> mi1: " << mi1 << endl;
	cout << "Matrix<double,1> md1 {mi1}: " << md1 << endl;
	cout << "Matrix<int,2> mi2 {{1,2,3},{4,5,6},{7,8,9}}: " << mi2 << endl;
	cout << "Matrix<double,2> md2 {mi2}: " << md2 << endl;
	cout << "Matrix<int,3> mi3 { {{1,2},{3,4},{5,6}}, {{7,8},{9,0},{1,2}} }: " << mi3 << endl;
	cout << "Matrix<double,3> md3 {mi3}: " << md3 << endl;
}

void assign_from_other_type_matrix()
{
	cout << "-- assign_from_other_type_matrix() --\n";

	Matrix<int,1> mi1 {1,2,3};
	Matrix<double,1> md1;
	Matrix<int,2> mi2 {{1,2,3},{4,5,6},{7,8,9}};
	Matrix<double,2> md2;
	Matrix<int,3> mi3 { {{1,2},{3,4},{5,6}}, {{7,8},{9,0},{1,2}} };
	Matrix<double,3> md3;

	cout << "Matrix<int,1> mi1: " << mi1 << endl;
	cout << "Matrix<double,1> md1: " << md1 << endl;
	cout << "Matrix<int,2> mi2 {{1,2,3},{4,5,6},{7,8,9}}: " << mi2 << endl;
	cout << "Matrix<double,2> md2: " << md2 << endl;
	cout << "Matrix<int,3> mi3 { {{1,2},{3,4},{5,6}}, {{7,8},{9,0},{1,2}} }: " << mi3 << endl;
	cout << "Matrix<double,3> md3: " << md3 << endl;

	md1 = mi1;
	md2 = mi2;
	md3 = mi3;

	cout << "md1 = mi1; " << md1 << endl;
	cout << "md2 = mi2; " << md2 << endl;
	cout << "md3 = mi3; " << md3 << endl;

}

void test_matrix_constructor_all()
{
	cout << "@@ 29.2.1 construct_and_assign @@\n";

	construct_from_extents();
	construct_from_matrix_initializer();
	copy_constructor();
	Matrix_Piece();
	construct_from_matrix_ref();
	assign_from_matrix_ref();
	construct_from_other_type_matrix();
	assign_from_other_type_matrix();
}
