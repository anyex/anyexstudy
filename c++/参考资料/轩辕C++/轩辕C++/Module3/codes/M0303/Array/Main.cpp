/*
 * Main.cpp
 *
 *  Created on: 2010-1-26
 *      Author: kwarph
 */

#include <iostream>
#include <stdexcept>
#include "Array.h"

using namespace std;

void print(const Array& a) {
    Array::const_iterator it = a.begin();
    for (; it != a.end(); ++it)
        cout << *it << ' ';
    cout << endl;
}

int main() {
    Array a(12);
    a.append(12);
    a.append(232);
    a.append(72);
    a.append(19);
    a.append(166);
    a.append(72);
    a.append(133);
    a.append(199);
    print(a);
    try {
        a.remove(a.size() - 1);
        print(a);
        a.remove(3);
        a.remove(4);
        print(a);
    } catch (out_of_range& e) {
        cout << e.what() << endl;
    }

    cout << a.capacity() << endl;

    //    a.insert(2, 289);
    //    print(a);
    //    a.insert(2, 567);
    //    print(a);
    //    a.insert(2, 326);
    //    print(a);
}
