/*
 * string_comparision..cpp
 *
 *  Created on: 2017/01/04
 *      Author: sasaki
 */


#include <locale>
#include <iostream>
using namespace std;

void f(const string& s1, const string& s2, const string& name)
{
	bool b {s1==s2};
	cout << boolalpha << "b: " << b << endl;

	const char* s1b {s1.data()};
	const char* s1e {s1.data()+s1.size()};
	const char* s2b {s2.data()};
	const char* s2e {s2.data()+s2.size()};

	using Col = collate<char>;

	const Col& global {use_facet<Col>(locale{})};
	int i0 {global.compare(s1b,s1e,s2b,s2e)};
	cout << "i0: " << i0 << endl;

#if 0
	const Col& my_coll {use_facet<Col>(locale{""})};
	int i1 {my_coll.compare(s1b,s1e,s2b,s2e)};
	cout << "i1: " << i1 << endl;

	const Col& n_coll {use_facet<Col>(locale{name})};
	int i2 {n_coll.compare(s1b,s1e,s2b,s2e)};
	cout << "i2: " << i2 << endl;
#endif
}

void f2(const string& s1, const string& s2, const string& name)
{
	bool b0 = locale{}(s1,s2);
	bool b1 = locale{""}(s1,s2);
	bool b2 = locale(name)(s1,s2);

	cout << boolalpha;
	cout << "b0: " << b0 << endl;
	cout << "b1: " << b1 << endl;
	cout << "b2: " << b2 << endl;
}

int main()
{
	string s1 = "abcd";
	string s2 = "XYZ";
	string name = "en_US.UTF-8";

	f(s1, s2, name);
	f2(s1, s2, name);

	return 0;
}
