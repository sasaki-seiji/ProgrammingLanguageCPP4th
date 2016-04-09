/*
 * string.cpp
 *
 *  Created on: 2016/04/02
 *      Author: sasaki
 */

#include <iostream>
#include <string>
using namespace std;

// + operator: concatination
string compose(const string& name, const string& domain)
{
	return name + '@' + domain;
}

// += operator
void m2(string& s1, string& s2)
{
	s1 = s1 + '\n';
	s2 += '\n';
}

// sub-string operators
string name = "Niels Stroustrup";
void m3()
{
	string s = name.substr(6, 10);
		cout << "name.substr(6, 10) returns: " << s << '\n';
	name.replace(0, 5, "nicholas");
	name[0] = toupper(name[0]);
}

// ==, != operator
string incantation;
void respond(const string& answer)
{
	if (answer == incantation) {
		cout << "answer == incantions" << '\n';
	}
	else if (answer == "yes") {
		cout << "answer == \"yes\"" << '\n';
	}
}

int main()
{
	auto addr = compose("dmr", "bell-labs.com");
	cout << "compose returns: " << addr << '\n';

	string	str1{"string1"}, str2{"string2"};

	m2(str1, str2);
	cout << "str1=" << str1 << ", str2=" << str2 << '\n';

	cout << "befere m3() call, name=" << name << '\n';
	m3();
	cout << "after m3() call, name=" << name << '\n';

	incantation = "incantation";
	respond("incantation");
	respond("yes");
}
