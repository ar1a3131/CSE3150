# Vector Operations and Distance Calculation

This project demonstrates the implementation of basic 2D vector operations and the calculation of distances between vectors. It utilizes custom data structures for representing vectors and their distances and provides utility functions for operations such as dot product and cosine distance calculation.

## Compiling Instructions 

Ensure you have a C++ compiler and make (or a similar build system) installed on your system. The project uses the following source files: `vector2D_operations.cpp`, `main.cpp`, and `unit_test.cpp` for unit testing.

### Compiling the Main Program

To compile the main program, run the following command in the terminal:

```bash
g++ -o vector_operations vector2D_operations.cpp main.cpp -std=c++11
```

```bash
g++ -o unit_tests unit_test.cpp vector2D_operations.cpp -std=c++11 -I. -D DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
```

```bash
./unit_tests
```
