//
//  main.cpp
//  assignment01.triangleClassifier
//
//  Created by Matt Josse on 1/9/18.
//  Copyright © 2018 Matt Josse. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <cmath>

#define PI 3.14159265

/**
 * A representation of a triangle. Whether or not an instance of the Triangle
 * object actually represents a valid triangle is not guaranteed simply because
 * the object exists.
 */
struct Triangle {
  int x1, x2, x3; // May be able to remove these as private members
  int y1, y2, y3;
  double side1, side2, side3;
  double angle1, angle2, angle3;
  Triangle(int x1, int x2, int x3, int y1, int y2, int y3);
  bool is_triangle();
  bool is_right_triangle();
  bool is_isoceles();
  bool is_equilateral();
  bool is_obtuse();
  bool is_acute();
  std::string get_classification();
};

/**
 * Instantiates a Triangle object. Provided with all three x-coordinates
 * followed by all three y-coordiantes, determines the lengths of the three
 * sides and the corresponding angles (in degrees).
 */
Triangle::Triangle(int x1, int x2, int x3, int y1, int y2, int y3)
:x1(x1), x2(x2), x3(x3), y1(y1), y2(y2), y3(y3) {
  
  /*
   * The distance formula computes all three side lengths of the triangle when
   * only three coordinate points are given.
   */
  side1 = sqrt((pow(x2 - x1, 2)) + (pow(y2 - y1, 2)));
  side2 = sqrt((pow(x3 - x2, 2)) + (pow(y3 - y2, 2)));
  side3 = sqrt((pow(x1 - x3, 2)) + (pow(y1 - y3, 2)));
  
  /*
   * The law of cosines describes the calculation of angles within a triangle
   * when only the side lengths are known. The C++ documentation describes the
   * conversion from radians to degrees when implementing arc cosine.
   */
  angle1 = acos(((pow(side2, 2) + pow(side3, 2)) - pow(side1, 2)) /
                (2 * side2 * side3)) * 180 / PI;
  angle2 = acos(((pow(side3, 2) + pow(side1, 2)) - pow(side2, 2)) /
                (2 * side3 * side1)) * 180 / PI;
  angle3 = 180 - (angle1 + angle2);
}

/**
 * Determines whether the three coordinate points within a Triangle object
 * actually represent a valid triangle shape. A valid triangle is a geometric
 * shape containing three vertices where each vertex occupies its own unique
 * coordinate point and the shape itself is in harmony with the Triangle
 * Inequality Theorem.
 *
 * @return true if the object actually represents a valid triangle
 */
bool Triangle::is_triangle() {
  
  // Multiple points cannot exist at the same coordinates
  if ((x1 == x2 && y1 == y2) || (x2 == x3 && y2 == y3) ||
      (x3 == x1 && y3 == y1)) {
    return false;
  }
  
  /*
   * Triangle Inequality Theorem - The sum of the lengths of two sides of a
   * triangle must always be greater than the third side.
   */
  if (!((side1 + side2) > side3) && ((side2+ side3) > side1) &&
      ((side3 + side1) > side2)) {
    return false;
  }
  
  // TODO: A test specific to collinearity?
  return true;
}

/**
 * Returns true if the triangle object represents a valid triangle and the
 * square of two sides is equal to the square of the third (Pathagorean Theorem).
 * Otherwise returns false.
 *
 * @return true if the object represents a right triangle
 */
bool Triangle::is_right_triangle() {
  if (!is_triangle()) {
    return false;
  }
  // Pathagorean Theorem...
  if (side1 - side2 > 0 && side1 - side3 > 0) {
    if (pow(side1, 2) == pow(side2, 2) + pow(side3, 2)) {
      return true;
    }
  } else if (side2 - side1 > 0 && side2 - side3 > 0) {
    if (pow(side2, 2) == pow(side1, 2) + pow(side3, 2)) {
      return true;
    }
  } else {
    if (pow(side3, 2) == pow(side2, 2) + pow(side1, 2)) {
      return true;
    }
  }
  return false;
}

/**
 * Returns true if the triangle object represents a valid triangle and at least
 * two of its sides are equivalent length. Otherwise, returns false.
 *
 * @return true if the object represents an isoceles triangle
 */
bool Triangle::is_isoceles() {
  if (!is_triangle()) {
    return false;
  }
  if (side1 == side2 || side2 == side3 || side3 == side1) {
    return true;
  }
  return false;
}

/**
 * Returns true if the triangle object represents a valid triangle and all three
 * sides are equivalent in length. Otherwise, returns false.
 *
 * @return true if the object represents an equilateral triangle
 */
