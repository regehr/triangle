//
//  triangle.cpp
//  triangle_classifier
//
//  Created by Chaofan Su on 1/9/18.
//  Copyright © 2018 su. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

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

double getDistance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double getSidesDiff(Point p1, Point p2, Point p3) {
    double maxLen = getDistance(p1, p2);
    maxLen = max(maxLen, getDistance(p2, p3));
    maxLen = max(maxLen, getDistance(p1, p3));
    if (maxLen == getDistance(p1, p2)) {
        return pow(maxLen, 2) - (pow(getDistance(p2, p3), 2) + pow(getDistance(p1, p3), 2));
    } else if (maxLen == getDistance(p2, p3)) {
        return pow(maxLen, 2) - (pow(getDistance(p1, p2), 2) + pow(getDistance(p1, p3), 2));
    } else {
        return pow(maxLen, 2) - (pow(getDistance(p2, p3), 2) + pow(getDistance(p1, p2), 2));
    }
}

bool isDegenerate(Point p1, Point p2, Point p3) {
    return ((getDistance(p1, p2) + getDistance(p2, p3)) <= getDistance(p1, p3))
        || ((getDistance(p1, p2) + getDistance(p1, p3)) <= getDistance(p2, p3))
        || ((getDistance(p1, p3) + getDistance(p2, p3)) <= getDistance(p1, p2));
}

bool isRight(Point p1, Point p2, Point p3) {
    return abs(getSidesDiff(p1, p2, p3)) < MARGIN_ERROR;
}

bool isObtuse(Point p1, Point p2, Point p3) {
    return getSidesDiff(p1, p2, p3) > MARGIN_ERROR;
}

bool isAcute(Point p1, Point p2, Point p3) {
    return getSidesDiff(p1, p2, p3) < MARGIN_ERROR;
}

bool isIsosceles(Point p1, Point p2, Point p3) {
    return getDistance(p1, p2) == getDistance(p1, p3)
        || getDistance(p1, p2) == getDistance(p2, p3)
        || getDistance(p1, p3) == getDistance(p2, p3);
}

bool isEquilateral(Point p1, Point p2, Point p3) {
    return getDistance(p1, p2) == getDistance(p1, p3)
        && getDistance(p1, p2) == getDistance(p2, p3);
}

void testTriangleClassifier(Point p1, Point p2, Point p3) {
        if (isDegenerate(p1, p2, p3)) { // eg. p1(1, 2), p2(2, 2), p3(3, 2)
            cout << "Points " << "(" << p1.x << ", " << p1.y << "), "
            << "(" << p2.x << ", " << p2.y << "), "
            << "(" << p3.x << ", " << p3.y << ") "
            << "cannot form a triangle." << endl;
        } else if (isRight(p1, p2, p3)) { // eg. p1(1, 1), p2(1, 3), p3(3, 1)
            cout << "Points " << "(" << p1.x << ", " << p1.y << "), "
            << "(" << p2.x << ", " << p2.y << "), "
            << "(" << p3.x << ", " << p3.y << ") "
            << "form right triangle." << endl;
        } else if (isIsosceles(p1, p2, p3)) { // eg. p1(1, 1), p2(3, 1), p3(2, 3)
            cout << "Points " << "(" << p1.x << ", " << p1.y << "), "
            << "(" << p2.x << ", " << p2.y << "), "
            << "(" << p3.x << ", " << p3.y << ") "
            << "form isosceles." << endl;
        } else if (isEquilateral(p1, p2, p3)) { // possible for all integer coordinates?
            cout << "Points " << "(" << p1.x << ", " << p1.y << "), "
            << "(" << p2.x << ", " << p2.y << "), "
            << "(" << p3.x << ", " << p3.y << ") "
            << "form equilateral." << endl;
        } else if (isObtuse(p1, p2, p3)) {  // eg. p1(1, 1), p2(4, 1), p3(2, 2)
            cout << "Points " << "(" << p1.x << ", " << p1.y << "), "
            << "(" << p2.x << ", " << p2.y << "), "
            << "(" << p3.x << ", " << p3.y << ") "
            << "form obtuse." << endl;
        } else if (isAcute(p1, p2, p3)) {   // eg. p1(1, 1), p2(4, 1), p3(2, 3)
            cout << "Points " << "(" << p1.x << ", " << p1.y << "), "
            << "(" << p2.x << ", " << p2.y << "), "
            << "(" << p3.x << ", " << p3.y << ") "
            << "form acute." << endl;
        } else {   // eg. p1(1, 1), p2(4, 1), p3(2, 2) - never reached
            cout << "Points " << "(" << p1.x << ", " << p1.y << "), "
            << "(" << p2.x << ", " << p2.y << "), "
            << "(" << p3.x << ", " << p3.y << ") "
            << "form scalene." << endl;
        }
}

int main(int argc, const char * argv[]) {
    int numOfTriangles;
    cout << "Please enter the number of triangles to test: ";
    cin >> numOfTriangles;
    vector<vector<Point>> inputSet;
    for (int i = 0; i < numOfTriangles; i++) {
        cout << "Please Enter the coordinates in format x1 y1 x2 y2 x3 y3: " << endl;
        Point p1, p2, p3;
        cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
        vector<Point> PointsSet;
        PointsSet.push_back(p1);
        PointsSet.push_back(p2);
        PointsSet.push_back(p3);
        inputSet.push_back(PointsSet);
    }
    for (vector<Point> points : inputSet) {
        testTriangleClassifier(points.at(0), points.at(1), points.at(2));
    }
    return 0;
}


