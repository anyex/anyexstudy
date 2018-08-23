/*
 * Main.cpp
 *
 *  Created on: 2010-1-23
 *      Author: kwarph
 */
#include <iostream>
#include "Date.h"
using namespace std;

int main() {
    using namespace std;
    Date d(2010, 1, 20);
    cout << d.toString() << endl;

    d.set(15, Date::MONTH);
    cout << d.toString() << endl;

    d.addDay(-100);
    cout << d.toString() << endl;

    cout << Date::today().toString() << endl;
    Date d2(2010, 1, 35); // day 2010-1-35 ==>2010-02-04
    cout << d2 << endl; // 2010-02-04
    cout << Date::today().diff(d2) << endl;
}
