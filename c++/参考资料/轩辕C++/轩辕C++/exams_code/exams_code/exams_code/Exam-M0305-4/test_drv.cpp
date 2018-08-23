/*
 * test_drv.cpp
 *
 *  Created on: Jan 6, 2011 7:31:18 PM
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 */

#include "print_array.h"

bool greatThan5(const int& i) {
    return i > 5;
}

bool lessThan5(const int& i) {
    return i < 5;
}

bool equals5(const int& i) {
    return i == 5;
}

bool isOdd(const int& i) {
    return i & 1;
}

int main() {
    const int N = 8;
    int a[N] = { 12, 3, 5, 28, -2, 23, 5, 2 };

    printArray(a, a + N, isOdd, "Odd numbers: ");

    printArray(a, a + N, greatThan5, "Numbers great than 5: ");

    printArray(a, a + N, lessThan5, "Numbers less than 5: ");

    printArray(a, a + N, equals5, "Numbers equals 5: ");
}
