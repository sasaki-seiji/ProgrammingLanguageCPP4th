/*
 * find_family.cpp
 *
 *  Created on: 2016/12/20
 *      Author: sasaki
 */


#include <string>
#include <iostream>
using namespace std;

void f()
{
	string s {"accdcde"};

	auto i1 = s.find("cd");
	auto i2 = s.rfind("cd");

	cout << "i1: " << i1 << ", s.substr(i1,2): " << s.substr(i1,2) << endl;
	cout << "i2: " << i2 << ", s.substr(i2,2): " << s.substr(i2,2) << endl;
	auto i3 = s.find_first_of("cd");
	auto i4 = s.find_last_of("cd");

	cout << "i3: " << i3 << ", s[i3]: " << s[i3] << endl;
	cout << "i4: " << i4 << ", s[i4]: " << s[i4] << endl;

	auto i5 = s.find_first_not_of("cd");
	auto i6 = s.find_last_not_of("cd");

	cout << "i5: " << i5 << ", s[i5]: " << s[i5] << endl;
	cout << "i6: " << i6 << ", s[i6]: " << s[i6] << endl;
}

int main()
{
	f();
}
