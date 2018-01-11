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
    if(firstx < 0 || firstx > 100 || secondx < 0 || secondx > 100 ||
       firsty < 0 || firsty > 100 || secondy < 0 || secondy > 100) {
        return 0;
    }

    return sqrt((pow((secondx - firstx), 2)) + (pow((secondy - firsty), 2)));
}

//Checks the first or second slope to ensure that it is a triangle
bool checkSlopes(triangle tri){
    
    float firstSlope;
    
    //if the denominator of the first slope = 0 test the second slope
    if ((tri.x2 - tri.x1) != 0){
    firstSlope = ((tri.y2 - tri.y1) / (tri.x2 - tri.x1));
    }
    else {
        firstSlope = ((tri.y3 - tri.y2) / (tri.x3 - tri.x2));
    }
    
    if (firstSlope == numeric_limits<float>::infinity()){
        return true;
    }
    else if( firstSlope == 1 || -1) {
        return true;
    }
    return false;
}


string sidesWork(triangle tri) {
    
    if(!checkSlopes(tri) || (tri.x1 == tri.x2 && tri.x2 == tri.x3 && tri.x3 == tri.x1)){
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

//Tests to ensure that you will get an acute triangle
void testAcute() {
    triangle acute;
    acute.x1 = 0;
    acute.y1 = 1;
    acute.x2 = 6;
    acute.y2 = 0;
    acute.x3 = 3;
    acute.y3 = 5;
    
    acute.lengthSideC = findLength(acute.x1, acute.y1, acute.x2, acute.y2);
    acute.lengthSideA = findLength(acute.x2, acute.y2, acute.x3, acute.y3);
    acute.lengthSideB = findLength(acute.x3, acute.y3, acute.x1, acute.y1);
    
    assert(sidesWork(acute) == "unknown");
    assert(findAngles(acute) == "acute");
}

//Tests to ensure that you will get an obtuse triangle
void testObtuse() {
    triangle obtuse;
    obtuse.x1 = 0;
    obtuse.y1 = 1;
    obtuse.x2 = 0;
    obtuse.y2 = 2;
    obtuse.x3 = 3;
    obtuse.y3 = 0;
    
    obtuse.lengthSideC = findLength(obtuse.x1, obtuse.y1, obtuse.x2, obtuse.y2);
    obtuse.lengthSideA = findLength(obtuse.x2, obtuse.y2, obtuse.x3, obtuse.y3);
    obtuse.lengthSideB = findLength(obtuse.x3, obtuse.y3, obtuse.x1, obtuse.y1);
    
    assert(sidesWork(obtuse) == "unknown");
    assert(findAngles(obtuse) == "obtuse");
}

//Tests to ensure that you will get a right triangle
void testRight() {
    triangle right;
    right.x1 = 0;
    right.y1 = 0;
    right.x2 = 0;
    right.y2 = 2;
    right.x3 = 3;
    right.y3 = 0;
    
    right.lengthSideC = findLength(right.x1, right.y1, right.x2, right.y2);
    right.lengthSideA = findLength(right.x2, right.y2, right.x3, right.y3);
    right.lengthSideB = findLength(right.x3, right.y3, right.x1, right.y1);
    
    assert(sidesWork(right) == "unknown");
    assert(findAngles(right) == "right");
}

//Tests to ensure that a point is not a triangle
void testAllPtDegen() {
    triangle degen;
    degen.x1 = 0;
    degen.y1 = 0;
    degen.x2 = 0;
    degen.y2 = 0;
    degen.x3 = 0;
    degen.y3 = 0;
    
    degen.lengthSideC = findLength(degen.x1, degen.y1, degen.x2, degen.y2);
    degen.lengthSideA = findLength(degen.x2, degen.y2, degen.x3, degen.y3);
    degen.lengthSideB = findLength(degen.x3, degen.y3, degen.x1, degen.y1);
    
    assert(sidesWork(degen) == "unknown");
    assert(findAngles(degen) == "degenerate");
}

//Tests to ensure collinear lines are not triangles
void testSamePlaneDegen() {
    triangle degen;
    degen.x1 = 0;
    degen.y1 = 1;
    degen.x2 = 2;
    degen.y2 = 3;
    degen.x3 = 4;
    degen.y3 = 5;
    
    degen.lengthSideC = findLength(degen.x1, degen.y1, degen.x2, degen.y2);
    degen.lengthSideA = findLength(degen.x2, degen.y2, degen.x3, degen.y3);
    degen.lengthSideB = findLength(degen.x3, degen.y3, degen.x1, degen.y1);
    
    //two of the lengths are the same, should give you isoceles triangle
    assert(sidesWork(degen) == "isoceles");
    assert(findAngles(degen) == "degenerate");
}

//Tests to insure that you do get a isoceles triangle before testing angles
void testIsoceles() {
    triangle isoceles;
    isoceles.x1 = 1;
    isoceles.y1 = 1;
    isoceles.x2 = 1;
    isoceles.y2 = 6;
    isoceles.x3 = 6;
    isoceles.y3 = 1;
    
    isoceles.lengthSideC = findLength(isoceles.x1, isoceles.y1, isoceles.x2, isoceles.y2);
    isoceles.lengthSideA = findLength(isoceles.x2, isoceles.y2, isoceles.x3, isoceles.y3);
    isoceles.lengthSideB = findLength(isoceles.x3, isoceles.y3, isoceles.x1, isoceles.y1);
    
    assert(sidesWork(isoceles) == "isoceles");
    assert(findAngles(isoceles) == "right");
}

// Tests to make sure side lengths give an equilateral triangle
void testEqual() {
    triangle equal;
    equal.lengthSideA = 2;
    equal.lengthSideB = 2;
    equal.lengthSideC = 2;
    
    //these points dont make an equilateral, but the sides are what we are truly testing
    equal.x1 = 0;
    equal.y1 = 1;
    equal.x2 = 0;
    equal.y2 = 2;
    equal.x3 = 3;
    equal.y3 = 0;
    
    assert(sidesWork(equal) == "equilateral");
}






int main(int argc, const char * argv[]) {
//    getInput();
    
    testAcute();
    testObtuse();
    testRight();
    testAllPtDegen();
    testSamePlaneDegen();
    testIsoceles();
    testEqual();
    return 0;
}
