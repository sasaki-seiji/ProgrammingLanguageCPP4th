/*
 * user.cpp
 *
 *  Created on: 2017/06/17
 *      Author: sasaki
 */

#include "output_iterator.h"
using namespace Estd;

#include <iterator>
#include <forward_list>
#include <list>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	bool b1 = Output_iterator<istream_iterator<char>,char>();
	bool b2 = Output_iterator<ostream_iterator<char>,char>();
	bool b3 = Output_iterator<forward_list<int>::const_iterator,int>();
	bool b4 = Output_iterator<forward_list<int>::iterator,int>();
	bool b5 = Output_iterator<list<int>::const_iterator,int>();
	bool b6 = Output_iterator<list<int>::iterator,int>();
	bool b7 = Output_iterator<vector<int>::const_iterator,int>();
	bool b8 = Output_iterator<vector<int>::iterator,int>();
	bool b9 = Output_iterator<const int*,int>();
	bool b10 = Output_iterator<int*,int>();


	cout << boolalpha;
	cout << "Output_iterator<istream_iterator<char>,char>(): " << b1 << endl;
	cout << "Output_iterator<ostream_iterator<char>,char>(): " << b2 << endl;
	cout << "Output_iterator<forward_list<int>::const_iterator,int>(): " << b3 << endl;
	cout << "Output_iterator<forward_list<int>::iterator,int>(): " << b4 << endl;
	cout << "Output_iterator<list<int>::const_iterator,int>(): " << b5 << endl;
	cout << "Output_iterator<list<int>::iterator,int>(): " << b6 << endl;
	cout << "Output_iterator<vector<int>::const_iterator,int>(): " << b7 << endl;
	cout << "Output_iterator<vector<int>::iterator,int>(): " << b8 << endl;
	cout << "Output_iterator<const int*,int>(): " << b9 << endl;
	cout << "Output_iterator<int*,int>(): " << b10 << endl;

}
