/*
 * user.cpp
 *
 *  Created on: 2016/08/26
 *      Author: sasaki
 */

#include "List.h"
#include "List2.h"
#include "List3.h"
#include <iostream>
using namespace std;

template<typename T>
void would_be_meddler(List<T>* p)
{
	//typename List<T>::Link* q = nullptr;
		// error: 'struct List<int>::Link' is private

	//q = p->free;
		// error: 'List<int>::Link* List<int>::free' is private

	//if (List<T>::Chunk::chunk_size > 31) { }
		// error: 'struct List<int>::Chunk' is private
}

void use()
{
	cout << "-- use() --\n";

	List<int> ilist;
	ilist.insert(10);
	ilist.insert(20);
	ilist.insert(30);
	cout << ilist.get() << '\n';
	cout << ilist.get() << '\n';
	cout << ilist.get() << '\n';

	List<string> slist;
	slist.insert("string1");
	slist.insert("string2");
	cout << slist.get() << '\n';
	cout << slist.get() << '\n';
}

void use2()
{
	cout << "-- use2() --\n";

	List2<int> ilist;
	ilist.insert(10);
	ilist.insert(20);
	ilist.insert(30);
	cout << ilist.get() << '\n';
	cout << ilist.get() << '\n';
	cout << ilist.get() << '\n';

	List2<string> slist;
	slist.insert("string1");
	slist.insert("string2");
	cout << slist.get() << '\n';
	cout << slist.get() << '\n';
}

void use3()
{
	cout << "-- use3() --\n";

	List3<int> ilist;
	ilist.insert(10);
	ilist.insert(20);
	ilist.insert(30);
	cout << ilist.get() << '\n';
	cout << ilist.get() << '\n';
	cout << ilist.get() << '\n';

	List3<string> slist;
	slist.insert("string1");
	slist.insert("string2");
	cout << slist.get() << '\n';
	cout << slist.get() << '\n';
}


int main()
{
	List<int> ilist;
	would_be_meddler(&ilist);

	use();
	use2();
	use3();
}
