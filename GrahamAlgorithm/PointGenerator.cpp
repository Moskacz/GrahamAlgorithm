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

vector<Point> PointGenerator::generate() {
	vector<Point> pointVector = vector<Point>();
	int i = 0;
	while (i < amount) {
		pointVector.push_back(Point(rand() % 10, rand() % 10));
		i++;
	}
	return pointVector;
}
