/*
 * bit_field.cpp
 *
 *  Created on: 2016/04/21
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

struct PPN {
	unsigned int PFN : 22;
	int : 3;
	unsigned int CCA : 3;
	bool nonreachable : 1;
	bool dirty : 1;
	bool valid : 1;
	bool global : 1;
};

void part_of_VM_system(PPN* p)
{
	if (p->dirty) {
		cout << "copy to disc\n";
		p->dirty = 0;
	}
}

int main()
{
	PPN ppn;

	ppn.dirty = 1;
	part_of_VM_system(&ppn);
}

