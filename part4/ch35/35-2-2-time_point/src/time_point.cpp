/*
 * time_point.cpp
 *
 *  Created on: 2016/12/13
 *      Author: sasaki
 */


#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

void test()
{
	time_point<steady_clock,milliseconds> tp1(milliseconds(100));
	time_point<steady_clock,microseconds> tp2(microseconds(100*1000));
	//tp1 = tp2;
		// error: no matching function for call to 'std::chrono::duration<long long int, std::ratio<1ll, 1000ll> >::duration(std::chrono::time_point<std::chrono::_V2::steady_clock, std::chrono::duration<long long int, std::ratio<1ll, 1000000ll> > >::duration)'
	tp2 = tp1;
	if (tp1 != tp2) cerr << "Insane!";
}

void test2()
{
	auto tp = steady_clock::now();
	auto d1 = time_point_cast<hours>(tp).time_since_epoch().count()/24;

	using days = duration<long,ratio<24*60*60,1>>;
	auto d2 = time_point_cast<days>(tp).time_since_epoch().count();

	if (d1!=d2) cout << "Impossible!\n";

	cout << "d1==d2: " << d1 << endl;
}
int main()
{
	test();
	test2();
}
