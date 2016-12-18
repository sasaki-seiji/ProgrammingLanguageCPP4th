/*
 * basic_operation.cpp
 *
 *  Created on: 2016/12/18
 *      Author: sasaki
 */


#include <string>
#include <iostream>
using namespace std;

void fill(istream& in, string& s, int max)
{
	s.reserve(max);
	in.read(&s[0],max);
	const int n = in.gcount();
	s.resize(n);	// here, size():0 -> n, so filled with '\0'
	s.shrink_to_fit();
}

int main()
{
	string buf;
	fill(cin, buf, 1000);
	cout << "buf.size(): " << buf.size() << ", buf: " << buf << endl;
}
