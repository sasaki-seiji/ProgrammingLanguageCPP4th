/*
 * Entry.h
 *
 *  Created on: 2017/06/04
 *      Author: sasaki
 */

#ifndef ENTRY_H_
#define ENTRY_H_

#include <string>
#include <iostream>

struct Entry {
	int id;
	std::string name;
};
std::ostream& operator<<(std::ostream& os, const Entry& e)
{
	return os << "id=" << e.id << ",name=" << e.name;
}

struct Record {
	int id;
	std::string name;
	int phone;
	std::string addr;
};


template<typename Rec>
struct Comp_by_id {
	bool operator()(const Rec* p1, const Rec* p2) { return p1->id < p2->id; }
};
template<typename Rec>
struct Comp_by_name {
	bool operator()(const Rec* p1, const Rec* p2)
		{ return p1->name < p2->name; }
};




#endif /* ENTRY_H_ */
