#include "child.h"
using namespace std;

void Child::collide(Child * c) {
	float new_vel = ((get_mass() - c.get_mass()) * get_vel() + (2 * c.get_mass()) * c.get_vel()) / (get_mass() + c.get_mass());
	delta_info.vel += new_vel - get_vel();
	
	try_break();
}

void Child::collide(vector<Child *> children) {
	for (int i = 0; i < children.size(); i++)  {
		collide(children[i]);
	}
}

void Child::try_break() {
	if (!is_fragile || get_radius() + c.get_radius() < 20)
		return;
	//@TODO break

}
void Child::update() {
	set_vel(get_vel() + delta_info.vel);
	set_pos(get_pos() + delta_info.pos);
	set_radius(get_radius() + delta_info.radius);
	set_status(delta_info.status);
	set_charachter(get_anger() + delta_info.anger, get_charisma() + delta_info.charisma, get_courage() + delta_info.courage);
}

void Child::move(int dt) {
	current_info.pos = current_info.pos + current_info.vel * dt;
}

void Child::reflect(Wall w) {
	if (get_pos() >= w.get_min() && get_pos() <= w.get_max()) //kill the child
		die();
	else if (is_horizantal_collision())
			delta_info.vel.y += -2* get_vel().y;
	else if (is_vertical_collision())
			delta_info.vel.x += -2* get_vel().x;
}

bool is_horizantal_collision(Wall w) {
	if(get_pos().x >= w.get_min().x && get_pos().x <= w.get_max().x)
		if (get_pos.y >= w.get_min().y - get_radius() && get_pos.y <= w.get_max().y + get_radius())
			return true;
	return false;
}

bool is_vertical_collision(Wall w) {
	if(get_pos().y >= w.get_min().y && get_pos().y <= w.get_max().y)
		if (get_pos.x >= w.get_min().x - get_radius() && get_pos.x <= w.get_max().x + get_radius())
			return true;
	return false;
}

void Child::get_mass() {
	return current_info.radius * current_info.radius;
}
Point get_vel() {
	return current_info.vel;
}

void Child::die(){
	delta_info.status = dead;
}