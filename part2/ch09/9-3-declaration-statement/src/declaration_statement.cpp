/*
 * declaration_statement.cpp
 *
 *  Created on: 2016/04/23
 *      Author: sasaki
 */

#include <iostream>
#include <vector>
using namespace std;

void error(const char* mes)
{
	cerr << mes << '\n';
	exit(1);
}

void f(vector<string>& v, size_t i ,const char* p)
{
	cout << "-- f(vector<string>&,size_t,const char*) ---\n";

	if (p==nullptr) return;
	if (i<0 || v.size()<=i)
		error("bad index");
	string s = v[i];
	if (s == p) {
		cout << "v[" << i << "] == " << p << "\n";
	}
}

void use()
{
	cout << "-- use() --\n";

	string s1;
	s1 = "The best is the enemy of the good.";

	string s2{"Voltaire"};
}

void input()
{
	cout << "-- input() --\n";

	const int max = 10;
	int buf[max];
	int count = 0;
	for (int i; cin>>i; ) {
		if (i<0) error("unexpected negative value");
		if (count==max) error("buffer overflow");
		buf[count++] = i;
	}

	for (int i=0; i<count; ++i)
		cout << buf[i] << ' ';
	cout << '\n';
}

int main()
{
	vector<string> v = { "this", "is", "a", "string" };
	f(v, 0, "string");
	f(v, 3, "string");
	f(v, 0, nullptr);

	use();

	input();
}

