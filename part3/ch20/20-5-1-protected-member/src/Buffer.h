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
	void set_buf(char* p, int s);
public:
	Buffer(int s=default_size);
	~Buffer() { delete[] buf; }
	int	size() const { return sz; }
private:
	static const int default_size = 16;
	int	sz;
	char* buf;
};

#endif /* BUFFER_H_ */
