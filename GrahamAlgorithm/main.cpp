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
		return lhs.getCosinus() < rhs.getCosinus();
	}
};

void calculateCosinus(Point& startingPoint, Point& point) {
	//przeciwprostokatna
	double hypotenuse = point.distanceToPoint(startingPoint);
	// przyprostokątna
	double cathetus = fabs(point.getY() - startingPoint.getY());
	double cosinus = cathetus / hypotenuse;
	point.setCosinus(cosinus);
}

void printVector(vector<Point> aVector) {
	for (vector<Point>::iterator iterator = aVector.begin(); iterator != aVector.end(); iterator++) {
		cout << *iterator << endl;
	}
}

int main(int argc, const char * argv[]) {
	
	cout << "Hello, World!\n";
	
	PointGenerator generator = PointGenerator(10);
	vector<Point> pointVector = generator.generate();
	sort(pointVector.begin(), pointVector.end(), coordinatesSorter());
	
	Point startingPoint = pointVector.front();
	
	pointVector.erase(pointVector.begin());
	
	for(vector<Point>::iterator iterator = pointVector.begin(); iterator != pointVector.end(); iterator++) {
		calculateCosinus(startingPoint, *iterator);
	}
	
	sort(pointVector.begin(), pointVector.end(), cosinusValueSorter());
	printVector(pointVector);
	
	
	
	return 0; 
}
