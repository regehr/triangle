//
//  main.cpp
//  triangle
//
//  Created by Jennifer Niang on 1/9/18.
//  Copyright © 2018 Jennifer Niang. All rights reserved.
//

#include <iostream>
#include <cmath>

//Variables for the triangle
double hypotenuse = -1;
double side1 = -1;
double side2 = -1;

//calculating the distance between two coordinates
//Information found here: https://codereview.stackexchange.com/questions/144586/finding-the-distance-between-two-points-in-c
double distance(double x1, double y1, double x2, double y2){
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
//Looking for the Hypotenuse for the Triangle
double findMax (double distance1, double distance2, double distance3){
    double maxDistance = std::max(distance1, distance2);
    maxDistance = std::max(maxDistance, distance3);
    return maxDistance;
}
//calculate each angle
//Information from classmate Kayla Cresswall
void findAngle(double distance1, double distance2, double distance3){
    // float angle1, angle2, angle3;
    //TODO: I need to finish this helper fucntion to get the angle for the obtuse and acute Triangle
    double angleA, angleB, angleC = 0;
    angleA = acos((pow(distance2, 2.0) + pow(distance3, 2.0) - pow(distance1, 2.0)) / 2 * distance2 * distance3);
    angleB = acos((pow(distance3, 2.0) + pow(distance1, 2.0) - pow(distance2, 2.0)) / 2 * distance3 * distance1);
    angleC = acos((pow(distance1, 2.0) + pow(distance2, 2.0) - pow(distance3, 2.0)) / 2 * distance1 * distance2);
}
void findSides(double distance1, double distance2, double distance3){
    double hypotenuse = findMax(distance1, distance2, distance3);
    if(distance1 == hypotenuse){
        side1 = distance2;
        side2 = distance3;
    }
    if(distance2 == hypotenuse){
        side1 = distance1;
        side2 = distance3;
    }
    if(distance3 == hypotenuse){
        side1 = distance1;
        side2 = distance2;
    }
}
//use the Distance found above to use in the Pythagorean Theroem
bool isRightTriangle (double distance1, double distance2, double distance3){
    findSides(distance1, distance2, distance3);
    //std::cout <<//TODO: this is correct my precision is off I need to round these
    return (pow(side1, 2) + pow(side2, 2)) == pow(hypotenuse, 2);
}
bool isIsocelesTriangle(double distance1, double distance2, double distance3){
    return distance1 == distance2 || distance2 == distance3 || distance1 == distance3;
}
bool isEquilateralTriangle(double distance1, double distance2, double distance3){
    
    return distance1 == distance2 && distance2 == distance3;
}
bool isAcuteTriangle(double distance1, double distance2, double distance3){
    return true;
}
bool isObtuseTriangle(double distance1, double distance2, double distance3){
    return true;
}
bool isDegenerateTriangle(double distance1, double distance2, double distance3){
    //TODO: I need the sides to be a helper function I can use the side1 and side2 in multiple  functions
    // return side1 + side2 < hypotenuse;
     findSides(distance1, distance2, distance3);
    return side1 + side2 < hypotenuse;
}

int main(int argc, const char * argv[]) {
    //message to the user for the six different coordinates for the triangle
    std::cout << "Enter Triangle x and y coordinates:\n";
    int x1, x2, x3, y1, y2, y3;
    //TODO: error message not enough coordiante points or too many inputs given
    //TODO: need to think about more than one triangle and get results back from each triangle in the same order as input and output
    //TODO: check for negative or decimals and the range is between 0-100
    
    //while loop to do mutliple inputs and outputs
    while (std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3){
        double distance1 = distance (x1, y1, x2, y2);
        double distance2 = distance (x2, y2, x3, y3);
        double distance3 = distance(x1, y1, x3, y3);
        
        if(isDegenerateTriangle(distance1, distance2, distance3)){
            std::cout << "Is a degenerate!\n";
        }else if(isRightTriangle(distance1, distance2, distance3)){
            std::cout << "Is a right Triangle!\n";
        }else if (isIsocelesTriangle(distance1, distance2, distance3)){
            std::cout << "Is an Isoceles Triangle!\n";
        }else if (isEquilateralTriangle(distance1, distance2, distance3)){
            std:: cout << "Is an Equilateral Triagnle!\n";
        }else if (isObtuseTriangle(distance1, distance2, distance3)){
            std:: cout << "Is an Obtuse Triangle!\n";
        }else if (isAcuteTriangle(distance1, distance2, distance3)){
            std:: cout << "Is an Acute Triangle!\n";
        }
    }
    
    
    return 0;
}
