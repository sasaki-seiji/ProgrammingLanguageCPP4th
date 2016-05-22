/*
 * interface.h
 *
 *  Created on: 2016/05/14
 *      Author: sasaki
 */

#ifndef INTERFACE_H_
#define INTERFACE_H_

#define	E_CPLPLFCTBLEWIT 123

#ifdef __cplusplus
extern "C" {
#endif
	void c_function();
	void call_from_C()
	#ifdef __cplusplus
		noexcept
	#endif
	;
	void c_entry();
#ifdef __cplusplus
}
#endif

#endif /* INTERFACE_H_ */
