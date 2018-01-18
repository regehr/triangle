//
//  triangle.h
//  CS6015-TriangleClassifier
//
//  Created by Irene Yeung on 1/13/18.
//  Copyright © 2018 Irene Yeung. All rights reserved.
//

#ifndef triangle_h
#define triangle_h

#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

struct xycoordinate {
  double x, y;
  xycoordinate(double x, double y) : x(x), y(y) {}
};

/* getCoordinates  -- converts std::cin input to xycoordinate structs
 @param - 6 input values representing coordinates on a plane.
 @result - vector of xycoordinate structs */
std::vector<xycoordinate> getCoordinates(double x1, double y1, double x2,
                                         double y2, double x3, double y3);

/* isDegenerate -- validates triangle coordinates
 @param vector of xycoordinates
 @result true if points are collinear or duplicate, else returns false */

bool isDegenerate(std::vector<xycoordinate> points);

/* duplicateVertices -- checks for duplicate vertices
 @param vector of xycoordinates
 @result returns true if any two points are equivalent */

bool duplicateVertices(std::vector<xycoordinate> points);

/* coordinatesValid -- verifies coordinates are in range [0,100]
 @param coordinates
 @result false if coordinates are out of range, else returns true */

bool coordinatesValid(double x1, double y1, double x2, double y2, double x3,
                      double y3);

/* getGradient -- calculates slope between two points
 @param two xycoordinates
 @result returns -101 if x coordinates are identical; else returns delta y/delta
 x */
double getGradient(xycoordinate p1, xycoordinate p2);

/* checkSlopeEq -- checks for collinear points
 @param vector of xycoordinates
 @result true if any two points are collinear */

bool checkSlopeEq(std::vector<xycoordinate> coordinates);

/* getSideLength -- calculates length of side using Pythagorean Theorem
 @param two xycoordinate points
 @result double side length */

double getSideLength(xycoordinate p1, xycoordinate p2);

const double PI();

double radDegConv(double theta);

/* checkEqual -- verifies if two doubles are equal to 1E-6 precision
 @param two doubles
 @result true if doubles are within 1E-6 precision */

bool checkEqual(double a, double b);

/* getLargestAngle -- uses law of cosines to calculate an angle from 3 lengths
 @param 3 lengths of triangle
 @result angle in radians of a given angle */

double getLargestAngle(double lengthA, double lengthB, double lengthC);

std::vector<double> getLengths(std::vector<xycoordinate> vertices);
std::vector<double> getAngles(std::vector<xycoordinate> vertices);

bool isRightAngle(std::vector<double> thetas);
bool isIsosc(std::vector<double> lengths, std::vector<double> thetas);
bool isObtuse(std::vector<double> lengths, std::vector<double> thetas);
bool isAcute(std::vector<double> lengths, std::vector<double> thetas);
std::string classifyTriangle(std::vector<xycoordinate> vertices);
void triangleClassifier();

#endif /* triangle_h */
