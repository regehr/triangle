//
//  main.cpp
//  Triangle
//
//  Created by William Aldrich on 1/9/18.
//  Copyright © 2018 William Aldrich. All rights reserved.
//

#include <assert.h>
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

// Checks the first or second slope to ensure that it is a triangle
bool checkSlopes(triangle tri) {

  // CHECK ALL SLOPES
  float firstSlope = 0;
  float secondSlope = 0;
  float thirdSlope = 0;

  if ((tri.pointB.x - tri.pointA.x) != 0) {
    firstSlope =
        ((tri.pointB.y - tri.pointA.y) / (tri.pointB.x - tri.pointA.x));
  }
  if ((tri.pointC.x - tri.pointB.x) != 0) {
    secondSlope =
        ((tri.pointC.y - tri.pointB.y) / (tri.pointC.x - tri.pointB.x));
  }
  if ((tri.pointA.x - tri.pointC.x) != 0) {
    thirdSlope =
        ((tri.pointA.y - tri.pointC.y) / (tri.pointA.x - tri.pointC.x));
  }

  if (firstSlope == secondSlope || secondSlope == thirdSlope ||
      thirdSlope == firstSlope) {
    return false;
  }

  return true;
}

string sidesWork(triangle tri) {

  if (!checkSlopes(tri)) {
    return "unknown";
  }

  if (tri.lengthSideC == tri.lengthSideA ||
      tri.lengthSideA == tri.lengthSideB ||
      tri.lengthSideB == tri.lengthSideC) {
    return "isoceles";
  }

  return "unknown";
}

string findAngles(triangle tri) {

  const double pi = 3.1415926535897;

  tri.angleA = acos((pow(tri.lengthSideB, 2) + pow(tri.lengthSideC, 2) -
                     pow(tri.lengthSideA, 2)) /
                    (2 * tri.lengthSideB * tri.lengthSideC)) *
               (180 / pi);
  tri.angleB = acos((pow(tri.lengthSideC, 2) + pow(tri.lengthSideA, 2) -
                     pow(tri.lengthSideB, 2)) /
                    (2 * tri.lengthSideC * tri.lengthSideA)) *
               (180 / pi);
  tri.angleC = 180 - tri.angleA - tri.angleB;

  if (tri.angleA + tri.angleB + tri.angleC != 180 || tri.angleA < 0 ||
      tri.angleB < 0 || tri.angleC < 0) {
    return "degenerate";
  } else if (tri.angleA == 90 || tri.angleB == 90 || tri.angleC == 90) {
    return "right";
  } else if (tri.angleA > 90 || tri.angleB > 90 || tri.angleC > 90) {
    return "obtuse";
  } else {
    return "acute";
  }
}

string triangleComputations(triangle tri) {

  // find the length of the sides
  tri.lengthSideC =
      findLength(tri.pointA.x, tri.pointA.y, tri.pointB.x, tri.pointB.y);
  tri.lengthSideA =
      findLength(tri.pointB.x, tri.pointB.y, tri.pointC.x, tri.pointC.y);
  tri.lengthSideB =
      findLength(tri.pointC.x, tri.pointC.y, tri.pointA.x, tri.pointA.y);

  string possibleTriangle = sidesWork(tri);
  if (possibleTriangle.compare("unknown") == 0) {
    possibleTriangle = findAngles(tri);
  }
  return possibleTriangle + " triangle";
}

void getInput() {

  cout << "Plese enter 6 coordinate points (x,y) for a triangle in the "
          "format \"# # # # # #\" :  \n";

  while (true) {
    triangle currentTriangle;
    if (cin >> currentTriangle.pointA.x >> currentTriangle.pointA.y >>
        currentTriangle.pointB.x >> currentTriangle.pointB.y >>
        currentTriangle.pointC.x >> currentTriangle.pointC.y) {

      string displayTriangle = triangleComputations(currentTriangle);
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
