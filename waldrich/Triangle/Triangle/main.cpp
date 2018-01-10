//
//  main.cpp
//  Triangle
//
//  Created by William Aldrich on 1/9/18.
//  Copyright © 2018 William Aldrich. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;

struct triangle {
    float x1;
    float y1;
    float x2;
    float y2;
    float x3;
    float y3;
    float lengthSideC;
    float lengthSideA;
    float lengthSideB;
    float angleA;
    float angleB;
    float angleC;
};


double findLength(int firstx, int firsty, int secondx, int secondy) {
    if(firstx < 0 || firstx > 100)
        return 0;
    else if (firsty < 0 || firsty > 100)
        return 0;
    else if (secondx < 0 || secondx > 100)
        return 0;
    else if (secondy < 0 || secondy > 100)
        return 0;
    return sqrt((pow((secondx - firstx), 2)) + (pow((secondy - firsty), 2)));
}

bool checkSlopes(triangle tri){
    float firstSlope = ((tri.y2 - tri.y1) / (tri.x2 - tri.x1));
    if (firstSlope == numeric_limits<float>::infinity()){
        return true;
    }
    else if( firstSlope == 1 || -1) {
        return false;
    }
    return true;
}


string sidesWork(triangle tri) {
    
    if(!checkSlopes(tri) || tri.x1 == tri.x2 || tri.x2 == tri.x3 || tri.x3 == tri.x1){
        return "unknown";
    }
    
    if (tri.lengthSideC == tri.lengthSideA || tri.lengthSideA == tri.lengthSideB || tri.lengthSideB == tri.lengthSideC) {
        return "isoceles";
    }

    if(tri.lengthSideC == tri.lengthSideA == tri.lengthSideB){
        return "equilateral";
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
    else if (tri.angleA < 90 & tri.angleB < 90 & tri.angleC < 90) {
        return "acute";
    }
    
    return "scalene";
}


void triangleComputations(triangle allTriangles [], int numOfTriangles) {
    
    //find the length of the sides
    for (int i = 0; i < numOfTriangles; i++){
        allTriangles[i].lengthSideC = findLength(allTriangles[i].x1, allTriangles[i].y1, allTriangles[i].x2, allTriangles[i].y2);
        allTriangles[i].lengthSideA = findLength(allTriangles[i].x2, allTriangles[i].y2, allTriangles[i].x3, allTriangles[i].y3);
        allTriangles[i].lengthSideB = findLength(allTriangles[i].x3, allTriangles[i].y3, allTriangles[i].x1, allTriangles[i].y1);
        
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
        cin >> newTriangle.x1 >> newTriangle.y1 >> newTriangle.x2 >> newTriangle.y2 >> newTriangle.x3 >> newTriangle.y3;
        allTriangles[i] = newTriangle;
    }
    
    triangleComputations(allTriangles, numberOfTriangles);
}


int main(int argc, const char * argv[]) {
    getInput();
    return 0;
}
