# Structural Design Patterns (C++)

This directory contains implementations of common Structural Design Patterns in C++.

## Overview

Structural patterns are concerned with composing classes and objects to form larger structures while keeping these structures flexible and efficient.

This workspace includes simple, self-contained examples demonstrating the core idea of each pattern plus a small `main()` demo.

## Implemented Patterns

- Decorator
  - Location: `StructuralDesignPatterns/DecoratorPattern/Decorator.cpp`
  - Purpose: Attach additional responsibilities to an object dynamically. Demonstrates wrapping a `Beverage` (e.g., `Coffee`) with decorators such as `MilkDecorator` and `SugarDecorator` to alter description and cost.

- Adapter
  - Location: `StructuralDesignPatterns/AdapterPattern/Adapter.cpp`
  - Purpose: Convert the interface of an existing class (`Adaptee`) into the interface expected by the client (`Target`). Shows an object adapter that translates `request()` to `specificRequest()`.

- Proxy
  - Location: `StructuralDesignPatterns/ProxyPattern/Proxy.cpp`
  - Purpose: Provide a surrogate or placeholder for another object to control access, add lazy loading, caching, or access control. Includes `ProxyImage` that lazily creates and reuses a `RealImage`.

## How to build & run

Each example is a single C++ source file that can be compiled and run independently. From the repository root use PowerShell (or any shell with a C++ compiler on PATH):

```powershell
# Decorator
cd "Design-Patterns/StructuralDesignPatterns/DecoratorPattern"
# On Windows using MinGW/GCC
g++ Decorator.cpp -o Decorator
.\Decorator.exe

# Adapter
cd "..\AdapterPattern"
g++ Adapter.cpp -o Adapter
.\Adapter.exe

# Proxy
cd "..\ProxyPattern"
g++ Proxy.cpp -o Proxy
.\Proxy.exe
```

If `g++` isn't available, you can compile with MSVC (`cl`) or `clang++` — adapt the commands accordingly.

## Formatting & tooling

This workspace includes a `.clang-format` and VS Code workspace settings to enable auto-format on save. Install `clang-format` or the Microsoft C/C++ extension in VS Code and restart the editor to enable formatting.

## Notes

- Each example is intentionally small and focused for learning; production code may require additional error handling and separation into headers/source files.
- If you want, I can split each implementation into header/source files and add a small test harness or CMake project.
