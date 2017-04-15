/*
 * user.cpp
 *
 *  Created on: 2016/08/18
 *      Author: sasaki
 */


#include "String.h"
#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::flush;
using std::endl;

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
	cout << "-- test_hash() --\n";

	String hs1 = "abcdef", hs2 = "01234";
	int h1 = hash(hs1), h2 = hash(hs2);
	cout << "hash(\"" << hs1 << "\"): " << h1 << '\n';
	cout << "hash(\"" << hs2 << "\"): " << h2 << '\n';

}

void test_print_in_order()
{
	cout << "-- test_print_in_order() --\n";

	String s = "01234";
	vector<int> vi {4,1,2,0};
	print_in_order(s, vi);
}

// 19.3.5: user defined literal _s

void f(const char*);
void f(const String&);

void g()
{
	cout << "-- g() --\n";

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
	cout << "-- test_19_3_6() --\n";

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

void test_begin_end()
{
	cout << "-- test_begin_end() --\n";

	String s{"abcdefg"};
	cout << "initially, s=" << s << endl;

	for (auto& x : s)
		x = toupper(x);

	cout << "after toupper(), s=" << s << endl;
}

String make_string(const char* p)
{
	String s{p};
	return s;
}

void test_move()
{
	cout << "-- test_move() --\n";

	String s = make_string("short string");
	cout << "s=" << s << endl;

	s = make_string("a little bit long string");
	cout << "s=" << s << endl;

	String s1{std::move(s)};
	cout << "String s1{move(s)}; s1:" << s1 << ", s:" << s << endl;
}

void test_assign()
{
	cout << "-- test_assign() --\n";

	String s1;
	String ss{"short string"};
	String sl{"a little bit long string"};

	s1 = ss;
	cout << "s1=ss; s1:" << s1 << endl;
	s1 = sl;
	cout << "s1=sl; s1:" << s1 << endl;
}

int main()
{
	test_hash();
	test_print_in_order();
	g();
	test_begin_end();
	test_move();
	test_assign();

	test_19_3_6();
}
