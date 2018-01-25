//  triangle.cpp
//  TriangleClassifier
//
//  Created by Mason West on 1/9/18.
//  Copyright © 2018 Mason West. All rights reserved.
//
/*  This program takes an entered input of 3 coordinates and it calculates it
 the coordinates make a triangle and what type of triangle it creates.
 */

#include <cassert>
#include <cmath>
#include <iostream>
#include <math.h>

#define PI 3.14159265359

/* findDistance finds the length of each side of the triangle using
 the Pythagorean Theorem to solve
 */
float findDistance(float x1, float y1, float x2, float y2) {
    float xSquares = pow((x2 - x1), 2.0);
    float ySquares = pow((y2 - y1), 2.0);
    float distance = sqrt(xSquares + ySquares);
    return distance;
}

// Uses law of cosines to solve
float findAngleA(float c, float b, float a) {
    float A = acos((pow(b, 2.0) + pow(c, 2.0) - pow(a, 2.0)) / (2.0 * b * c));
    return A;
}

// uses law of sines to solve
float findAngleB(float c, float b, float a) {
    float B = acos((pow(a,2)+pow(c,2)-pow(b,2))/(2*a*c));
    return B;
}

//sets the precicion and sees if angles are equal withing 0.00001
bool doublesEqual(double a, double b) { return std::abs(a - b) < 0.0001; }

/* Checks if the triangle is a right triangle by checking if
 one of the angles is greater than 90 degrees
 */
bool isRight(float A, float B, float C) {
    if (doublesEqual(A, 90.0) || doublesEqual(B, 90.0) ||
        doublesEqual(C, 90.0)) {
        return true;
    } else
        return false;
}
//bool isRight(float A, float B, float C) {
//    if (A == 90 || B == 90 || C == 90) {
//        return true;
//    } else
//        return false;
//}

/* Checks if the triangle is an Isosceles triangle
 */
bool isIsosceles(float A, float B, float C, float a, float b, float c) {
    if (((A == B) || (A == C) || (B == C)) ||
        ((a == b) || (a == c) || (b == c))) {
        return true;
    } else
        return false;
}

///* Checks if the triangle is an Equilateral triangle
// */
// bool isEquilateral (float A, float B, float C, float a, float b, float
// c)
//{
//    if(((A == B) && (A == C) && (B == C)) || ((a == b) && (a == c) && (b ==
//    c)))
//    {
//        return true;
//    }
//    else return false;
//}

/* Checks if the triangle is an Obtuse triangle
 */
bool isObtuse(float A, float B, float C) {
    if ((A > 90) || (B > 90) || (C > 90)) {
        return true;
    } else
        return false;
}

/* Checks if the triangle is an Acute triangle
 */
bool isAcute(float A, float B, float C) {
    if ((A < 90) && (B < 90) && (C < 90)) {
        return true;
    } else
        return false;
}

// Checks tp make sure two entered points are not the same as well as checks the
// triangles area  Returns degenerate it area is 0 or two points are the same
bool isDegenerate(float x1, float y1, float x2, float y2, float x3,
                  float y3) {
    // Check to see if any two points entered are the same.
    if ((x1 == x2 && y1 == y2) || (x1 == x3 && y1 == y3) ||
        (x3 == x2 && y3 == y2)) {
        return true;
    }
    // Solve for the area to see if 0. If so, points are colinear. //can calc
    // slope for this as another
    if (int area =
        std::abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2) == 0) {
        return true;
    }
    return false;
}

static void triangleClassifier(int x1, int x2, int x3, int y1, int y2, int y3) {
    
    if (isDegenerate(x1, y1, x2, y2, x3, y3)) {
        std::cout << "degenerate" << std::endl;
    } else {
        float c = findDistance(x1, y1, x2, y2);
        float b = findDistance(x1, y1, x3, y3);
        float a = findDistance(x2, y2, x3, y3);
        assert(a >= 0 && b >= 0 && c >= 0); // Chris Roper's great idea
        
        // Calculates angles in triangle
        float A = (findAngleA(c, b, a) *
                    (180 / PI)); // was using Round here, and it was causing issues
        float B = (findAngleB(c, b, a) *
                    (180 / PI)); // was using Round here, and it was causing issues
        float C = 180.0 - A - B;
//        A = round(A);
//        B = round(B);
//        C = round(C);
        //        std::cout << "A = " << A << "B = " << B << "C = " << C << std::endl;
        
        // Checks triangle type
        //  if (isDegenerate(x1, y1, x2, y2, x3, y3)) {
        //    std::cout << "degenerate" << std::endl;
        //  }
        if (isRight(A, B, C)) {
            std::cout << "right" << std::endl;
        }
        //        else if(isEquilateral(A, B, C, a, b, c))
        //        {
        //            std::cout << "The input coordinates make an EQUILATERAL
        //            TRIANGLE." << std::endl; continue;
        //        }
        else if (isIsosceles(A, B, C, a, b, c)) {
            std::cout << "isosceles" << std::endl;
        } else if (isObtuse(A, B, C)) {
            std::cout << "obtuse" << std::endl;
        } else if (isAcute(A, B, C)) {
            std::cout << "acute" << std::endl;
        }
    }
}

int main(int argc, const char *argv[]) {
    
    while (true) {
        // Get information from user
        int x1, y1, x2, y2, x3, y3;
//        std::cout << "Please enter the coordinates of your triangle:" <<
//        std::endl;

        // Input Validation
        if (!(std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)) {
            break;
        }
        
        // Caluculates type of trianlge
        triangleClassifier(x1, x2, x3, y1, y2, y3);
    }
    return 0;
}
