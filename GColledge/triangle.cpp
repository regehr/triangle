//
//  traingle.cpp
//  MSD_6015
//
//  Created by Gregory Colledge on 1/9/18.
//  Copyright © 2018 Gregory Colledge. All rights reserved.
//
//  The following link was used for reference:
//  https://stackoverflow.com/questions/1321137/convert-string-containing-several-numbers-into-integers

#include <algorithm>
#include <iostream>
#include <math.h>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>

#define PI 3.14159265

/*
 * distanceBetweenTwoPoints
 *  firstX - the x component of the first point.
 *  firstY - the y component of the first point.
 *  secondX - the x component of the second point.
 *  secondY - the y component of the second point.
 */
float distanceBetweenTwoPoints(float firstX, float firstY, float secondX,
                               float secondY) {
  float result =  sqrt((firstX - secondX) * (firstX - secondX) +
              (firstY - secondY) * (firstY - secondY));
  assert(result >= 0);
    return result;
}

/*
 * classifyTriangle
 *  parameters are the x and y components of the three points.
 *  returns - no return value. The result of running this function is a
 *    single word printed to the console identifying the type of triangle.
 */

int classifyTriangle(float x1, float y1, float x2, float y2, float x3,
                     float y3) {
  // Test for a triangle
  // chekc for verticle line
  if (x1 - x2 == 0 && x1 - x3 == 0) {
    std::cout << "degenerate\n"; // All points fall on a line.
    return 0;
  }
  // check for any other line
  float slope;
  if (x1 != x2) {
    slope = (y1 - y2) / (x1 - x2);
  } else {
    slope = (y3 - y2) / (x3 - x2);
  }
  float intercept = y1 - slope * x1;

  if (y3 == (slope * x3 + intercept)) {
    std::cout << "degenerate\n"; // All points fall on a line.
    return 0;
  }

  // calculate side lengths
  float sideA = distanceBetweenTwoPoints(x1, y1, x2, y2);
  float sideB = distanceBetweenTwoPoints(x2, y2, x3, y3);
  float sideC = distanceBetweenTwoPoints(x3, y3, x1, y1);
  std::vector<float> sides;
  sides.push_back(sideA);
  sides.push_back(sideB);
  sides.push_back(sideC);

  std::sort(sides.begin(),
            sides.end()); // sort the side lengths for further use.
  // the first is the smallest, the last is the largest
  assert(sides[2] < sides[0] + sides[1]);
  // check for right triangles
  // test using the pythagorean theorem
  if (abs(sides[0] * sides[0] + sides[1] * sides[1] - sides[2] * sides[2]) <=
      0.005) {
    // above is the pythagorean theorem solved for zero
    std::cout << "right\n";
    return 1;
  }

  // check for Isosceles triangle
  if (abs(sides[1] - sides[0]) <= 0.0001 ||
      abs(sides[2] - sides[1]) <= 0.0001) {
    std::cout << "isosceles\n";
    return 1;
  }

  // check for obtuse
  // by finding the largest angle
  float largeAngle =
      acos((pow(sides[2], 2) - pow(sides[1], 2) - pow(sides[0], 2)) /
           (-2 * sides[1] * sides[0]));
  /*the above line is the law of cosines solved for the angle. The largest angle
   *is solved for by the fact that the largest side is always opposite the
   *largest angle.
   */

  if (largeAngle * (180.0 / PI) >
      90.0) { // convert to degrees before making the comparison.
    std::cout << "obtuse\n";
    return 1;
  } else { // if it isnt an obtuse or a right triangle then it must be acute
    std::cout << "acute\n";
    return 1;
  }
}

int main(int argc, const char *argv[]) {
  float points[] = {0, 0, 0, 0, 0, 0};

  //// Removed for testing purposes.
  //  std::cout << "Enter the points of a triangle as follows:\n";
  //  std::cout << "x1 y1 x2 y2 x3 y3\n";
  //  std::cout
  //      << "Where each x and y can be integers between 0 and 100
  //      inclusive.\n";
  //  std::cout << "Press enter after each set of 6 numbers.\n";

  do {
    if (!(std::cin >> points[0] >> points[1] >> points[2] >> points[3] >>
          points[4] >> points[5])) {
      break;
    }
    classifyTriangle(points[0], points[1], points[2], points[3], points[4],
                     points[5]);
  } while (true);
}
