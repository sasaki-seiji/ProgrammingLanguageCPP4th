/*
 * string_stream.cpp
 *
 *  Created on: 2016/12/24
 *      Author: sasaki
 */


#include <sstream>
#include <iostream>
using namespace std;

void test()
{
	ostringstream oss {"Label: ", ios::ate};
	cout << oss.str() << '\n';
	oss << "val";
	cout << oss.str() << '\n';


	ostringstream oss2 {"Label: "};
	cout << oss2.str() << '\n';
	oss2 << "val";
	cout << oss2.str() << '\n';
}

void test2()
{
	istringstream iss;
	iss.str("Foobar");

	//cout << iss << '\n';
		// error: no match for 'operator<<' (operand types are 'std::ostream {aka std::basic_ostream<char>}' and 'std::istringstream {aka std::__cxx11::basic_istringstream<char>}')
	cout << iss.str() << '\n';
}

int main()
{
	test();
	test2();
}
