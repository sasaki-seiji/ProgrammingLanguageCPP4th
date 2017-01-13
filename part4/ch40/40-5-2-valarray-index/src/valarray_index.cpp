/*
 * valarray_index.cpp
 *
 *  Created on: 2017/01/13
 *      Author: sasaki
 */

#include <valarray>
#include <iostream>
using namespace std;

ostream& operator<<(ostream& os, const valarray<char> v)
{
	os << "{\"";
	for (auto x : v)
		os << x;
	return os << "\"," << v.size() << "}";
}

void const_valarray_slice()
{
	const valarray<char> v0 {"abcdefghijklmnop",16};
	valarray<char> v1 {v0[slice(2,5,3)]};

	cout << v1 << endl;
}

void nonconst_valarray_slice()
{
	valarray<char> v0 {"abcdefghijklmnop",16};
	valarray<char> v1 {"ABCDE",5};
	v0[slice(2,5,3)] = v1;

	cout << v0 << endl;

}

void const_valarray_gslice()
{
	const valarray<char> v0 {"abcdefghijklmnop",16};
	const valarray<size_t> len {2,3};
	const valarray<size_t> str {7,2};
	valarray<char> v1 {v0[gslice(3,len,str)]};

	cout << v1 << endl;
}

void nonconst_valarray_gslice()
{
	valarray<char> v0 {"abcdefghijklmnop",16};
	//valarray<char> v1 {"ABCDE",5};
	valarray<char> v1 {"ABCDEF",6};
	const valarray<size_t> len {2,3};
	const valarray<size_t> str {7,2};
	v0[gslice(3,len,str)] = v1;

	cout << v0 << endl;
}

void const_valarray_mask()
{
	const valarray<char> v0 {"abcdefghijklmnop",16};
	const bool vb[] {false, false, true, true, false, true};
	valarray<char> v1 {v0[valarray<bool>(vb,6)]};

	cout << v1 << endl;
}

void nonconst_valarray_mask()
{
	valarray<char> v0 {"abcdefghijklmnop",16};
	valarray<char> v1 {"ABC",3};
	const bool vb[] {false, false, true, true, false, true};
	v0[valarray<bool>(vb,6)] = v1;

	cout << v0 << endl;
}

void const_valarray_indirect()
{
	const valarray<char> v0 {"abcdefghijklmnop",16};
	const size_t vi[] {7, 5, 2, 3, 8};
	valarray<char> v1 {v0[valarray<size_t>(vi,5)]};

	cout << v1 << endl;
}

void nonconst_valarray_indirect()
{
	valarray<char> v0 {"abcdefghijklmnop",16};
	valarray<char> v1 {"ABCDE",5};
	const size_t vi[] {7, 5, 2, 3, 8};
	v0[valarray<size_t>(vi,5)] = v1;

	cout << v0 << endl;
}

int main()
{
	const_valarray_slice();
	nonconst_valarray_slice();
	const_valarray_gslice();
	nonconst_valarray_gslice();
	const_valarray_mask();
	nonconst_valarray_mask();
	const_valarray_indirect();
	nonconst_valarray_indirect();
}
