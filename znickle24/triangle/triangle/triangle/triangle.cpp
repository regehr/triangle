//
//  triangle.cpp
//  triangle
//
//  Created by Zander Nickle on 1/11/18.
//  Copyright © 2018 Zander Nickle. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>

double x, y, x2, y2, x3, y3;
int numberOfTriangles;
std::vector<double> calculateLineLengths (double x, double y, double x2, double y2, double x3, double y3) {
    std::vector<double> lineLengths;
    double lineLength1 = 0.0;
    double lineLength2 = 0.0;
    double lineLength3 = 0.0;
    double dx1 = x2 - x;
    double dy1 = y2 - y;
    lineLength1 = sqrt(dx1*dx1+dy1*dy1);
    double dx2 = x3 - x;
    double dy2 = y3 - y;
    lineLength2 = sqrt(dx2*dx2 + dy2*dy2);
    double dx3 = x3 - x2;
    double dy3 = y3 - y2;
    lineLength3 = sqrt(dx3*dx3 + dy3*dy3);
    lineLengths.push_back(lineLength1);
    lineLengths.push_back(lineLength2);
    lineLengths.push_back(lineLength3);
    return lineLengths;
}
std::vector<double> angleCalculator (std::vector<double> lengths) {
    std:: vector<double> angles;
    double a = lengths[0];
    double b = lengths[1];
    double c = lengths[2];
    double angleA, angleB, angleC = 0;
    double pi = 3.141592653589793238463;
    //angle in radians
    //then convert from radians to degrees
    angleA = acos(((pow(b,2) + pow(c,2) - pow(a,2)))/(2*b*c)) * 180/pi;
    angleB = acos(((pow(c,2) + pow(a,2) - pow(b,2)))/(2*a*c)) * 180/pi;
    angleC = acos(((pow(a,2) + pow(b, 2) - pow(c,2)))/(2*a*b)) * 180/pi;

    angles.push_back(angleA);
    angles.push_back(angleB);
    angles.push_back(angleC);
    return angles;
}
void typeOfTriangle(std::vector<double> lineLengths, std::vector<double> angles) {
    if (x < 0 || x2 <0 || x3 < 0 || y < 0 || y2 < 0 || y3 < 0 || x > 100 || x2 > 100 || x3 > 100 || y > 100 || y2 > 100 || y3 > 100) {
        std::cout << "This is an invalid input and will not be considered. Must be between 0 and 100. \n ";
    } else if ((x == x2 && y == y2) || (x2 == x2 && y2 == y3) || (x3 == x && y3 == y)) {
        std::cout << "This is a degenerate and cannot be a triangle! \n";
    } else if (!(lineLengths[0] != lineLengths[1] || lineLengths[1] != lineLengths[2] || lineLengths[2] != lineLengths[0])) {
        std::cout << "This is an equilateral triangle. \n";
    } else if (lineLengths[0] == lineLengths[1] || lineLengths[1] == lineLengths[2] || lineLengths[0] == lineLengths[2]) {
        std::cout << "This is an isosceles triangle. \n";
    } else if (angles[0] > 90 || angles[1] > 90 || angles[2] > 90) {
        std::cout << "This is an obtuse triangle. \n";
    } else if (angles[0] == 90 || angles[1] == 90 || angles[2] == 90) {
        std::cout << "This is a right triangle. \n";
    }else if (angles[0] < 90 && angles[1] < 90 && angles[2] < 90) {
        std::cout << "This is an acute triangle. \n";
    }
}
int main(int argc, const char * argv[]) {
    //took this idea to loop through the number of triangles from Sydney
    std::cout << "Please enter the coordinates for your triangle (format: x1 y1 x2 y2 x3 y3): \n";
    while (true) {
        if (!(std::cin >> x >> y >> x2 >> y2 >> x3 >> y3)) {
            break;
        }
        
        std:: vector<double> lineLengths = calculateLineLengths(x, y, x2, y2, x3, y3);
        std::vector<double> angles = angleCalculator(lineLengths);
        typeOfTriangle(lineLengths, angles);

    }
    return 0;
}
