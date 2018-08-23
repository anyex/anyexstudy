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
    //    for (int i = 0; i < _size; ++i)
    //        items[i] = other.items[i];
    std::memcpy(items, other.items, _size * sizeof(int));
}

Array& Array::operator=(const Array& other) {
    if (&other != this) {
        _size = other._size;
        _capacity = other._capacity;
        delete[] items;
        items = new int[_capacity];
        std::memcpy(items, other.items, _size * sizeof(int));
    }
    return *this;
}

Array::~Array() {
    delete[] items;
}

Array::iterator Array::begin() {
    return items;
}

Array::const_iterator Array::begin() const {
    return items;
}

Array::iterator Array::end() {
    return items + _size;
}

Array::const_iterator Array::end() const {
    return items + _size;
}

const int& Array::operator[](const int& index) const {
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

    if (_size < _capacity) {
        std::memmove(items + (index + 1), items + index, (_size - index)
                * sizeof(int));
        items[index] = value;
    } else {
        _capacity *= 2;
        int* tmp = new int[_capacity];
        std::memcpy(tmp, items, index * sizeof(int));

        std::memcpy(tmp + (index + 1), items + index, (_size - index)
                * sizeof(int));

        tmp[index] = value;

        delete[] items;
        items = tmp;
    }

    ++_size;
}

void Array::append(const int& value) {
    if (_size < _capacity) {
        items[_size] = value;
    } else {
        _capacity *= 2;
        int* tmp = new int[_capacity];

        std::memcpy(tmp, items, _size * sizeof(int));
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
    if (index != _size) // _size already decreased.
        std::memmove(items + index, items + (index + 1), (_size - index)
                * sizeof(int));
//    for (int i = index; i < _size; ++i)
//        items[i] = items[i + 1];
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
