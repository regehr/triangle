//
//  triangle.cpp
//  A Triangle classifier that will return the type of
//  triangle supplied as an input. Possible outputs are:
//
//  right triangle: one 90 degree angle
//  isosceles: two sides same length
//  equilateral: all sides same length
//  obtuse: one angle >90
//  acute: all angles <90
//  scalene: all three sides are different lengths
//  degenerate: not a triangle
//
//  Assumes a valid input will be given from [0-100]. Also, the
//  type of triangle will return following the order presented above,
//  which means that an equilateral triangle will always return
//  as an isosceles triangle.
//
//  Created by Doug on 1/9/18.
//  Copyright © 2018 Doug. All rights reserved.
//

#include <cmath> // for std::abs
#include <iostream>
#include <math.h>
#define PI 3.14159265

//  Forward declare functions
std::string getTriangleType(int x1, int y1, int x2, int y2, int x3, int y3);
double distanceFormula(int x1, int y1, int x2, int y2);
double findAngle(double a, double b, double c);
bool doublesEqual(double a, double b);

int main(int argc, const char *argv[]) {

  while (true) {
    // Get the three point coordinates
    int x1, y1, x2, y2, x3, y3;
    if (!(std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)) {
      break;
    }

    // Get the type of the triangle
    std::string type = getTriangleType(x1, y1, x2, y2, x3, y3);

    // Print out the type of triangle
    std::cout << type << "\n";
  }

  return 0;
}

/* Sets the type of a triangle
 */
std::string getTriangleType(int x1, int y1, int x2, int y2, int x3, int y3) {

  // Determine the three side lengths
  double sideA = distanceFormula(x1, y1, x2, y2);
  double sideB = distanceFormula(x2, y2, x3, y3);
  double sideC = distanceFormula(x3, y3, x1, y1);

  // determine the three angles
  double angleA = findAngle(sideB, sideC, sideA);
  double angleB = findAngle(sideC, sideA, sideB);
  double angleC = findAngle(sideA, sideB, sideC);

  // If two or more points are the same, this isn't a triangle
  if ((x1 == x2 && y1 == y2) || (x2 == x3 && y2 == y3) ||
      (x3 == x1 && y3 == y1)) {
    return "degenerate";
  }

  // If the length of a side is >= the sum of the others, not a triangle
  if (sideA >= sideB + sideC || sideB >= sideA + sideC ||
      sideC >= sideA + sideB) {
    return "degenerate";
  }

  // If one of the angles is 90 degrees, right triangle
  if (doublesEqual(angleA, 90.0) || doublesEqual(angleB, 90.0) ||
      doublesEqual(angleC, 90.0)) {
    return "right triangle";
  }

  // If two or more sides are the same, isosceles triangle
  if (doublesEqual(sideA, sideB) || doublesEqual(sideB, sideC) ||
      doublesEqual(sideC, sideA)) {
    return "isosceles";
  }

  // If one of the angles is > 90 degrees, obtuse triangle
  if (angleA > 90 || angleB > 90 || angleC > 90) {
    return "obtuse";
  }

  // If all angles are < 90 degrees (This is the last option, so if code
  // reaches this far, this is what we have)
  // Dead code from old if statement: if (angleA < 90.0 && angleB < 90.0 &&
  // angleC < 90.0)
  return "acute";
}

/* Calculates the distance between two points using the distance formula:
 * distance = sqrt( (x2-x1)^2 + (y2-y1)^2 )
 */
double distanceFormula(int x1, int y1, int x2, int y2) {
  return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

/* Calculates the angle opposite of side c using the Law of Cosines
 */
double findAngle(double a, double b, double c) {
  double math = (pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b);
  return acos(math) * 180.0 / PI;
}

/* Returns true if two doubles are equal to each other with
 * a margin of error of .000001
 */
bool doublesEqual(double a, double b) { return std::abs(a - b) < 0.000001; }
