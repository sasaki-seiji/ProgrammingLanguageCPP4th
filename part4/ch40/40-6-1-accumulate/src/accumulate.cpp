/*
 * accumulate.cpp
 *
 *  Created on: 2017/01/14
 *      Author: sasaki
 */


#include <numeric>
#include <vector>
#include <list>
#include <iostream>
using namespace std;

void f(vector<int>& price ,list<float>& incr)
{
	int i = accumulate(price.begin(), price.end(), 0);
	double d = 0;
	d = accumulate(incr.begin(), incr.end(), d);
	int prod = accumulate(price.begin(), price.end(), 1,
			[](int a, int b){ return a*b; });

	cout << "sum of price: " << i << endl;
	cout << "sum of incr: " << d << endl;
	cout << "product of price: " << prod << endl;
}

struct Record {
	int unit_price;
	int number_of_units;
};

long price(long val, const Record& r)
{
	return val + r.unit_price * r.number_of_units;
}

void f(const vector<Record>& v)
{
	cout << "Total values: " << accumulate(v.begin(), v.end(), 0, price) << '\n';
}

int main()
{
	vector<int> price { 10, 25, 30, 50, 80, 30 };
	list<float> incr { 1.1, 2.2, 3.3, 4.4 };
	f(price, incr);

	vector<Record> rec { {10, 1}, {20, 2}, {15, 1}, {30, 3} };
	f(rec);
}
