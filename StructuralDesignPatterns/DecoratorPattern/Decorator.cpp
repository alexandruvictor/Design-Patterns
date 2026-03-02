#include <iostream>
#include <memory>
#include <string>

// ===== Component Interface =====
// Abstract interface that both concrete components and decorators implement
class Beverage {
public:
    virtual ~Beverage() = default;
    virtual std::string getDescription() const = 0;
    virtual double getCost() const = 0;
};

// ===== Concrete Component =====
// The base object that can be decorated
class Coffee : public Beverage {
public:
    std::string getDescription() const override 
    {
        return "Coffee";
    }

    double getCost() const override 
    {
        return 2.00;  // Base price
    }
};

// ===== Decorator Base Class =====
// Abstract decorator that wraps a Beverage component
class BeverageDecorator : public Beverage 
{
protected:
    std::shared_ptr<Beverage> beverage;

public:
    BeverageDecorator(std::shared_ptr<Beverage> b) : beverage(b) {}
    virtual ~BeverageDecorator() = default;

    // Default implementation - can be overridden
    std::string getDescription() const override 
    {
        return beverage->getDescription();
    }

    double getCost() const override 
    {
        return beverage->getCost();
    }
};

// ===== Concrete Decorators =====
// Each decorator adds specific functionality and cost

// Adds milk to the beverage
class MilkDecorator : public BeverageDecorator 
{
public:
    MilkDecorator(std::shared_ptr<Beverage> b) : BeverageDecorator(b) {}

    std::string getDescription() const override 
    {
        return beverage->getDescription() + " + Milk";
    }

    double getCost() const override 
    {
        return beverage->getCost() + 0.50;
    }
};

// Adds sugar to the beverage
class SugarDecorator : public BeverageDecorator 
{
public:
    SugarDecorator(std::shared_ptr<Beverage> b) : BeverageDecorator(b) {}

    std::string getDescription() const override 
    {
        return beverage->getDescription() + " + Sugar";
    }

    double getCost() const override {
        return beverage->getCost() + 0.25;
    }
};

// Adds whipped cream to the beverage
class WhippedCreamDecorator : public BeverageDecorator 
{
public:
    WhippedCreamDecorator(std::shared_ptr<Beverage> b) : BeverageDecorator(b) {}

    std::string getDescription() const override {
        return beverage->getDescription() + " + Whipped Cream";
    }

    double getCost() const override 
    {
        return beverage->getCost() + 0.75;
    }
};

// Adds cinnamon to the beverage
class CinnamonDecorator : public BeverageDecorator 
{
public:
    CinnamonDecorator(std::shared_ptr<Beverage> b) : BeverageDecorator(b) {}

    std::string getDescription() const override 
    {
        return beverage->getDescription() + " + Cinnamon";
    }

    double getCost() const override 
    {
        return beverage->getCost() + 0.30;
    }
};

// ===== Example Usage =====
int main() {
    std::cout << "--- Decorator Pattern Demo ---\n" << std::endl;
    
    {    
        // Create a simple coffee
        std::cout << "1. Simple Coffee:" << std::endl;
        std::shared_ptr<Beverage> coffee = std::make_shared<Coffee>();
        std::cout << coffee->getDescription() << std::endl;
        std::cout << "Cost: $" << std::fixed << std::setprecision(2) << coffee->getCost() << std::endl;
    }

    {
        // Create a coffee with milk
        std::cout << "\n2. Coffee + Milk:" << std::endl;
        std::shared_ptr<Beverage> coffeeWithMilk = std::make_shared<MilkDecorator>(std::make_shared<Coffee>());
        std::cout << coffeeWithMilk->getDescription() << std::endl;
        std::cout << "Cost: $" << std::fixed << std::setprecision(2) << coffeeWithMilk->getCost() << std::endl;
    }

    {
        // Create a coffee with milk and sugar
        std::cout << "\n3. Coffee + Milk + Sugar:" << std::endl;
        std::shared_ptr<Beverage> coffeeWithMilkAndSugar = 
            std::make_shared<SugarDecorator>(
                std::make_shared<MilkDecorator>(std::make_shared<Coffee>()));
        std::cout << coffeeWithMilkAndSugar->getDescription() << std::endl;
        std::cout << "Cost: $" << std::fixed << std::setprecision(2) << coffeeWithMilkAndSugar->getCost() << std::endl; 
    }

    {
        // Create a deluxe coffee with multiple decorators
        std::cout << "\n4. Coffee + Milk + Whipped Cream + Cinnamon:" << std::endl;
        std::shared_ptr<Beverage> deluxeCoffee = 
            std::make_shared<CinnamonDecorator>(
                std::make_shared<WhippedCreamDecorator>(
                    std::make_shared<MilkDecorator>(std::make_shared<Coffee>())));
        std::cout << deluxeCoffee->getDescription() << std::endl;
        std::cout << "Cost: $" << std::fixed << std::setprecision(2) << deluxeCoffee->getCost() << std::endl;
    }

    {
        // Create a coffee with just sugar
        std::cout << "\n5. Coffee + Sugar:" << std::endl;
        std::shared_ptr<Beverage> coffeeWithSugar = std::make_shared<SugarDecorator>(std::make_shared<Coffee>());
        std::cout << coffeeWithSugar->getDescription() << std::endl;
        std::cout << "Cost: $" << std::fixed << std::setprecision(2) << coffeeWithSugar->getCost() << std::endl;
    }

    {
        // Create a coffee with multiple variations
        std::cout << "\n6. Multiple variations:" << std::endl;
        std::shared_ptr<Beverage> variation1 = 
            std::make_shared<SugarDecorator>(
                std::make_shared<WhippedCreamDecorator>(std::make_shared<Coffee>()));
        std::cout << variation1->getDescription() << " - $" << std::fixed << std::setprecision(2) << variation1->getCost() << std::endl;
    }
    
    return 0;
}
