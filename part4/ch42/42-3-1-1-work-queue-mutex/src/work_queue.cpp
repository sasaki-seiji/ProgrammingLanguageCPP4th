/*
 * work_queue.cpp
 *
 *  Created on: 2017/01/21
 *      Author: sasaki
 */

#include <thread>
#include <mutex>
#include <list>
#include <iostream>
using namespace std;
using namespace std::chrono;

#include "work_queue.h"

mutex wqm;
list<Work> wq;

void worker()
{
	for ( ; ; ) {
		Work w;
		wqm.lock();
		if (!wq.empty()) {
			w = wq.front();
			wq.pop_front();
			wqm.unlock();

			if (w.cmd == Work::quit) break;
			else if (w.cmd == Work::add) {
				int sum = w.a + w.b;
				cout << "sum of " << w.a << " and " << w.b << " is " << sum << endl;
			}
		}
		else {
			wqm.unlock();
			this_thread::sleep_for(milliseconds{1});
		}
	}
}

