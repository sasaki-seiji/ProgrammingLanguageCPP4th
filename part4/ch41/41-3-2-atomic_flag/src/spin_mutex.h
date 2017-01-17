/*
 * spin_mutex.h
 *
 *  Created on: 2017/01/17
 *      Author: sasaki
 */

#ifndef SPIN_MUTEX_H_
#define SPIN_MUTEX_H_

#include <atomic>
using std::atomic_flag;

class spin_mutex {
	atomic_flag flag = ATOMIC_FLAG_INIT;
public:
	void lock() { while(flag.test_and_set()); }
	void unlock() { flag.clear(); }
};



#endif /* SPIN_MUTEX_H_ */
