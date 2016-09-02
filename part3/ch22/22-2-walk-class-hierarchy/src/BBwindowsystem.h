/*
 * BBwindowsystem.h
 *
 *  Created on: 2016/09/03
 *      Author: sasaki
 */

#ifndef BBWINDOWSYSTEM_H_
#define BBWINDOWSYSTEM_H_

#include "BBwindow.h"
#include <list>
#include <utility>
using std::list;
using std::pair;

typedef void (*Callback)(BBwindow*);

class BB_window_system {
public:
	static BB_window_system* get_instance();
	void add_event_handler(BBwindow* w, Callback cb);
	void fire_event();
private:
	BB_window_system() { }
	static BB_window_system *instance;
	list<pair<BBwindow*,Callback>> handlers;
};

#endif /* BBWINDOWSYSTEM_H_ */
