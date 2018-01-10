//
//  traingle.cpp
//  MSD_6015
//
//  Created by Gregory Colledge on 1/9/18.
//  Copyright © 2018 Gregory Colledge. All rights reserved.
//
//  The following link was used for reference:
//  https://stackoverflow.com/questions/1321137/convert-string-containing-several-numbers-into-integers

#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <algorithm>
#include <vector>

#define PI 3.14159265



float distance(float firstX, float firstY, float secondX, float secondY){
    return sqrt((firstX - secondX)*(firstX - secondX) + (firstY - secondY)*(firstY - secondY));
}

int main(int argc, const char * argv[]) {
    int x1, y1, x2, y2, x3, y3;
    std::string input;

    std::cout << "Enter the points of a triangle as follows:\n";
    std::cout << "x1 y1 x2 y2 x3 y3\n";
    std::cout << "Where each x and y can be integers between 0 and 100 inclusive.\n";

    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    std::cout << "Your input was: " << x1 << " " << y1 << " " << x2 << " " << y2 << " "<< x3 << " " << y3 << "\n";//FEC
    
//Test for a triangle
    //chekc for verticle line
    if(x1 - x2 == 0 && x1 - x3 == 0){
        std::cout << "degenerate.";// All points fall on a line.
        return 0;
    }
    //check for any other line
    float slope;
    if(x1 != x2){
        slope = (y1 - y2) / (x1 - x2);
    }else{
        slope = (y3 - y2) / (x3 - x2);
    }
    float intercept = y1 - slope * x1;

    if(y3==(slope*x3 + intercept)){
        std::cout << "degenerate\n";// All points fall on a line.
        return 0;
    }
    
    //calculate side lengths
    float sideA = distance(x1,y1,x2,y2);
    float sideB = distance(x2,y2,x3,y3);
    float sideC = distance(x3,y3,x1,y1);
    std::vector<float> sides = {sideA, sideB, sideC};
    
    std::sort(sides.begin(), sides.end());
    std::cout << "Here are the sides in order: " << sides[0] << " " << sides[1] << " " << sides[2] << "\n";//FEC
    //check for right triangles
    if(abs(sides[0]*sides[0] + sides[1]*sides[1] - sides[2]*sides[2]) <= 0.0001){
        std::cout << "right triangle\n";
        return 1;
    }
    
    //check for Isosceles triangle
    if(abs(sides[1]-sides[0]) <= 0.0001 || abs(sides[2]-sides[1]) <= 0.0001){
        std::cout << "isosceles\n";
        return 1;
    }
    
    //check for equilateral triangle//this is a completely useless part of the code.
    if(abs(sides[2]-sides[0]) <= 0.0001){
        std::cout << "equilateral\n";
        return 1;
    }
    
    //check for obtuse
    float largeAngle = acos((pow(sides[2],2) - pow(sides[1],2) - pow(sides[0],2))/(-2*sides[1]*sides[0]));
        //the above line is the law of cosines solved for the angle. The largest angle is solved for.
    if(largeAngle * (180/PI) > 90){
        std::cout << "obtuse\n";
        return 1;
    }else{
        std::cout << "acute\n";
        return 1;
    }
    return 1;
}

