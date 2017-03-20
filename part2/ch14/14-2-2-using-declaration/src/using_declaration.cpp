/*
 * using_declaration.cpp
 *
 *  Created on: 2016/05/23
 *      Author: sasaki
 */

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

std::vector<std::string> split(const std::string& s)
{
	std::cout << "-- split(const std::string&) --\n";

	std::vector<std::string> res;
	std::istringstream iss(s);
	for (std::string buf; iss >> buf; )
		res.push_back(buf);
	return res;
}

using std::string;

std::vector<string> split2(const string& s)
{
	std::cout << "-- split2(const string&) --\n";

	std::vector<string> res;
	std::istringstream iss(s);
	for (string buf; iss >> buf; )
		res.push_back(buf);
	return res;
}

namespace N {
	void f(int);
	void f(string);
}

void g()
{
	std::cout << "-- g() --\n";

	using N::f;
	f(789);
	f("Bruce");
}

template<typename T>
std::ostream& operator<<(std::ostream&os, const std::vector<T>& v)
{
	std::cout << "[";
	for (auto& x : v)
		std::cout << x << ",";
	std::cout << "]";
	return os;
}

int main()
{
	std::vector<std::string> v = split("this is a pen");
	std::cout << v << '\n';

	std::vector<string> v2 = split2("this is another pen");
	std::cout << v2 << '\n';

	g();
}

// undefs
void N::f(int i)
{
	std::cout << "N::f(" << i << ")\n";
}
void N::f(string s)
{
	std::cout << "N::f(\"" << s << "\")\n";
}

