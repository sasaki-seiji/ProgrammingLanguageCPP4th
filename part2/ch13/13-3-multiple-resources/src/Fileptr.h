/*
 * Fileptr.h
 *
 *  Created on: 2016/05/14
 *      Author: sasaki
 */

#ifndef FILEPTR_H_
#define FILEPTR_H_

#include <cstdio>
#include <stdexcept>
#include <string>
using std::runtime_error;
using std::string;

class File_ptr {
	FILE* p;
public:
	File_ptr(const char* n, const char* a)
		: p{fopen(n,a)}
	{
		if (p == nullptr) throw runtime_error{"File_ptr: Can't open file"};
	}

	File_ptr(const string& n, const char* a)
		:File_ptr(n.c_str(), a)
	{ }

	explicit File_ptr(FILE* pp)
		:p{pp}
	{
		if (p == nullptr) throw runtime_error("File_ptr: nullptr");
	}

	// 2017.03.11 add: delete copy
	File_ptr(const File_ptr&) = delete;
	File_ptr& operator=(const File_ptr&) = delete;

	~File_ptr() { fclose(p); }

	operator FILE*() { return p; }
};

#endif /* FILEPTR_H_ */
