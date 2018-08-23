/*
 * Array.cpp
 *
 *  Created on: 2010-1-26
 *      Author: kwarph
 */

#include <stdexcept>
#include <cstring>

#include "Array.h"

Array::Array(const int& capcity) :
    _size(0), _capacity(capcity) {
    items = new int[_capacity];
}

Array::Array(const Array& other) :
    _size(other._size), _capacity(other._capacity) {
    items = new int[_capacity];
}

Array& Array::operator=(const Array& other) {
    _size = other._size;
    _capacity = other._capacity;
    delete[] items;
    items = new int[_capacity];
    std::memcpy(items, other.items, _capacity);

    return *this;
}

Array::~Array() {
    if (_size)
        delete[] items;
}

Array::iterator Array::begin() {
    return &items[0];
}

Array::const_iterator Array::begin() const {
    return &items[0];
}

Array::iterator Array::end() {
    return &items[_size - 1] + 1;
}

Array::const_iterator Array::end() const {
    return &items[_size - 1] + 1;
}

int Array::operator[](const int& index) const {
    if (index < 0 || _size <= index)
        throw std::out_of_range("Array::operator[](const int&) const");
    return items[index];
}

int& Array::operator[](const int& index) {
    if (index < 0 || _size <= index)
        throw std::out_of_range("Array::operator[](const int&) const");
    return items[index];
}

void Array::insert(const int& index, const int& value) {
    if (index < 0 || _size <= index)
        throw std::out_of_range("Array::insert(const int&, const int&)");

    if (RESERVED_SIZE + 1 != _capacity - _size) {
        for (int i = _size; i > index; --i)
            items[i] = items[i - 1];
        items[index] = value;
    } else {
        _capacity += DEFAUL_CAP;
        int* tmp = new int[_capacity];

        for (int i = 0; i < index; ++i)
            tmp[i] = items[i];
        for (int j = index; j < _size; ++j)
            tmp[j + 1] = items[j];

        tmp[index] = value;

        delete[] items;
        items = tmp;
    }

    ++_size;
}

void Array::append(const int& value) {
    if (RESERVED_SIZE + 1 != _capacity - _size) {
        items[_size] = value;
    } else {
        _capacity += DEFAUL_CAP;
        int* tmp = new int[_capacity];

        for (int i = 0; i < _size; ++i)
            tmp[i] = items[i];

        tmp[_size] = value;

        delete[] items;
        items = tmp;
    }

    ++_size;
}

void Array::remove(const int& index) {
    if (index < 0 || _size <= index)
        throw std::out_of_range("Array::remove(const int&)");

    --_size;
    if (index != _size)
        for (int i = index; i < _size; ++i)
            items[i] = items[i + 1];
}

int Array::size() const {
    return _size;
}

int Array::capacity() const {
    return _capacity;
}

bool Array::empty() const {
    return 0 == _size;
}
