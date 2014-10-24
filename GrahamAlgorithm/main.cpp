//
//  main.cpp
//  GrahamAlgorithm
//
//  Created by Michal Moskala on 13/10/14.
//  Copyright (c) 2014 Michal Moskala. All rights reserved.
//

#include <iostream>
#include "Point.h"
#include "PointGenerator.h"
#include <stdlib.h>
#include <math.h>
#include <stack>
#include <list>


using namespace std;

struct coordinatesSorter {
	inline bool operator() (const Point& lhs, const Point& rhs) {
		if (lhs.getY() == rhs.getY()) {
			return lhs.getX() <= rhs.getX();
		}
		return lhs.getY() < rhs.getY();
	}
};

struct cosinusValueSorter {
	inline bool operator() (const Point& lhs, const Point& rhs) {
		return lhs.getCosinus() > rhs.getCosinus();
	}
};

void calculateCosinus(Point& startingPoint, Point& point) {
	double hypotenuse = startingPoint.distanceToPoint(point);
	
	if (hypotenuse == 0) {
		point.setCosinus(-1);
		return;
	}
	
	double cathetus = fabs(point.getX() - startingPoint.getX());
	double cosinus = cathetus / hypotenuse;
	point.setCosinus(cosinus);
	
	
	if (point.getX() < startingPoint.getX()) {
		double sinVal = fabs(point.getX() - startingPoint.getX()) / hypotenuse;
		point.setCosinus(-sinVal);
	}
}

void printVector(vector<Point> aVector) {
	for (vector<Point>::iterator iterator = aVector.begin(); iterator != aVector.end(); iterator++) {
		cout << *iterator << endl;
	}
}

double determinant(Point firstPoint, Point secondPoint, Point thirdPoint) {
	double a = firstPoint.getX() * secondPoint.getY()  + firstPoint.getY() * thirdPoint.getX() + secondPoint.getX() * thirdPoint.getY();
	double b = thirdPoint.getX() * secondPoint.getY() + firstPoint.getX() * thirdPoint.getY() + secondPoint.getX() * firstPoint.getY();
	return a - b;
}

bool isTurningRight(stack<Point> stack, Point startingPoint) {
	Point first = stack.top();
	stack.pop();
	Point second = stack.top();
	stack.push(first);
	
	return determinant(second, first, startingPoint) < 0;
}

int main(int argc, const char * argv[]) {
	
	PointGenerator generator = PointGenerator(10);
	vector<Point> pointVector = generator.generate();
	
	sort(pointVector.begin(), pointVector.end(), coordinatesSorter());
	
	for(vector<Point>::iterator iterator = pointVector.begin(); iterator != pointVector.end(); iterator++) {
		calculateCosinus(pointVector.front(), *iterator);
	}
	
	sort(pointVector.begin() + 1, pointVector.end(), cosinusValueSorter());
	printVector(pointVector);
	
	stack<Point> pointStack;
	pointStack.push(pointVector[0]);
	pointStack.push(pointVector[1]);
	pointStack.push(pointVector[2]);
	
	for(int index = 3; index < pointVector.size(); index++) {
		while (isTurningRight(pointStack, pointVector[index])) {
			pointStack.pop();
		}
		pointStack.push(pointVector[index]);
	}
	
	cout << "Rozwiazanie: " << endl;
	while (!pointStack.empty()) {
		cout << pointStack.top() << endl;
		pointStack.pop();
	}
	
	return 0; 
}












