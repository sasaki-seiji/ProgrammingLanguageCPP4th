/*
 * duration.cpp
 *
 *  Created on: 2016/12/13
 *      Author: sasaki
 */


#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

void count()
{
	cout << "--- count() ---\n";

	duration<long long,milli> d1 {7};
	duration<double,pico> d2 {3.33};
	duration<int,ratio<1,1>> d3 { };

	cout << d1.count() << '\n';
	cout << d2.count() << '\n';
	cout << d3.count() << '\n';

	d2 = d1;
	cout << d1.count() << '\n';
	cout << d2.count() << '\n';
}

void narrow_conversion()
{
	cout << "--- narrow_conversion() ---\n";

	duration<int, milli> d {3};
	//duration<int, milli> dd {3.5};
		// no matching function for call to 'std::chrono::duration<int, std::ratio<1ll, 1000ll> >::duration(<brace-enclosed initializer list>)'

	duration<int, milli> ms {3};
	duration<int, micro> us {ms};
	//duration<int, milli> ms2 {us};
		// error: no matching function for call to 'std::chrono::duration<int, std::ratio<1ll, 1000ll> >::duration(<brace-enclosed initializer list>)'
}

void si_unit()
{
	cout << "--- si_unit() ---\n";

	duration<long long,milli> d1 {7};
	//d1 += 5;
		// error: no match for 'operator+=' (operand types are 'std::chrono::duration<long long int, std::ratio<1ll, 1000ll> >' and 'int')

	duration<int,ratio<1,1>> d2 {7};
	//d2 = 5;
		// error: no match for 'operator=' (operand types are 'std::chrono::duration<int, std::ratio<1ll> >' and 'int')
	//d2 += 5;
		// error: no match for 'operator+=' (operand types are 'std::chrono::duration<int, std::ratio<1ll> >' and 'int')

	d1 += duration<long long, milli>{5};
	d2 += decltype(d2){5};

	cout << d1.count() << endl;
	cout << d2.count() << endl;
}

void f(long long x)
{
	volatile long long sum = 0;
	for ( long long i = 0; i < x; ++i )
		sum += i;
}

void cast()
{
	cout << "--- cast() ---\n";

	long long x = 1000000000;
	auto t1 = system_clock::now();
	f(x);
	auto t2 = system_clock::now();

	auto dms = duration_cast<milliseconds>(t2-t1);
	cout << "f(x) took " << dms.count() << " milliseconds\n";

	auto ds = duration_cast<seconds>(t2-t1);
	cout << "f(x) took " << ds.count() << " seconds\n";
}

void construct()
{
	cout << "--- construct() ---\n";

	long long x = 1000000000;
	auto t1 = system_clock::now();
	f(x);
	auto t2 = system_clock::now();

	//cout << "f(x) took " << milliseconds(t2-t1).count() << " milliseconds\n";
		// error: no matching function for call to 'std::chrono::duration<long long int, std::ratio<1ll, 1000ll> >::duration(std::__success_type<std::chrono::duration<long long int, std::ratio<1ll, 1000000000ll> > >::type)'
	cout << "f(x) took " << nanoseconds(t2-t1).count() << " nanoseconds\n";

}
int main()
{
	count();
	narrow_conversion();
	si_unit();
	cast();
	construct();
}
