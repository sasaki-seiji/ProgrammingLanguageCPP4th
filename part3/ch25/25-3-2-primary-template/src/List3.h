/*
 * List3.h
 *
 *  Created on: 2016/09/20
 *      Author: sasaki
 */

#ifndef LIST3_H_
#define LIST3_H_


template<typename T>
class List3 {

};

//List3<int*> li;

template<typename T>
class List3<T*> {

};
// error: partial specialization of 'class List3<T*>' after instantiation of 'class List3<int*>' [-fpermissive]

#endif /* LIST3_H_ */
