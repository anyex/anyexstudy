/*
 * Shape.cpp
 * 
 *  Created on: 2009-12-25 上午10:06:10
 *      Author: kwarph
 */
#include <iostream>

#include "Shape.h"

Shape::Shape() {
}

Shape::~Shape() {
}

void Shape::draw() const {
	std::cout << "Shape::draw()\n";
}
