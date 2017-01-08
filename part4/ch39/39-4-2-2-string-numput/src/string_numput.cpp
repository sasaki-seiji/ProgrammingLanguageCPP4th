/*
 * string_numput.cpp
 *
 *  Created on: 2017/01/03
 *      Author: sasaki
 */

#include <locale>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

template<typename C>
class String_numput : public num_put<C, typename basic_string<C>::iterator> {
public:
	String_numput() : num_put<C, typename basic_string<C>::iterator>{1} { }
};

void f(int i, string& s, int pos)
{
	String_numput<char> f;
	//f.put(s.begin()+pos, cout, ' ', i);
		// error: call of overloaded ‘put(__gnu_cxx::__normal_iterator<char*, std::__cxx11::basic_string<char> >, std::ostream&, char, int&)’ is ambiguous
	f.put(s.begin()+pos, cout, ' ', (long)i);
}

void test(iostream& io, char ch)
{
	locale loc = io.getloc();

	wchar_t wc = use_facet<ctype<wchar_t>>(loc).widen(ch);
	char point = use_facet<numpunct<char>>(loc).decimal_point();
	string false_name = use_facet<numpunct<char>>(loc).falsename();

	cout << "wc: " << wc << endl;
	cout << "point: '" << point << "'\n";
	cout << "false_name: \"" << false_name << "\"\n";
}

int main()
{
	string buf = "abcdefghijklmn";
	f(123456789, buf, 2);
	cout << "default locale: " << buf << endl;

	cout.imbue(locale("en_US.UTF-8"));
	f(123456789, buf, 2);
	cout << "en_US.UTF-8: " << buf << endl;

	cout.imbue(locale("fr_FR.UTF-8"));
	f(123456789, buf, 2);
	cout << "fr_FR.UTF-8: " << buf << endl;

	cout.imbue(locale("da_DK.UTF-8"));
	f(123456789, buf, 2);
	cout << "da_DK.UTF-8: " << buf << endl;

	stringstream ss("this is string test data");
	cout << "-- default locale ---\n";
	test(ss, 'A');

	cout << "-- en_US.UTF-8 ---\n";
	ss.imbue(locale("en_US.UTF-8"));
	test(ss, 'A');

	cout << "-- fr_FR.UTF-8 ---\n";
	ss.imbue(locale("fr_FR.UTF-8"));
	test(ss, 'A');
}
