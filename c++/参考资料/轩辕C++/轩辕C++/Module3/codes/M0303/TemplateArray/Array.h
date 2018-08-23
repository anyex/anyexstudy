/*
 * Array.h
 *
 *  Created on: 2010-1-26
 *      Author: kwarph
 */

#ifndef ARRAY_H_
#define ARRAY_H_

template<typename T>
class Array {
    int _size;
    int _capacity;
    T* items;
public:
    typedef T* iterator;
    typedef const T* const_iterator;

    enum {
        DEFAUL_CAP = 16
    };
    enum {
        RESERVED_SIZE = 5
    };

    explicit Array(const int& capcity = DEFAUL_CAP);
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();

    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;

    T operator[](const int& index) const;
    T& operator[](const int& index);

    void insert(const int& index, const T& value);
    void remove(const int& index);
    void append(const T& value);

    int size() const;
    int capacity() const;
    bool empty() const;

};

#include "Array.tcc"

#endif /* ARRAY_H_ */
