# University Management System (C++)

## Overview
This repository contains a backend University Management System built in C++ for Assignments 4 and 5. The system dynamically manages a university population of up to 5,000 students, 100 professors, and 200 courses using Object-Oriented Programming principles, specifically focusing on **polymorphism**, **file I/O streams**, **exception handling**, and **operator overloading**.

## Class Architecture
The system is built on a robust inheritance hierarchy managed by a central `dataManager` class:

* **Central Manager:** `dataManager` (Manages arrays of polymorphic pointers to prevent object slicing).
* **Base Classes:** `person`, `course`, `courseRegistration`, `date`.
* **Inheritance Trees:**
  * `person` ➔ `student` ➔ `undergraduateStudent` / `graduateStudent`
  * `person` ➔ `professor` ➔ `FullTimeProfessor` / `PartTimeProfessor`

## Key Features & OOP Concepts Demonstrated
* **Dynamic Polymorphism:** The `dataManager` utilizes arrays of base class pointers (`student*`, `professor*`) to store derived objects. Virtual functions (like `print()`) cascade through the inheritance tree to output the correct specialized data.
* **File I/O Processing :** The system can persistently save and retrieve student records to/from a text file (e.g., `students.txt`) using `ifstream` and `ofstream` with `ios::app` mode.
* **Operator Overloading :** 
  * Overloaded stream insertion `<<` operators format polymorphic object data for clean console output and text file writing.
  * Overloaded `>` comparison operators within the `date` class handle deadline and graduation logic.
* **Robust Exception Handling (Assignment 5):** Risky operations, such as searching for a missing file or an unregistered student ID, are wrapped in `try/catch` blocks. Standard exceptions (`std::runtime_error`) gracefully catch errors, display warnings, and terminate the program safely (`return 1`) when a fatal missing file error occurs.

## How to Compile and Run
1. Ensure you have a standard C++ compiler (like GCC/G++) installed.
2. Open your terminal and navigate to the project directory.
3. Compile all `.cpp` files together:
   ```bash
   g++ *.cpp -o UniSystem
