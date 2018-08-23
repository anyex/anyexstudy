/*
 * Main.cpp
 *
 *  Created on: 2010-1-26
 *      Author: kwarph
 */

#include <iostream>
#include <stdexcept>
#include <iterator>
#include "Array.h"

using namespace std;

int main() {
    Array a(5);
    a.append(13);
    a.append(16);
    a.append(11);
    a.insert(2, 1000);
    a.insert(3, 1002);
    a.append(3);
    a.append(8);
    cout << a.size() << endl;
    cout << a.capacity() << endl;
    a.append(8);
    a.append(6);

//    cout << a.size() << endl;
//    cout << a.capacity() << endl;

    copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
    cout << '\n';

    Array a2(a);
    copy(a2.begin(), a2.end(), ostream_iterator<int>(cout, " "));
    cout << '\n';
}
