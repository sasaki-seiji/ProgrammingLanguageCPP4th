/*
 * main.cpp
 *
 *  Created on: 2017/01/28
 *      Author: sasaki
 */


#include <iostream>
#include <chrono>
#include "parallel_find.h"
using namespace std;
using namespace std::chrono;

const int nrecord = 10000000;
vector<Record> goods(nrecord);

void find_first_cheap_red()
{
	cout << "--- find_first_cheap_red() ---\n";

	assert(goods.size()%grain == 0);

	auto t0 = steady_clock::now();
	Record* p = pfind(goods,
			[](Record& r) { return r.price < 200 && r.color == Color::red; });
	auto t1 = steady_clock::now();
	auto d = duration_cast<microseconds>(t1-t0);

	cout << "record " << *p << ", index=" << p-&goods[0] << endl;
	cout << "duration=" << d.count() << " microseconds\n";
}

void find_any_cheap_red()
{
	cout << "--- find_any_cheap_red() ---\n";

	assert(goods.size()%grain == 0);

	auto t0 = steady_clock::now();
	Record* p = pfind_any(goods,
			[](Record& r) { return r.price < 200 && r.color == Color::red; });
	auto t1 = steady_clock::now();
	auto d = duration_cast<microseconds>(t1-t0);

	cout << "record " << *p << ", index=" << p-&goods[0] << endl;
	cout << "duration=" << d.count() << " microseconds\n";
}

void find_all_cheap_red()
{
	cout << "--- find_all_cheap_red() ---\n";

	assert(goods.size()%grain == 0);

	auto t0 = steady_clock::now();
	auto vp = pfind_all(goods,
			[](Record& r) { return r.price < 200 && r.color == Color::red; });
	auto t1 = steady_clock::now();
	auto d = duration_cast<microseconds>(t1-t0);

	for (auto p : vp)
		cout << "record " << *p << ", index=" << p-&goods[0] << endl;

	cout << "duration=" << d.count() << " microseconds\n";
}

void just_find_first_cheap_red()
{
	cout << "--- just_find_first_cheap_red() ---\n";

	auto t0 = steady_clock::now();
	auto p = find_if(goods.begin(), goods.end(),
			[](Record& r) { return r.price < 200 && r.color == Color::red; });
	auto t1 = steady_clock::now();
	auto d = duration_cast<microseconds>(t1-t0);

	if (p!=goods.end())
		cout << "record " << *p << ", index=" << &*p-&goods[0] << endl;

	cout << "duration=" << d.count() << " microseconds\n";
}

void just_find_all_cheap_red()
{
	cout << "--- just_find_all_cheap_red() ---\n";

	auto t0 = steady_clock::now();
	auto vp = find_all_rec(goods, 0, goods.size(),
			[](Record& r) { return r.price < 200 && r.color == Color::red; });
	auto t1 = steady_clock::now();
	auto d = duration_cast<microseconds>(t1-t0);

	for (auto p : vp)
		cout << "record " << *p << ", index=" << p-&goods[0] << endl;

	cout << "duration=" << d.count() << " microseconds\n";
}

void setup_record()
{
	int index  = 9999999;
	int index2 = 8888888;

	for (int i = 0; i < nrecord; ++i) {
		goods[i].price = 500;
		goods[i].color = static_cast<Color>(i%3);
	}

	goods[index].price = 150;
	goods[index].color = Color::red;
	goods[index2].price = 100;
	goods[index2].color = Color::red;
}

int main()
{
	setup_record();
	find_first_cheap_red();
	find_any_cheap_red();
	find_all_cheap_red();
	just_find_first_cheap_red();
	just_find_all_cheap_red();
}
