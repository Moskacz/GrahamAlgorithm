//
//  Point.h
//  GrahamAlgorithm
//
//  Created by Michal Moskala on 13/10/14.
//  Copyright (c) 2014 Michal Moskala. All rights reserved.
//

#ifndef __GrahamAlgorithm__Point__
#define __GrahamAlgorithm__Point__

#include <stdio.h>
#include <iostream>

class Point {
private:
	double x;
	double y;
	double cosinusValue;
public:
	Point(double x, double y);
	double distanceToPoint(Point other);
	double getX() const;
	double getY() const;
	double getCosinus() const;
	void setCosinus(double value);
	friend std::ostream& operator<<(std::ostream& os, const Point& point);
};


#endif 


/* defined(__GrahamAlgorithm__Point__) */
