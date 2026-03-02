#include <iostream>
#include <string>

// ===== Product Class =====
// Complex object that will be built step by step
class House {
private:
    std::string foundation;
    std::string walls;
    std::string roof;
    std::string windows;
    std::string doors;

public:
    // Setters for builder to use
    void setFoundation(const std::string& f) { foundation = f; }
    void setWalls(const std::string& w) { walls = w; }
    void setRoof(const std::string& r) { roof = r; }
    void setWindows(const std::string& w) { windows = w; }
    void setDoors(const std::string& d) { doors = d; }

    // Display the constructed house
    void display() const {
        std::cout << "\n=== House Built ===" << std::endl;
        std::cout << "Foundation: " << foundation << std::endl;
        std::cout << "Walls: " << walls << std::endl;
        std::cout << "Roof: " << roof << std::endl;
        std::cout << "Windows: " << windows << std::endl;
        std::cout << "Doors: " << doors << std::endl;
    }
};

// ===== Builder Class =====
// Responsible for constructing the complex object step by step
class HouseBuilder {
private:
    House house;

public:
    // Builder methods return 'this' for method chaining
    HouseBuilder& buildFoundation() 
    {
        std::cout << "Building foundation..." << std::endl;
        house.setFoundation("Concrete foundation");
        return *this;
    }

    HouseBuilder& buildWalls() 
    {
        std::cout << "Building walls..." << std::endl;
        house.setWalls("Brick walls");
        return *this;
    }

    HouseBuilder& buildRoof() 
    {
        std::cout << "Building roof..." << std::endl;
        house.setRoof("Tile roof");
        return *this;
    }

    HouseBuilder& buildWindows() 
    {
        std::cout << "Adding windows..." << std::endl;
        house.setWindows("Glass windows");
        return *this;
    }

    HouseBuilder& buildDoors() 
    {
        std::cout << "Adding doors..." << std::endl;
        house.setDoors("Wooden doors");
        return *this;
    }

    // Return the final constructed object
    House& getHouse() 
    {
        return house;
    }

    // Build minimal house
    HouseBuilder& buildSimpleHouse() 
    {
        std::cout << "\nBuilding simple house...\n" << std::endl;
        return buildFoundation().buildWalls().buildRoof();
    }

    // Build complete house
    HouseBuilder& buildCompleteHouse() 
    {
        std::cout << "\nBuilding complete house...\n" << std::endl;
        return buildFoundation()
               .buildWalls()
               .buildRoof()
               .buildWindows()
               .buildDoors();
    }
};

// ===== Alternative: Director Class =====
// Optional class to manage the building process
class HouseDirector {
private:
    HouseBuilder* builder;

public:
    HouseDirector(HouseBuilder* b) : builder(b) {}

    void constructSimpleHouse() 
    {
        builder->buildSimpleHouse();
    }

    void constructLuxuryHouse() 
    {
        std::cout << "\nBuilding luxury house...\n" << std::endl;
        builder->buildFoundation()
               .buildWalls()
               .buildRoof()
               .buildWindows()
               .buildDoors();
    }
};

// ===== Example Usage =====
int main() {
    std::cout << "--- Builder Pattern Demo ---" << std::endl;

    // ===== Method 1: Using Builder with method chaining =====
    std::cout << "\n[ Method 1: Builder with Chaining ]\n" << std::endl;

    HouseBuilder builder1;
    House& house1 = builder1.buildCompleteHouse().getHouse();
    house1.display();

    // Build a simple house
    HouseBuilder builder2;
    House& house2 = builder2.buildSimpleHouse().getHouse();
    house2.display();

    // Build custom house - flexibility to skip steps
    std::cout << "\n[ Method 2: Custom Configuration ]\n" << std::endl;
    
    HouseBuilder builder3;
    House& house3 = builder3.buildFoundation()
                            .buildWalls()
                            .buildRoof()
                            .getHouse();
    house3.display();

    // ===== Method 2: Using Director =====
    std::cout << "\n[ Method 3: Using Director ]\n" << std::endl;

    HouseBuilder builder4;
    HouseDirector director(&builder4);
    director.constructLuxuryHouse();
    builder4.getHouse().display();

    return 0;
}
