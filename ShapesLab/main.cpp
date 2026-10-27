#include <numbers>
#include <cmath>
#include <iostream>
#include <cassert>

class Shape {
private:
public:
	double getArea() { return 0.0; }
	double getPerimeter() { return 0.0; }
};

class Circle : public Shape {
private:
	double radius;
public:
	Circle(double r) : radius(r) {}
	double getArea() { return std::numbers::pi * radius * radius; }
	double getPerimeter() { return 2.0 * std::numbers::pi * radius; }
};

class Rectangle : public Shape {
protected:
	double length;
	double width;
public:
	Rectangle(double l, double w) : length(l), width(w) {}
	double getArea() { return length * width; }
	double getPerimeter() { return length + length + width + width; }
};

class RightTriangle : public Shape {
protected:
	double length;
	double height;
public:
	RightTriangle(double l, double h) : length(l), height(h) {}
	double getArea() { return 0.5 * length * height; }
	double getPerimeter() { return std::sqrt((length * length) + (height * height)) + length + height; }
};

class Square : public Rectangle {
private:
public:
	Square(double l) : Rectangle(l, l) {}
};

class IsocelesRightTriangle : public RightTriangle {
private:
public:
	IsocelesRightTriangle(double l) : RightTriangle(l, l) {}
};

int main() {
	// Shape
	Shape s = Shape();
	assert(s.getArea() == 0.0);
	assert(s.getPerimeter() == 0.0);
	
	// Circle
	Circle c = Circle(5);
	assert(c.getArea() == std::numbers::pi * 5 * 5);
	assert(c.getPerimeter() == 2.0 * std::numbers::pi * 5);

	// Rectangle
	Rectangle r = Rectangle(6, 7);
	assert(r.getArea() == 42.0);
	assert(r.getPerimeter() == 26.0);

	// Right Triangle
	RightTriangle rt = RightTriangle(3, 4);
	assert(rt.getArea() == 6.0);
	assert(rt.getPerimeter() == 12.0);

	// Square
	Square sq = Square(4);
	assert(sq.getArea() == 16.0);
	assert(sq.getPerimeter() == 16.0);
	
	// Isoceles Right Triangle
	IsocelesRightTriangle irt = IsocelesRightTriangle(8);
	assert(irt.getArea() == 32.0);
	assert(irt.getPerimeter() == std::sqrt((8 * 8) + (8 * 8)) + 8 + 8);

	std::cout << "All tests passed.\n";

	return 0;
}