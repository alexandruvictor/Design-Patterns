# Behavioral Design Patterns (C++)

This directory contains implementations of common Behavioral Design Patterns in C++.

## Overview

Behavioral patterns are concerned with algorithms and the assignment of responsibilities between objects. They help make interactions between objects more flexible and easier to maintain.

## Implemented Patterns

- Observer
  - Location: `BehavioralDesignPatterns/ObserverPattern/Observer.cpp`
  - Purpose: Define a one-to-many dependency so that when one object (Subject) changes state, all its dependents (Observers) are notified and updated automatically.
  - Example: `Subject` manages observers and notifies them when its state changes.

- Strategy
  - Location: `BehavioralDesignPatterns/StrategyPattern/Strategy.cpp`
  - Purpose: Define a family of algorithms, encapsulate each one, and make them interchangeable. Strategy lets the algorithm vary independently from clients that use it.
  - Example: `Context` accepts different `Strategy` implementations (Add, Subtract, Multiply).

## How to build & run

Each example is a single C++ source file that can be compiled and run independently. From the repository root use PowerShell (or any shell with a C++ compiler on PATH):

```powershell
# Observer
cd "Design-Patterns/BehavioralDesignPatterns/ObserverPattern"
g++ Observer.cpp -o Observer
.\Observer.exe

# Strategy
cd "..\StrategyPattern"
g++ Strategy.cpp -o Strategy
.\Strategy.exe
```

If `g++` isn't available, compile with MSVC (`cl`) or `clang++` and adapt commands accordingly.

## Formatting & tooling

This workspace includes a `.clang-format` and VS Code workspace settings to enable auto-format on save. Install `clang-format` or the Microsoft C/C++ extension in VS Code and restart the editor to enable formatting.

## Next steps

If you want, I can:
- Split each example into header/source files
- Add a CMakeLists.txt to build all examples
- Add unit tests or more behavioral patterns (Command, Iterator, Mediator, State, etc.)

Tell me which option you'd like next.
