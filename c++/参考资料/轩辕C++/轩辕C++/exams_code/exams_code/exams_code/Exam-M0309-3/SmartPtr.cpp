/*
 * SmartPtr.cpp
 *
 *  Created on: 2010-1-25
 *      Author: kwarph
 */
#include <iostream>

#include "SmartPtr.h"

A::A(const int& i) :
    k(i) {
    std::cout << "A(" << k << ") created\n";
}

A::~A() {
    std::cout << "A(" << k << ") destroyed\n";
}

int A::getK() const {
    return k;
}

SmartPtr::SmartPtr(A* aptr) :
    ptr(aptr), refCount(new int(1)) {
    std::cout << "SmartPtr(A* aptr){" << ptr->getK() << "}--> ref: "
            << *refCount << "\n";
}

SmartPtr::SmartPtr(const SmartPtr& other) {
    refCount = other.refCount;
    ++*refCount;
    ptr = other.ptr;
    std::cout << "SmartPtr(const SmartPtr& other){" << ptr->getK()
            << "}--> ref: " << *refCount << "\n";
}

SmartPtr& SmartPtr::operator=(const SmartPtr& other) {
    --*refCount;// this->ptr will point to other A, decrement refCount first
    std::cout << "operator=(const SmartPtr& other){" << ptr->getK()
            << "}--> old ref: " << *refCount << "\n";
    if (0 == *refCount) {
        delete ptr;
        delete refCount;
    }

    refCount = other.refCount;
    ++*refCount;
    ptr = other.ptr;
    std::cout << "operator=(const SmartPtr& other){" << ptr->getK()
            << "}--> new ref: " << *refCount << "\n";

    return *this;
}

A* SmartPtr::operator->() {
    return ptr;
}

A& SmartPtr::operator*() {
    return *ptr;
}

SmartPtr::~SmartPtr() {
    --*refCount;
    std::cout << "~SmartPtr(){" << ptr->getK() << "}--> ref: " << *refCount
            << "\n";
    if (0 == *refCount) {
        delete ptr;
        delete refCount;
    }
}
