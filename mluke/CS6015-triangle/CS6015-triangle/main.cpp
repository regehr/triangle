//
//  main.cpp
//  CS6015-triangle
//
//  Created by Madeline Luke on 1/9/18.
//  Copyright © 2018 Madeline Luke. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <cmath>

float findDistance(int x, int y, int x1, int y1) {
    int value = pow((x1 - x),2) + pow((y1 - y),2) ;
    return sqrt(value) ;
}

float findAngle(int x, int y, int z) {
    float val = (pow(x, 2) + pow(y, 2) - pow(z, 2)) / (2*x*y) ;
    return acos(val) * (180.0/3.14);
}

void triangleClassifier(int x1, int y1, int x2, int y2, int x3, int y3) {
    float side1, side2, side3 ;
    side1 = findDistance(x1, y1, x2, y2) ;
    side2 = findDistance(x1, y1, x3, y3) ;
    side3 = findDistance(x2, y2, x3, y3) ;
    
    float angleA, angleB, angleC ;
    angleC = findAngle(side1, side2, side3) ;
    angleA = findAngle(side2, side3, side1) ;
    angleB = findAngle(side3, side1, side2) ;
    
    if (angleA == 90 || angleB == 90 || angleC == 90) {
        std:: cout << "This is a right triangle. \n" ;
    } else if (side1 == side2 || side1 == side3 || side2 == side3) {
        std::cout << "This is an isosceles triangle. \n" ;
    } else if (side1 == side2 || side2 == side3) {
        std::cout << "This is an equilateral triangle. \n" ;
    } else if (angleA > 90 || angleB > 90 || angleC > 90) {
        std::cout << "This is an obtuse triangle. \n" ;
    } else if (angleA < 90 && angleB < 90 && angleC < 90) {
        std::cout << "This is an acute angle. \n" ;
    } else {
        std::cout << "This is a scalene triangle." ;
    }
}

int main(int argc, const char * argv[]) {
    
    int triangleAmount ;
    int x1, y1, x2, y2, x3, y3 ;
    std::cout << "How many triangles? \n" ;
    std::cin >> triangleAmount ;

    for (int i = 0 ; i < triangleAmount ; i++) {
        std::cout << "Enter 6 points for a triangle. \n" ;
        std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 ;
        triangleClassifier(x1, y1, x2, y2, x3, y3) ;
    }
    
    // Right triangle.
    triangleClassifier(-1, 1, 4, 4, 6, 2) ;
    // Isosceleses.
    triangleClassifier(8, 2, 11, 13, 2, 6)  ;
    triangleClassifier(-3, -3, 0, 5, 3, -3)  ;
    // Obtuse
   triangleClassifier(0, 0, -1, 4, 4, 0)  ;
    //Acute
triangleClassifier(9, 0, 0, 0, 4, 6) ;
    
  return 0;
}
