//
//  main.cpp
//  SpecifyTriangle
//
//  Created by Eric Williams on 1/9/18.
//  Copyright © 2018 Eric Williams. All rights reserved.
//

#include <iostream>
#include <cmath>

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
//struct Triangle {
//    Triangle();
//
//    Triangle(int coor1[], int coor2[], int coor3[]);
//
//    int *coor1 = new int[2];
//    int *coor2 = new int[2];
//    int *coor3 = new int[2];
//    float lengthA, lengthB, lengthC;
//    float longestLength;
//    float angleAB, angleAC, angleBC;
//    float largestAngle;
//};

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

//final angle
float calculateFinalAngle(float largestAngle, float angle2) {
    return 180 - largestAngle - angle2;
}


void findAllAngles(float &finalAngle, float &largestAngle, float largestSide,
                   float length1, float length2, float &sinAngle) {
    largestAngle = findLargestAngle(largestSide, length1, length2);
    sinAngle = caluclateSINAngle(largestAngle, largestSide, length1);
    finalAngle = calculateFinalAngle(largestAngle, sinAngle);
}

// used for evaluation of numbers to help produce testing.
//void printDetails(int coor1[], int coor2[], int coor3[], float lengthA, float lengthB, float lengthC, float angleAB, float angleAC, float angleBC, float largestAngle) {
//    // confirm points of triangle
//    std::cout << "Your points: (" << coor1[0] << ", " << coor1[1] << ") ("
//    << coor2[0] << ", " << coor2[1] << ") (" << coor3[0] << ", "
//    << coor3[1] << ")" << "\n";
//
//    std::cout << lengthA << " " << lengthB << " " << lengthC << "\n";
//    std::cout << "Largest Angle: " << largestAngle << "\n";
//
//    // print all angles
//    std::cout << angleAB << "\n";
//    std::cout << angleAC << "\n";
//    std::cout << angleBC << "\n\n";
//
//}

/*
 * Borrowed this code method from Doug Garding, and updated to floats from doubles
 * Returns true if two floats are equal to each other with
 * a margin of error of .001
 */
bool floatsEqual(float a, float b) { return abs(a - b) < 0.001;}

//analyze triangles
std::string analyzeTrinagle(float lengthA, float lengthB, float lengthC, float angleAB, float angleAC, float angleBC, float largestAngle){
    if (lengthA == 0 || lengthB == 0 || lengthC == 0) {
        return "degenerate\n";
    } else if (floatsEqual(180, largestAngle)) {
        return "degenerate\n";
    }
    
    if (floatsEqual(90, largestAngle)) {
        return "right\n";
    } else if (lengthA == lengthB || lengthA == lengthC || lengthB == lengthC) {
        return "isosceles\n";
    } else if (largestAngle > 90.0) {
        return "obtuse\n";
    } else {
        return "acute\n";
    }
}

static void buildTriangles(int x1, int y1, int x2, int y2, int x3, int y3) {
    // assign values to coordinates
    
    int *coor1 = new int[2];
    int *coor2 = new int[2];
    int *coor3 = new int[2];
    
    coor1[0] = x1;
    coor1[1] = y1;
    
    coor2[0] = x2;
    coor2[1] = y2;
    
    coor3[0] = x3;
    coor3[1] = y3;
    
    float lengthA = findLength(coor1, coor2);
    float lengthB = findLength(coor2, coor3);
    float lengthC = findLength(coor1, coor3);
    float longestLength;
    
    float angleAB, angleAC, angleBC;
    float largestAngle;
    float sinAngle;
    float finalAngle;
    
    if (floatsEqual(lengthA, 0.0) || floatsEqual(lengthB, 0.0) || floatsEqual(lengthC, 0.0)) {
        std::cout << "degenerate\n";
    } else {
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
        
        std::cout << analyzeTrinagle(lengthA, lengthB, lengthC, angleAB, angleAC, angleBC, largestAngle);
        //    printDetails(coor1, coor2, coor3, lengthA, lengthB, lengthC, angleAB, angleAC, angleBC, largestAngle);
    }
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
