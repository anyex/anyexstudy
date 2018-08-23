/*
 * Array.cpp
 *
 *  Created on: 2010-1-26
 *      Author: kwarph
 */

#include <stdexcept>
#include <cstring>

#include "Array.h"

template<typename T>
Array<T>::Array(const int& capcity) :
    _size(0), _capacity(capcity) {
    items = new T[_capacity];
}

template<typename T>
Array<T>::Array(const Array& other) :
    _size(other._size), _capacity(other._capacity) {
    items = new T[_capacity];
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    _size = other._size;
    _capacity = other._capacity;
    delete[] items;
    items = new T[_capacity];
    std::memcpy(items, other.items, _capacity);

    return *this;
}

template<typename T>
Array<T>::~Array() {
    if (_size)
        delete[] items;
}

template<typename T>
typename Array<T>::iterator Array<T>::begin() {
    return &items[0];
}

template<typename T>
typename Array<T>::const_iterator Array<T>::begin() const {
    return &items[0];
}

template<typename T>
typename Array<T>::iterator Array<T>::end() {
    return &items[_size - 1] + 1;
}

template<typename T>
typename Array<T>::const_iterator Array<T>::end() const {
    return &items[_size - 1] + 1;
}

template<typename T>
T Array<T>::operator[](const int& index) const {
    if (index < 0 || _size <= index)
        throw std::out_of_range("Array<T>::operator[](const int&) const");
    return items[index];
}

template<typename T>
T& Array<T>::operator[](const int& index) {
    if (index < 0 || _size <= index)
        throw std::out_of_range("Array<T>::operator[](const int&) const");
    return items[index];
}

template<typename T>
void Array<T>::insert(const int& index, const T& value) {
    if (index < 0 || _size <= index)
        throw std::out_of_range("Array<T>::insert(const int&, const int&)");

    if (RESERVED_SIZE + 1 != _capacity - _size) {
        for (int i = _size; i > index; --i)
            items[i] = items[i - 1];
        items[index] = value;
    } else {
        _capacity += DEFAUL_CAP;
        int* tmp = new T[_capacity];

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

template<typename T>
void Array<T>::append(const T& value) {
    if (RESERVED_SIZE + 1 != _capacity - _size) {
        items[_size] = value;
    } else {
        _capacity += DEFAUL_CAP;
        int* tmp = new T[_capacity];

        for (int i = 0; i < _size; ++i)
            tmp[i] = items[i];

        tmp[_size] = value;

        delete[] items;
        items = tmp;
    }

    ++_size;
}

template<typename T>
void Array<T>::remove(const int& index) {
    if (index < 0 || _size <= index)
        throw std::out_of_range("Array<T>::remove(const int&)");

    --_size;
    if (index != _size)
        for (int i = index; i < _size; ++i)
            items[i] = items[i + 1];
}

template<typename T>
int Array<T>::size() const {
    return _size;
}

template<typename T>
int Array<T>::capacity() const {
    return _capacity;
}

template<typename T>
bool Array<T>::empty() const {
    return 0 == _size;
}
