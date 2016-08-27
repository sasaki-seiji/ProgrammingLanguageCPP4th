/*
 * Stdinterface.h
 *
 *  Created on: 2016/08/27
 *      Author: sasaki
 */

#ifndef STDINTERFACE_H_
#define STDINTERFACE_H_

class Std_interface {
public:
	virtual void start() = 0;
	virtual void suspend() = 0;
	virtual void resume() = 0;
	virtual void quit() = 0;
	virtual void full_size() = 0;
	virtual void small() = 0;

	virtual ~Std_interface() { }
};

using Pstd_mem = void (Std_interface::*)();

#endif /* STDINTERFACE_H_ */
