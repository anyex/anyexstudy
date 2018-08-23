/*
 * Main.cpp
 * 
 *  Created on: 2009-12-25 上午09:47:38
 *      Author: kwarph
 */

#include <iostream>

#include "Circle.h"
#include "Rectangle.h"
#include "Shape.h"

void testStep22(Shape* s) {
	s->draw();
}

int main() {
	Circle c;
	Rectangle r;

	testStep22(&c);
	testStep22(&r);
}
