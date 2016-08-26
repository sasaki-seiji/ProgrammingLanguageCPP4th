/*
 * Buffer.h
 *
 *  Created on: 2016/08/26
 *      Author: sasaki
 */

#ifndef BUFFER_H_
#define BUFFER_H_

class Out_of_range { };

class Buffer {
public:
	char& operator[](int i);
protected:
	char& access(int i) { return buf[i]; }
public:
	Buffer(int s);
	int	size() const { return sz; }
	void set_buf(char* p, int s);
private:
	int	sz;
	char* buf;
};

#endif /* BUFFER_H_ */
