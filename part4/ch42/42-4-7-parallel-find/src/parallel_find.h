/*
 * parallel_find.h
 *
 *  Created on: 2017/01/28
 *      Author: sasaki
 */

#ifndef PARALLEL_FIND_H_
#define PARALLEL_FIND_H_

#include <cassert>
#include <vector>
#include <algorithm>
#include <future>
#include "Record.h"
#include "future_extension.h"
using std::vector;
using std::future;
using std::chrono::microseconds;

template<typename Pred>
Record* find_rec(vector<Record>& vr, int first, int last, Pred pr)
{
	vector<Record>::iterator p = std::find_if(vr.begin()+first, vr.begin()+last, pr);
	if (p == vr.begin()+last)
		return nullptr;
	return &*p;
}

template<typename Pred>
vector<Record*> find_all_rec(vector<Record>& vr, int first, int last, Pred pr)
{
	vector<Record*> res;
	for (int i=first; i!=last; ++i)
		if (pr(vr[i]))
			res.push_back(&vr[i]);
	return res;
}

template<typename Pred>
Record* pfind(vector<Record>& vr, Pred pr)
{
	assert(vr.size() % grain == 0);

	vector<future<Record*>> res;

	for (size_t i = 0; i!=vr.size(); i+=grain)
		res.push_back(async(find_rec<Pred>, ref(vr), i, i+grain, pr));

	for (size_t i = 0; i!=res.size(); ++i)
		if (auto p = res[i].get())
			return p;

	return nullptr;
}

template<typename Pred>
Record* pfind_any(vector<Record>& vr, Pred pr)
{
	vector<future<Record*>> res;

	for (size_t i = 0; i!=vr.size(); i+=grain)
		res.push_back(async(find_rec<Pred>, ref(vr), i, i+grain, pr));

	for (int count = res.size(); count; --count) {
		int i = wait_for_any(res, microseconds{10});
		if (auto p = res[i].get())
			return p;
	}

	return nullptr;
}

template<typename Pred>
vector<Record*> pfind_all(vector<Record>& vr, Pred pr)
{
	vector<future<vector<Record*>>> res;

	for (size_t i = 0; i!=vr.size(); i+=grain)
		res.push_back(async(find_all_rec<Pred>, ref(vr), i, i+grain, pr));

	vector<vector<Record*>> r2 = wait_for_all(res);

	vector<Record*> r;
	for (auto& x : r2)
		for (auto p : x)
			r.push_back(p);
	return r;
}
#endif /* PARALLEL_FIND_H_ */
