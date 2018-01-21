//
//  triangle.cpp
//  triangleClassifier
//
//  Created by Kayla Cresswell on 1/9/18.
//  Copyright © 2018 Kayla Cresswell. All rights reserved.
//

#include <iostream>
#include <cmath>
#define PI 3.14159265

//distance formula
double calcDistance(int x1, int y1, int x2, int y2) {
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2) );
}


//angle calc and radians conversion from doug
double findAngle(double a, double b, double c) {
    double math = (pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b);
    double comp = std::abs(acos( math ) * 180.0 / PI);

    return comp;
}

//from doug, margin or error needed to get right triangle to work in my code.
bool doublesEqual(double a, double b) {
    return std::abs(a-b) < 0.000001;
}

std::string determineTriangleType(int x1, int y1, int x2, int y2, int x3, int y3) {
    
    // Determine the three side lengths
    double sideA = calcDistance(x1, y1, x2, y2);
    double sideB = calcDistance(x2, y2, x3, y3);
    double sideC = calcDistance(x3, y3, x1, y1);
    
    // determine the three angles
    double angleA = findAngle(sideB, sideC, sideA);
    double angleB = findAngle(sideC, sideA, sideB);
    double angleC = findAngle(sideA, sideB, sideC);

    //degenerate check
    //|| (angleA + angleB + angleC < 180)
    if(sideA >= sideB + sideC || sideB >= sideA + sideC || sideC >= sideA + sideB) {
        return "degenerate\n";
    }
    
    // If one of the angles is 90 degrees, right triangle
    if (doublesEqual(angleA, 90.0) || doublesEqual(angleB, 90.0) || doublesEqual(angleC, 90.0)) {
        return "right\n";
    }
    
    // If two or more sides are the same, isosceles triangle
    else if (doublesEqual(sideA, sideB) || doublesEqual(sideB, sideC) || doublesEqual(sideC, sideA)) {
        return "isosceles\n";
    }
    
    // If one of the angles is > 90 degrees, obtuse triangle
    else if (angleA > 90 || angleB > 90 || angleC > 90) {
        return "obtuse\n";
    }
    
    // If all angles are < 90 degrees
    else if (angleA < 90 && angleB < 90 && angleC < 90) {
        return "acute\n";
    }
    
    return "degenerate";
}


int main(int argc, const char * argv[]) {
    
    //while true loop and error check code from Doug
    while(true){
        // Get the three point coordinates
        int x1, y1, x2, y2, x3, y3;
        if ( !(std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) ) {
            break;
        }
        
        // Get the type of the triangle
        std::cout << determineTriangleType(x1, y1, x2, y2, x3, y3);
    }
    
    return 0;
}

