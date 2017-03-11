/*
 * Locked_file.h
 *
 *  Created on: 2017/03/12
 *      Author: sasaki
 */

#ifndef LOCKED_FILE_H_
#define LOCKED_FILE_H_

#include <mutex>
#include "Fileptr.h"

class Locked_file_handle {
	std::unique_lock<std::mutex> lck;
	File_ptr p;
public:
	Locked_file_handle(const char* file, std::mutex& m)
		: lck{m}, p{file,"rw"}
		{ }
	operator FILE*() { return p.operator FILE*(); }
};



#endif /* LOCKED_FILE_H_ */
