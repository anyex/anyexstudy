/*
 * Array.h
 *
 *  Created on: 2010-1-26
 *      Author: kwarph
 */

#ifndef ARRAY_H_
#define ARRAY_H_

class Array {
    int _size;
    int _capacity;
    int* items;
public:
    typedef int* iterator;
    typedef const int* const_iterator;

    enum { DEFAUL_CAP = 16 };

    explicit Array(const int& capcity = DEFAUL_CAP);
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();

    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;

    const int& operator[](const int& index) const;
    int& operator[](const int& index);

    void insert(const int& index, const int& value);
    void remove(const int& index);
    void append(const int& value);

    int size() const;
    int capacity() const;
    bool empty() const;

};

#endif /* ARRAY_H_ */
