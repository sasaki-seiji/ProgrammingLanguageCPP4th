/*
 * standard_facet.cpp
 *
 *  Created on: 2017/01/08
 *      Author: sasaki
 */


#include <locale>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	for (auto x : v)
		os << x << ',';
	return os;
}

locale dk {"da_DK"};

void f(vector<string>& v, const locale& loc)
{
	const collate<char>& col {use_facet<collate<char>>(dk)};
	const ctype<char>& ctyp {use_facet<ctype<char>>(dk)};

	locale dk1 {loc, &col};
	locale dk2 {dk1, &ctyp};

	cout << v << endl;
	sort(v.begin(), v.end(), dk2);
	cout << v << endl;
}

int main()
{
	vector<string> v {"abc", "01234", "xyz", "%&#$/?", "XYZ", "ABCD" };
	locale loc;
	f(v,loc);

	locale dk_us(locale::classic(), dk, locale::collate|locale::ctype);
	const ctype<char>& ct = use_facet<ctype<char>>(dk_us);
	cout.imbue(dk_us);
	for (char ch = 0x20; ch < 127; ++ch)
		cout << int(ch) << ": " << ch << ' ' << ct.is(ctype_base::alpha,ch) << endl;
}
