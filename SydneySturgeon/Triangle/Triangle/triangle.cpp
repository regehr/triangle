//
//  triangle.cpp
//  Triangle
//
//  Created by Sydney Sturgeon on 1/9/18.
//  Copyright © 2018 Sydney Sturgeon. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <assert.h>

using namespace std;

// Helper function for triangleClassifier()
// Uses distance formula to calculate the length between 2 x,y pts
// Takes four ints as 2 x,y pts as parameters
// Returns a float as the length between the two input pts
float lineLength(int x1, int y1, int x2, int y2) {
  float x = pow((x2 - x1), 2);
  float y = pow((y2 - y1), 2);
  float length = sqrt(x + y);
    assert(length >= 0.0); //checks for positive lengths
  return length;
}

// Helper function for triangleClassifier()
// Uses the law of cosines to calculate an angle in degrees in a triangle
// Takes lengths of three lines as floats as parameters
// Returns an angle in degrees as a float
float calculateAngleA(float line1, float line2, float line3) {
  float numeratorA = (pow(line2, 2)) + (pow(line3, 2)) - (pow(line1, 2));
  float denominatorA = 2 * line2 * line3;
  float angleA = acos(numeratorA / denominatorA); // calculates angle in radians
  const float PI = 3.141592653589793238463f;
  return angleA * (180.0f / PI); // convert angle from radians to degrees
}

// Helper function for triangleClassifier()
// Uses law of cosines to calculate an angle in degrees in a triangle
// Takes lengths of three lines as floats as parameters
// Returns an angle in degrees as a float
float calculateAngleB(float line1, float line2, float line3) {
  float numeratorB = (pow(line3, 2)) + (pow(line1, 2)) - (pow(line2, 2));
  float denominatorB = 2 * line3 * line1;
  float angleB = acos(numeratorB / denominatorB); // calculates angle in radians
  const float PI = 3.141592653589793238463f;
  return angleB * (180.0f / PI); // convert angle from radians to degrees
}

// Using three (x,y) points this classifies the triangle type
// If the three (x,y) points do not make a valid triangle the input is
// classified as degenerate.  Returns a one-word standard print statement to the
// console stating the classification for a valid triangle.
void triangleClassifier(int x1, int y1, int x2, int y2, int x3, int y3) {

  // calculate the lengths of the sides of the triangle
  float lineLength12 = lineLength(x1, y1, x2, y2);
    //cout << lineLength12 << endl;
  float lineLength13 = lineLength(x1, y1, x3, y3);
    //cout << lineLength12 << endl;
  float lineLength23 = lineLength(x2, y2, x3, y3);
    //cout << lineLength23 << endl;

  // calculate the angles in the triangle - rounded to 1 decimal place
  float angleA =
    calculateAngleA(lineLength12, lineLength13, lineLength23);
    //roundf(
      //(calculateAngleA(lineLength12, lineLength13, lineLength23) * 10) / 10);
    //cout << "anglea" << angleA << endl;
  float angleB = roundf(
      (calculateAngleB(lineLength12, lineLength13, lineLength23) * 10) / 10);
    //cout << angleB << endl;
  float angleC = roundf(((180.0f - angleA - angleB) * 10) / 10);
    //cout << angleC << endl;

  // classify the triangle according to its side lengths or angles
  // right triangle: one 90 degree angle
  // isoceles: two sides same length
  // obtuse: one angle > 90 degrees
  // acute: all angles < 90 degrees

  // if any of the angles are 0 it is degenerate
  if ((angleA <= 0.0f) || (angleB <= 0.0f) || (angleC <= 0.0f)) {
    cout << "degenerate\n";
    // cout << "Degenerate. Not a triangle. One of the angles is 0.\n";
  } else if (angleA == 90.0f || angleB == 90.0f || angleC == 90.0f) {
    cout << "right\n";
  } else if ((lineLength12 == lineLength13 && lineLength12 != lineLength23) ||
             (lineLength13 == lineLength23 && lineLength13 != lineLength12) ||
             (lineLength12 == lineLength23 && lineLength12 != lineLength13)) {
    cout << "isosceles\n";
  }
  else if (angleA > 90.0f || angleB > 90.0f || angleC > 90.0f) {
    cout << "obtuse\n";
  } else if (angleA < 90.0f && angleB < 90.0f && angleC < 90.0f) {
    cout << "acute\n";
  }
}

// Using three (x,y) points as input the points are determined to be able to
// make a triangle or not.  If the three (x,y) points do not make a valid
// triangle the input is classified as degenerate.
void triangle() {
  while (true) { // loop will run as long as there are points being entered
    int x1, y1, x2, y2, x3, y3; // represent three x,y points
    if (!(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)) {
      break; // stops program
    }
    // if two or more points are the same (Degenerate)
    if ((x1 == x2 && y1 == y2) || (x2 == x3 && y2 == y3) ||
             (x1 == x3 && y1 == y3)) {
      cout << "degenerate\n";
      // cout << "Degenerate. Not a triangle. 2 or more points are the same.\n";
    }
    // if points lie on the same line (Degenerate)
    else if ((x1 == x2 && x2 == x3) || (y1 == y2 && y2 == y3)) {
      cout << "degenerate\n";
      // cout << "Degenerate. Not a triangle. Points lie on the same line.\n";
    }
    // if the three points are determined to be a triangle it is classified
    else {
      triangleClassifier(x1, y1, x2, y2, x3, y3);
    }
  } // end of while(true) loop
}

