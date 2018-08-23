/*
 * Main.cpp
 *
 *  Created on: 2010-1-25
 *      Author: kwarph
 */

#include <iostream>

#include "SmartPtr.h"

using namespace std;

int main() {
    SmartPtr ptr(new A(1));
    SmartPtr ptr2(ptr);
    cout << ptr2->getK() << endl;

    SmartPtr ptr3(new A(2));
    ptr2 = ptr3;
    cout << ptr2->getK() << endl;
}
