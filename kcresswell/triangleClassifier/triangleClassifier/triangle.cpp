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
double calcDistance(int x1, int y1, int x2, int y2){
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2) );
}


//angle calc and radians conversion from doug
double findAngle(double a, double b, double c){
    double math = (pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b);
    double comp = std::abs(acos( math ) * 180.0 / PI);

    return comp;
}

//from doug, margin or error needed to get right triangle to work in my code.
bool doublesEqual(double a, double b){
    return std::abs(a-b) < 0.000001;
}

std::string determineTriangleType(int x1, int y1, int x2, int y2, int x3, int y3){
    
    // Determine the three side lengths
    double sideA = calcDistance(x1, y1, x2, y2);
    double sideB = calcDistance(x2, y2, x3, y3);
    double sideC = calcDistance(x3, y3, x1, y1);
    
    //if any sides are 0 then it is degenerate
    //have to check before calculating angles
//    if(sideA == 0.0 || sideB == 0.0 || sideC == 0.0) {
//        return "degenerate\n";
//    }
    
    // determine the three angles
    double angleA = findAngle(sideB, sideC, sideA);
    double angleB = findAngle(sideC, sideA, sideB);
    double angleC = findAngle(sideA, sideB, sideC);

    
    
    // If one of the angles is 90 degrees, right triangle
    if (doublesEqual(angleA, 90.0) || doublesEqual(angleB, 90.0) || doublesEqual(angleC, 90.0)){
        return "right\n";
    }
    
    // If two or more sides are the same, isosceles triangle
    else if (doublesEqual(sideA, sideB) || doublesEqual(sideB, sideC) || doublesEqual(sideC, sideA)){
        return "isosceles\n";
    }
    
    // If one of the angles is > 90 degrees, obtuse triangle
    else if (angleA > 90 || angleB > 90 || angleC > 90){
        return "obtuse\n";
    }
    
    // If all angles are < 90 degrees
    else if (angleA < 90 && angleB < 90 && angleC < 90){
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
        determineTriangleType(x1, y1, x2, y2, x3, y3);
        
    }
    
    return 0;
}

//std::string getTriangleType(int aX, int aY, int bX, int bY, int cX, int cY){
//    //calculate each side length
////    float lengthA, lengthB, lengthC = 0;
////    lengthA = round(sqrt(pow(cX - bX, 2) + pow(cY - bY, 2)));
////    lengthB = round(sqrt(pow(cX - aX, 2) + pow(cY - aY, 2)));
////    lengthC = round(sqrt(pow(bX - aX, 2) + pow(bY - aY, 2)));
////
////    //calculate each angle
////    float angleAlpha, angleBravo, angleCharlie = 0;
////    angleAlpha = round(acos((pow(lengthB, 2.0) + pow(lengthC, 2.0) - pow(lengthA, 2.0)) / 2 * lengthB * lengthC));
////    angleBravo = round(acos((pow(lengthC, 2.0) + pow(lengthA, 2.0) - pow(lengthB, 2.0)) / 2 * lengthC * lengthA));
////    angleCharlie = round(acos((pow(lengthA, 2.0) + pow(lengthB, 2.0) - pow(lengthC, 2.0)) / 2 * lengthA * lengthB));
//
//    //from myriah
//    double lengthA = findLineLength(aX, aY, bX, bY);
//    double lengthB = findLineLength(aX, aY, cX, cY);
//    double lengthC = findLineLength(bX, bY, cX, cY);
//
//    double angleAlpha = findAngle(lengthA, lengthB, lengthC);
//    double angleBravo = findAngle(lengthB, lengthA, lengthC);
//    double angleCharlie = 180 - angleAlpha - angleBravo;
//
//    //right triangle: one 90 degree angle
//    //if(abs(lengthA * lengthA + lengthB * lengthB - lengthC * lengthC) <=
//     //  0.0001){
//    if(angleAlpha == 90.0 || angleBravo == 90.0 || angleCharlie == 90.0){
//        std::cout << "right\n";
//    }
////    if (angleAlpha == 90.0 || angleBravo == 90.0 || angleCharlie == 90.0) {
////        std::cout << "right\n";
////    }
//
//    //isosceles: two sides same length
//    else if(lengthA == lengthB || lengthA == lengthC || lengthB == lengthC){
//        std::cout << "isosceles\n";
//    }
//
//    //obtuse: one angle >90
//    else if(angleAlpha > 90.0 || angleBravo > 90.0 || angleCharlie > 90.0){
//        std::cout << "obtuse\n";
//    }
//
//    //equilateral: all sides same length
//    else if(lengthA == lengthB && lengthA == lengthC){
//        std::cout << "equilateral\n";
//    }
//
//    //acute: all angles <90
//    else if(angleAlpha < 90 && angleBravo < 90 && angleCharlie < 90){
//        std::cout << "acute\n";
//    }
//
//    //sum of two short sides must be > the hypotenuse
//    else if(lengthA + lengthB <= lengthC){
//        std::cout << "degenerate\n";
//    }
//
//    //scalene: none of the above
//    else{
//        std::cout << "scalene\n";
//    }
//
//    return "";
//
//}
//
//int main(int argc, const char * argv[]) {
//    int x1, y1, x2, y2, x3, y3 = 0;
//    std::cout << "Enter shape coordinates in the following format x1 y1 x2 y2 x3 y3: ";
//    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
//    std::cout << "You entered: " << x1 << " " << y1 << " " << x2  << " " << y2  << " " << x3  << " " << y3 << "\n";
//    std::cout << "Triangle Type: " << getTriangleType(x1, y1, x2, y2, x3, y3);
//
//    return 0;
//}

