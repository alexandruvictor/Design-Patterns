# Design Patterns in C++

A comprehensive collection of Design Pattern implementations in C++.

## Creational Patterns

Creational design patterns deal with object creation mechanisms, trying to create objects in a manner suitable to the situation.

### 1. Singleton Pattern
**Location:** `creational/SingletonPattern/singleton.cpp`

**Purpose:** Ensures that a class has only one instance and provides a global point of access to it.

**Key Features:**
- Private constructor prevents direct instantiation
- Static method `getInstance()` returns the unique instance
- Thread-safe using Meyers' Singleton (static local variable)
- Copy/move constructors and assignment operators are deleted

**Use Cases:**
- Database connection pools
- Logger instances
- Configuration managers
- Resource managers (file handles, etc.)

**Example:**
```cpp
Singleton& instance = Singleton::getInstance();
instance.doSomething();
```

---

### 2. Factory Pattern
**Location:** `creational/FactoryPattern/Factory.cpp`

**Purpose:** Provides an interface for creating objects without specifying their exact classes. The factory determines which class to instantiate based on input.

**Key Features:**
- Abstract base class (Product) defines the interface
- Concrete product classes implement the interface
- Factory class handles object creation logic
- Client doesn't need to know concrete classes

**Use Cases:**
- UI element creation (buttons, panels, dialogs)
- Database driver creation
- Network protocol handlers
- Document type creation

**Example:**
```cpp
std::shared_ptr<Shape> shape = ShapeFactory::createShape("circle");
shape->draw();
```

---

### 3. Builder Pattern
**Location:** `creational/BuilderPattern/Builder.cpp`

**Purpose:** Separates the construction of a complex object from its representation. Allows step-by-step construction and provides flexibility in the building process.

**Key Features:**
- Builder class constructs complex objects step-by-step
- Method chaining for readable fluent interface
- Supports optional components and partial construction
- Optional Director class can manage complex constructions
- Separates object construction from representation

**Use Cases:**
- Building complex objects with many optional parameters
- Constructing UI components with multiple configurations
- Creating HTTP requests with various options
- Configuration object creation
- Document building

**Example:**
```cpp
House& house = HouseBuilder()
    .buildFoundation()
    .buildWalls()
    .buildRoof()
    .getHouse();
```

---

## Pattern Comparison

| Pattern | Purpose | Complexity | Flexibility |
|---------|---------|-----------|------------|
| Singleton | Single instance access | Low | Low |
| Factory | Object creation | Low-Medium | Medium |
| Builder | Complex object construction | Medium | High |

---

## Compilation

Each pattern file can be compiled independently:

```bash
# Singleton
cd creational/SingletonPattern
g++ singleton.cpp -o singleton
./singleton

# Factory
cd creational/FactoryPattern
g++ Factory.cpp -o Factory
./Factory

# Builder
cd creational/BuilderPattern
g++ Builder.cpp -o Builder
./Builder
```

---

## Design Pattern Categories

- **Creational Patterns** - Focus on object creation (Singleton, Factory, Builder, Prototype, Abstract Factory)
- **Structural Patterns** - Compose objects into larger structures (Adapter, Bridge, Composite, Decorator, Facade, Proxy)
- **Behavioral Patterns** - Define communication between objects (Observer, Strategy, Command, Iterator, Mediator, Memento, State, Template Method, Visitor, Chain of Responsibility, Interpreter)