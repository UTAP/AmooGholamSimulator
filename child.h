#include "childinfo.h"
#include "wall.h"
#include <vector>
#include <string>
using std::vector;


class Child {
public:
	virtual void collide(Child * c);
	virtual void collide(vector<Child *> children);
	void update(); //@TODO pure virtual update without setters
	void move(int dt);
	void reflect(Wall w);
	void try_break();
	virtual void clone() = 0;

	//setters and getters
	int get_mass();
	int get_radius();
	Point get_vel();
	Point get_pos();
	void die();

	virtual void set_vel(Point new_vel) = 0;
	virtual void set_pos(Point new_pos) = 0;
	virtual void set_radius(int new_r) = 0;
	virtual void set_status(Status new_s);
	virtual void set_charachter(int new_a, int new_k, int new_c) = 0;
	int get_anger();
	int get_charisma();
	int get_courage();
	vector<Child *> get_clones();

private:
	ChildInfo current_info, delta_info;
	int id; 
	string type;
	bool is_fragile;
	vector<Child *> clones;
};