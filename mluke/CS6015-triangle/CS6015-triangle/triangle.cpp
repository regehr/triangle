//
//  main.cpp
//  CS6015-triangle
//
//  Created by Madeline Luke on 1/9/18.
//  Copyright © 2018 Madeline Luke. All rights reserved.
//

#include <cmath>
#include <iostream>
#include <math.h>

float findDistance(int x, int y, int x1, int y1) {
  int value = pow((x1 - x), 2) + pow((y1 - y), 2);
  return sqrt(value);
}

double findAngle(double x, double y, double z) {
  float val = ((pow(x, 2) + pow(y, 2) - pow(z, 2))) / (2 * x * y);
  return acos(val) * (180.0 / 3.14);
}

void triangleClassifier(int x1, int y1, int x2, int y2, int x3, int y3) {
  float side1, side2, side3;
  side1 = findDistance(x1, y1, x2, y2);
  side2 = findDistance(x1, y1, x3, y3);
  side3 = findDistance(x2, y2, x3, y3);

  double angleA, angleB, angleC;
  angleC = round(findAngle(side1, side2, side3));
  angleA = round(findAngle(side2, side3, side1));
  angleB = round(findAngle(side3, side1, side2));

  if (angleA == 90.0 || angleB == 90.0 || angleC == 90.0) {
    std::cout << "right \n";
  } else if (side1 == side2 || side1 == side3 || side2 == side3) {
    std::cout << "isosceles \n";
  } else if (angleA > 90 || angleB > 90 || angleC > 90) {
    std::cout << "obtuse \n";
  } else if (angleA < 90 && angleB < 90 && angleC < 90) {
    std::cout << "acute \n";
  } else if ((x1 == x2 && y1 == y2) || (x1 == x3 && y1 == y3) ||
             (x2 == x3 && y2 == y3)) {
    std::cout << "degenerate \n";
  }
}

int main(int argc, const char *argv[]) {

  int x1, y1, x2, y2, x3, y3;

  while (true) {
    if (!(std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)) {
      break;
    }
    triangleClassifier(x1, y1, x2, y2, x3, y3);
  }

  return 0;
}
