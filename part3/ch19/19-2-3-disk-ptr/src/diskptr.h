/*
 * diskptr.h
 *
 *  Created on: 2016/08/11
 *      Author: sasaki
 */

#ifndef DISKPTR_H_
#define DISKPTR_H_

#include <string>
#include <fstream>
using std::string;
using std::ifstream;
using std::ofstream;

template<typename T>
class Disk_ptr {
	string identifier;
	T* in_core_address;
public:
	Disk_ptr(const string& s) : identifier{s}, in_core_address{nullptr} { }
	~Disk_ptr() { write_to_disk(in_core_address, identifier); }

	T* operator->()
	{
		if (in_core_address == nullptr)
			in_core_address = read_from_disk(identifier);
		return in_core_address;
	}

private:
	void write_to_disk(T*, const string&);
	T* read_from_disk(const string&);
};

template<typename T>
void Disk_ptr<T>::write_to_disk(T* p, const string& s)
{
	ofstream ofs{s};
	if (ofs)
		ofs << *p;
}

template<typename T>
T* Disk_ptr<T>::read_from_disk(const string& s)
{
	T *p = new T;
	ifstream ifs{s};
	if (ifs)
		ifs >> *p;
	return p;
}

#endif /* DISKPTR_H_ */
