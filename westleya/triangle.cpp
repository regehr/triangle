//
//  triangle.cpp
//  triangle classifier
//
//  Created by Westley Kirkham on 1/9/18.
//  Copyright © 2018 Westley Kirkham. All rights reserved.
//

#include <cstdio>
#include <fstream>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

/*
 * Takes a string and makes a vector containing
 * any numbers present in the string. Separations
 * occur at any non-digit character.
 */
std::vector<int> stringToVec(std::string s) {
  std::vector<int> vec_of_int;

  for (int i = 0; i < s.length(); i++) {
    std::string next = "";

    while (
        isdigit(s[i])) { // http://www.cplusplus.com/reference/cctype/isdigit/
      next += s[i];
      i++;
    }

    if (next.length() > 0) {
      int next_num =
          std::stoi(next); // http://www.cplusplus.com/reference/string/stoi/
      vec_of_int.push_back(next_num);
    }
  }

  return vec_of_int;
}

/*
 * Checks for input that doesn't produce a triangle.
 * Any input without enough points, anything out of
 * bounds, or any points that are insufficient to
 * define a triangle qualify as degenerate.
 */
bool isDegenerate(std::vector<int> tri_pts) {

  if (tri_pts.size() != 6) {
    return true;
  }

  for (int c : tri_pts) {
    if (c > 100 || c < 0) {
      return true;
    }
  }

  int x1 = tri_pts[0], x2 = tri_pts[2], x3 = tri_pts[4];
  int y1 = tri_pts[1], y2 = tri_pts[3], y3 = tri_pts[5];
  // http://www.cplusplus.com/reference/cmath/fabs/
  // if all x values are the same, if any of the three points are the same, or
  // if the slope of two of the lines are the same it is not a triangle.
  if ((x1 == x2 && x3 == x2) || (x1 == x2 && y1 == y2) ||
      (y2 == y3 && x3 == x2) || (x1 == x3 && y3 == y1)) {
    return true;
  } else if (x1 != x2 && x2 != x3 &&
             fabs((y1 - y2) / (x1 - x2) - (y2 - y3) / (x2 - x3)) < 0.00001) {
    return true;
  }

  return false;
}

/*
 * Calculates an angle using Law of Cosines
 */
float triangleAngles(float a, float b, float c) {
  // reminder to check for radians/degrees from Mason.
  // div/0?
  float angle_rad = acosf((-pow(a, 2) + pow(b, 2) + pow(c, 2)) / (2 * b * c));
  float angle_deg = angle_rad * 180 / 3.1415926;
  return angle_deg;
}

/*
 * All sides can be calculated using the
 * Pythagorean Theorem.
 */
float triangleSides(int x1, int y1, int x2, int y2) {
  float side = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
  return side;
}
/*
 * Returns a classification of the triangle
 * described by the three points provided.
 */
void classifyTriangle(std::vector<int> tri_pts) {

  int x1 = tri_pts[0], x2 = tri_pts[2], x3 = tri_pts[4];
  int y1 = tri_pts[1], y2 = tri_pts[3], y3 = tri_pts[5];
  // I got the idea to calculate sides and angles
  // first and then do checks from Doug.
  float side_a = triangleSides(x1, y1, x2, y2);
  float side_b = triangleSides(x2, y2, x3, y3);
  float side_c = triangleSides(x3, y3, x1, y1);

  float angle_a = triangleAngles(side_a, side_b, side_c);
  float angle_b = triangleAngles(side_b, side_c, side_a);
  float angle_c = 180 - (angle_a + angle_b);

  // The specs require that only one defining characteristic of
  // the triangle be reported, with priority in the following
  // order: right, isosceles, equilateral (impossible), obtuse,
  // acute, scalene (impossible). Equilateral and scalene are
  // therefore, omitted.
  float tolerance = 0.00001; // arbitrarily assigned

  if (fabs(angle_a - 90) < tolerance || fabs(angle_b - 90) < tolerance ||
      fabs(angle_c - 90) < tolerance) {
    std::cout << "right\n";
    return;
  } else if (fabs(side_a - side_b) < tolerance ||
             fabs(side_b - side_c) < tolerance ||
             fabs(side_a - side_c) < tolerance) {
    std::cout << "isosceles\n";
    return;
  } else if ((angle_a - 90) > tolerance || (angle_b - 90) > tolerance ||
             (angle_c - 90) > tolerance) {
    std::cout << "obtuse\n";
    return;
  } else {
    std::cout << "acute\n";
    return;
  }
}

int main() {

  std::string user_input;

  while (getline(std::cin, user_input)) {

    std::vector<int> tri_pts = stringToVec(user_input);

    if (isDegenerate(tri_pts)) {
      std::cout << "degenerate\n";
      continue;
    }

    classifyTriangle(tri_pts);
  }

  return 0;
}
