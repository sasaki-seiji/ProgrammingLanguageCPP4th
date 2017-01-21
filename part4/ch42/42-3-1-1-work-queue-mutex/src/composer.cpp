/*
 * composer.cpp
 *
 *  Created on: 2017/01/21
 *      Author: sasaki
 */


#include <mutex>
#include <list>
using namespace std;

#include "work_queue.h"

extern mutex wqm;
extern list<Work> wq;

void composer()
{
	list<Work> requests;
	const int max_req = 100;
	int seq = 0;

	while (true) {
		for (int i=0; i!=10; ++i) {
			Work w;
			w.seq = seq;
			w.cmd = Work::add;
			w.a = seq;
			w.b = i*i;
			requests.push_back(w);
			++seq;
		}
		if (wqm.try_lock()) {
			//wq.splice(requests);
			wq.splice(wq.end(), requests);
			wqm.unlock();
		}

		if (seq >= max_req) {
			Work w;
			w.cmd = Work::quit;
			wqm.lock();
			wq.push_back(w);
			wqm.unlock();
			break;
		}
	}
}
