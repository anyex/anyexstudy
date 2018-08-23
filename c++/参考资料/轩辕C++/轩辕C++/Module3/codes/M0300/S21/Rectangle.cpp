/*
 * Rectangle.cpp
 * 
 *  Created on: 2009-12-25 上午09:37:14
 *      Author: kwarph
 */
#include <iostream>

#include "Rectangle.h"

Rectangle::Rectangle() :
	length(), width() {
}

Rectangle::~Rectangle() {
}

void Rectangle::draw() const {
	std::cout << "Rectangle::draw()\n";
}

void Rectangle::rotate(const double& angle) {
	std::cout << "Rectangle::rotate() with angle: " << angle << "\n";
}
