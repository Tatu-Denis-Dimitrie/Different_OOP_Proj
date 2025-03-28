# C++ Projects Overview

This repository contains three C++ projects, each demonstrating different object-oriented programming concepts. Below is a brief description of each project, including functionality and key features.

---

## 1. **Chocolate Box Inheritance**
### Description:
This project models different types of chocolate boxes using object-oriented programming principles such as inheritance and polymorphism. The base class `CutiePraline` is extended by three derived classes (`Lindt`, `Baravelli`, and `Rafaello`), each implementing its own `getVolume` function.

### Features:
- Implements a base class `CutiePraline` with aroma and origin attributes.
- Derived classes (`Lindt`, `Baravelli`, `Rafaello`) override the `getVolume()` method.
- Demonstrates polymorphism through the `toString()` method.
- Outputs details of chocolate boxes along with their volumes.

### How to Run:
Compile and execute the `main.cpp` file using a C++ compiler:
```sh
 g++ -o chocolate_box chocolate_box.cpp && ./chocolate_box
```

---

## 2. **Person and Employee Management**
### Description:
This project provides a class hierarchy to represent people, including employees and students. It showcases operator overloading, sorting, and dynamic memory handling.

### Features:
- `Persoana` base class with `nume`, `prenume`, and `varsta` attributes.
- `Angajat` (Employee) and `Student` (Student) derived classes with additional attributes (`salariu` and `medie`).
- Overloaded stream operators for user input and output.
- Sorting functionality based on name.
- Salary increment method for employees.

### How to Run:
Compile and execute the `main.cpp` file using a C++ compiler:
```sh
g++ -o person_management person_management.cpp && ./person_management
```

---

## 3. **Matrix Operations**
### Description:
This project implements a matrix class with various operations such as addition, subtraction, multiplication, transposition, and determinant calculation.

### Features:
- Dynamic memory allocation for matrices.
- Overloaded operators (`+`, `-`, `*`, `!`, `~`) for matrix operations.
- Calculates determinant and matrix power.
- Menu-driven user interface.

### How to Run:
Compile and execute the `main.cpp` file using a C++ compiler:
```sh
g++ -o matrix_operations matrix_operations.cpp && ./matrix_operations
```

---

## Requirements:
- A C++ compiler (GCC, Clang, or MSVC).
- Basic knowledge of C++ and object-oriented programming.

## Author:
This repository was created to demonstrate and upload object-oriented programming principles in C++.