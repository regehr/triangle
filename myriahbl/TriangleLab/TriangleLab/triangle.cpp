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
 
 Notes to self:
 Create text file for tests
 Comment out things that shouldn't get printed
 Comment out my testing function
 Uncomment stuff in main
 
 
 */
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

double findLineLength(double x1, double y1, double x2, double y2){
    
    double X1 = x1/1.0;
    double Y1 = y1/1.0;
    double X2 = x2/1.0;
    double Y2 = y2/1.0;
    
    return sqrt((pow(X2 - X1, 2) + pow(Y2 - Y1, 2)));
    
}

double findAngle(double side1, double side2, double side3){
    
    //cout << "side1: " << side1 << endl;
    //cout << "side2: " << side2 << endl;
    //cout << "side3: " << side3 << endl;
    
    return abs(acos((pow(side2, 2) + pow(side3, 2) - pow(side1, 2)) / (2.0 * side2 * side3)) * (180.0/3.14159265359));
    
}



string classifyTriangle(double x1, double y1, double x2, double y2, double x3, double y3){
    
    double side1 = findLineLength(x1, y1, x2, y2);
    
    double side2 = findLineLength(x1, y1, x3, y3);
    
    double side3 = findLineLength(x2, y2, x3, y3);
    
    
    double firstAngle = findAngle(side1, side2, side3);
    //cout << "firstAngle: " << firstAngle << endl;
    double secondAngle = findAngle(side2, side1, side3);
    //cout << "secondAngle: " << secondAngle << endl;
    double thirdAngle = findAngle(side3, side1, side2);
    //cout << "thirdAngle: " << thirdAngle << endl;
    
    float slope;
    if (x1 != x2) {//could be a possible divide by zero problem because I'm using doubles
        slope = (y1 - y2) / (x1 - x2); //got this from Greg
    } else {
        slope = (y3 - y2) / (x3 - x2);
    }
    
    float intercept = y1 - (slope * x1);//got this from Greg; ask him about it
    
    if((x1 - x2 == 0) && (x1 - x3 == 0)){
        //check for verticle line Note: got this idea from Greg
        //cout << "degenerate" << endl;
        return "degenerate";
        
    } else if(y3 == (slope * x3 + intercept)){
        //check to see if all points fall on a line
        
            //std::cout << "degenerate\n"; // All points fall on a line.
        
            return "degenerate";
        
        
    } else if((firstAngle < 90.001 && firstAngle > 89.999) || (secondAngle < 90.001 && secondAngle > 89.999)|| (thirdAngle < 90.001 && thirdAngle > 89.999)){
        
        //cout << "right" << endl;
        return "right";
        
    } else if ((abs(side1 - side2) < 0.001) && (abs(side1 - side3) < 0.001) && (abs(side2 - side3) < 0.001)){
        
       // cout << "equilateral" << endl;
        return "equilateral";
        
        
    } else if((abs(side1 - side2) < 0.001) || (abs(side1 - side3) < 0.001) || (abs(side2 - side3) < 0.001)){
        cout << "isoceles" << endl;
        return "isoceles";
        
    } else if(firstAngle > 90.0 || secondAngle > 90.0 || thirdAngle > 90.0){
        
        //cout << "obtuse" << endl;
        return "obtuse";
        
    } else if(firstAngle < 90.0 && secondAngle < 90.0 && thirdAngle < 90.0){
        
        //cout << "acute" << endl;
        return "acute";
        
    } else {
        
        //cout << "scalene" << endl;
        return "scalene";
    }
    
    
    
}

void runTests(){
    
    if(classifyTriangle(0, 1, 0, 2, 0, 3) == "degenerate"){
        
        cout << "Test1 passed" << endl;
        
    } else {
        
        cout << "Test1 failed" << endl;
        
    }
    
    if(classifyTriangle(0, 0, 0, 1, 1, 0) == "right"){
        
        cout << "Test2 passed" << endl;
        
    } else {
        
        cout << "Test2 failed" << endl;
        
    }
    
    if(classifyTriangle(0, 0, -4, 3, 0.598, 4.964) == "equilateral" ){
        
        cout << "Test2.5 passed" << endl;
        
    } else {
        
        cout << "Test2.5 failed" << endl;
        
    }
    
    if(classifyTriangle(0, 0, -1, 2, 1, 2) == "isoceles" ){
        
        cout << "Test3 passed" << endl;
        
    } else {
        
        cout << "Test3 failed" << endl;
        
    }
    
    if(classifyTriangle(0, 0, -2, 1, 4, 1) == "obtuse" ){
        
        cout << "Test4 passed" << endl;
        
    } else {
        
        cout << "Test4 failed" << endl;
        
    }
    if(classifyTriangle(0, 0, -1, 2, 2, 3) == "acute" ){
        
        cout << "Test5 passed" << endl;
        
    } else {
        
        cout << "Test5 failed" << endl;
        
    }
    if(classifyTriangle(0, 0, -1, 2, 2, 3) == "scalene" ){
        
        cout << "Test6 passed" << endl;
        
    } else {
        
        cout << "Test6 failed" << endl;
        
    }
    
   
    
    
    
}


int main(int argc, const char * argv[]) {
    
    //runTests();
    
    
    double x1, y1, x2, y2, x3, y3;
    
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    cout << classifyTriangle(x1, y1, x2, y2, x3, y3) << endl;
    
    
    
    return 0;
}
