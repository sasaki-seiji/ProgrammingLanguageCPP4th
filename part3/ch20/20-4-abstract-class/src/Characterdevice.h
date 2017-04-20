/*
 * Characterdevice.h
 *
 *  Created on: 2016/08/24
 *      Author: sasaki
 */

#ifndef CHARACTERDEVICE_H_
#define CHARACTERDEVICE_H_

class Character_device {
public:
	virtual int open(int opt) = 0;
	virtual int close(int opt) = 0;
	virtual int read(char* p, int n) = 0;
	virtual int write(const char* p, int n) = 0;
	virtual int ioctl(int ...) = 0;

	virtual ~Character_device() { }
};

#endif /* CHARACTERDEVICE_H_ */
