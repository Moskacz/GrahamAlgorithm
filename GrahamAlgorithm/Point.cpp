//
//  Point.cpp
//  GrahamAlgorithm
//
//  Created by Michal Moskala on 13/10/14.
//  Copyright (c) 2014 Michal Moskala. All rights reserved.
//

#include "Point.h"
#include <math.h>
#include <iostream>

Point::Point(double x, double y) {
	this->x = x;
	this->y = y;
}

double Point::distanceToPoint(Point other) {
	double xDistance = this->x - other.x;
	double yDistance = this->y - other.y;
	return sqrt(pow(xDistance, 2) + pow(yDistance, 2));
}

double Point::getX() const {
	return this->x;
}

double Point::getY() const {
	return y;
}

double Point::getCosinus() const {
	return this->cosinusValue;
}

void Point::setCosinus(double value) {
	this->cosinusValue = value;
}

std::ostream& operator<<(std::ostream& outputStream, const Point& object) {
	outputStream << "x: " << object.getX() << " y: " << object.getY();
	return outputStream;
}
