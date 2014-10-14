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

using namespace std;

int main(int argc, const char * argv[]) {
	
	cout << "Hello, World!\n";
	
	PointGenerator generator = PointGenerator(10);
	list<Point> pointList = generator.generate();
	
	for (list<Point>::iterator iter = pointList.begin(); iter != pointList.end(); iter++) {
		cout << *iter << endl;
	}
	
	
	
	return 0; 
}
