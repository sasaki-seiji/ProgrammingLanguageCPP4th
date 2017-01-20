/*
 * vulnerable_code.cpp
 *
 *  Created on: 2017/01/20
 *      Author: sasaki
 */


#include <thread>
#include <vector>
#include <iostream>
using namespace std;
using namespace std::chrono;

void f()
{
	cout << "f()\n";
	this_thread::sleep_for(seconds{2});
}

void g()
{
	cout << "g()\n";
	this_thread::sleep_for(seconds{3});
}

struct Foo {
	int x = 12;
};

void run(int i, int n)
try
{
	thread t1 {f};
	thread t2;
	vector<Foo> v;

	if (i<n) {
		thread t3 {g};

		t2 = move(t3);
	}
	v.at(i) = Foo{};

	t1.join();
	t2.join();
}
catch (exception& e)
{
	cerr << "caught exception: " << e.what() << endl;
}

int main()
{
	cout << "run(10,20)\n";
	run(10,20);

	cout << "run(20,10)\n";
	run(20,10);
}
