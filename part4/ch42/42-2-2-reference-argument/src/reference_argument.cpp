/*
 * reference_argument.cpp
 *
 *  Created on: 2017/01/19
 *      Author: sasaki
 */

#include <thread>
#include <vector>
#include <iostream>
using namespace std;

void my_task(vector<double>& arg);

void test(vector<double>& v)
{
	//thread my_thread1 {my_task, v};
		// error: no type named ‘type’ in ‘class std::result_of<void (*(std::vector<double>))(std::vector<double>&)>’
	thread my_thread2 {my_task, ref(v)};
	thread my_thread3 {[&v]{ my_task(v); }};

	my_thread2.join();
	my_thread3.join();
}

void my_task(vector<double>& arg)
{
	for (auto& x : arg)
		x += 1.0;
}

int main()
{
	vector<double> v {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
	test(v);

	for (auto x : v)
		cout << x << ' ';
}
