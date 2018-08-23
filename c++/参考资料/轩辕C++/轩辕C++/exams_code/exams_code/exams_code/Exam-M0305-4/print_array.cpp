/*
 * print_array.cpp
 *
 *  Created on: Jan 6, 2011 7:04:04 PM
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 */

#include <iostream>

#include "print_array.h"

void printArray(int* begin, int* end, isRight f, const char* hint) {
    std::cout << hint;
    for (; begin != end; ++begin)
        if (f(*begin))
            std::cout << *begin << ' ';
    std::cout << '\n';
}
