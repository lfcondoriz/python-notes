#include <iostream>
#include "vector.h"

int main() {
    Vector v(5);

    std::cout << "size: " << v.size() << '\n';
    std::cout << "capacity: " << v.capacity() << '\n';

    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << '\n';
    }
}