// Test case examples
void testTriangle() {
  // Test right triangle
  // 0 0 4 0 4 3
  // 0 0 1 0 1 1

  // Test isosceles triangle
  // 2 1 7 1 5 5
  // 5 5 2 1 7 1
  // 7 1 5 5 2 1

  // Test equilateral triangle
  // Difficult to find three integer points that make up an equilateral triangle
  // Equilateral case commented out in code

  // Test obtuse triangle (both test cases also scalene)
  // 0 2 10 0 18 2
  // 15 30 30 30 20 35

  // Test acute triangle (both test cases also scalene)
  // 0 0 10 2 4 30
  // 0 0 30 4 2 10

  // Test scalene triangle
  // Triangle will be classified as something else before being classified as
  // scalene  Scalene case commented out in code

  // Test degenerate
  // 0 0 10 5 0 0 - two points are the same
  // 65 35 1 1 65 35 - two points are the same
  // 0 0 5 0 10 0 - points lie on the same line
  // 50 4 10 4 40 4 - points lie on the same line
  // 1 2 3 4 5 6 - one angle is 0
  // 100 90 80 70 60 50 - one angle is 0

  // Test incorrect inputs
  //-1 0 40 10 0 15
  // 50 101 40 33 20 70

  // More test cases with points and corresponding outputs below
//    0 0 0 0 0 0
//    0 0 0 0 100 100
//    0 0 0 1 99 99
//    0 0 0 2 0 47
//    0 0 0 2 3 0
//    0 0 0 5 5 0
//    0 0 0 50 0 100
//    0 0 1 0 1 1
//    0 0 1 1 2 2
//    0 0 1 1 2 2
//    0 0 1 1 99 99
//    0 0 1 3 2 0
//    0 0 1 5 0 10
//    0 0 1 5 1 6
//    0 0 1 5 1 60
//    0 0 10 0 5 5
//    0 0 10 2 4 30
//    0 0 10 5 0 0
//    0 0 100 0 0 100
//    0 0 100 0 1 99
//    0 0 100 0 50 1
//    0 0 2 0 0 2
//    0 0 3 5 5 1
//    0 0 30 4 2 10
//    0 0 4 0 2 3
//    0 0 4 0 4 3
//    0 0 5 0 0 5
//    0 0 5 0 10 0
//    0 0 50 50 0 50
//    0 0 50 50 100 100
//    0 1 0 2 3 0
//    0 1 1 0 0 6
//    0 1 6 0 3 5
//    0 2 10 0 18 2
//    1 0 0 4 0 5
//    1 1 1 6 6 1
//    1 1 100 0 0 100
//    1 1 3 1 2 2
//    1 11 1 0 1 23
//    1 2 3 4 5 6
//    10 10 0 10 20 13
//    10 10 11 19 10 10
//    100 100 0 0 50 25
//    100 100 100 50 50 100
//    100 90 80 70 60 50
//    11 12 13 14 15 16
//    12 10 5 1 8 13
//    12 21 12 31 5 15
//    12 21 13 31 14 41
//    13 80 36 4 12 4
//    15 1 17 17 23 23
//    15 1 3 40 23 5
//    15 10 15 10 20 35
//    15 10 30 15 45 20
//    15 10 35 10 20 35
//    15 10 35 10 30 35
//    15 10 45 10 30 45
//    15 10 45 10 56 30
//    15 15 27 15 15 5
//    15 30 30 30 20 35
//    2 1 7 1 5 5
//    2 3 8 3 5 8
//    24 60 0 60 12 43
//    3 1 25 8 71 81
//    3 80 3 4 12 4
//    5 1 15 1 10 81
//    5 4 82 9 31 40
//    5 5 2 1 7 1
//    5 5 5 2 2 23
//    5 7 2 3 12 8
//    50 35 15 40 15 35
//    50 4 10 4 40 4
//    65 35 1 1 65 35
//    7 1 5 5 2 1
//    71 3 22 8 39 66
//    1 1 2 2 3 1
//    0 0 0 1 1 0
//    1 0 100 99 99 100

//    degenerate
//    degenerate
//    degenerate
//    degenerate
//    right
//    right
//    degenerate
//    right
//    degenerate
//    degenerate
//    degenerate
//    isosceles
//    isosceles
//    obtuse
//    obtuse
//    right
//    acute
//    degenerate
//    right
//    acute
//    isosceles
//    right
//    acute
//    acute
//    isosceles
//    right
//    right
//    degenerate
//    right
//    degenerate
//    obtuse
//    obtuse
//    acute
//    obtuse
//    obtuse
//    right
//    isosceles
//    right
//    degenerate
//    degenerate
//    obtuse
//    degenerate
//    obtuse
//    right
//    degenerate
//    degenerate
//    acute
//    obtuse
//    degenerate
//    acute
//    obtuse
//    acute
//    degenerate
//    degenerate
//    acute
//    acute
//    isosceles
//    obtuse
//    right
//    obtuse
//    isosceles
//    isosceles
//    isosceles
//    obtuse
//    right
//    isosceles
//    obtuse
//    isosceles
//    obtuse
//    obtuse
//    right
//    degenerate
//    degenerate
//    isosceles
//    acute
//    right
//    right
//    right
}

int main(int argc, const char *argv[]) {
  triangle();
  return 0;
}
