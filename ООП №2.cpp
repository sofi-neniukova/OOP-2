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
	Point(const Point& p) : x(p.x), y(p.y)
	{
		cout << "Point(const Point& p)\n";
	}
	void set_attr(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	void print()
	{
		cout << "x = " << x << ", y = " << y << endl;
	}
	~Point()
	{
		cout << "~Point()\n";
	}
};


class Round
{
protected:
	Point* p1;
	Point* p2;
public:
	Round()
	{
		cout << "Round()\n";
		p1 = new Point;
		p2 = new Point;
	}
	Round(int x1, int y1, int x2, int y2)
	{
		cout << "Round(int x, int y)\n";
		p1 = new Point(x1, y1);
		p2 = new Point(x2, y2);
	}
	Round(const Round& r)
	{
		cout << "Round(const Round& r)\n";
		p1 = new Point(*(r.p1));
		p2 = new Point(*(r.p2));
	}
	~Round()
	{
		cout << "~Round()\n";
		delete p1;
		delete p2;
	}
};

class Shape
{
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
	Shape(const Shape& s) : x1(s.x1), y1(s.y1), x2(s.x2), y2(s.y2)
	{
		cout << "Shape(const Shape& s)\n";
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

class Line : public Shape
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
	Line(const Line& l) : Shape(l), length(l.length)
	{
		cout << "Line(const Line& l)\n";
	}
	void draw() // реализация метода сразу в определении
	{
		Shape::draw();
		cout << "Length: " << length << endl;
	}
	void set_protected(int x1, int y1, int x2, int y2)
	{
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;
	}

	~Line()
	{
		cout << "~Line()\n";
	}
};

class B
{
public:
	int num;
	B() : num(0)
	{
		cout << "B()\n";
	}
	B(int n) : num(n)
	{
		cout << "B(int n)\n";
	}
	B(const B& b) : num(b.num)
	{
		cout << "B(const B& b)\n";
	}
	~B()
	{
		cout << "~B()\n";
	}
};
class A
{
public:
	B b;
	A() : b(0)
	{
		cout << "A()\n";
	}
	A(B& b) : b(b)
	{
		cout << "A(B& b)\n";
	}
	A(const A& a) : b(a.b)
	{
		cout << "A(const A& a)\n";
	}
	~A()
	{
		cout << "~A()\n";
	}

};


void Shape::move(int dx, int dy) //реализация методов после определения
{
	x1 = x1 + dx;
	x2 = x2 + dx;
	y1 = y1 + dy;
	y2 = y2 + dy;
}

int main()
{
	setlocale(LC_ALL, "RU");
	cout << "статическое создание" << endl;
	Point p; 	//конструктор по умолчанию
	Point p1(1, 1);		//конструктор с параметрами
	Point p2(p1);	//конструктор копирования
	p1.print();
	p1.set_attr(30, 40);
	p1.print();
	//p1.x = 1; вызовет ошибку 
	
	cout << "динамическое создание" << endl;
	Point* p3 = new Point(10, 10);
	p3->print();
	p3->set_attr(50, 60);
	p3->print();
	cout << "\n\n\n";

	cout << "объекты классов - наследников:" << endl;
	Line l;		//вызывается конструктор по умолчанию родителя, потом потомка
	Line l1(1, 2, 3, 4, 6);		//вызывается конструктор с параметрами родителя, потом потомка

	// l1.x1 = 1; вызовет ошибку
	l1.length = 10;
	l1.set_protected(13, 15, 23, 25); //доступ к защищенным полям
	l1.draw();
	l1.move(100, 100);
	l1.draw();
	cout << "копирование объекта в объект того же самого класса" << endl;
	Line l2(l1);	 //вызывается конструктор копирования родителя, потом потомка
	l1.length = 1;
	l2.draw(); //вызов переопределенного в потомке метода
	l2.length = 50;
	l1.draw(); //при редактировании с копией ничего не происходит
	cout << "\n\n\nкопирование указателя в указатель того же самого класса\n";
	{
		Line* l3 = new Line(10, 10, 10, 10, 100); //копирование указателя в указатель того же самого класса 
		Line* l4 = l3;							    
		l3->length = 10;
		l3->draw();
		l4->draw();
		delete l3;
	}
	cout << "\n\n\nпомещение объектов в переменные различных типов\n";
	{

		Shape* s = new Shape(123, 123, 123, 123);
		s->draw();
		Shape* sl = new Line(234, 234, 234, 234, 52);
		sl->draw();
		delete s;
		delete (Line*)sl;
	}
	cout << "\n\n\n";
	delete p3;
	cout << "\n\n\nкомпозиция\n";
	{
		B b(123);
		A a(b);
		//создан Б, при создании А сначала вызывается B(B& b), затем вызывается A(B& b), удаляется сначала А, потом поле b класса а, затем объект класса Б 
	}
	cout << "\n\n\nкомпозиция с указателем\n";
	{
		Round r1;
		cout << "\n";
		Round r2(2, 2, 6, 6);
		cout << "\n";
		Round* r3 = new Round(r2);
		cout << "\n";
	}

	cout << "\n\n\n";
}