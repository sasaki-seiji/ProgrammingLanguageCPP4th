/*
 * weak_ptr.cpp
 *
 *  Created on: 2016/12/08
 *      Author: sasaki
 */

#include <memory>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

struct Asteroid {
	static constexpr double RADIUS = 10;
	static constexpr int TICK_COUNT = 1000;
	static constexpr double time_delta = 1;
	static constexpr int INIT_AREA = 1000;
	static constexpr int INIT_SPEED = 5;
	static constexpr double GRAVITY = 100;

	int	id;
	double x, y;
	double vx, vy;

	static int count;
	weak_ptr<Asteroid> neighbor;

	Asteroid(int iden, double init_x, double init_y, double init_vx, double init_vy)
		: id{iden}, x{init_x}, y{init_y}, vx{init_vx}, vy{init_vy} { ++count; }
};

int Asteroid::count = 0;

using vec_Asteroid = vector<shared_ptr<Asteroid>>;

double calc_sdist(shared_ptr<Asteroid> sp1, shared_ptr<Asteroid> sp2)
{
	double delta_x = sp1->x - sp2->x, delta_y = sp1->y - sp2->y;
	return delta_x * delta_x + delta_y * delta_y;
}

void update_neighbor(vec_Asteroid& va, size_t i)
{
	shared_ptr<Asteroid> sp = va[i];
	if (sp==nullptr) return;

	size_t min_index = -1;
	double min_sdist = Asteroid::INIT_AREA*2;
	double x = sp->x, y = sp->y;
	for (size_t j=0; j<100; ++j) {
		if (j==i) continue;
		if (va[j]==nullptr) continue;

		double sdist = calc_sdist(sp, va[j]);
		if (sdist < min_sdist) {
			min_index = j;
			min_sdist = sdist;
		}
	}

	if (min_index == -1)
		sp->neighbor.reset();
	else
		sp->neighbor = va[min_index];
}

void update_speed(shared_ptr<Asteroid> sp)
{
	if (sp==nullptr) return ;

	if (auto neighbor = sp->neighbor.lock()) {
		double sdist = calc_sdist(sp, neighbor);
		double dist = sqrt(sdist);
		double unit_vx = ( neighbor->x - sp->x ) / dist;
		double unit_vy = ( neighbor->y - sp->y ) / dist;
		sp->vx += Asteroid::GRAVITY * unit_vx / sdist;
		sp->vy += Asteroid::GRAVITY * unit_vy / sdist;
	}
	else {
		sp->neighbor.reset();
	}
}

void update_position(shared_ptr<Asteroid> sp)
{
	if (sp==nullptr) return ;

	sp->x += sp->vx * Asteroid::time_delta;
	sp->y += sp->vy * Asteroid::time_delta;
}

void collision(vec_Asteroid& va, shared_ptr<Asteroid> sp1, shared_ptr<Asteroid> sp2)
{
	cout << "collision: asteroid#" << sp1->id << ", asteroid#" << sp2->id << endl;

	for_each(va.begin(), va.end(),
		[sp1, sp2](shared_ptr<Asteroid>& x) { if (x==sp1||x==sp2) x.reset();});

	Asteroid::count -= 2;
}

void check_collision(vec_Asteroid& va, size_t i)
{
	shared_ptr<Asteroid> sp = va[i];
	if (sp==nullptr) return;

	if (auto neighbor = sp->neighbor.lock()) {
		double sdist = calc_sdist(sp, neighbor);
		if (sdist <= Asteroid::RADIUS*Asteroid::RADIUS) {
			collision(va, sp, neighbor);
		}
	}
	else {
		sp->neighbor.reset();
	}
}

void owner()
{
	vec_Asteroid va(100);
	for (size_t i=0; i<va.size(); ++i) {
		double x = rand()%Asteroid::INIT_AREA - Asteroid::INIT_AREA/2;
		double y = rand()%Asteroid::INIT_AREA - Asteroid::INIT_AREA/2;
		double vx = rand()%Asteroid::INIT_SPEED - Asteroid::INIT_SPEED/2;
		double vy = rand()%Asteroid::INIT_SPEED - Asteroid::INIT_SPEED/2;
		va[i].reset(new Asteroid(i, x,y,vx,vy));
	}

	for (int time = 0; time < Asteroid::TICK_COUNT; ++time) {
		cout << "-- time: " << time << ", count: " << Asteroid::count << "--\n";

		for (size_t i=0; i<va.size(); ++i) {
			update_neighbor(va, i);
			update_speed(va[i]);
			update_position(va[i]);
			check_collision(va, i);
		}
	}
}

int main()
{
	owner();
}
