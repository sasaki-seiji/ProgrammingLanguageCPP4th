/*
 * WinMgr.cpp
 *
 *  Created on: 2017/04/30
 *      Author: sasaki
 */

#include "WinMgr.h"

Window::Window(int l, int t, int w, int h, bool visible)
	:l{l}, t{t}, w{w}, h{h}, visible{visible}
{
	Window_manager::get_instance()->add_window(this);
}

Window::~Window()
{
	Window_manager::get_instance()->remove_window(this);
}

void Window::show()
{
	visible = true;
}

void Window::hide()
{
	visible = false;
}

Window_manager* Window_manager::get_instance()
{
	if (!inst) inst = new Window_manager();
	return inst;
}

void Window_manager::mouse1hit(int x, int y)
{
	for (auto p : win_list) {
		if (p->is_visible()
				&& p->left() <= x && x < p->left() + p->width()
				&& p->top() <= y && y < p->top() + p->height()) {
			p->on_mouse1hit(x - p->left(), y - p->top());
		}
	}
}

void Window_manager::bring_top(Window* p)
{
	win_list.remove(p);
	win_list.push_front(p);
}

Window_manager* Window_manager::inst = nullptr;



