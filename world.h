#include <vector>

class World{
public:
	void run()
private:
	int total_time, simulation_step;
	vector<Wall> walls;
	vector<Child *> children;
}