/*
 * Rectangle.h
 * 
 *  Created on: 2009-12-25 上午09:37:14
 *      Author: kwarph
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

/*
 *
 */
class Rectangle {
public:
	Rectangle();
	virtual ~Rectangle();

	void draw() const;
	void rotate(const double& angle);

private:
	double length, width;
};

#endif /* RECTANGLE_H_ */
