/*
 * memory_management.cpp
 *
 *  Created on: 2016/04/29
 *      Author: sasaki
 */

#include <vector>
#include <memory>
#include <iostream>
using namespace std;

void bad()
{
	int* p1 = new int{99};
	int* p2 = p1;
	delete p1;
	p1 = nullptr;
	char* p3 = new char{'x'};
	*p2 = 999;
	cout << *p3 << '\n';
}

void sloppy()
{
	int* p = new int[1000];
	for (int i=0; i != 1000; ++i)
		p[i] = i;
	delete[] p;

	//delete[] p;
		// crash!!!
}

void f(const string& s)
{
	vector<char> v;
	for (auto c : s)
		v.push_back(c);
	cout << "v.size(): " << v.size() << '\n';
}

string reverse(const string& s)
{
	string ss;
	for (int i = s.size()-1; i >= 0; --i)
		ss.push_back(s[i]);
	return ss;
}

void f(int n)
{
	int* p1 = new int[n];
	unique_ptr<int[]> p2 {new int[n]};

	if (n%2) throw runtime_error("odd");
	delete[] p1;
	cout << "p1 is freed and f() is finished\n";
}

int main()
{
	bad();
	sloppy();

	f("this is a string that is copied to vector<char>");

	string str = "this is a string to be reversed";
	cout << "reverse(str): " << reverse(str) << '\n';

	try {
		f(4);
		f(3);
	}
	catch (runtime_error& e) {
		cout << e.what() << '\n';
	}
}

