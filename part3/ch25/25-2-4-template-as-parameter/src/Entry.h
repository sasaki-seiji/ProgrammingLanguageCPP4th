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
std::ostream& operator<<(std::ostream& os, const Record& e)
{
	return os << "id=" << e.id << ",name=" << e.name
			<< ",phone=" << e.phone << ",addr=" << e.addr;
}



template<typename Rec>
struct Comp_by_id {
	bool operator()(const Rec* p1, const Rec* p2) { return p1->id < p2->id; }
};
template<typename Rec>
struct Comp_by_name {
	bool operator()(const Rec* p1, const Rec* p2)
		{ return p1->name < p2->name; }
};
template<typename Rec>
struct Comp_by_phone {
	bool operator()(const Rec* p1, const Rec* p2)
		{ return p1->phone < p2->phone; }
};
template<typename Rec>
struct Comp_by_addr {
	bool operator()(const Rec* p1, const Rec* p2)
		{ return p1->addr < p2->addr; }
};


#endif /* ENTRY_H_ */
