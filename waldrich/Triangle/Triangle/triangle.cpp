//
//  main.cpp
//  Triangle
//
//  Created by William Aldrich on 1/9/18.
//  Copyright © 2018 William Aldrich. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <assert.h>

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
    if(firstx < 0 || firstx > 100 || secondx < 0 || secondx > 100 ||
       firsty < 0 || firsty > 100 || secondy < 0 || secondy > 100) {
        return 0;
    }

    return sqrt((pow((secondx - firstx), 2)) + (pow((secondy - firsty), 2)));
}

//Checks the first or second slope to ensure that it is a triangle
bool checkSlopes(triangle tri){

    float slope;

    //if the denominator of the first slope = 0 test the second slope
    if ((tri.pointB.x - tri.pointA.x) != 0){
    slope = ((tri.pointB.y - tri.pointA.y) / (tri.pointB.x - tri.pointA.x));
    }
    else if ((tri.pointC.x - tri.pointA.x) != 0){
        slope = ((tri.pointC.y - tri.pointB.y) / (tri.pointC.x - tri.pointB.x));
    }
    else {
        return false;
    }

    if (slope == numeric_limits<float>::infinity()){
        return true;
    }
    else if( slope == 1 || -1) {
        return false;
    }

}


string sidesWork(triangle tri) {

    if(!checkSlopes(tri) || (tri.pointA.x == tri.pointB.x && tri.pointB.x == tri.pointC.x && tri.pointC.x == tri.pointA.x)){
        return "unknown";
    }

    if(tri.lengthSideC == tri.lengthSideA && tri.lengthSideC == tri.lengthSideB && tri.lengthSideA == tri.lengthSideB){
        return "equilateral";
    }

    if (tri.lengthSideC == tri.lengthSideA || tri.lengthSideA == tri.lengthSideB || tri.lengthSideB == tri.lengthSideC) {
        return "isoceles";
    }

    return "unknown";
}

string findAngles(triangle tri) {

    const double pi = 3.1415926535897;

    tri.angleA = acos((pow(tri.lengthSideB, 2) + pow(tri.lengthSideC, 2) - pow(tri.lengthSideA, 2)) / (2*tri.lengthSideB*tri.lengthSideC)) * (180/pi);
    tri.angleB = acos((pow(tri.lengthSideC, 2) + pow(tri.lengthSideA, 2) - pow(tri.lengthSideB, 2)) / (2*tri.lengthSideC*tri.lengthSideA)) * (180/pi);
    tri.angleC = 180 - tri.angleA - tri.angleB;

    if (tri.angleA + tri.angleB + tri.angleC != 180 || tri.angleA < 0 || tri.angleB < 0 || tri.angleC < 0) {
        return "degenerate";
    }
    else if (tri.angleA == 90 || tri.angleB == 90 || tri.angleC == 90){
        return "right";
    }
    else if (tri.angleA > 90 || tri.angleB > 90 || tri.angleC > 90) {
        return "obtuse";
    }
    else if (tri.angleA < 90 && tri.angleB < 90 && tri.angleC < 90) {
        return "acute";
    }

    return "scalene";
}


void triangleComputations(triangle allTriangles [], int numOfTriangles) {

    //find the length of the sides
    for (int i = 0; i < numOfTriangles; i++){
        allTriangles[i].lengthSideC = findLength(allTriangles[i].pointA.x, allTriangles[i].pointA.y, allTriangles[i].pointB.x, allTriangles[i].pointB.y);
        allTriangles[i].lengthSideA = findLength(allTriangles[i].pointB.x, allTriangles[i].pointB.y, allTriangles[i].pointC.x, allTriangles[i].pointC.y);
        allTriangles[i].lengthSideB = findLength(allTriangles[i].pointC.x, allTriangles[i].pointC.y, allTriangles[i].pointA.x, allTriangles[i].pointA.y);

        string possibleTriangle = sidesWork(allTriangles[i]);
        if (possibleTriangle.compare("unknown") == 0) {
            possibleTriangle = findAngles(allTriangles[i]);
        }
        cout << "Triangle " << i + 1 << " is a: " << possibleTriangle << " triangle. \n";
    }

}


void getInput() {
    
    int numberOfTriangles = -1;
    
    while (numberOfTriangles < 0){
        cout << "Please enter how many triangles you would like to test: ";
        cin >> numberOfTriangles;
    }
    
    triangle allTriangles[numberOfTriangles];
    
    for(int i = 0; i < numberOfTriangles; i++){
        triangle newTriangle;
        cout << "Please enter points for triangle " << i+1 << ": ";
        cin >> newTriangle.pointA.x >> newTriangle.pointA.y >> newTriangle.pointB.x >> newTriangle.pointB.y >> newTriangle.pointC.x >> newTriangle.pointC.y;
        allTriangles[i] = newTriangle;
    }
    
    triangleComputations(allTriangles, numberOfTriangles);
}


int main(int argc, const char * argv[]) {
    getInput();
    
//    testAcute();
//    testObtuse();
//    testRight();
//    testAllPtDegen();
//    testSamePlaneDegen();
//    testIsoceles();
//    testEqual();
    return 0;
}
