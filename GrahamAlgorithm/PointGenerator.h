//
//  PointGenerator.h
//  GrahamAlgorithm
//
//  Created by Michal Moskala on 13/10/14.
//  Copyright (c) 2014 Michal Moskala. All rights reserved.
//

#ifndef __GrahamAlgorithm__PointGenerator__
#define __GrahamAlgorithm__PointGenerator__

#include <stdio.h>
#include <vector>
#include "Point.h"

using namespace std;

class PointGenerator {
private:
	int amount;
public:
	PointGenerator(int amount);
	vector<Point> generate();
};

#endif /* defined(__GrahamAlgorithm__PointGenerator__) */
