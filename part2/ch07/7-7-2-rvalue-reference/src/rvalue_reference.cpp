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
string f() { return ""; }

string& r1 {var};
//string& r2 {f()};
	// invalid initialization of non-const reference of type 'std::__cxx11::string& {aka std::__cxx11::basic_string<char>&}' from an rvalue of type 'std::__cxx11::string {aka std::__cxx11::basic_string<char>}'
//string& r3 {"Princeton"};
	// invalid initialization of non-const reference of type 'std::__cxx11::string& {aka std::__cxx11::basic_string<char>&}' from an rvalue of type 'std::__cxx11::string {aka std::__cxx11::basic_string<char>}'

//string&& rr1 {var};
	// cannot bind 'std::__cxx11::string {aka std::__cxx11::basic_string<char>}' lvalue to 'std::__cxx11::string&& {aka std::__cxx11::basic_string<char>&&}'
string&& rr2 {f()};
string&& rr3 {"Oxford"};

const string& cr1 {"Harvard"};

string f(string&& s)
{
	if (s.size())
		s[0] = toupper(s[0]);
	return s ;
}

template<typename T>
void swap1(T& a, T& b)
{
	T tmp {a};
	a = b;
	b = tmp;
}

template<typename T>
void swap2(T& a, T& b)
{
	T tmp {static_cast<T&&>(a)};
	a = static_cast<T&&>(b);
	b = static_cast<T&&>(tmp);
}

template<typename T>
void swap3(T& a, T& b)
{
	T tmp {move(a)};
	a = move(b);
	b = move(tmp);
}

template<typename T>
void swap3(T&& a, T& b)
{
	T tmp {move(a)};
	a = move(b);
	b = move(tmp);
}

template<typename T>
void swap3(T& a, T&& b)
{
	T tmp {move(a)};
	a = move(b);
	b = move(tmp);
}

void f(vector<int>& v)
{
	swap3(v, vector<int>{1,2,3});
}

void f(string& s, vector<int>& v)
{
	s.shrink_to_fit();
	swap3(s, string{s});
	v.clear();
	swap3(v, vector<int>{});
	v = {};
}

int main()
{
	string val = f("tempolary string");
	cout << "val = " << val << '\n';

	vector<int> v1(1000), v2(10000);

	swap1(v1, v2);
	cout << "v1.size() = " << v1.size() << ", v2.size() = " << v2.size() << '\n';
	swap2(v1, v2);
	cout << "v1.size() = " << v1.size() << ", v2.size() = " << v2.size() << '\n';
	swap3(v1, v2);
	cout << "v1.size() = " << v1.size() << ", v2.size() = " << v2.size() << '\n';

	f(v1);
	cout << "v1.size() = " << v1.size() << " after call f(v1)\n";

	string s;
	vector<int> v;
	for (int i = 0; i < 1000; ++i) {
		s.push_back('a');
		v.push_back(i);
	}
	cout << "s.capacity() = " << s.capacity() << '\n';
	cout << "v.size() = " << v.size() << '\n';

	f(s, v);
	cout << "s.capacity() = " << s.capacity() << '\n';
	cout << "v.size() = " << v.size() << '\n';
}

