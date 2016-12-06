/*
 * tuple.cpp
 *
 *  Created on: 2016/12/06
 *      Author: sasaki
 */

#include <tuple>
#include <vector>
#include <iostream>
using namespace std;

tuple<string,vector<double>,int> t2 =
	make_tuple("Hello, tuple", vector<double>{1,2,3}, 'x');

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	os << "[ ";
	for (auto& x : v)
		os << x << ' ';
	return os << "]";
}

tuple<int,int,int> rotate(tuple<int,int,int> t)
{
	//return {get<2>(t), get<0>(t), get<1>(t)};
	return tuple<int,int,int>{get<2>(t), get<0>(t), get<1>(t)};
		// error: converting to 'std::tuple<int, int, int>' from initializer list would use explicit constructor 'constexpr std::tuple< <template-parameter-1-1> >::tuple(_UElements&& ...) [with _UElements = {int&, int&, int&}; <template-parameter-2-2> = void; _Elements = {int, int, int}]'
}

pair<int,int> rotate(pair<int,int> p)
{
	return {p.second, p.first};
}

tuple<double,int,string> compute()
{
	return tuple<double,int,string>{1.2345, 6789, "string"};
}

void test_tie()
{
	auto t = make_tuple(2.71828, 299792458, "Hannibal");
	int c;
	string name;
	tie(ignore, c, name) = t;
	cout << "c: " << c << ", name: " << name << endl;

	int c2 = get<1>(t);
	string name2 = get<2>(t);
	cout << "c2: " << c2 << ", name2: " << name2 << endl;

	int c3;
	string name3;
	tie(ignore, c3, name3) = compute();
	cout << "c3: " << c3 << ", name3: " << name3 << endl;
}

int main()
{
	cout << "t2: " << get<0>(t2) << '/' << get<1>(t2) << '/' << get<2>(t2) << endl;

	//auto t3 = rotate({3,7,9});
	auto t3 = rotate(tuple<int,int,int>{3,7,9});
		// error: converting to 'std::tuple<int, int, int>' from initializer list would use explicit constructor 'constexpr std::tuple< <template-parameter-1-1> >::tuple(_UElements&& ...) [with _UElements = {int, int, int}; <template-parameter-2-2> = void; _Elements = {int, int, int}]'
	cout << "t3: " << get<0>(t3) << '/' << get<1>(t3) << '/' << get<2>(t3) << endl;

	auto p2 = rotate({3,7});
	cout << "p2: " << p2.first << '/' << p2.second << endl;

	test_tie();
}
