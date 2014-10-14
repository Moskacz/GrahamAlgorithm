//
//  PointGenerator.cpp
//  GrahamAlgorithm
//
//  Created by Michal Moskala on 13/10/14.
//  Copyright (c) 2014 Michal Moskala. All rights reserved.
//

#include "PointGenerator.h"

PointGenerator::PointGenerator(int amount) {
	this->amount = amount;
}


list<Point> PointGenerator::generate() {
	list<Point> pointList = list<Point>();
	int i = 0;
	while (i < amount) {
		pointList.push_back(Point(rand() % 10, rand() % 10));
		i++;
	}
	return pointList;
}
