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
#include <string.h>
using std::vector;
using std::string;
using std::cout;
using std::swap;

// 2016.09.13 add
template<typename T>
void print(const vector<T>& v)
{
	for (auto& x : v)
		cout << x << ' ';
	cout << '\n';
}

// version 1

template<typename T> void sort(vector<T>&);

void f(vector<int>& vi, vector<string>& vs)
{
	sort(vi);
	print(vi);
	sort(vs);
	print(vs);
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
	print(vi);
	sort2(vs);
	print(vs);
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
	print(vi);
	sort3<int,std::greater<int>>(vi);
	print(vi);

	sort3(vs);
	print(vs);
	sort3<string,No_case>(vs);
	print(vs);
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
	return stricmp(a.c_str(), b.c_str()) < 0;
}

// add main

int main()
{
	cout << "-- f(vi,vs):\n";
	vector<int> vi { 2,3,1,40, 20, 30, 3, 2, 5};
	vector<string> vs { "abc", "ABC", "xyz", "123", "XYZ" };
	f(vi, vs);

	cout << "\n-- f2(vi,vs):\n";
	vi = { 2,3,1,40, 20, 30, 3, 2, 5};
	vs = { "abc", "ABC", "xyz", "123", "XYZ" };
	f2(vi, vs);

	cout << "\n-- f3(vi,vs):\n";
	vi = { 2,3,1,40, 20, 30, 3, 2, 5};
	vs = { "abc", "ABC", "xyz", "123", "XYZ" };
	f3(vi, vs);
}

