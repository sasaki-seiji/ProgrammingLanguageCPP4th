/*
 * Component.h
 *
 *  Created on: 2016/09/03
 *      Author: sasaki
 */

#ifndef COMPONENT_H_
#define COMPONENT_H_

#include "Storable.h"

class Component : public virtual Storable{
public:
	Component() { virt_func1(); }
	~Component() { virt_func2(); }
	void virt_func1() override { cout << "virt_func1() in Componect\n"; }
	void virt_func2() override { cout << "virt_func2() in Componect\n"; }
};

#endif /* COMPONENT_H_ */
