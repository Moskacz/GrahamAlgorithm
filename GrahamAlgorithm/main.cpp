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
#include <algorithm>

using namespace std;

struct coordinatesSorter {
	inline bool operator() (const Point& lhs, const Point& rhs) {
		if (lhs.getY() == rhs.getY()) {
			return lhs.getX() <= rhs.getX();
		}
		return lhs.getY() < rhs.getY();
	}
};

void calculateCosinus(Point& startingPoint, Point point) {
	
}

int main(int argc, const char * argv[]) {
	
	cout << "Hello, World!\n";
	
	PointGenerator generator = PointGenerator(10);
	vector<Point> pointVector = generator.generate();
	std::sort(pointVector.begin(), pointVector.end(), coordinatesSorter());
	
	Point startingPoint = pointVector.front();
	
	pointVector.erase(pointVector.begin());
	
	for(vector<Point>::iterator iterator = pointVector.begin(); iterator != pointVector.end(); iterator++) {
		
	}
	
	return 0; 
}
