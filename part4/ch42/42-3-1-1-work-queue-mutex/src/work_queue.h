/*
 * work_queue.h
 *
 *  Created on: 2017/01/21
 *      Author: sasaki
 */

#ifndef WORK_QUEUE_H_
#define WORK_QUEUE_H_

#include <mutex>
#include <list>

struct Work{
	int seq;
	enum { add, quit } cmd;
	int a, b;
};

extern std::mutex wqm;
extern std::list<Work> wq;

void worker();


#endif /* WORK_QUEUE_H_ */
