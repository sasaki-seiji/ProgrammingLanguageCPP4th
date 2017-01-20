/*
 * guarded_thread.cpp
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

struct guarded_thread : thread {
	using thread::thread;
	~guarded_thread() { if (joinable()) join(); }

	// 2017.01.20 add
	void operator=(thread&& t) { thread::operator=(move(t)); }
};

void run(int i, int n)
try
{
	guarded_thread t1 {f};
	guarded_thread t2;
	vector<Foo> v;

	if (i<n) {
		thread t3 {g};

		t2 = move(t3);
	}
	v.at(i) = Foo{};
}
catch (exception& e)
{
	cerr << "caught exception: " << e.what() << endl;
}
catch (...)
{
	cerr << "caught unknown exception" << endl;
}

int main()
{
	cout << "run(10,20)\n";
	run(10,20);

	cout << "run(20,10)\n";
	run(20,10);
}


