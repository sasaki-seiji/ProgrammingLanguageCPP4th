/*
 * future_extension.h
 *
 *  Created on: 2017/01/26
 *      Author: sasaki
 */

#ifndef FUTURE_EXTENSION_H_
#define FUTURE_EXTENSION_H_

#include <vector>
#include <future>

template<typename T>
std::vector<T> wait_for_all(std::vector<std::future<T>>& vf)
{
	std::vector<T> res;
	for (auto& fu : vf)
		res.push_back(fu.get());
	return res;
}

template<typename T>
int wait_for_any(std::vector<std::future<T>>& vf, std::chrono::steady_clock::duration d)
{
	while(true) {
		for (size_t i=0; i!=vf.size(); ++i) {
			if (!vf[i].valid()) continue;
			switch (vf[i].wait_for(std::chrono::seconds{0})) {
			case std::future_status::ready:
				return i;
			case std::future_status::timeout:
				break;
			case std::future_status::deferred:
				//throw std::runtime_error("wait_for_any(): deffered future");
				return i;
			}
		}
		std::this_thread::sleep_for(d);
	}
}
#endif /* FUTURE_EXTENSION_H_ */
