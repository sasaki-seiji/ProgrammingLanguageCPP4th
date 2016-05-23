/*
 * using_directive.cpp
 *
 *  Created on: 2016/05/23
 *      Author: sasaki
 */

#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<std::string> split(const string& s)
{
	vector<string> res;
	istringstream iss(s);
	for (string buf; iss >> buf; )
		res.push_back(buf);
	return res;
}

#include <iostream>
template<typename T>
ostream& operator<<(ostream&os, const vector<T>& v)
{
	cout << "[";
	for (auto& x : v)
		cout << x << ",";
	cout << "]";
	return os;
}
int main()
{
	vector<std::string> v = split("this is a pen");
	cout << v << '\n';
}



