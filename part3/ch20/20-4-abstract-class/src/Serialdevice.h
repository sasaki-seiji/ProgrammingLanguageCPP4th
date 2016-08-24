/*
 * Serialdevice.h
 *
 *  Created on: 2016/08/24
 *      Author: sasaki
 */

#ifndef SERIALDEVICE_H_
#define SERIALDEVICE_H_

#include "Characterdevice.h"

class Serial_device : public Character_device {
	int	unit;
public:
	Serial_device(int u);

	int open(int opt) override;
	int close(int opt) override;
	int read(char* p, int n) override;
	int write(const char* p, int n) override;
	int ioctl(int ...) override;

	virtual ~Serial_device();
};

#endif /* SERIALDEVICE_H_ */
