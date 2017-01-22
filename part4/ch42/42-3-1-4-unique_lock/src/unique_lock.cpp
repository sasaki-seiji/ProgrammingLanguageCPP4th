/*
 * unique_lock.cpp
 *
 *  Created on: 2017/01/22
 *      Author: sasaki
 */

#include <thread>
#include <mutex>
#include <iostream>
using namespace std;
using namespace std::chrono;

mutex mtx;
timed_mutex mtx2;

void use()
{
	unique_lock<mutex> lck {mtx,defer_lock};
	unique_lock<timed_mutex> lck2 {mtx2,defer_lock};

	//lck.try_lock_for(milliseconds{2});
		// error: ‘std::unique_lock<std::mutex>::mutex_type {aka class std::mutex}’ has no member named ‘try_lock_for’

	bool b1 = lck2.try_lock_for(milliseconds{2});
	cout << "use(): try_lock_for is " << (b1?"succeded":"failed") << endl;

	try {
		bool b2 = lck2.try_lock_until(steady_clock::now()+milliseconds{2});
		cout << "use(): try_lock_until is " << (b2?"succeded":"failed") << endl;
	}
	catch (system_error& e) {
		cerr << "try_lock_until: " << e.what() << endl;
	}
}

void use2()
{
	unique_lock<timed_mutex> lck2 {mtx2,milliseconds{2}};
	if (lck2.owns_lock()) {
		cout << "use2() owns lock\n";
	}
	else {
		cout << "use2() does not own lock\n";
	}
}

int main()
{
	use();
	use2();
}
