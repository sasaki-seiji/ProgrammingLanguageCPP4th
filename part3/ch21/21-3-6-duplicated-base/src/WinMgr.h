/*
 * WinMgr.h
 *
 *  Created on: 2017/04/30
 *      Author: sasaki
 */

#ifndef WINMGR_H_
#define WINMGR_H_

#include <list>
using namespace std;

class Window {
public:
	Window(int l, int t, int w, int h, bool visible=true);
	virtual ~Window();

	void show();
	void hide();
	bool is_visible() const { return visible; }

	int left() const { return l; }
	int top() const { return t; }
	int width() const { return w; }
	int height() const { return h; }

	virtual void on_mouse1hit(int x, int y) { }
	virtual void draw() { }
private:
	int l, t, w, h;
	bool visible;
};

class Window_manager {
public:
	static Window_manager* get_instance();

	void mouse1hit(int x, int y);

	void add_window(Window* p) { win_list.push_front(p); }
	void remove_window(Window* p) { win_list.remove(p); }
	void bring_top(Window* p);

private:
	static Window_manager* inst;
	list<Window*> win_list;
};

#endif /* WINMGR_H_ */