bool Triangle::is_equilateral() {
  if (!is_triangle()) {
    return false;
  }
  if (side1 == side2 && side2 == side3) {
    return true;
  }
  return false;
}

/**
 * Returns true if the triangle object represents a valid triangle and contains
 * an angle greater than or equal to 90 degrees. Otherwise, returns false.
 *
 * @return true if the object represents an obtuse triangle
 */
bool Triangle::is_obtuse() {
  if (!is_triangle()) {
    return false;
  }
  if (angle1 >= 90.0 || angle2 >= 90 || angle3 >= 90) {
    return true;
  }
  return false;
}

/**
 * Returns true if the triangle object represents a valid triangle and contains
 * angles which are all measured as less than 90 degrees. Otherwise, returns
 * false.
 *
 * @return true if the object represents an acute triangle
 */
bool Triangle::is_acute() {
  if (!is_triangle()) {
    return false;
  }
  if (angle1 < 90 && angle2 < 90 && angle3 < 90) {
    return true;
  }
  // TODO: Should negative values be explicitly taken care of in the constructor?
  return false;
}

/**
 * Returns the classification of the triangle object. If the object does not
 * represent a valid triangle, returns "degenerate". A triangle is considered
 * scalene if it is a valid triangle but does not fit any of the following
 * classifications: right, isoceles, equilateral, obtuse, acute. Triangles which
 * may fit multiple classifications are given the first classification to
 * which they match. For example: an isoceles may be considered an equilateral
 * but will always match first to isoceles.
 */
std::string Triangle::get_classification() {
  if (is_right_triangle()) {
    return "right triangle\n";
  } else if (is_isoceles()) {
    return "isoceles\n";
  } else if (is_equilateral()) {
    return "equilateral\n";
  } else if (is_obtuse()) {
    return "obtuse\n";
  } else if (is_acute()) {
    return "acute\n";
  } else if (is_triangle()){
    return "scalene\n";
  } else {
    return "degenerate\n";
  }
}

/**
 * Determines whether or not a list of coordinate points represent valid
 * triangles and prints the type of each triangle to the console. Coordinates
 * are input via std::cin and are listed as x1 y1 x2 y2 x3 y3 with a single
 * space between each coordinate. Output via std::cout.
 * Note: There is no error checking and thus, invalid input does not have
 * defined behavior.
 */
void run_triangle_util() {
  std::cout << "Enter coordinates: ";
  
  int x1, x2, x3;
  int y1, y2, y3;
  std::vector<Triangle> triangles;
  
  // Use ctrl + d to break loop
  while (std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {
    Triangle t = Triangle(x1, x2, x3, y1, y2, y3);
    // TODO: Figure out why the 'new' keyword is not used here
    triangles.push_back(t);
  }
  
  for (int i = 0; i < triangles.size(); i++) {
    std::cout << triangles[i].get_classification();
    
    std::cout << triangles[i].side1 << "\n" << triangles[i].side2 << "\n" << triangles[i].side3 << "\n";
    std::cout << triangles[i].angle1 << "\n" << triangles[i].angle2 << "\n" << triangles[i].angle3 << "\n";
  }
}

void test(std::string name, const Triangle& t, bool expected, bool actual) {
  if (actual == false) {
    std::cout << "FAILED TEST: " << name << "\n\n\tSide 1: \t" << t.side1 <<
    "\n\tSide 2: \t" << t.side2 << "\n\tSide 3: \t" << t.side3 <<
    "\n\n\tAngl 1: \t" << t.angle1 << "\n\tAngl 2: \t" << t.angle2 <<
    "\n\tAngl 3: \t" << t.angle3 << "\n\n";
  } else {
    std::cout << "PASSED!\n\n";
  }
}

// Use this test function for the get_classification method
void test(std::string name, const Triangle& t) {
  
}

int main(int argc, const char * argv[]) {
  
  //run_triangle_util();
  
  Triangle right_scalene = Triangle(0, 0, 0, 5, 6, 0);
  // TODO: How do you test an equilateral with integers (should be impossible)?
  Triangle obtuse_isoceles = Triangle(1, 1, 0, 6, 6, 0);
  Triangle acute_scalene = Triangle(5, 0, 0, 0, 3, 10);
  Triangle degenerate = Triangle(0, 0, 9, 9, 0, 0);
  
  test("Right", right_scalene, true, right_scalene.is_right_triangle());
  test("Obtuse", obtuse_isoceles, true, obtuse_isoceles.is_isoceles());
  test("Isoceles", obtuse_isoceles, true, obtuse_isoceles.is_obtuse());
  test("Acute", acute_scalene, true, acute_scalene.is_acute());
  
  return 0;
}

// https://stackoverflow.com/questions/39275363/sequence-of-integers-using-while-loop
