/*
 * SmartPtr.h
 *
 *  Created on: 2010-1-25
 *      Author: kwarph
 */

#ifndef SMARTPTR_H_
#define SMARTPTR_H_

class A {
    int k;
public:
    explicit A(const int& i);
    ~A();
    int getK() const;
};

class SmartPtr {
    A* ptr;
    int* refCount;
public:
    explicit SmartPtr(A* aptr);

    SmartPtr(const SmartPtr& other);
    SmartPtr& operator=(const SmartPtr& other);

    A* operator->();
    A& operator*();

    ~SmartPtr();
};

#endif /* SMARTPTR_H_ */
