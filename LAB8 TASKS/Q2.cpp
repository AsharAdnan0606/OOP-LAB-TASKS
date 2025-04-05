#include <iostream>

class Shape {
private:
    double area;
public:
    Shape(double a) : area(a) {}

    double getArea() const { return area; }

    Shape operator+(const Shape& other) const {
        return Shape(area + other.area);
    }

    friend std::ostream& operator<<(std::ostream& os, const Shape& s) {
        os << "Area: " << s.area;
        return os;
    }
};

int main() {
    Shape shape1(25.5), shape2(30.0);
    Shape totalArea = shape1 + shape2;
    std::cout << "Shape1 " << shape1 << "\n";
    std::cout << "Shape2 " << shape2 << "\n";
    std::cout << "Total " << totalArea << "\n";
    return 0;
}

