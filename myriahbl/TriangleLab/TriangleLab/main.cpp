//
//  main.c
//  TriangleLab
//
//  Created by Myriah Gibbons on 1/9/18.
//  Copyright © 2018 Myriah Gibbons. All rights reserved.
//
/*
 right triangle: one 90 degree angle
 isoceles: two sides same length
 equilateral //probs not using this one
 obtuse: one angle greater than 90 degrees
 acute: all angles less than 90 degrees
 scalene: none of the above
 degenerate: not a triangle
 x1 y1 x2 y2 x3 y3
 coordinates are integers in [0...100]
 coordinates are separated by spaces
 input is on stdin
 output in on stdout
 inpur is zero or more lines, each containing a triangle
 behavior is undefined if input is malformed
 
 assignement: write a triangle classifier in C++
 write 7 test cases
 
 */
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

double findLineLength(int x1, int y1, int x2, int y2){
    
    return pow((pow(x2 - x1, 2) + pow(y2 - y1, 2)), .5);
    
}

double findAngle(double side1, double side2, double side3){
    
    return acos((pow(side2, 2) + pow(side3, 2) - pow(side1, 2)) / (2 * side2 * side3));
    
}



string classifyTriangle(int x1, int y1, int x2, int y2, int x3, int y3){
    
    double side1 = findLineLength(x1, y1, x2, y2);
    double side2 = findLineLength(x1, y1, x3, y3);
    double side3 = findLineLength(x2, y2, x3, y3);
    
    double firstAngle = findAngle(side1, side2, side3);
    double secondAngle = findAngle(side2, side1, side3);
    double thirdAngle = 180 - firstAngle - secondAngle;
    
    if((x1 == x2 && x1 == x3 && x2 == x3) || (y1 == y2 && y1 == y3 && y2 == y3)){
        //check to see if it is a triangle
        cout << "degenerate: not a triangle" << endl;
        return "degenerate: not a triangle";
        
    } else if(firstAngle == 90.0 || secondAngle == 90.0 || thirdAngle == 90.0){
        
        cout << "right triangle: one 90 degree angle" << endl;
        return "right triangle: one 90 degree angle";
        
    } else if (side1 == side2 && side1 == side3 && side2 == side3){
        
        cout << "equilateral: all sides same length" << endl;
        return "equilateral: all sides same length";
        
        
    } else if((side1 == side2) || (side1 == side3) || (side2 == side3)){
        cout << "isoceles: two sides same length" << endl;
        return "isoceles: two sides same length";
        
    } else if(firstAngle > 90 || secondAngle > 90 || thirdAngle > 90){
        cout << "obtuse: one angle greater than 90 degrees" << endl;
        return "obtuse: one angle greater than 90 degrees";
        
    } else if(firstAngle < 90 && secondAngle < 90 && thirdAngle < 90){
        cout << "acute: all angles less than 90 degrees" << endl;
        return "acute: all angles less than 90 degrees";
        
    } else {
        
        cout << "scalene: none of the above" << endl;
        return "scalene: none of the above";
    }
    
    
    
}

void runTests(){
    
    if(classifyTriangle(1, 0, 2, 0, 3, 0) == "degenerate: not a triangle"){
        
        cout << "Test1 passed" << endl;
        
    } else {
        
        cout << "Test1 failed" << endl;
        
    }
    
    if(classifyTriangle(0, 0, 0, 1, 1, 0) == "right triangle: one 90 degree angle"){
        
        cout << "Test2 passed" << endl;
        
    } else {
        
        cout << "Test2 failed" << endl;
        
    }
    
    if(classifyTriangle(0, 0, -1, 2, 1, 2) == "isoceles: two sides same length" ){
        
        cout << "Test3 passed" << endl;
        
    } else {
        
        cout << "Test3 failed" << endl;
        
    }
    
    if(classifyTriangle(0, 0, -2, 1, 2, 1) == "obtuse: one angle greater than 90 degrees" ){
        
        cout << "Test4 passed" << endl;
        
    } else {
        
        cout << "Test4 failed" << endl;
        
    }
    if(classifyTriangle(0, 0, -1, 2, 1, 3) == "acute: all angles less than 90 degrees" ){
        
        cout << "Test5 passed" << endl;
        
    } else {
        
        cout << "Test5 failed" << endl;
        
    }
    if(classifyTriangle(0, 0, -1, 2, 1, 3) != "scalene: none of the above" ){
        
        cout << "Test6 passed" << endl;
        
    } else {
        
        cout << "Test6 failed" << endl;
        
    }
    
    if(classifyTriangle(0, 0, -1, 2, 1, 3) != "equilateral: all sides same length" ){
        
        cout << "Test7 passed" << endl;
        
    } else {
        
        cout << "Test7 failed" << endl;
        
    }
    
    
    
}


int main(int argc, const char * argv[]) {
    
    runTests();
    
    /*
    int x1, y1, x2, y2, x3, y3;
    
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    cout << classifyTriangle(x1, y1, x2, y2, x3, y3) << endl;
    
    */
    
    return 0;
}
