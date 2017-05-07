/*
 * LSpopupivalslider.h
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#ifndef LSPOPUPIVALSLIDER_H_
#define LSPOPUPIVALSLIDER_H_

#include "Popupivalslider.h"
#include "LSslider.h"

class LS_popup_ival_slider : public Popup_ival_slider, protected LSslider {
public:
	LS_popup_ival_slider(int low, int high, int l=-1, int t=-1, int w=-1, int h=-1);
	~LS_popup_ival_slider() { }

	int get_value() override;
	void set_value(int i) override;
	void reset_value(int i) override;
	void prompt() override;
	bool was_changed() const override;

	void incr() override;
	void decr() override;

	void popup() override ;
	void popdown() override ;

	void display_info() const override;

protected:
	void on_changed(int i) override;

private:
	bool changed;
};

#endif /* LSPOPUPIVALSLIDER_H_ */
