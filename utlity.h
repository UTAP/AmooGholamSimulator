class Point {
public:	
	float x,y;
	Point operator*(int i) {
		Point p;
		p.x = x * i;
		p.y = y * i;
		return p;
	}
	operator+=;
	operator-;
	operator+;
	operator >, <, <=, >=, ==;

}