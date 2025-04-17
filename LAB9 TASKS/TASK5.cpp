#include <iostream>
#include <cmath>

// Abstract class Shape
class Shape {
public:
    // Pure virtual function to calculate area
    virtual double getArea() const = 0; 

    // Virtual destructor to ensure proper cleanup for derived classes
    virtual ~Shape() {}
};

// Rectangle class that derives from Shape
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    // Constructor
    Rectangle(double w, double h) : width(w), height(h) {}

    // Implementation of the getArea function for Rectangle
    double getArea() const override {
        return width * height;
    }
};

// Triangle class that derives from Shape
class Triangle : public Shape {
private:
    double base;
    double height;

public:
    // Constructor
    Triangle(double b, double h) : base(b), height(h) {}

    // Implementation of the getArea function for Triangle
    double getArea() const override {
        return 0.5 * base * height;
    }
};

int main() {
    // Creating a Rectangle and Triangle object
    Shape* rectangle = new Rectangle(5.0, 10.0);
    Shape* triangle = new Triangle(4.0, 6.0);

    // Output the areas
    std::cout << "Area of Rectangle: " << rectangle->getArea() << std::endl;
    std::cout << "Area of Triangle: " << triangle->getArea() << std::endl;

    // Clean up dynamic memory
    delete rectangle;
    delete triangle;

    return 0;
}

