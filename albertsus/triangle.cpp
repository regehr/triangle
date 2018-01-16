//
//  triangle.cpp
//  triangle_classifier
//
//  Created by Chaofan Su on 1/9/18.
//  Copyright © 2018 su. All rights reserved.
//

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define MARGIN_ERROR 1e-10;

using namespace std;

struct Point {
  int x;
  int y;
};

double getDistance(Point p1, Point p2);
double getSidesDiff(Point p1, Point p2, Point p3);
bool isDegenerate(Point p1, Point p2, Point p3);
bool isRight(Point p1, Point p2, Point p3);
bool isObtuse(Point p1, Point p2, Point p3);
bool isAcute(Point p1, Point p2, Point p3);
bool isIsosceles(Point p1, Point p2, Point p3);
bool isEquilateral(Point p1, Point p2, Point p3);
void testTriangleClassifier(Point p1, Point p2, Point p3);

/* Get the distance of two points */
double getDistance(Point p1, Point p2) {
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

/* Calculate the difference of sides length, get the max one and
   substract the sum of the other two */
double getSidesDiff(Point p1, Point p2, Point p3) {
  double maxLen = getDistance(p1, p2);
  maxLen = max(maxLen, getDistance(p2, p3));
  maxLen = max(maxLen, getDistance(p1, p3));
  if (maxLen == getDistance(p1, p2)) {
    return pow(maxLen, 2) -
           (pow(getDistance(p2, p3), 2) + pow(getDistance(p1, p3), 2));
  } else if (maxLen == getDistance(p2, p3)) {
    return pow(maxLen, 2) -
           (pow(getDistance(p1, p2), 2) + pow(getDistance(p1, p3), 2));
  } else {
    return pow(maxLen, 2) -
           (pow(getDistance(p2, p3), 2) + pow(getDistance(p1, p2), 2));
  }
}

/* Decide if the triangle is degenerate. If it is return true, otherwise, return
 * false */
bool isDegenerate(Point p1, Point p2, Point p3) {
  return ((getDistance(p1, p2) + getDistance(p2, p3)) <= getDistance(p1, p3)) ||
         ((getDistance(p1, p2) + getDistance(p1, p3)) <= getDistance(p2, p3)) ||
         ((getDistance(p1, p3) + getDistance(p2, p3)) <= getDistance(p1, p2));
}

/* Decide if the triangle is right. If it is return true, otherwise, return
 * false */
bool isRight(Point p1, Point p2, Point p3) {
  return abs(getSidesDiff(p1, p2, p3)) < MARGIN_ERROR;
}

/* Decide if the triangle is obtuse. If it is return true, otherwise, return
 * false */
bool isObtuse(Point p1, Point p2, Point p3) {
  return getSidesDiff(p1, p2, p3) > MARGIN_ERROR;
}

/* Decide if the triangle is acute. If it is return true, otherwise, return
 * false */
bool isAcute(Point p1, Point p2, Point p3) {
  return getSidesDiff(p1, p2, p3) < MARGIN_ERROR;
}

/* Decide if the triangle is isosceles. If it is return true, otherwise, return
 * false */
bool isIsosceles(Point p1, Point p2, Point p3) {
  return getDistance(p1, p2) == getDistance(p1, p3) ||
         getDistance(p1, p2) == getDistance(p2, p3) ||
         getDistance(p1, p3) == getDistance(p2, p3);
}

/* Decide if the triangle is equilateral. If it is return true, otherwise,
 * return false */
bool isEquilateral(Point p1, Point p2, Point p3) {
  return getDistance(p1, p2) == getDistance(p1, p3) &&
         getDistance(p1, p2) == getDistance(p2, p3);
}

/* Decide the type of triangle with three points */
void testTriangleClassifier(Point p1, Point p2, Point p3) {
  if (isDegenerate(p1, p2, p3)) {
    cout << "degenerate" << endl;
  } else if (isRight(p1, p2, p3)) {
    cout << "right" << endl;
  } else if (isIsosceles(p1, p2, p3)) {
    cout << "isosceles" << endl;
  } else if (isEquilateral(p1, p2, p3)) {
    cout << "equilateral" << endl;
  } else if (isObtuse(p1, p2, p3)) {
    cout << "obtuse" << endl;
  } else if (isAcute(p1, p2, p3)) {
    cout << "acute" << endl;
  } else {
    cout << "scalene" << endl;
  }
}

int main(int argc, const char *argv[]) {
  while (true) {
    Point p1, p2, p3;
    if (!(cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y)) {
      break;
    }
    testTriangleClassifier(p1, p2, p3);
  }
  return 0;
}
