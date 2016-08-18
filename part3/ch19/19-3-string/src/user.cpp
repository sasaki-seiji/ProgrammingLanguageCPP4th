/*
 * user.cpp
 *
 *  Created on: 2016/08/18
 *      Author: sasaki
 */


#include "String.h"
#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::flush;
using std::vector;

// 19.3.2: [] and at() member function
int hash(const String& s)
{
	if (s.size()==0) return 0;
	int h {s[0]};
	for (int i {1}; i<s.size(); ++i)
		h ^= s[i]>>1;
	return h;
}

void print_in_order(const String& s, const vector<int>& index)
{
	for (auto x : index)
		cout << s.at(x) << '\n';
}

void test_hash()
{
	String hs1 = "abcdef", hs2 = "01234";
	int h1 = hash(hs1), h2 = hash(hs2);
	cout << "hash(\"" << hs1 << "\"): " << h1 << '\n';
	cout << "hash(\"" << hs2 << "\"): " << h2 << '\n';

}

void test_print_in_order()
{
	String s = "01234";
	vector<int> vi {4,3,2,1,0};
	print_in_order(s, vi);
}

// 19.3.5: user defined literal _s

void f(const char*);
void f(const String&);

void g()
{
	f("Madden's");
	f("Christopher's"_s);
}

// add undef

void f(const char* p)
{
	cout << "f(const char* : \"" << p << "\")\n";
}

void f(const String& s)
{
	cout << "f(const String& : \"" << s << "\")\n";
}

// 19.3.6 : total test

void test_19_3_6()
{
	cout << "-- total test\n";

	String s ("abcdefghij");
	cout << s << '\n';
	s += 'k';
	s += 'l';
	s += 'm';
	s += 'n';
	cout << s << '\n';

	String s2 = "Hell";
	s2 += " and high water";
	cout << s2 << '\n';

	String s3 = "qwerty";
	s3 = s3;
	String s4 = "the quick brown fox jumped over the lazy dog";
	s4 = s4;
	cout << s3 << " " << s4 << "\n";
	cout << s + ". " + s3 + String(". ") + "Horsefeathers\n";

	cout << flush ;
	String buf;
	while (cin>>buf && buf!="quit")
		cout << buf << " " << buf.size() << " " << buf.capacity() << '\n' << flush;
}

int main()
{
	test_hash();
	test_print_in_order();
	g();
	test_19_3_6();
}
