#include "vector.h"

Vector::Vector()
    : data(nullptr),
      sz(0),
      cap(0)
{}

Vector::Vector(size_t n)
    : data(new int[n]()),
      sz(n),
      cap(n)
{}

Vector::Vector(const Vector& other)
    : data(new int[other.cap]),
      sz(other.sz),
      cap(other.cap) {
    for (size_t i = 0; i < sz; i++) {
        data[i] = other.data[i];
    }
}

Vector& Vector::operator=(const Vector& other) {
    if (this == &other) {
        return *this;
    }

    delete[] data;

    data = new int[other.cap];
    sz = other.sz;
    cap = other.cap;

    for (size_t i = 0; i < sz; i++){
        data[i] = other.data[i];
    }

    return *this;
}

Vector::~Vector() {
    delete[] data;
}

void Vector::resize_capacity(size_t new_cap) {
    int* new_data = new int[new_cap];

    for (size_t i = 0; i < sz; i++) {
        new_data[i] = data[i];
    }

    delete[] data;

    data = new_data;
    cap = new_cap;
}

void Vector::push_back(int value) {
    if (sz == cap) {
        size_t new_cap = (cap == 0) ? 1 : cap * 2;  // Duplicar la capacidad

        resize_capacity(new_cap);
    }

    data[sz] = value;
    sz++;
}

void Vector::pop_back() {
    if (sz > 0){
        sz--;
    }
}

void Vector::clear() {
    sz = 0;
}

bool Vector::empty() const {
    return sz == 0;
}

size_t Vector::size() const {
    return sz;
}

size_t Vector::capacity() const {
    return cap;
}

int& Vector::operator[](size_t index) {
    return data[index];
}

const int& Vector::operator[](size_t index) const {
    return data[index];
}

int& Vector::front() {
    return data[0];
}
    
const int& Vector::front() const {
    return data[0];
}

int& Vector::back() {
    return data[sz - 1];
}

const int& Vector::back() const {
    return data[sz - 1];
}

int& Vector::at(size_t index) {
    if (index >= sz) {
        throw std::out_of_range("Indice fuera de rango");
    }

    return data[index];
}

const int& Vector::at(size_t index) const {
    if (index >= sz) {
        throw std::out_of_range("Indice fuera de rango");
    }

    return data[index];
}