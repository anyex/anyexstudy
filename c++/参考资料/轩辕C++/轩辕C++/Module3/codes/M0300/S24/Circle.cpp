/*
 * Circle.cpp
 * 
 *  Created on: 2009-12-25 上午09:37:05
 *      Author: kwarph
 */
#include <iostream>

#include "Circle.h"

Circle::Circle() :
	center(Point()), radii() {
}

Circle::~Circle() {
}

void Circle::draw() const {
	std::cout << "Circle::draw()\n";
}

double Circle::curvature() const {
	return 1.;
}
