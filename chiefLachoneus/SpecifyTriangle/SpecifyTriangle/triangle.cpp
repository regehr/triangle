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
 scalene: none of the above -- unreachable condition given all the other conditions with single classification
 degenerate: not a triangle
 
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

//find lengths
float findLength(int coorA[], int coorB[]){
    return sqrtf(pow((coorA[0] - coorB[0]),2) + pow((coorA[1] - coorB[1]),2));
}

//finding angles
float findLargestAngle(float longestSide, float side2, float side3) {
    //use cos rule to calculate largest angle
    float cosValue = (pow(side2, 2) + pow(side3, 2) - pow(longestSide, 2))/(2 * side2 * side3);
    float radians = acos(cosValue);
    
    //convert to degrees
    return (radians * 180)/M_PI;
}

float calculateFinalAngle(float largestAngle, float angle2){
    return 180 - largestAngle - angle2;
}

float caluclateSINAngle(float largestAngle, float largestSide, float side2){
    //convert to radians
    float degreesOfLargestAngle = largestAngle * M_PI / 180;
    
    //use sin rule to calcualte second side
    float sinValue = side2 * sin(degreesOfLargestAngle)/ largestSide;
    float radians = asin(sinValue);
    
    //convert back to degrees
    return (radians * 180)/M_PI;
}

void findAllAngles(float &finalAngle, float &largestAngle, float largestSide, float length1, float length2, float &sinAngle) {
    largestAngle = findLargestAngle(largestSide, length1, length2);
    sinAngle = caluclateSINAngle(largestAngle, largestSide, length1);
    finalAngle = calculateFinalAngle(largestAngle, sinAngle);
}

static void buildTriangles(int x1, int y1, int x2, int y2, int x3, int y3) {
    //assign values to coordinates
    int coor1[] = {x1, y1};
    int coor2[] = {x2, y2};
    int coor3[] = {x3, y3};
    
    //confirm points of triangle
    std::cout << "Your points: (" << coor1[0] << ", " << coor1[1]  << ") ("
    << coor2[0] << ", " << coor2[1] << ") ("
    << coor3[0] << ", " << coor3[1] << ")";
    std::cout << std::endl;
    std::cout << std::endl;
    
    float lengthA = findLength(coor1, coor2);
    float lengthB = findLength(coor2, coor3);
    float lengthC = findLength(coor1, coor3);
    
    std::cout << lengthA << " " << lengthB << " " << lengthC;
    std::cout << std::endl;
    std::cout << std::endl;
    
    float angleAB, angleAC, angleBC;
    float largestSide;
    float largestAngle;
    float sinAngle;
    float finalAngle;
    
    if(lengthB > lengthA && lengthB > lengthC) {
        largestSide = lengthB;
        findAllAngles(finalAngle, largestAngle, largestSide, lengthA, lengthC, sinAngle);
        
        angleAC = largestAngle;
        angleBC = sinAngle;
        angleAB = finalAngle;
    } else if (lengthC > lengthA && lengthC > lengthB) {
        largestSide = lengthC;
        findAllAngles(finalAngle, largestAngle, largestSide, lengthA, lengthB, sinAngle);
        
        angleAB = largestAngle;
        angleBC = sinAngle;
        angleAC = finalAngle;
    } else {
        largestSide = lengthA;
        findAllAngles(finalAngle, largestAngle, largestSide, lengthC, lengthB, sinAngle);
        
        angleBC = largestAngle;
        angleAB = sinAngle;
        angleAC = finalAngle;
    }
    
    std::cout << "Largest Angle: " << largestAngle <<  std::endl;
    std::cout << std::endl;
    
    //print all angles
    std::cout << angleAB <<  std::endl;
    std::cout << angleAC <<  std::endl;
    std::cout << angleBC <<  std::endl;
}

//main method to run tests
int main(int argc, const char * argv[]) {
    int x1, y1, x2, y2, x3, y3;
    
    while (true) {
        //ask for points of triangle
        if (!(std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)) {
            break;
        }
        
        buildTriangles(x1, y1, x2, y2, x3, y3);
    }
    
    return 0;
}
