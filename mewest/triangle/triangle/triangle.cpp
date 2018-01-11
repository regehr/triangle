//  triangle.cpp
//  TriangleClassifier
//
//  Created by Mason West on 1/9/18.
//  Copyright © 2018 Mason West. All rights reserved.
//
/*  This program takes an entered input of 3 coordinates and it calculates it the coordinates make a triangle and what
 type of triangle it creates.
 */

#include <iostream>
#include <cmath>
#include <math.h>
#include <cassert>

#define PI 3.14159265359

/* findDistance finds the length of each side of the triangle using
 the Pythagorean Theorem to solve
 */
double findDistance (double x1, double y1, double x2, double y2)
{
    double xSquares = pow((x2 - x1), 2.0);
    double ySquares = pow((y2 - y1), 2.0);
    double distance = sqrt(xSquares + ySquares);
    return distance;
}

//Uses law of cosines to solve
double findAngleA(double c, double b, double a)
{
    double cosA = (pow(b, 2.0) + pow(c, 2.0) - pow(a, 2.0)) / (2.0 * b * c);
    double A = acos(cosA);
    return A;
}

//uses law of sines to solve
double findAngleB(double c, double b, double a, double A)
{
    double sinB = (b * sin(A * (PI / 180.0))) / a;
    double B = asin(sinB);
    return B;
}

/* Checks if the triangle is a right triangle by checking if
 one of the angles is greater than 90 degrees
 */
bool isRight (double A, double B, double C)
{
    if((A == 90) || (B == 90) || (C == 90))
    {
        return true;
    }
    else return false;
}

/* Checks if the triangle is an Isosceles triangle
 */
bool isIsosceles (double A, double B, double C, double a, double b, double c)
{
    if(((A == B) || (A == C) || (B == C)) || ((a == b) || (a == c) || (b == c)))
    {
        return true;
    }
    else return false;
}

/* Checks if the triangle is an Equilateral triangle
 */
bool isEquilateral (double A, double B, double C, double a, double b, double c)
{
    if(((A == B) && (A == C) && (B == C)) || ((a == b) && (a == c) && (b == c)))
    {
        return true;
    }
    else return false;
}

/* Checks if the triangle is an Obtuse triangle
 */
bool isObtuse (double A, double B, double C)
{
    if((A > 90) || (B > 90) || (C > 90))
    {
        return true;
    }
    else return false;
}

/* Checks if the triangle is an Acute triangle
 */
bool isAcute (double A, double B, double C)
{
    if((A < 90) && (B < 90) && (C < 90))
    {
        return true;
    }
    else return false;
}

int main(int argc, const char * argv[]) {
    
    while(true){
        //Get information from user
        double x1, y1, x2, y2, x3, y3;
        std::cout << "Please enter the coordinates of your triangle:" << std::endl;
        std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        
        //Input Validation
        if(!(y3 >= 1)){
            std::cout << "Improper data entered." << std::endl;
        }
        //Check to see if any two points entered are the same.
        if((x1 == x2 && y1 == y2) || (x1 == x3 && y1 == y3) || (x3 == x2 && y3 == y2)){
            std::cout << "Improper data entered. Two points are the same." << std::endl;
            break;
        }
        //Solve for the area to see if 0. If so, points are colinear.
        if( abs((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2))/2) == 0){
            std::cout << "Improper data entered. Points are collinear." << std::endl;
            break;
        }
        std::cout << "We got your coords, calculating response:" << std::endl;
        
        //Caluculates length of sides
        double c = findDistance(x1, y1, x2, y2);
        double b = findDistance(x1, y1, x3, y3);
        double a = findDistance(x2, y2, x3, y3);
        assert(a > 0 && b > 0 && c > 0); //Chris Roper's great idea
        
        //Calculates angles in triangle
        double A = round(findAngleA(c, b, a) * (180/PI));
        double B = round(findAngleB(c, b, a, A) * (180/PI));
        double C = 180.0 - A - B;
        
        //Checks triangle type
        if(isRight(A, B, C))
        {
            std::cout << "The input coordinates make a RIGHT TRIANGLE." << std::endl;
            continue;
        }
        else if(isEquilateral(A, B, C, a, b, c))
        {
            std::cout << "The input coordinates make an EQUILATERAL TRIANGLE." << std::endl;
            continue;
        }
        else if(isIsosceles(A, B, C, a, b, c))
        {
            std::cout << "The input coordinates make an ISOSCELES TRIANGLE." << std::endl;
            continue;
        }
        else if(isObtuse(A, B, C))
        {
            std::cout << "The input coordinates make an OBTUSE SCALENE TRIANGLE." << std::endl;
            continue;
        }
        else if(isAcute(A, B, C))
        {
            std::cout << "The input coordinates make an ACUTE SCALENE TRIANGLE." << std::endl;
            continue;
        }
    }
    return 0;
}
//bool isDegenerate (double x1, double y1, double x2, double y2, double x3, double y3)
//{
//    //if a2 + b2 != c2 then its not a triangle
//    //if any points equal
//    if((x1 == x2 && y1 == y2) || (x1 == x3 && y1 == y3) || (x3 == x2 && y3 == y2)){
//        return true;
//    }
//    //if points are in line
//    else if(){
//
//    }
//}

