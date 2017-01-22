/*
 * my_mutiple_try_lock.h
 *
 *  Created on: 2017/01/22
 *      Author: sasaki
 */

#ifndef MY_MULTIPLE_TRY_LOCK_H_
#define MY_MULTIPLE_TRY_LOCK_H_

inline int my_try_lock()
{
	return -1;
}

template<typename M1, typename... Mx>
int my_try_lock(M1& mtx, Mx&... tail)
{
	if (mtx.try_lock()) {
		int n = my_try_lock(tail...);
		if (n == -1) return -1;
		mtx.unlock();
		return n+1;
	}
	return 0;
}

#if 0	// partially specialized template function
template<typename M1>
int my_try_lock(M1& mtx)
{
	return (mtx.try_lock()) ? -1 : 0;
}
#endif

#endif /* MY_MULTIPLE_TRY_LOCK_H_ */
