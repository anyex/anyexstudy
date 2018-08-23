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

void testStep25(Shape* s) {
	s->draw();

	Rectangle* r = dynamic_cast<Rectangle*> (s);
	if (r != 0)
		r->rotated(1.58);

	Circle* c = dynamic_cast<Circle*> (s);
	if (c != 0)
		std::cout << "curvature of c: " << c->curvature() << std::endl;
}

int main() {
	Circle c;
	Rectangle r;
	Triangle t;

	//	Shape s;

	testStep25(&c);
	testStep25(&r);
	testStep25(&t);
}
