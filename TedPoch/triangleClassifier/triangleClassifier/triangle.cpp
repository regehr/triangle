//
//  main.cpp
//  triangleClassifier
//
//  Created by Ted Pochmara on 1/9/18.
//  Copyright © 2018 Ted Pochmara. All rights reserved.
//
//  This solution inspired/adapted from one found at the following URL: https://www.geeksforgeeks.org/classify-a-triangle/

#include <iostream>
#include <cmath>

/**
 Establishes a data type for points of a triangle on a 2d graph
 */
struct Point {
    int x, y;
};

/**
 Establishes datatype for triangles that makes use of 'Point'
 */
struct Triangle {
    Point p1, p2, p3;
    int sideA, sideB, sideC;
};


/**
 Function that calculates the Euclidean length of a triangle's side using
 two end points (x, y)
 
 TODO: modify this or make another function to return normal space length

 @param a first end point that contains x/y coords
 @param b other end point with x/y coords
 @return length of line between the two input points
 */
int sideLength (Point a, Point b){
    return sqrt(pow((b.x - a.x),2) + pow((b.y - a.y),2));
}

/**
 Tests if the three points actually make up a triangle.
 If each of the points all contain the same x or y coordinate, then
 it can not be a triangle.

 @param tri a triangle object constructed from the input
 @return true if the triangle object is truly a triangle
 */
bool isTriangle (Triangle tri){
    return !((tri.p1.x == tri.p2.x) && (tri.p1.x == tri.p3.x)) ||
           ((tri.p1.y == tri.p2.y) && (tri.p1.y == tri.p3.y));
}

int main(int argc, const char * argv[]) {
    Point p1, p2, p3;
    int sides[3];
    while (!std::cin.eof()){
        std::cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
        Triangle tri {p1, p2, p3,0,0,0};
        if (isTriangle(tri)){
            sides[0] = sideLength(p1, p2);
            sides[1] = sideLength(p2, p3);
            sides[2] = sideLength(p3, p1);
            std::sort(sides, sides + 3);
            tri.sideA = sides[0];
            tri.sideB = sides[1];
            tri.sideC = sides[2];
            
            if ((pow(tri.sideA, 2) + pow(tri.sideB, 2)) == pow(tri.sideC, 2)) {
                std::cout << "right" << std::endl;
            }
            else if ((tri.sideA == tri.sideB) || (tri.sideB == tri.sideC)){
                std::cout << "isosceles" << std::endl;
            }
            else if ((tri.sideA == tri.sideB) && (tri.sideB == tri.sideC)){
                std::cout << "equilateral" << std::endl;
            }
            else if ((pow(tri.sideA, 2) + pow(tri.sideB, 2)) < pow(tri.sideC, 2)){
                std::cout << "obtuse" << std::endl;
            }
            else if ((pow(tri.sideA, 2) + pow(tri.sideB, 2)) > pow(tri.sideC, 2)){
                std::cout << "acute" << std::endl;
            }
            else {
                std::cout << "scalene" << std::endl;
            }
        }
        else {
            std::cout << "degenerate" << std::endl;
        }
    }
    return 0;
}
