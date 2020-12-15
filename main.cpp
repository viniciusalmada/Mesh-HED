#include <iostream>
#include <array>
#include <vector>
#include "Point.h"
#include "Mesh.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    std::vector<Point> points{
            {0.0, 0.0},
            {1.0, 0.0},
            {1.0, 1.0},
            {0.0, 0.1}
    };

    Mesh mesh{points};

    return 0;
}
