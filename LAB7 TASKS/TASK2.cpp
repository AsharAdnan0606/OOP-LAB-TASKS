#include <iostream>
using namespace std;

class Shape {
protected:
    string position, color;
    double borderThickness;

public:
    Shape(string pos, string col, double border = 0) : position(pos), color(col), borderThickness(border) {}
    virtual void draw() { cout << "Drawing Shape\n"; }
    virtual double calculateArea() { return 0; }
    virtual double calculatePerimeter() { return 0; }
};

class Circle : public Shape {
    double radius;
    string centerPosition;

public:
    Circle(string pos, string col, double rad, string center, double border = 0)
        : Shape(pos, col, border), radius(rad), centerPosition(center) {}
    void draw() override { cout << "Drawing Circle\n"; }
    double calculateArea() override { return 3.14 * radius * radius; }
    double calculatePerimeter() override { return 2 * 3.14 * radius; }
};

class Rectangle : public Shape {
    double width, height;
    string topLeftCorner;

public:
    Rectangle(string pos, string col, double w, double h, string topLeft, double border = 0)
        : Shape(pos, col, border), width(w), height(h), topLeftCorner(topLeft) {}
    void draw() override { cout << "Drawing Rectangle\n"; }
    double calculateArea() override { return width * height; }
    double calculatePerimeter() override { return 2 * (width + height); }
};

int main() {
    Circle c("Center", "Red", 5, "(0,0)");
    Rectangle r("TopLeft", "Blue", 4, 6, "(0,10)");
    
    c.draw();
    cout << "Circle Area: " << c.calculateArea() << "\n";
    cout << "Circle Perimeter: " << c.calculatePerimeter() << "\n\n";
    
    r.draw();
    cout << "Rectangle Area: " << r.calculateArea() << "\n";
    cout << "Rectangle Perimeter: " << r.calculatePerimeter() << "\n";
    
    return 0;
}

