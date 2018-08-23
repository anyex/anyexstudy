/*
 * Triangle.h
 * 
 *  Created on: 2009-12-25 上午10:28:54
 *      Author: kwarph
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "Shape.h"
#include "Point.h"
/*
 *
 */
class Triangle : public Shape {
public:
	Triangle();
	virtual ~Triangle();

	virtual void draw() const;

private:
	Point v1, v2, v3;
};

#endif /* TRIANGLE_H_ */
