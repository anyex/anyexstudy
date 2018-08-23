/*
 * print_array.h
 *
 *  Created on: Jan 6, 2011 7:30:37 PM
 *      Author: kwarph
 *        Mail: kwarph@gmail.com
 */

#ifndef PRINT_ARRAY_H_
#define PRINT_ARRAY_H_

typedef bool (*isRight) (const int&);

/*
 * @brief Iterations an array, print it's elements meet certain condition,
 *        The condition is given by the function f.
 * @param begin - The position begin iteration.
 * @param end - The position end iteration.
 * @param f - The predicate.
 * @param hint - Describes the function what to do.
 */
void printArray(int* begin, int* end, isRight f, const char* hint);


#endif /* PRINT_ARRAY_H_ */
