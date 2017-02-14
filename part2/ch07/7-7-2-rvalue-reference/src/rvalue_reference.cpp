/*
 * rvalue_reference.cpp
 *
 *  Created on: 2016/04/17
 *      Author: sasaki
 */

#include <iostream>
#include <vector>
using namespace std;

string var {"Cambridge"};
string f() { return "string returned from f()"; }

string& r1 {var};
//string& r2 {f()};
	// error: invalid initialization of non-const reference of type 'std::__cxx11::string& {aka std::__cxx11::basic_string<char>&}' from an rvalue of type 'std::__cxx11::string {aka std::__cxx11::basic_string<char>}'
//string& r3 {"Princeton"};
	// error: invalid initialization of non-const reference of type 'std::__cxx11::string& {aka std::__cxx11::basic_string<char>&}' from an rvalue of type 'std::__cxx11::string {aka std::__cxx11::basic_string<char>}'

string&& rr1 {f()};
//string&& rr2 {var};
	// error: cannot bind 'std::__cxx11::string {aka std::__cxx11::basic_string<char>}' lvalue to 'std::__cxx11::string&& {aka std::__cxx11::basic_string<char>&&}'
string&& rr3 {"Oxford"};

const string& cr1 {"Harvard"};

string f(string&& s)
{
	cout << "-- f(string&& \"" << s << "\") --\n";

	if (s.size())
		s[0] = toupper(s[0]);
	return s ;
}

template<typename T>
void swap1(T& a, T& b)
{
	cout << "-- swap1(T&,T&) --\n";

	T tmp {a};
	a = b;
	b = tmp;
}

template<typename T>
void swap2(T& a, T& b)
{
	cout << "-- swap2(T&,T&) --\n";

	T tmp {static_cast<T&&>(a)};
	a = static_cast<T&&>(b);
	b = static_cast<T&&>(tmp);
}

template<typename T>
void swap3(T& a, T& b)
{
	cout << "-- swap3(T&,T&) --\n";

	T tmp {move(a)};
	a = move(b);
	b = move(tmp);
}

template<typename T>
void swap3(T&& a, T& b)
{
	cout << "-- swap3(T&&,T&) --\n";

	T tmp {move(a)};
	a = move(b);
	b = move(tmp);
}

template<typename T>
void swap3(T& a, T&& b)
{
	cout << "-- swap3(T&,T&&) --\n";

	T tmp {move(a)};
	a = move(b);
	b = move(tmp);
}

void f(vector<int>& v)
{
	cout << "-- f(vector<int>&) --\n";

	swap3(v, vector<int>{1,2,3});
}

void f(string& s1, string& s2, vector<int>& v1, vector<int>& v2, vector<int>& v3)
{
	cout << "-- f(string&, string&, vector<int>&, vector<int>&, vector<int>&) --\n";

	cout << "s1.capacity() = " << s1.capacity() << '\n';
	s1.shrink_to_fit();
	cout << "s1.capacity() = " << s1.capacity() << '\n';

	cout << "s2.capacity() = " << s2.capacity() << '\n';
	swap3(s2, string{s2});
	cout << "s2.capacity() = " << s2.capacity() << '\n';

	cout << "v1.size() = " << v1.size() << '\n';
	v1.clear();
	cout << "v1.size() = " << v1.size() << '\n';

	cout << "v2.size() = " << v2.size() << '\n';
	swap3(v2, vector<int>{});
	cout << "v2.size() = " << v2.size() << '\n';

	cout << "v3.size() = " << v3.size() << '\n';
	v3 = {};
	cout << "v3.size() = " << v3.size() << '\n';
}

int main()
{
	cout << "-- lvalue reference and rvalue reference --\n";
	cout << "::var = " << ::var << '\n';
	cout << "::r1 = " << ::r1 << '\n';
	cout << "::rr1 = " << ::rr1 << '\n';
	cout << "::rr3 = " << ::rr3 << '\n';

	string val = f("tempolary string");
	cout << "val = " << val << '\n';

	vector<int> vec1(1000), vec2(10000);

	swap1(vec1, vec2);
	cout << "vec1.size() = " << vec1.size() << ", vec2.size() = " << vec2.size() << '\n';
	swap2(vec1, vec2);
	cout << "vec1.size() = " << vec1.size() << ", vec2.size() = " << vec2.size() << '\n';
	swap3(vec1, vec2);
	cout << "vec1.size() = " << vec1.size() << ", vec2.size() = " << vec2.size() << '\n';

	f(vec1);
	cout << "vec1.size() = " << vec1.size() << " after call f(vec1)\n";

	string s1, s2;
	vector<int> v1, v2, v3;
	for (int i = 0; i < 1000; ++i) {
		s1.push_back('a');
		s2.push_back('a');
		v1.push_back(i);
		v2.push_back(i);
		v3.push_back(i);
	}
	f(s1, s2, v1, v2, v3);
}

