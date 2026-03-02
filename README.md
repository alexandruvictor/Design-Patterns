# Design Patterns in C++

A comprehensive collection of Design Pattern implementations in C++.

Directory layout (implemented examples):

- `CreationalDesignPatterns/`
  - `SingletonPattern/Singleton.cpp`
  - `FactoryPattern/Factory.cpp`
  - `BuilderPattern/Builder.cpp`

- `StructuralDesignPatterns/`
  - `DecoratorPattern/Decorator.cpp`
  - `AdapterPattern/Adapter.cpp`
  - `ProxyPattern/Proxy.cpp`

- `BehavioralDesignPatterns/`
  - `ObserverPattern/Observer.cpp`
  - `StrategyPattern/Strategy.cpp`

Summary of categories

- Creational Patterns: control object creation (e.g., Singleton, Factory, Builder)
- Structural Patterns: compose objects and add responsibilities (e.g., Adapter, Decorator, Proxy)
- Behavioral Patterns: manage algorithms and object interactions (e.g., Observer, Strategy)

How to build

Each example is a single-file demo that can be compiled independently. From the repository root (PowerShell):

```powershell
cd "Design-Patterns\CreationalDesignPatterns\SingletonPattern"
g++ Singleton.cpp -o Singleton
.\Singleton.exe

cd "..\FactoryPattern"
g++ Factory.cpp -o Factory
.\Factory.exe

cd "..\..\StructuralDesignPatterns\DecoratorPattern"
g++ Decorator.cpp -o Decorator
.\Decorator.exe

cd "..\AdapterPattern"
g++ Adapter.cpp -o Adapter
.\Adapter.exe

cd "..\ProxyPattern"
g++ Proxy.cpp -o Proxy
.\Proxy.exe

cd "..\..\BehavioralDesignPatterns\ObserverPattern"
g++ Observer.cpp -o Observer
.\Observer.exe

cd "..\StrategyPattern"
g++ Strategy.cpp -o Strategy
.\Strategy.exe
```

Notes

- The project includes a workspace `.clang-format` and `.vscode/settings.json` to enable automatic formatting in VS Code (install `clang-format` and the Microsoft C/C++ extension).
- Examples are intentionally simple; if you want, I can split code into headers/sources, add a `CMakeLists.txt`, or add more patterns.

Enjoy exploring the patterns — tell me if you'd like a build script or CMake support added.

## Design Pattern Categories

- **Creational Patterns** - Focus on object creation (Singleton, Factory, Builder, Prototype, Abstract Factory)
- **Structural Patterns** - Compose objects into larger structures (Adapter, Bridge, Composite, Decorator, Facade, Proxy)
- **Behavioral Patterns** - Define communication between objects (Observer, Strategy, Command, Iterator, Mediator, Memento, State, Template Method, Visitor, Chain of Responsibility, Interpreter)