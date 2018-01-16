//
//  main.cpp
//  SpecifyTriangle
//
//  Created by Eric Williams on 1/9/18.
//  Copyright © 2018 Eric Williams. All rights reserved.
//

#include <iostream>
#include <math.h>

/*
 right triangle: one 90 degree angle
 equilateral: all sides same length
 isosceles: two sides same length
 obtuse: one angle >90
 acute: all angles <90
 scalene: none of the above -- unreachable condition given all the other
 conditions with single classification degenerate: not a triangle
 
 x1 y1 x2 y2 x3 y3
 
 coordinates are integers in [0..100]
 
 coordinates are separated by spaces
 
 input is on stdin
 
 output is on stdout
 
 input is zero or more lines, each containing a triangle
 
 behavior is undefined if input is malformed
 
 
 
 assignment: write a triangle classifier in C++
 
 write 7 test cases
 
 
 */

//define Triangle Struct
struct Triangle {
    Triangle();
    
    ~Triangle();
    
    //copier
    Triangle(const Triangle& triangle);
    
    int *coor1 = new int[2];
    int *coor2 = new int[2];
    int *coor3 = new int[2];
    float lengthA, lengthB, lengthC;
    float longestLength;
    float angleAB, angleAC, angleBC;
    float largestAngle;
};

// find lengths
float findLength(int coorA[], int coorB[]) {
    return sqrtf(pow((coorA[0] - coorB[0]), 2) + pow((coorA[1] - coorB[1]), 2));
}

// first angle, being the largest
float findLargestAngle(float longestSide, float side2, float side3) {
    // use cos rule to calculate largest angle
    float cosValue = (pow(side2, 2) + pow(side3, 2) - pow(longestSide, 2)) /
    (2 * side2 * side3);
    float radians = acos(cosValue);
    
    // convert to degrees
    return (radians * 180) / M_PI;
}

//final angle
float calculateFinalAngle(float largestAngle, float angle2) {
    return 180 - largestAngle - angle2;
}

//second angle
float caluclateSINAngle(float largestAngle, float largestSide, float side2) {
    // convert to radians
    float degreesOfLargestAngle = largestAngle * M_PI / 180;
    
    // use sin rule to calcualte second side
    float sinValue = side2 * sin(degreesOfLargestAngle) / largestSide;
    float radians = asin(sinValue);
    
    // convert back to degrees
    return (radians * 180) / M_PI;
}

void findAllAngles(float &finalAngle, float &largestAngle, float largestSide,
                   float length1, float length2, float &sinAngle) {
    largestAngle = findLargestAngle(largestSide, length1, length2);
    sinAngle = caluclateSINAngle(largestAngle, largestSide, length1);
    finalAngle = calculateFinalAngle(largestAngle, sinAngle);
}

void printDetails(const Triangle& triangle) {
    // confirm points of triangle
    std::cout << "Your points: (" << triangle.coor1[0] << ", " << triangle.coor1[1] << ") ("
    << triangle.coor2[0] << ", " << triangle.coor2[1] << ") (" << triangle.coor3[0] << ", "
    << triangle.coor3[1] << ")";
    std::cout << std::endl;
    std::cout << std::endl;
    
    std::cout << triangle.lengthA << " " << triangle.lengthB << " " << triangle.lengthC;
    std::cout << std::endl;
    std::cout << std::endl;
    
    std::cout << "Largest Angle: " << triangle.largestAngle << std::endl;
    std::cout << std::endl;
    
    // print all angles
    std::cout << triangle.angleAB << std::endl;
    std::cout << triangle.angleAC << std::endl;
    std::cout << triangle.angleBC << std::endl;
}

//analyze triangles
std::string analyzeTrinagle(Triangle triangle){
    if (triangle.lengthA == triangle.lengthB && triangle.lengthA == triangle.lengthC) {
        return "equilateral\n";
    }
    if (triangle.lengthA == triangle.lengthB || triangle.lengthA == triangle.lengthC || triangle.lengthB == triangle.lengthC) {
        return "isosceles\n";
    } else if (triangle.largestAngle == 90.0) {
        return "right triangle\n";
    } else if (triangle.largestAngle > 90.0) {
        return "obtuse\n";
    } else if (triangle.largestAngle < 90.0) {
        return "acute\n";
    } else {
        return "degenerate\n";
    }
}

static void buildTriangles(int x1, int y1, int x2, int y2, int x3, int y3) {
    // assign values to coordinates
    Triangle triangle;
    triangle.coor1[0] = x1;
    triangle.coor1[1] = y1;
    
    triangle.coor2[0] = x2;
    triangle.coor2[1] = y2;
    
    triangle.coor3[0] = x3;
    triangle.coor3[1] = y3;
    
    float lengthA = findLength(triangle.coor1, triangle.coor2);
    float lengthB = findLength(triangle.coor2, triangle.coor3);
    float lengthC = findLength(triangle.coor1, triangle.coor3);
    float longestLength;
    
    float angleAB, angleAC, angleBC;
    float largestAngle;
    float sinAngle;
    float finalAngle;
    
    if (lengthB > lengthA && lengthB > lengthC) {
        longestLength = lengthB;
        findAllAngles(finalAngle, largestAngle, longestLength, lengthA, lengthC,
                      sinAngle);
        
        angleAC = largestAngle;
        angleBC = sinAngle;
        angleAB = finalAngle;
    } else if (lengthC > lengthA && lengthC > lengthB) {
        longestLength = lengthC;
        findAllAngles(finalAngle, largestAngle, longestLength, lengthA, lengthB,
                      sinAngle);
        
        angleAB = largestAngle;
        angleBC = sinAngle;
        angleAC = finalAngle;
    } else {
        longestLength = lengthA;
        findAllAngles(finalAngle, largestAngle, longestLength, lengthC, lengthB,
                      sinAngle);
        
        angleBC = largestAngle;
        angleAB = sinAngle;
        angleAC = finalAngle;
    }
    
    triangle.longestLength = longestLength;
    triangle.largestAngle = largestAngle;
    
    std::cout << analyzeTrinagle(triangle);
    
    printDetails(triangle);
}

// main method to run tests
int main(int argc, const char *argv[]) {
    int x1, y1, x2, y2, x3, y3;
    
    while (true) {
        // ask for points of triangle
        if (!(std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)) {
            break;
        }
        
        buildTriangles(x1, y1, x2, y2, x3, y3);
    }
    
    return 0;
}
