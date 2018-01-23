//
//  triangle.cpp
//  Triangle
//
//  Created by Sydney Sturgeon on 1/9/18.
//  Copyright © 2018 Sydney Sturgeon. All rights reserved.
//

#include <assert.h>
#include <iostream>
#include <math.h>

using namespace std;

// Helper function for triangleClassifier()
// Uses distance formula to calculate the length between 2 x,y pts
// Takes four ints as 2 x,y pts as parameters
// Returns a float as the length between the two input pts
double lineLength(int x1, int y1, int x2, int y2) {
  double x = pow((x2 - x1), 2);
  double y = pow((y2 - y1), 2);
  double length = sqrt(x + y);
  assert(length >= 0.0); // checks for positive lengths
  return length;
}

// Helper function for triangleClassifier()
// Uses the law of cosines to calculate an angle in degrees in a triangle
// Takes lengths of three lines as floats as parameters
// Returns an angle in degrees as a float
double calculateAngleA(double line1, double line2, double line3) {
  double numeratorA = (pow(line2, 2)) + (pow(line3, 2)) - (pow(line1, 2));
  double denominatorA = 2 * line2 * line3;
  double angleA = acos(numeratorA / denominatorA); // calculates angle in radians
  const float PI = 3.141592653589793238463f;
  return angleA * (180.0f / PI); // convert angle from radians to degrees
}

// Helper function for triangleClassifier()
// Uses law of cosines to calculate an angle in degrees in a triangle
// Takes lengths of three lines as floats as parameters
// Returns an angle in degrees as a float
double calculateAngleB(double line1, double line2, double line3) {
  double numeratorB = (pow(line3, 2)) + (pow(line1, 2)) - (pow(line2, 2));
  double denominatorB = 2 * line3 * line1;
  double angleB = acos(numeratorB / denominatorB); // calculates angle in radians
  const float PI = 3.141592653589793238463f;
  return angleB * (180.0f / PI); // convert angle from radians to degrees
}

// Using three (x,y) points this classifies the triangle type
// If the three (x,y) points do not make a valid triangle the input is
// classified as degenerate.  Returns a one-word standard print statement to the
// console stating the classification for a valid triangle.
void triangleClassifier(int x1, int y1, int x2, int y2, int x3, int y3) {

  // calculate the lengths of the sides of the triangle
  double lineLength12 = lineLength(x1, y1, x2, y2);
  double lineLength13 = lineLength(x1, y1, x3, y3);
  double lineLength23 = lineLength(x2, y2, x3, y3);

  // calculate the angles in the triangle
  double angleA = calculateAngleA(lineLength12, lineLength13, lineLength23);
  double angleB = calculateAngleB(lineLength12, lineLength13, lineLength23);
  double angleC = 180.0f - angleA - angleB;

  // classify the triangle according to its side lengths or angles
  // right: one 90 degree angle
  // isosceles: two sides same length
  // obtuse: one angle > 90 degrees
  // acute: all angles < 90 degrees

  // if any of the angles are <= 0 it is degenerate
  if ((angleA <= 0.0) || (angleB <= 0.0) || (angleC <= 0.0)) {
    cout << "degenerate\n";
  } else if ((angleA > 89.95 && angleA < 90.02 ) || (angleB > 89.95
             && angleB < 90.02) || (angleC > 89.95 && angleC < 90.02)){
    cout << "right\n";
  } else if ((lineLength12 == lineLength13 && lineLength12 != lineLength23) ||
             (lineLength13 == lineLength23 && lineLength13 != lineLength12) ||
             (lineLength12 == lineLength23 && lineLength12 != lineLength13)) {
    cout << "isosceles\n";
  } else if (angleA > 90.0f || angleB > 90.0f || angleC > 90.0f) {
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
    }
    // if points lie on the same line (Degenerate)
    else if ((x1 == x2 && x2 == x3) || (y1 == y2 && y2 == y3)) {
      cout << "degenerate\n";
    }
    // if the three points are determined to be a triangle it is classified
    else {
      triangleClassifier(x1, y1, x2, y2, x3, y3);
    }
  } // end of while(true) loop
}

int main(int argc, const char *argv[]) {
  triangle();
  return 0;
}
