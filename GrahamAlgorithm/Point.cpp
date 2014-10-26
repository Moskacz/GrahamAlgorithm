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
	this->cosinusValue = 0;
	this->distanceToStartingPoint = 0;
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
	return this->y;
}

double Point::getCosinus() const {
	return this->cosinusValue;
}

double Point::getDistanceToStartingPoint() const {
	return this->distanceToStartingPoint;
}

void Point::setCosinus(double value) {
	this->cosinusValue = value;
}

void Point::setDistanceToStartingPoint(double value) {
	this->distanceToStartingPoint = value;
}

std::ostream& operator<<(std::ostream& outputStream, const Point& object) {
	outputStream << "{" << object.getX() << "," << object.getY() << "} cos: " << object.getCosinus();
	return outputStream;
}

bool Point::operator==(const Point &another) {
	return this->x == another.getX() && this->y == another.getY();
}
