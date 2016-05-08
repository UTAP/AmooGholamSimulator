#include "utility.h"
enum Status {dead, alive};

class ChildInfo{
public:
	int anger, charisma, courage;
	int radius;
	Status status;//dead or alive
	Point pos, vel;
}