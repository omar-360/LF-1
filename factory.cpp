#include <iostream>
#include <memory>
#include <cmath>

// Abstract base class for shapes
class Shape {
public:
    virtual double computeArea() const = 0;
    virtual void draw() const = 0;
    virtual ~Shape() = default;
};

// Circle class
class Circle : public Shape {
private:
    double radius;

public:
    explicit Circle(double r) : radius(r) {}

    double computeArea() const override {
        return M_PI * radius * radius;
    }

    void draw() const override {
        std::cout << "Drawing a Circle with radius: " << radius << std::endl;
    }
};

// Square class
class Square : public Shape {
private:
    double side;

public:
    explicit Square(double s) : side(s) {}

    double computeArea() const override {
        return side * side;
    }

    void draw() const override {
        std::cout << "Drawing a Square with side: " << side << std::endl;
    }
};

// Rectangle class
class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double computeArea() const override {
        return length * width;
    }

    void draw() const override {
        std::cout << "Drawing a Rectangle with length: " << length << " and width: " << width << std::endl;
    }
};

// Factory function to create shapes
std::unique_ptr<Shape> createShape(const std::string& type, double a, double b = 0) {
    if (type == "Circle") {
        return std::make_unique<Circle>(a);
    } else if (type == "Square") {
        return std::make_unique<Square>(a);
    } else if (type == "Rectangle") {
        return std::make_unique<Rectangle>(a, b);
    } else {
        return nullptr;
    }
}

int main() {
    // Create and compute area of a Circle
    auto circle = createShape("Circle", 5);
    if (circle) {
        circle->draw();
        std::cout << "Area: " << circle->computeArea() << std::endl;
    }

    // Create and compute area of a Square
    auto square = createShape("Square", 4);
    if (square) {
        square->draw();
        std::cout << "Area: " << square->computeArea() << std::endl;
    }

    // Create and compute area of a Rectangle
    auto rectangle = createShape("Rectangle", 6, 3);
    if (rectangle) {
        rectangle->draw();
        std::cout << "Area: " << rectangle->computeArea() << std::endl;
    }

    return 0;
}