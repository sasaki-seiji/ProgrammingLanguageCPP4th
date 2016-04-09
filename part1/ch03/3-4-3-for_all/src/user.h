/*
 * user.h
 *
 *  Created on: 2016/03/30
 *      Author: sasaki
 */

#ifndef USER_H_
#define USER_H_


template<typename C, typename Oper>
void for_all(C& c, Oper op)
{
	for (auto& x : c)
		op(*x);
}


#endif /* USER_H_ */
