//
//  main.cpp
//  triangle
//
//  Created by Matt Josse on 1/12/18.
//  Copyright © 2018 Matt Josse. All rights reserved.
//

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#define PI 3.14159265

// An instance of Triangle does not guarantee a valid triangle. Invoking the
// is_valid() method determines its existence.
struct Triangle {
  int x1, y1, x2, y2, x3, y3;
  double len1, len2, len3, ang1, ang2, ang3;
  Triangle(int x1, int y1, int x2, int y2, int x3, int y3);
  void print_values();
  bool is_valid();
  bool is_right();
  bool is_isosceles();
  bool is_obtuse();
  bool is_acute();
  std::string classify();
};

// Calculates side length and angles (in degrees). Implements the distance
// formula and the law of cosines.
Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3)
: x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {
  len1 = sqrt((pow(x2 - x1, 2)) + (pow(y2 - y1, 2)));
  len2 = sqrt((pow(x3 - x2, 2)) + (pow(y3 - y2, 2)));
  len3 = sqrt((pow(x1 - x3, 2)) + (pow(y1 - y3, 2)));
  ang1 =
  acos(((pow(len2, 2) + pow(len3, 2)) - pow(len1, 2)) / (2 * len2 * len3)) *
  180 / PI;
  ang2 =
  acos(((pow(len3, 2) + pow(len1, 2)) - pow(len2, 2)) / (2 * len3 * len1)) *
  180 / PI;
  ang3 = 180 - (ang1 + ang2);
}

// A valid triangle is represented by three cartesian coordinate points whose
// area is greater than zero. Implements Heron's formula.
bool Triangle::is_valid() {
  double p = (len1 + len2 + len3) / 2;
  double area = sqrt(p * (p - len1) * (p - len2) * (p - len3));
  return (area > 0);
}

// Returns true if a valid triangle and contains a single angle of 90 degrees.
// Implements a forgiving arbitrary epsilon value.
bool Triangle::is_right() {
  const double e = 0.0001;
  return is_valid() &&
  (abs(ang1 - 90.0) < e || abs(ang2 - 90.0) < e || abs(ang3 - 90.0) < e);
}

// Returns true if a valid triangle and at least two of the three side lengths
// are equal. Input restricted to integers does not necessitate an espsilon
// value.
bool Triangle::is_isosceles() {
  return is_valid() && (len1 == len2 || len2 == len3 || len3 == len1);
}

// Returns true if a valid triangle and any angle is greater than or equal to
// 90 degrees.
bool Triangle::is_obtuse() {
  return is_valid() && (ang1 >= 90 || ang2 >= 90 || ang3 >= 90);
}

// Returns true if a valid triangle and all three angles are less than 90
// degrees.
bool Triangle::is_acute() {
  return is_valid() && (ang1 < 90.0 && ang2 < 90.0 && ang3 < 90.0);
}

// Returns a string representation of the Triangle class. If not a valid
// triangle, returns "degenerate".
// Possible output: "right", "isosceles", "obtuse", "acute" and "degenerate".
// Equilateral is impossible with whole number coordinates and obtuse and acute
// triangle classifications are assumed to be scalene.
std::string Triangle::classify() {
  if (is_right()) {
    return "right";
  } else if (is_isosceles()) {
    return "isosceles";
  } else if (is_obtuse()) {
    return "obtuse";
  } else if (is_acute()) {
    return "acute";
  } else {
    return "degenerate";
  }
}

// Input/output via stdio. Provided a list of cartesian coordinate points,
// prints the classification of any valid triangle according to the Triangle's
// classify() documentation.
void triangle_util() {
  std::cout << "Enter six integer coordinates (e.g. x1, y1, x2, y2, x3, y3):\n";
  int x1, y1, x2, y2, x3, y3;
  while (std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {
    std::cout << Triangle(x1, y1, x2, y2, x3, y3).classify() << "\n";
  }
}

int main() {
  triangle_util();
  return 0;
}
