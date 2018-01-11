//
//  main.cpp
//  CS6015-TriangleClassifier
//
//  Created by Irene Yeung on 1/9/18.
//  Copyright © 2018 Irene Yeung. All rights reserved.
//



/*
Triangle Classifier Program Specifications:
 Six integer coordinates separated by spaces must be entered.
 All coordinates must be in range [0,100].
 Input is zero or more lines containing triangle coordinates.
 Behavior is undefined if input is malformed.
 Priority: Equilateral --> Right --> Isosceles --> Scalene --> Obtuse -->
    Acute --> Degenerate
 */

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>


double getLength(double x1, double y1, double x2, double y2);
const double PI();
double radDegConv(double theta);
double getLargestAngle(double lengthA, double lengthB, double lengthC);
double getSecondAngle(double lengthA, double thetaA, double lengthB);
bool isEquilat(std::vector<double> lengths, std::vector<double> thetas);
bool isRightAngle(std::vector<double> lengths, std::vector<double> thetas);
bool isIsosc(std::vector<double> lengths, std::vector<double> thetas);
bool isScal(std::vector<double> lengths, std::vector<double> thetas);
bool isObtuse(std::vector<double> lengths, std::vector<double> thetas);
bool isAcute(std::vector<double> lengths, std::vector<double> thetas);
std::string classifyTriangle(std::vector<double> lengths, std::vector<double> thetas);

int main(int argc, const char * argv[]) {
    // insert code here...
    double x1, y1, x2, y2, x3, y3;
    x1 = -1;
    x2 = -1;
    x3 = -1;
    y1 = -1;
    y2 = -1;
    y3 = -1;
    std::vector<double> coords;
    while(true){
        std::cout << "Enter Triangle (x,y) Coordinates:\n";
        std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        coords.push_back(x1);
        coords.push_back(y1);
        coords.push_back(x2);
        coords.push_back(y2);
        coords.push_back(x3);
        coords.push_back(y3);
        if ((x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0 || x3 < 0 || y3 <0)|| (x1 + x2 + x3 + y1 + y2 + y3 <= 0)){
            std::cout << "Invalid Coordinates Entered.\n";
            return 1;
        }
        else {
            std::vector<double> lengths;
            std::vector<double> angles;
            double thetaA, thetaB, thetaC, max;
            lengths.push_back(getLength(x1, y1, x2, y2));
            lengths.push_back(getLength(x1, y1, x3, y3));
            lengths.push_back(getLength(x2, y2, x3, y3));
            max = *max_element(std::begin(lengths), std::end(lengths));
            if (max == lengths[0]){
                thetaA = getLargestAngle(lengths[1], lengths[2], max);
                thetaB = getSecondAngle(max, thetaA, lengths[1]);
            }
            else if (max == lengths[1]){
                thetaA = getLargestAngle(lengths[0], lengths[2], max);
                thetaB = getSecondAngle(max, thetaA, lengths[0]);
            }
            else {
                thetaA = getLargestAngle(lengths[0], lengths[1], max);
                thetaB = getSecondAngle(max, thetaA, lengths[0]);
            }
            thetaC = radDegConv(180) - thetaA - thetaB;
            angles.push_back(thetaA);
            angles.push_back(thetaB);
            angles.push_back(thetaC);
            std::cout << classifyTriangle(lengths, angles) << std::endl;
            coords.clear();
            continue;
        }
    }
    
}



double getLength(double x1, double y1, double x2, double y2){
    return sqrt(pow((y2 - y1),2) + pow((x2-x1),2));
}
const double PI(){
    return std::atan(1)*4;
}
double radDegConv(double theta){
    return (theta * PI())/180.0;
}
double getLargestAngle(double lengthA, double lengthB, double lengthC){
    return std::acos((pow(lengthA,2) + pow(lengthB,2) - pow(lengthC,2))/
                     (2*lengthA*lengthB));
}

double getSecondAngle(double lengthA, double thetaA, double lengthB){
    return asin((lengthB * sin(thetaA))/lengthA);
}
double getThirdAngle(double thetaA, double thetaB){
    return radDegConv(180) - thetaA - thetaB;
}

bool isEquilat(std::vector<double> lengths, std::vector<double> thetas){
    return round(thetas[0]) == round(thetas[1]) == round(thetas[2])
        && lengths[0] == lengths[1] == lengths[2];
}
bool isRightAngle(std::vector<double> lengths, std::vector<double> thetas){
    return thetas[0] == radDegConv(90) || thetas[1] == radDegConv(90) ||
    thetas[2] == radDegConv(90);
}
bool isIsosc(std::vector<double> lengths, std::vector<double> thetas){
    return lengths[0] == lengths[1] || lengths[1] == lengths[2]
        || lengths[0] == lengths[2];
}
bool isScal(std::vector<double> lengths, std::vector<double> thetas){
    return lengths[0] != lengths[1] && lengths[0] != lengths[2]
        && lengths[1] != lengths[2];
}
bool isObtuse(std::vector<double> lengths, std::vector<double> thetas){
    return thetas[0] > radDegConv(90) || thetas[1] > radDegConv(90)
        || thetas[2] > radDegConv(90);
}
bool isAcute(std::vector<double> lengths, std::vector<double> thetas){
    return thetas[0] < radDegConv(90) && thetas[1] < radDegConv(90)
        && thetas[2] < radDegConv(90);
}
std::string classifyTriangle(std::vector<double> lengths, std::vector<double> thetas){
    if (isEquilat(lengths, thetas)){
        if (isObtuse(lengths, lengths)){
            return "Equilateral & Obtuse\n" ;
        }
        return "Equilateral & Acute\n" ;
    }
    else if (isRightAngle(lengths, thetas)){
        return "Right Angle Triangle\n";
    }
    else if (isIsosc(lengths, thetas)){
        if (isObtuse(lengths, thetas)){
            return "Isosceles & Obtuse\n";
        }
        return "Isosceles & Acute \n";
    }
    else if (isScal(lengths, thetas)){
        if (isObtuse(lengths, thetas)){
            return "Scalene & Obtuse\n";
        }
        return "Scalene & Acute\n";
    } else {
        return "Degenerate Triangle\n";
    }
}
