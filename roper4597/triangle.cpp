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
double pi = 3.1415926535897;

double slope(double x1, double x2, double y1, double y2) {
    return (x1-x2)/(y1-y2);
}

double degreesToRadians(double degrees) {
    return degrees*pi/180;
}

double radiansToDegrees(double radians) {
    return radians*180/pi;
}
std::string getTriangleType(int x1, int y1, int x2, int y2, int x3, int y3) {
    //equal points check
    if((x1 == x2 && y1 == y2) || (x2 == x3 && y2 == y3) || (x1 == x3 && y1 == y3)) {
        return "Degenerate\n";
    }
    //all points on same x,y line check
    if((x1 == x2 && x2 == x3) || (y1 == y2 && y2 == y3)) {
        return "Degenerate\n";
    }
    //slope check (assumes points are not equal - other cases are caught above)
    if(x1 != x2 && x2 != x3 && y1 != y2 && y2 != y3) {
        if(slope(x1, x2, y1, y2) == slope(x2, x3, y2, y3)) {
        return "Degenerate\n";
        }
    }
    double lengthC = sqrt(pow((x1-x2),2)+pow((y1-y2),2));
    double lengthA = sqrt(pow((x2-x3),2)+pow((y2-y3),2));
    double lengthB = sqrt(pow((x3-x1),2)+pow((y3-y1),2));
    assert(lengthA > 0 && lengthB > 0 && lengthC > 0);
    
    double angleC = round(10*(radiansToDegrees(acos((pow(lengthA,2)+pow(lengthB,2)-pow(lengthC,2))/(2*lengthA*lengthB))))/10);
    double angleB = round(10*(radiansToDegrees(asin(lengthB*(sin(degreesToRadians(angleC))/lengthC))))/10);
    double angleA = 180 - angleC - angleB;
    assert(angleA > 0 && angleB > 0 && angleC > 0);
//    std::cout << lengthA << " " << lengthB << " " << lengthC << "\n";
//    std::cout << angleA << " " << angleB << " " << angleC << "\n";
    if (angleA == 90 || angleB == 90 || angleC == 90) {
        return "Right\n";
    }
    else if ((angleA == angleB) || (angleB == angleC) || (angleC == angleA) || (lengthA == lengthB) || (lengthB==lengthC) || (lengthC==lengthA)) {
        return "Isosceles\n";
    }
    else if (angleA < 90 && angleB < 90 && angleC < 90) {
        return "Acute\n";
    }
    else return "Obtuse\n";
}

int main(int argc, const char * argv[]) {
    std::cout << "Please enter coordinates:\n";
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
