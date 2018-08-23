/*
 * Shape.h
 * 
 *  Created on: 2009-12-25 上午10:06:10
 *      Author: kwarph
 */

#ifndef SHAPE_H_
#define SHAPE_H_

/*
 *
 */
class Shape {
public:
	Shape();
	virtual ~Shape();

	virtual void draw() const =0;
};

#endif /* SHAPE_H_ */
