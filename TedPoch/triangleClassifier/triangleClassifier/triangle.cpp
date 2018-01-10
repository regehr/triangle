//
//  main.cpp
//  triangleClassifier
//
//  Created by Ted Pochmara on 1/9/18.
//  Copyright © 2018 Ted Pochmara. All rights reserved.
//

#include <iostream>
#include <cmath>


/**
 Establishes a data type for points of a triangle on a 2d graph
 */
struct Point {
    int x, y;
};

/**
 Function that calculates the length of a triangle's side using
 two end points (x, y)

 @param a first end point that contains x/y coords
 @param b other end point with x/y coords
 @return length of line between the two input points
 */
int sideLength (Point a, Point b){
    return sqrt(pow((b.x - a.x),2) + pow((b.y - a.y),2));
}

/**
 Function tests for characteristics of a triangle that define
 it in terms of its component angles

 @param sideA <#sideA description#>
 @param sideB <#sideB description#>
 @param sideC <#sideC description#>
 @return <#return value description#>
 */
string angleClasser (int sideA, int sideB, int sideC){
    
}

/**
 Function tests for characteristics of a triangle that define
 it in terms of its component sides

 @param sideA <#sideA description#>
 @param sideB <#sideB description#>
 @param sideC <#sideC description#>
 @return <#return value description#>
 */
string sideClasser (int sideA, int sideB, int sideC){
    if (
}

int main(int argc, const char * argv[]) {
    
    
    return 0;
}


//right triangle: one 90 degree angle
//isoceles: two sides same length
//equilateral: all sides same length
//obtuse: one angle > 90
//acute: one angle < 90
//scalene: none of the above
//degenerate: not a triangle
//
//For every set of three points, print one of the above
//x1 y1 x2 y2 x3 y3
//coordinates are integers 0-100
//coordinates are separated by single spaces
//input is on stdin
//output is on stdout
//input is zero or more lines, each containing a triangle
//behavior is undefined if input is malformed
//write 7 test cases
//
//pseudo
//
//take the input for a triangle
//populate each point into a struct
//need a function to find the length of a side
//run those sides through a classification functions for sides and angles
//
//
