//
//  main.cpp
//  Triangles
//
//  Created by Chris Roper on 1/9/18.
//  Copyright © 2018 Chris Roper. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
#include <cmath>
#include <vector>
const float pi = 3.1415926535897f;

float slope(float x1, float x2, float y1, float y2) {
    if(x1 == x2 || y1 == y2) {
        return -99;
    }
    return (x1-x2)/(y1-y2);
}

float degreesToRadians(float degrees) {
    return degrees*pi/180.0f;
}

float radiansToDegrees(float radians) {
    return radians*180.0f/pi;
}
std::string getTriangleType(int x1, int y1, int x2, int y2, int x3, int y3) {
    //equal points check
    if((x1 == x2 && y1 == y2) || (x2 == x3 && y2 == y3) || (x1 == x3 && y1 == y3)) {
        return "degenerate";
    }
    //all points on same x,y line check
    if((x1 == x2 && x2 == x3) || (y1 == y2 && y2 == y3)) {
        return "degenerate";
    }
    //slope check (assumes points are not equal - other cases are caught above)
    if(x1 != x2 && x2 != x3 && y1 != y2 && y2 != y3) {
        if(slope(x1, x2, y1, y2) == slope(x2, x3, y2, y3)) {
        return "degenerate";
        }
    }
    
//    std::cout << slope(x1, x2, y1, y2) << "\n";
//    std::cout << slope(x2, x3, y2, y3) << "\n";
//    std::cout << slope(x1, x2, y2, y3) << "\n";
    double lengthC = sqrt(pow((x1-x2),2)+pow((y1-y2),2));
    double lengthA = sqrt(pow((x2-x3),2)+pow((y2-y3),2));
    double lengthB = sqrt(pow((x3-x1),2)+pow((y3-y1),2));
    assert(lengthA > 0 && lengthB > 0 && lengthC > 0);
    
    float angleC =  acos((pow(lengthA,2)+pow(lengthB,2)-pow(lengthC,2))/(2*lengthA*lengthB));
    angleC*= (180.0f/pi);
    float angleB = acos((pow(lengthA,2)+pow(lengthC,2)-pow(lengthB,2))/(2*lengthA*lengthC));
    angleB*= (180.0f/pi);
    //float angleB = (radiansToDegrees(asin(lengthB*(sin(degreesToRadians(angleC))/lengthC))));
    float angleA = 180 - angleC - angleB;
//    std::cout << lengthA << " " << lengthB << " " << lengthC << "\n";
//    std::cout << angleA << " " << angleB << " " << angleC << "\n";
    assert(angleA > 0.0 && angleB > 0.0 && angleC > 0.0);
    assert((angleA + angleB + angleC) < 180.01);
//    angleC = round(angleC);
//    angleB = round(angleB);
//    angleA = round(angleA);

    if ((angleA < 90.0001 && angleA > 89.9999) || (angleB < 90.0001 && angleB > 89.9999) || (angleC < 90.0001 && angleC > 89.9999)) {
        return "right";
    }
    else if ((angleA == angleB) || (angleB == angleC) || (angleC == angleA) || (lengthA == lengthB) || (lengthB==lengthC) || (lengthC==lengthA)) {
        return "isosceles";
    }
    else if (angleA > 90 || angleB > 90 || angleC > 90) {
        return "obtuse";
    }
    else return "acute";
}

int main(int argc, const char * argv[]) {
    while(true){
        int x1,y1,x2,y2,x3,y3;
        if(!(std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)) {
            break;
        }
        std::string triangleType = getTriangleType(x1, y1, x2, y2, x3, y3);
        std::cout << triangleType << "\n";
    }
    return 0;
}
