//
//  main.cpp
//  CS6015-TriangleClassifier
//
//  Created by Irene Yeung on 1/9/18.
//  Copyright © 2018 Irene Yeung. All rights reserved.
//

#include "triangle.h"
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

/*
 Triangle Classifier Program Specifications:
 -Six integer coordinates separated by spaces must be entered.
 -All coordinates must be in range [0,100].
 -Input is zero or more lines containing triangle coordinates.
 -Behavior is undefined if input is malformed.
 -Classification Priority:  Right --> Isosceles  --> Obtuse --> Acute -->
 Degenerate
 */

void triangleClassifier() {
  while (true) {
    std::vector<xycoordinate> coordinates;
    double x1, y1, x2, y2, x3, y3;
    if (!(std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)) { // ie std::cin.eof()
      break;
    }
    if (!coordinatesValid(x1, y1, x2, y2, x3, y3)) {
      std::cout << "Out of Range\n";
    } else {
      coordinates = getCoordinates(x1, y1, x2, y2, x3, y3);
      if (isDegenerate(coordinates)) {
        std::cout << "degenerate\n";
        continue;
      } else {
        std::cout << classifyTriangle(coordinates) << std::endl;
      }
    }
  }
}

const double PI() { return std::atan(1) * 4; }
double radDegConv(double theta) { return (theta * PI()) / 180.0; }

bool checkEqual(double a, double b) { return std::abs(a - b) <= 1E-6; }

bool checkSlopeEq(std::vector<xycoordinate> coordinates) {
  return getGradient(coordinates[0], coordinates[1]) ==
             getGradient(coordinates[1], coordinates[2]) ||
         getGradient(coordinates[1], coordinates[2]) ==
             getGradient(coordinates[2], coordinates[0]) ||
         getGradient(coordinates[2], coordinates[0]) ==
             getGradient(coordinates[0], coordinates[1]);
}

double getGradient(xycoordinate p1, xycoordinate p2) {
  return p1.x == p2.x ? -101 : (p2.y - p1.y) / (p2.x - p1.x);
    // return -101 to handle vertical lines with undef slope (ie check for division by zero)
}

bool isDegenerate(std::vector<xycoordinate> points) {
  return duplicateVertices(points) || checkSlopeEq(points);
}

bool duplicateVertices(std::vector<xycoordinate> points) {
  return (points[0].x == points[1].x && points[0].y == points[1].y) ||
         (points[1].x == points[2].x && points[1].y == points[2].y) ||
         (points[2].x == points[0].x && points[2].y == points[0].y);
}

bool coordinatesValid(double x1, double y1, double x2, double y2, double x3,
                      double y3) {
  double min = 0;
  double max = 100;
  return x1 >= min && x1 <= max && y1 >= min && y1 <= max && x2 >= min &&
         x2 <= max && y2 >= min && y2 <= max && x3 >= min && x3 <= max &&
         y3 >= min && y3 <= max;
}

std::vector<xycoordinate> getCoordinates(double x1, double y1, double x2,
                                         double y2, double x3, double y3) {
  std::vector<xycoordinate> coordinates;
  coordinates.push_back(xycoordinate(x1, y1));
  coordinates.push_back(xycoordinate(x2, y2));
  coordinates.push_back(xycoordinate(x3, y3));
  return coordinates;
}

double getSideLength(xycoordinate p1, xycoordinate p2) {
  return sqrt(pow((p2.y - p1.y), 2) + pow((p2.x - p1.x), 2));
}

double getLargestAngle(double lengthA, double lengthB, double lengthC) {
  return std::acos((pow(lengthA, 2) + pow(lengthB, 2) - pow(lengthC, 2)) /
                   (2 * lengthA * lengthB));
}

std::vector<double> getLengths(std::vector<xycoordinate> vertices) {
  std::vector<double> lengths;
  lengths.push_back(getSideLength(vertices[0], vertices[1]));
  lengths.push_back(getSideLength(vertices[1], vertices[2]));
  lengths.push_back(getSideLength(vertices[2], vertices[0]));
  return lengths;
}

std::vector<double> getAngles(std::vector<xycoordinate> vertices) {
  std::vector<double> angles;
  std::vector<double> lengths = getLengths(vertices);
  angles.push_back(getLargestAngle(lengths[0], lengths[1], lengths[2]));
  angles.push_back(getLargestAngle(lengths[1], lengths[2], lengths[0]));
  angles.push_back(getLargestAngle(lengths[2], lengths[0], lengths[1]));
  return angles;
}

bool isRightAngle(std::vector<double> thetas) {
  return checkEqual(thetas[0], radDegConv(90.0)) ||
         checkEqual(thetas[1], radDegConv(90.0)) ||
         checkEqual(thetas[2], radDegConv(90.0));
}

bool isIsosc(std::vector<double> lengths, std::vector<double> thetas) {
  return checkEqual(lengths[0], lengths[1]) ||
         checkEqual(lengths[1], lengths[2]) ||
         checkEqual(lengths[0], lengths[2]);
}

bool isObtuse(std::vector<double> lengths, std::vector<double> thetas) {
  return thetas[0] > radDegConv(90.0) || thetas[1] > radDegConv(90.0) ||
         thetas[2] > radDegConv(90.0);
}

std::string classifyTriangle(std::vector<xycoordinate> vertices) {
  std::vector<double> sides = getLengths(vertices);
  std::vector<double> angles = getAngles(vertices);
  if (isRightAngle(angles)) {
    return "right";
  } else if (isIsosc(sides, angles)) {
    return "isosceles";
  } else if (isObtuse(sides, angles)) {
    return "obtuse";
  } else {
    return "acute"; // If other conditions are false, triangle must be acute
  }
}

int main() {
  triangleClassifier();
}
