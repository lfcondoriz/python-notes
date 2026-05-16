#pragma once

#include <cstddef>
#include <stdexcept>

class Vector {
private:
    int* data;  // Buffer dinámico para almacenar los elementos
    size_t sz;  // Cantidad de elementos válidos.
    size_t cap; // Memoria reservada para futuras insercione

    void resize_capacity(size_t new_cap);

public:
    // Constructor vacío
    Vector();

    // Constructor con tamaño inicial
    Vector(size_t n);

    // Copy constructor
    Vector(const Vector& other);

    // Copy assignment
    Vector& operator=(const Vector& other);

    // Destructor
    ~Vector();

    void push_back(int value);
    void pop_back();

    void clear();

    bool empty() const;

    size_t size() const;
    size_t capacity() const;

    int& operator[](size_t index);
    const int& operator[](size_t index) const;

    int& front();
    const int& front() const;

    int& back();
    const int& back() const;

    int& at(size_t index);
    const int& at(size_t index) const;
};