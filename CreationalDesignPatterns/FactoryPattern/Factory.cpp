#include <iostream>
#include <memory>
#include <string>

// ===== Base Product =====
// Abstract class that defines the interface for objects created by the factory
class Shape {
public:
    virtual ~Shape() = default;
    virtual void draw() const = 0;
};

// ===== Concrete Products =====
// Concrete implementations of the Shape interface

class Circle : public Shape {
public:
    void draw() const override 
    {
        std::cout << "Drawing Circle" << std::endl;
    }
};

class Square : public Shape {
public:
    void draw() const override 
    {
        std::cout << "Drawing Square" << std::endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() const override
    {
        std::cout << "Drawing Rectangle" << std::endl;
    }
};

// ===== Factory Class =====
// Responsible for creating objects based on input
class ShapeFactory {
public:
    // Factory method that creates and returns the appropriate shape
    static std::shared_ptr<Shape> createShape(const std::string& shapeType) {
        if (shapeType == "circle") 
        {
            return std::make_shared<Circle>();
        } 
        else if (shapeType == "square") 
        {
            return std::make_shared<Square>();
        } 
        else if (shapeType == "rectangle") 
        {
            return std::make_shared<Rectangle>();
        }
        
        std::cerr << "Unknown shape type: " << shapeType << std::endl;
        return nullptr;
    }
};

// ===== Example Usage =====
int main() {
    std::cout << "--- Factory Pattern Demo ---\n" << std::endl;

    // Use factory to create objects without knowing concrete classes
    std::shared_ptr<Shape> shape1 = ShapeFactory::createShape("circle");
    if (shape1) shape1->draw();

    std::shared_ptr<Shape> shape2 = ShapeFactory::createShape("square");
    if (shape2) shape2->draw();

    std::shared_ptr<Shape> shape3 = ShapeFactory::createShape("rectangle");
    if (shape3) shape3->draw();

    std::cout << "\n--- Creating shapes from user input ---\n" << std::endl;

    // Create shapes from different inputs
    std::string shapes[] = {"circle", "square", "rectangle", "triangle"};
    for (const auto& shapeType : shapes) {
        
        auto shape = ShapeFactory::createShape(shapeType);
        
        if (shape) 
        {
            shape->draw();
        }
    }

    return 0;
}
