/*
 * Circle.h
 * 
 *  Created on: 2009-12-25 上午09:37:05
 *      Author: kwarph
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "Point.h"

/*
 *
 */
class Circle {
public:
	Circle();
	virtual ~Circle();

	void draw() const;
	double curvature() const;

private:
	Point center;
	double radii;
};

#endif /* CIRCLE_H_ */
