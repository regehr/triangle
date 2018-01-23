//
//  main.cpp
//  Triangle
//
//  Created by William Aldrich on 1/9/18.
//  Copyright © 2018 William Aldrich. All rights reserved.
//

#include <assert.h>
#include <fenv.h>
#include <iostream>
#include <math.h>

using namespace std;

struct point {
  int x;
  int y;
};

struct triangle {
  point pointA;
  point pointB;
  point pointC;
  float lengthSideC;
  float lengthSideA;
  float lengthSideB;
  float angleA;
  float angleB;
  float angleC;
};

double findLength(int firstx, int firsty, int secondx, int secondy) {
  return sqrt((pow((secondx - firstx), 2)) + (pow((secondy - firsty), 2)));
}

string computeTypeOfTriangle(triangle tri) {

  const double pi = 3.1415926535897;

  tri.angleA = acos((pow(tri.lengthSideB, 2) + pow(tri.lengthSideC, 2) -
                     pow(tri.lengthSideA, 2)) /
                    (2 * tri.lengthSideB * tri.lengthSideC)) *
               (180.0 / pi);
  tri.angleB = acos((pow(tri.lengthSideC, 2) + pow(tri.lengthSideA, 2) -
                     pow(tri.lengthSideB, 2)) /
                    (2 * tri.lengthSideC * tri.lengthSideA)) *
               (180.0 / pi);
  tri.angleC = 180.0 - tri.angleA - tri.angleB;
    
    tri.angleA = roundf(trunc(tri.angleA * 1000 + .5)) / 1000;
    tri.angleB = roundf(trunc(tri.angleB * 1000 + .5)) / 1000;
    tri.angleC = roundf(trunc(tri.angleC * 1000 + .5)) / 1000;


  if (tri.angleA <= 0.0f || isnan(tri.angleA) || tri.angleB <= 0.0f ||
      isnan(tri.angleB) || tri.angleC <= 0.0f || isnan(tri.angleC) ||
      (tri.pointA.x == tri.pointB.x && tri.pointA.y == tri.pointB.y) ||
      (tri.pointB.x == tri.pointC.x && tri.pointB.y == tri.pointC.y) ||
      (tri.pointC.x == tri.pointA.x && tri.pointC.y == tri.pointA.y)) {
    return "degenerate";
  } else if (tri.angleA == 90.0f || tri.angleB == 90.0f || tri.angleC == 90.0f) {
    return "right";
  } else if (tri.lengthSideC == tri.lengthSideA ||
             tri.lengthSideA == tri.lengthSideB ||
             tri.lengthSideB == tri.lengthSideC) {
    return "isosceles";
  } else if (tri.angleA > 90.0f || tri.angleB > 90.0f || tri.angleC > 90.0f) {
    return "obtuse";
  } else {
    return "acute";
  }
}

string displayTriangleType(triangle tri) {

  // find the length of the sides
  tri.lengthSideC =
      findLength(tri.pointA.x, tri.pointA.y, tri.pointB.x, tri.pointB.y);
  tri.lengthSideA =
      findLength(tri.pointB.x, tri.pointB.y, tri.pointC.x, tri.pointC.y);
  tri.lengthSideB =
      findLength(tri.pointC.x, tri.pointC.y, tri.pointA.x, tri.pointA.y);
    
    if(tri.lengthSideA == 0 || tri.lengthSideB == 0 || tri.lengthSideC == 0){
        return "degenerate";
    }

  string possibleTriangle = computeTypeOfTriangle(tri);
  return possibleTriangle;
}

void getInput() {

  while (true) {
    triangle currentTriangle;
    if (cin >> currentTriangle.pointA.x >> currentTriangle.pointA.y >>
        currentTriangle.pointB.x >> currentTriangle.pointB.y >>
        currentTriangle.pointC.x >> currentTriangle.pointC.y) {

      string displayTriangle = displayTriangleType(currentTriangle);
      cout << displayTriangle << "\n";
    } else {
      break;
    }
  }
}

int main(int argc, const char *argv[]) {
  getInput();
  return 0;
}
