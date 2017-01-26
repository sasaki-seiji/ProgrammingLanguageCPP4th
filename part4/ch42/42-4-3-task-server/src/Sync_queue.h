/*
 * Sync_queue.h
 *
 *  Created on: 2017/01/24
 *      Author: sasaki
 */

#ifndef SYNC_QUEUE_H_
#define SYNC_QUEUE_H_


#include <mutex>
#include <condition_variable>
#include <list>
using std::mutex;
using std::condition_variable;
using std::lock_guard;
using std::unique_lock;
using std::list;
using std::move;


template<typename T>
class Sync_queue {
public:
	void put(const T& val);
	void put(T&& val);
	void get(T& val);
private:
	mutex mtx;
	condition_variable cond;
	list<T> q;
};

template<typename T>
void Sync_queue<T>::put(const T& val)
{
	lock_guard<mutex> lck(mtx);
	q.push_back(val);
	cond.notify_one();
}

template<typename T>
void Sync_queue<T>::put(T&& val)
{
	lock_guard<mutex> lck(mtx);
	q.push_back(move(val));
	cond.notify_one();
}

template<typename T>
void Sync_queue<T>::get(T& val)
{
	unique_lock<mutex> lck(mtx);
	cond.wait(lck, [this]{ return !q.empty(); });
	//val = q.front();
	val = move(q.front());
	q.pop_front();
}

#endif /* SYNC_QUEUE_H_ */
