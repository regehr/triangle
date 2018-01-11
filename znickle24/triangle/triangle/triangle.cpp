//
//  main.cpp
//  triangle
//
//  Created by Zander Nickle on 1/9/18.
//  Copyright © 2018 Zander Nickle. All rights reserved.
//

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
    double dy2 = y3 - x;
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
    std:: vector<double> angles = lengths;
    double a = angles[0];
    double b = angles[1];
    double c = angles[2];
    //angle in radians
    a = acos(((pow(b,2) + pow(c,2) - pow(a,2)))/(2*b*c));
    b = acos(((pow(c,2) + pow(a,2) - pow(b,2)))/(2*a*c));
    c = acos(((pow(a,2) + pow(b, 2) - pow(c,2)))/(2*a*b));
    //convert from radians to degrees
    a = a* 57.295779513;
    b = b* 57.295779513;
    c = c* 57.295779513;
    angles.push_back(a);
    angles.push_back(b);
    angles.push_back(c);
    return angles;
}
void typeOfTriangle(std::vector<double> lineLengths, std::vector<double> angles) {
    if (!(lineLengths[0] != lineLengths[1] || lineLengths[1] != lineLengths[2] || lineLengths[2] != lineLengths[0])) {
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
    std::cout << "Please enter the number of triangles you'll be providing: \n";
    std:: cin >> numberOfTriangles;
    for (int i = 0; i < numberOfTriangles; i++) {
        std::cout << "Please enter the coordinates for your triangle (format: x1 y1 x2 y2 x3 y3): \n";
        std::cin >> x;
        std::cin >> y;
        std::cin >> x2;
        std::cin >> y2;
        std::cin >> x3;
        std::cin >> y3;
        if (x < 0 || x2 <0 || x3 < 0 || y < 0 || y2 < 0 || y3 < 0 || x > 100 || x2 > 100 || x3 > 100 || y > 100 || y2 > 100 || y3 > 100) {
            std::cout << "This is an invalid input and will not be considered. Must be between 0 and 100. \n ";
        } else if (x == x2 || x2 == x3 || x == x3 || y == y2 || y == y3 || y2 == y3) {
            std::cout << "This is a degenerate and cannot be a triangle! \n";
        } else {
            std:: vector<double> lineLengths = calculateLineLengths(x, y, x2, y2, x3, y3);
            std::vector<double> angles = angleCalculator(lineLengths);
            typeOfTriangle(lineLengths, angles);
        }
    }
    return 0;
}
