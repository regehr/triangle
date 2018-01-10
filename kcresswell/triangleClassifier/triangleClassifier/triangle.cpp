//
//  triangle.cpp
//  triangleClassifier
//
//  Created by Kayla Cresswell on 1/9/18.
//  Copyright © 2018 Kayla Cresswell. All rights reserved.
//

#include <iostream>
#include <cmath>

std::string getTriangleType(int aX, int aY, int bX, int bY, int cX, int cY){
    //calculate each side length
    //d = sqrt((x2 - x1)^2 + (y2 - y1)^2)
    float lengthA, lengthB, lengthC;
    lengthA = sqrt((cX - bX)^2 + (cY - bY)^2);
    lengthB = sqrt((cX - aX)^2 + (cY - aY)^2);
    lengthC = sqrt((bX - aX)^2 + (bY - aY)^2);
    
    //calculate each angle
    float angleAlpha, angleBravo, angleCharlie;
    angleAlpha = acos((pow(lengthB, 2.0) + pow(lengthC, 2.0) - pow(lengthA, 2.0)) / 2 * lengthB * lengthC);
    angleBravo = acos((pow(lengthC, 2.0) + pow(lengthA, 2.0) - pow(lengthB, 2.0)) / 2 * lengthC * lengthA);
    angleCharlie = acos((pow(lengthA, 2.0) + pow(lengthB, 2.0) - pow(lengthC, 2.0)) / 2 * lengthA * lengthB);
    
    //right triangle: one 90 degree angle
    if(angleAlpha == 90.0 || angleBravo == 90.0 || angleCharlie == 90.0){
        std::cout << "right\n";
    }
    
    //isosceles: two sides same length
    else if(lengthA == lengthB || lengthA == lengthC || lengthB == lengthC){
        std::cout << "isosceles\n";
    }
    
    //equilateral: all sides same length
    else if(lengthA == lengthB && lengthA == lengthC){
        std::cout << "equilateral\n";
    }
    
    //obtuse: one angle >90
    else if(angleAlpha > 90 || angleBravo > 90 || angleCharlie > 90){
        std::cout << "obtuse\n";
    }
    
    //acute: all angles <90
    else if(angleAlpha < 90 || angleBravo < 90 || angleCharlie < 90){
        std::cout << "acute\n";
    }
    
    //scalene: none of the above
    else{
        std::cout << "scalene\n";
    }
    
    return "";
    
}

int main(int argc, const char * argv[]) {
    int x1, y1, x2, y2, x3, y3 = 0;
    std::cout << "Enter shape coordinates in the following format x1 y1 x2 y2 x3 y3: ";
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    std::cout << "You entered: " << x1 << " " << y1 << " " << x2  << " " << y2  << " " << x3  << " " << y3 << "\n";
    std::cout << "Triangle Type: " << getTriangleType(x1, y1, x2, y2, x3, y3);
    
    return 0;
}
