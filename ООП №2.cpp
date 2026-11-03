#include <iostream>
using namespace std;

class Point
{
private:
	int x, y;
public:
	Point() : x(0), y(0) 
	{
		cout << "Point()\n";
	}
	Point(int x, int y) : x(x), y(y)
	{
		cout << "Point(int x, int y)\n";
	}
	Point(Point& p) : x(p.x), y(p.y)
	{
		cout << "Point(Point& p)\n";
	}
	~Point()
	{
		cout << "~Point()\n";
	}
};

class Shape
{
private: 	

protected:
	int x1, y1, x2, y2;
public:
	Shape() : x1(0), y1(0), x2(0), y2(0)
	{
		cout << "Shape()\n";
	}
	Shape(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2)
	{
		cout << "Shape(int x1, int y1, int x2, int y2)\n";
	}
	Shape(Shape& s) : x1(s.x1), y1(s.y1), x2(s.x2), y2(s.y2)
	{
		cout << "Shape(Shape& s)\n";
	}
	void draw()
	{
		cout << this->x1 << " " << this->y1 << " " << this->x2 << " " << this->y2 << endl;
	}
	void move(int dx, int dy);

	~Shape()
	{
		cout << "~Shape()\n";
	}
};

class Line : Shape
{
public:
	int length;

	Line() : length(0)
	{
		cout << "Line()\n";
	}
	Line(int x1, int y1, int x2, int y2, int length) : Shape(x1, y1, x2, y2), length(length)
	{
		cout << "Line(int x1, int y1, int x2, int y2, int length)\n";
	}
	Line(Line& l) : Shape(l.x1, l.y1, l.x2, l.y2), length(l.length)
	{
		cout << "Line(Line& l)\n";
	}
	void draw()
	{
		cout << this->x1 << " " << this->y1 << " " << "length: " << this->length << ", " << this->x2 << " " << this->y2 << endl;
	}
};

void Shape::move(int dx, int dy)
{
	x1 = x1 + dx;
	x2 = x2 + dx;
	y1 = y1 + dy;
	y2 = y2 + dy;
}

int main()
{
	Line l;
	

	Line n(l);
	l.length = -8;
	n.length = 52;
	l.draw();
	n.draw();
	
}