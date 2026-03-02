#include <iostream>
#include <memory>

// Singleton design pattern - ensures only one instance of a class exists
class Singleton {
private:
    // Private constructor - prevents direct instantiation
    Singleton() {
        std::cout << "Singleton instance created!" << std::endl;
    }

    // Private destructor
    ~Singleton() {
        std::cout << "Singleton instance destroyed!" << std::endl;
    }

public:
    // Delete copy constructor
    Singleton(const Singleton&) = delete;

    // Delete move constructor
    Singleton(Singleton&&) = delete;

    // Delete copy assignment operator
    Singleton& operator=(const Singleton&) = delete;

    // Delete move assignment operator
    Singleton& operator=(Singleton&&) = delete;

    // Static method to get the unique instance (Meyers' Singleton - thread-safe)
    static Singleton& getInstance() 
    {
        static Singleton instance;  // Created only once, destroyed at program end
        return instance;
    }

    // Example method
    void doSomething() 
    {
        std::cout << "Singleton is doing something!" << std::endl;
    }

    // Example method to demonstrate state
    void setValue(int value) 
    {
        this->value = value;
    }

    int getValue() const 
    {
        return value;
    }

private:
    int value = 0;
};

// ===== Example Usage =====
int main() {
    std::cout << "--- Singleton Pattern Demo ---\n" << std::endl;

    // Get instance - constructor is called only once
    Singleton& singleton1 = Singleton::getInstance();
    singleton1.doSomething();
    singleton1.setValue(42);

    std::cout << "\nGetting instance again..." << std::endl;

    // Get instance again - same instance is returned, constructor is NOT called again
    Singleton& singleton2 = Singleton::getInstance();
    singleton2.doSomething();
    std::cout << "Value from first instance: " << singleton1.getValue() << std::endl;
    std::cout << "Value from second instance: " << singleton2.getValue() << std::endl;

    // Verify they are the same object
    std::cout << "\nAre they the same object? " << (&singleton1 == &singleton2 ? "YES" : "NO") << std::endl;
    return 0;
}
