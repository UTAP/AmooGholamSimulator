#include <vector>
class Wall{
public:
	Point get_min();
	Point get_max();

private:
	vector<Point> blocks;
};