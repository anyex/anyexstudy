/*
 * Main.cpp
 * 
 *  Created on: 2009-12-25 上午09:47:38
 *      Author: kwarph
 */

#include <iostream>

#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

void testStep24(Shape* s) {
	s->draw();
}

int main() {
	Circle c;
	Rectangle r;
	Triangle t;

//	Shape s;

	testStep24(&c);
	testStep24(&r);
	testStep24(&t);
}
