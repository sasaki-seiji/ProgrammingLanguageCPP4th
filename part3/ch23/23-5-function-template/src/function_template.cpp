/*
 * function_template.cpp
 *
 *  Created on: 2016/09/13
 *      Author: sasaki
 */

#include <vector>
#include <string>
#include <iostream>
#include <utility>
#include <functional>
#include <cstring>
#include <strings.h> // for linux
using namespace std;

// 2017.05.13 change
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	for (auto& x : v)
		cout << x << ' ';
	return os;
}

// version 1

template<typename T> void sort(vector<T>&);

void f(vector<int>& vi, vector<string>& vs)
{
	sort(vi);
	cout << "vi: " << vi << endl;
	sort(vs);
	cout << "vs: " << vs << endl;
}

template<typename T>
void sort(vector<T>& v)
{
	const size_t n = v.size();
	for (int gap=n/2; 0<gap; gap/=2)
		for (int i=gap; i<n; i++)
			for (int j=i-gap; 0<=j; j-=gap)
				if (v[j+gap]<v[j]){
					T temp = v[j];
					v[j] = v[j+gap];
					v[j+gap] = temp;
				}
}

// version 2

template<typename T> void sort2(vector<T>&);

void f2(vector<int>& vi, vector<string>& vs)
{
	sort2(vi);
	cout << "vi: " << vi << endl;
	sort2(vs);
	cout << "vs: " << vs << endl;
}

template<typename T>
void sort2(vector<T>& v)
{
	const size_t n = v.size();
	for (int gap=n/2; 0<gap; gap/=2)
		for (int i=gap; i<n; i++)
			for (int j=i-gap; 0<=j; j-=gap)
				if (v[j+gap]<v[j])
					swap(v[j],v[j+gap]);
}

// version 3

template<typename T, typename Compare=std::less<T>>
void sort3(vector<T>&);

struct No_case {
	bool operator()(const string& a, const string& b) const;
};

void f3(vector<int>& vi, vector<string>& vs)
{
	sort3(vi);
	cout << "vi: " << vi << endl;
	sort3<int,greater<int>>(vi);
	cout << "sort<int,greater<int>> vi: " << vi << endl;

	sort3(vs);
	cout << "vs: " << vs << endl;
	sort3<string,No_case>(vs);
	cout << "sort<string,No_case> vs: " << vs << endl;
}

template<typename T, typename Compare>
void sort3(vector<T>& v)
{
	Compare cmp;
	const size_t n = v.size();

	for (int gap=n/2; 0<gap; gap/=2)
		for (int i=gap; i<n; i++)
			for (int j=i-gap; 0<=j; j-=gap)
				if (cmp(v[j+gap],v[j]))
					swap(v[j],v[j+gap]);
}

bool No_case::operator()(const string& a, const string& b) const
{
	//return stricmp(a.c_str(), b.c_str()) < 0;		// for Windows
	return strcasecmp(a.c_str(), b.c_str()) < 0;	// for Linux
}

// add main

int main()
{
	vector<int> vi { 2, 3, 1, 40, 20, 30, 3, 2, 5};
	vector<string> vs { "abc", "ABC", "xyz", "123", "XYZ" };

	cout << "-- f(vi,vs):\n";
	f(vi, vs);

	cout << "\n-- f2(vi,vs):\n";
	f2(vi, vs);

	cout << "\n-- f3(vi,vs):\n";
	f3(vi, vs);
}

