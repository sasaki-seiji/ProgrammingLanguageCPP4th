/*
 * container.h
 *
 *  Created on: 2016/03/26
 *      Author: sasaki
 */

#ifndef CONTAINER_H_
#define CONTAINER_H_

class Container {
public:
	virtual double& operator[](int) = 0;
	virtual int size() const = 0;
	virtual ~Container() {}
};

#endif /* CONTAINER_H_ */
