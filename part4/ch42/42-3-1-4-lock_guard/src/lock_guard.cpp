/*
 * lock_guard.cpp
 *
 *  Created on: 2017/01/22
 *      Author: sasaki
 */


#include <thread>
#include <mutex>
#include <vector>
#include <iostream>
using namespace std;

void use(mutex& mtx, vector<string>& vs, int i)
try
{
	mtx.lock();
	if (i<0) return;
	//string s = vs[i];
	string s = vs.at(i);

	cout << "use - vs[i]: " << s << endl;
	mtx.unlock();
}
catch (exception& e)
{
	cerr << "caught exception: " << e.what() << endl;
}

void use2(mutex& mtx, vector<string>& vs, int i)
try
{
	lock_guard<mutex> g {mtx};
	if (i<0) return;
	//string s = vs[i];
	string s = vs.at(i);

	cout << "use - vs[i]: " << s << endl;
}
catch (exception& e)
{
	cerr << "caught exception: " << e.what() << endl;
}

void use3(mutex& mtx, vector<string>& vs, int i)
try
{
	if (i<0) return;
	lock_guard<mutex> g {mtx};
	//string s = vs[i];
	string s = vs.at(i);

	cout << "use - vs[i]: " << s << endl;
}
catch (exception& e)
{
	cerr << "caught exception: " << e.what() << endl;
}

void use4(mutex& mtx, vector<string>& vs, int i)
try
{
	if (i<0) return;
	//string s = vs[i];
	string s;
	{
		lock_guard<mutex> g {mtx};
		s = vs.at(i);
	}

	cout << "use - vs[i]: " << s << endl;
}
catch (exception& e)
{
	cerr << "caught exception: " << e.what() << endl;
}

int main()
{
	thread t;
	mutex mtx;
	vector<string> vs {"this", "is", "a", "vector", "of", "string"};

	// valid usage
	cout << "-- use(): valid usage --\n";
	t = thread(use, ref(mtx), ref(vs), 0);
	t.join();
	if (!mtx.try_lock()) {
		cout << "mutex is locked\n";
	}
	mtx.unlock();

	// range check: i < 0
	cout << "-- use(): range check: i < 0 --\n";
	t = thread(use, ref(mtx), ref(vs), -1);
	t.join();
	if (!mtx.try_lock()) {
		cout << "mutex is locked\n";
	}
	mtx.unlock();

	// range check: i >= vs.size()
	cout << "-- use(): range check: i >= size() --\n";
	t = thread(use, ref(mtx), ref(vs), vs.size());
	t.join();
	if (!mtx.try_lock()) {
		cout << "mutex is locked\n";
	}
	mtx.unlock();

	// valid usage
	cout << "-- use2(): valid usage --\n";
	t = thread(use2, ref(mtx), ref(vs), 0);
	t.join();
	if (!mtx.try_lock()) {
		cout << "mutex is locked\n";
	}
	mtx.unlock();

	// range check: i < 0
	cout << "-- use2(): range check: i < 0 --\n";
	t = thread(use2, ref(mtx), ref(vs), -1);
	t.join();
	if (!mtx.try_lock()) {
		cout << "mutex is locked\n";
	}
	mtx.unlock();

	// range check: i >= vs.size()
	cout << "-- use2(): range check: i >= size() --\n";
	t = thread(use2, ref(mtx), ref(vs), vs.size());
	t.join();
	if (!mtx.try_lock()) {
		cout << "mutex is locked\n";
	}
	mtx.unlock();

	// valid usage
	cout << "-- use3(): valid usage --\n";
	t = thread(use3, ref(mtx), ref(vs), 0);
	t.join();
	if (!mtx.try_lock()) {
		cout << "mutex is locked\n";
	}
	mtx.unlock();

	// range check: i < 0
	cout << "-- use3(): range check: i < 0 --\n";
	t = thread(use3, ref(mtx), ref(vs), -1);
	t.join();
	if (!mtx.try_lock()) {
		cout << "mutex is locked\n";
	}
	mtx.unlock();

	// range check: i >= vs.size()
	cout << "-- use3(): range check: i >= size() --\n";
	t = thread(use3, ref(mtx), ref(vs), vs.size());
	t.join();
	if (!mtx.try_lock()) {
		cout << "mutex is locked\n";
	}
	mtx.unlock();

	// valid usage
	cout << "-- use4(): valid usage --\n";
	t = thread(use4, ref(mtx), ref(vs), 0);
	t.join();
	if (!mtx.try_lock()) {
		cout << "mutex is locked\n";
	}
	mtx.unlock();

	// range check: i < 0
	cout << "-- use4(): range check: i < 0 --\n";
	t = thread(use4, ref(mtx), ref(vs), -1);
	t.join();
	if (!mtx.try_lock()) {
		cout << "mutex is locked\n";
	}
	mtx.unlock();

	// range check: i >= vs.size()
	cout << "-- use4(): range check: i >= size() --\n";
	t = thread(use4, ref(mtx), ref(vs), vs.size());
	t.join();
	if (!mtx.try_lock()) {
		cout << "mutex is locked\n";
	}
	mtx.unlock();
}
