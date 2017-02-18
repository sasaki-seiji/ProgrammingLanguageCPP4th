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

void init_PPN(PPN *pPPN, unsigned PFN, unsigned CCA, bool nonreachable, bool global)
{
	pPPN->PFN = PFN;
	pPPN->CCA = CCA;
	pPPN->nonreachable = nonreachable;
	pPPN->dirty = false;
	pPPN->valid = true;
	pPPN->global = global;
}

void print_PPN(const PPN *pPPN)
{
	cout << "PPN: " << pPPN << endl;
	cout << boolalpha;
	cout << " PFN: " << pPPN->PFN << endl;
	cout << " CCA: " << pPPN->CCA << endl;;
	cout << " nonreachable: " << pPPN->nonreachable << endl;
	cout << " dirty: " << pPPN->dirty << endl;
	cout << " valid: " << pPPN->valid << endl;
	cout << " global: " << pPPN->global << endl;
	cout << endl;
}

int main()
{
	PPN ppn;

	init_PPN(&ppn, 0x00123456, 0x7, false, false);
	print_PPN(&ppn);
	part_of_VM_system(&ppn);

	ppn.dirty = 1;
	print_PPN(&ppn);
	part_of_VM_system(&ppn);
}

