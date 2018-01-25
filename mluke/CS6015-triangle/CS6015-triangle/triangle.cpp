//
//  triangle.cpp
//  CS6015-triangle
//
//  Created by Madeline Luke on 1/9/18.
//  Copyright © 2018 Madeline Luke. All rights reserved.
//

#include <cmath>
#include <iostream>
#include <math.h>

float findDistance(float x, float y, float x1, float y1) {
  return sqrt(pow((x1 - x), 2) + pow((y1 - y), 2));
}

double findAngle(float x, float y, float z) {
  double val = ((pow(x, 2) + pow(y, 2) - pow(z, 2))) / (2 * x * y);
const float PI = 3.141592653589793238463f;
  return acos(val) * (double)(180.0 / PI);
}

void triangleClassifier(int x1, int y1, int x2, int y2, int x3, int y3) {
  
    float side1, side2, side3;
  side1 = findDistance(x1, y1, x2, y2);
  side2 = findDistance(x1, y1, x3, y3);
  side3 = findDistance(x2, y2, x3, y3);

  double angleA, angleB, angleC;
  angleC = findAngle(side1, side2, side3);
  angleA = findAngle(side2, side3, side1);
  angleB = findAngle(side3, side1, side2);
    
  if ((angleA < 90.0001 && angleA > 89.9999) || (angleB < 90.0001 && angleB > 89.9999) ||
      (angleC < 90.0001 && angleC > 89.9999)) {
    std::cout << "right\n";
  } else if (side1 == side2 || side1 == side3 || side2 == side3) {
    std::cout << "isosceles\n";
  } else if (angleA > 90.0001 || angleB > 90.0001 || angleC > 90.0001) {
    std::cout << "obtuse\n";
  } else if (angleA < 89.9999 && angleB < 89.9999 && angleC < 89.9999) {
    std::cout << "acute\n";
  }
}

int main(int argc, const char *argv[]) {

  int x1, y1, x2, y2, x3, y3;

  while (true) {
    if (!(std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)) {
      break;
    }
      
    double area = (x1*(y2 - y3) + x2*(y3 - y1) +x3*(y1 - y2)) ;
   
      if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0 || x3 < 0 || y3 < 0 ||
        x1 > 100 || y1 > 100 || x2 > 100 || y2 > 100 || x3 > 100 ||
        y3 > 100) {
        std::cout << "degenerate\n" ;
        continue ;
    } else if ((x1 == x2 && y1 == y2) || (x1 == x3 && y1 == y3) ||
          (x2 == x3 && y2 == y3)) {
          std::cout << "degenerate\n";
          continue ;
    } else if (area == 0) {
        // I got this from Zander (znickle24)
        std::cout << "degenerate\n";
        continue;
    }
      
    triangleClassifier(x1, y1, x2, y2, x3, y3);
  }

  return 0;
}
