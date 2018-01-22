//
//  main.cpp
//  triangle
//
//  Created by Jennifer Niang on 1/9/18.
//  Copyright © 2018 Jennifer Niang. All rights reserved.
//

#include <iostream>
#include <cmath>
#define PI 3.14159265;

//Variables for the triangle
double hypotenuse, side1, side2 = -1;
//double angleA, angleB, angleC = 0;

//calculating the distance between two coordinates
//Information found here: https://codereview.stackexchange.com/questions/144586/finding-the-distance-between-two-points-in-c
double distance(double x1, double y1, double x2, double y2){
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
//Looking for the Hypotenuse for the Triangle
double findMax (double distance1, double distance2, double distance3){
    double maxDistance = std::max(distance1, distance2);
    maxDistance = std::max(maxDistance, distance3);
    return maxDistance;
}
//calculate each angle
//Information from classmate Kayla Cresswall
double findAngle(double distance1, double distance2, double distance3){
    // float angle1, angle2, angle3;
    //TODO: I need to finish this helper fucntion to get the angle for the obtuse and acute Triangle
    double math =(pow(distance1,2)+ pow(distance2,2)-pow(distance3,2))/(2*distance1*distance2);
    return acos(math)*180.0/PI;
}
//helper function that returns nothing this helps to find the maximum side which is the hypotenuse
void findSides(double distance1, double distance2, double distance3){
    hypotenuse = findMax(distance1, distance2, distance3);
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
//this function helps with the precision when sides are equal
bool isEqual(double d1, double d2) {
    return fabs(d1 - d2) < 10e-5;
    //changed abs to fabs becuse the abs is for integers not double or floating points
}
//use the Distance found above to use in the Pythagorean Theroem
bool isRightTriangle (double distance1, double distance2, double distance3){
    findSides(distance1, distance2, distance3);
    //std::cout <<//TODO: this is correct my precision is off I need to round these
    //double sidesTogether = round(pow(side1, 2) + pow(side2, 2));
    //double hypotenuse2 = round(pow(hypotenuse, 2));
    //std::cout << sidesTogether << std::endl;
    //std::cout << hypotenuse2 << std::endl;
    //std::cout << (sidesTogether == hypotenuse2) << std::endl;
    
    return round(pow(side1, 2) + pow(side2, 2)) == round(pow(hypotenuse, 2));
}
//use the helper function and then find two sides that are equal
bool isIsocelesTriangle(double distance1, double distance2, double distance3){
    findSides(distance1, distance2, distance3);
    return distance1 == distance2 || distance2 == distance3 || distance1 == distance3;
}
//use the helper function and code will never give equilateral becauseit will give the
//acute before this answer
bool isEquilateralTriangle(double distance1, double distance2, double distance3){
    findSides(distance1, distance2, distance3);
    return distance1 == distance2 && distance2 == distance3;
}
bool isAcuteTriangle(double distance1, double distance2, double distance3){
    double angleA = findAngle(distance2, distance3, distance1);
    double angleB = findAngle(distance3, distance1, distance2);
    double angleC = findAngle(distance1, distance2, distance3);
    
    return (angleA < 90 && angleB < 90 && angleC < 90);
}
bool isObtuseTriangle(double distance1, double distance2, double distance3){
    double angleA = findAngle(distance2, distance3, distance1);
    double angleB = findAngle(distance3, distance1, distance2);
    double angleC = findAngle(distance1, distance2, distance3);
    return (angleA > 90 || angleB > 90 || angleC > 90);
}
bool isDegenerateTriangle(double distance1, double distance2, double distance3){
    //TODO: I need the sides to be a helper function I can use the side1 and side2 in multiple functions
    // return side1 + side2 < hypotenuse;
     findSides(distance1, distance2, distance3);
    return side1 + side2 < hypotenuse || isEqual(side1 + side2, hypotenuse);
}

int main(int argc, const char * argv[]) {
    //message to the user for the six different coordinates for the triangle
    //std::cout << "Enter Triangle x and y coordinates:\n";
    int x1, x2, x3, y1, y2, y3;
    //TODO: error message not enough coordiante points or too many inputs given
    //TODO: need to think about more than one triangle and get results back from each triangle in the same order as input and output
    //TODO: check for negative or decimals and the range is between 0-100
    //TODO: error checking for divide by zero
    //TODO: add asserts of angle, length and all angles can only add up to 180
    //TODO: for some reason testing many at the same time I miss a few results at the end of the testing program bug
    
    
    //while loop to do mutliple inputs and outputs
    while (std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3){
        double distance1 = distance (x1, y1, x2, y2);
        double distance2 = distance (x2, y2, x3, y3);
        double distance3 = distance(x1, y1, x3, y3);
        
        // integers entered should be between 0 and 100 inclusively
        if (x1 < 0 || x2 < 0 || x3 < 0 || y1 < 0 || y2 < 0 || y3 < 0 ||x1 > 100 ||
            x2 > 100 || x3 > 100||y1 > 100 ||y2 > 100 || y3 > 100) {
            std::cout << "Error: Inputs out of data range. Points should be integers between 0 and 100.\n";
        } else if(isDegenerateTriangle(distance1, distance2, distance3)){
            std::cout << "degenerate\n";
        }else if(isRightTriangle(distance1, distance2, distance3)){
            std::cout << "right\n";
        }else if (isIsocelesTriangle(distance1, distance2, distance3)){
            std::cout << "isosceles\n";
            //change in travis spelled isosceles wrong 
        }//removed the code will never reach the equilateral because always be acute
        //else if (isEquilateralTriangle(distance1, distance2, distance3)){
          //  std:: cout << "equilateral\n";
        //}
        else if (isObtuseTriangle(distance1, distance2, distance3)){
            std:: cout << "obtuse\n";
        }else if (isAcuteTriangle(distance1, distance2, distance3)){
            std:: cout << "acute\n";
        }//removed the code will never reach the scalene because scalene is also a right triangle
        //else if(isScaleneTriangle(distance1, distance2, distance3)){
          //  std:: cout << "scalene\n";
        //}
    }
    
    
    return 0;
}
