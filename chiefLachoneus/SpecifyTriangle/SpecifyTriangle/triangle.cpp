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


float findLength(int coorA[], int coorB[]){
    return sqrtf(pow((coorA[0] - coorB[0]),2) + pow((coorA[1] - coorB[1]),2));
}

float findLargestAngle(float longestSide, float side2, float side3) {
    //use cos rule to calculate largest angle
    float cosValue = (pow(side2, 2) + pow(side3, 2) - pow(longestSide, 2))/(2 * side2 * side3);
    float radians = acos(cosValue);
    
    //convert to degrees
    return (radians * 180)/M_PI;
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

int main(int argc, const char * argv[]) {
    int x1, y1, x2, y2, x3, y3;
    
    //ask for points of triangle
    std::cout << "Please provide 3 points for a triangle in this format (x1 y1 x2 y2 x3 y3):" << std::endl;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
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
    
    if(lengthB > lengthA && lengthB > lengthC) {
        largestSide = lengthB;
        largestAngle = findLargestAngle(largestSide, lengthA, lengthC);
        angleAC = largestAngle;
        
        angleBC = caluclateSINAngle(largestAngle, largestSide, lengthA);
        angleAB = 180 - angleAC - angleBC;
    } else if (lengthC > lengthA && lengthC > lengthB) {
        largestSide = lengthC;
        largestAngle = findLargestAngle(largestSide, lengthA, lengthB);
        angleAB = largestAngle;
        
        angleBC = caluclateSINAngle(largestAngle, largestSide, lengthA);
        angleAC = 180 - angleAB - angleBC;
    } else {
        largestSide = lengthA;
        largestAngle = findLargestAngle(largestSide, lengthB, lengthC);
        angleBC = largestAngle;
        
        angleAB = caluclateSINAngle(largestAngle, largestSide, lengthC);
        angleAC = 180 - angleAB - angleBC;
    }
    
    std::cout << "Largest Angle: " << largestAngle <<  std::endl;
    std::cout << std::endl;
    
    //print all angles
    std::cout << angleAB <<  std::endl;
    std::cout << angleAC <<  std::endl;
    std::cout << angleBC <<  std::endl;
    
    
    return 0;
}
