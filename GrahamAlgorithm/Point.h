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
	double distanceToStartingPoint;
public:
	Point(double x, double y);
	double distanceToPoint(Point other);
	double getX() const;
	double getY() const;
	double getCosinus() const;
	double getDistanceToStartingPoint() const;
	void setCosinus(double value);
	void setDistanceToStartingPoint(double value);
	friend std::ostream& operator<<(std::ostream& os, const Point& point);
	bool operator==(const Point& another);
};


#endif 


/* defined(__GrahamAlgorithm__Point__) */
