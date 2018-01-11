//
//  triangle.cpp
//  Triangle
//
//  Created by Sydney Sturgeon on 1/9/18.
//  Copyright © 2018 Sydney Sturgeon. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;


//Helper function for triangleClassifier()
//Uses the distance formula to calculate the distance (length) between two (x, y) points
//Takes four ints as two (x, y) points as parameters
//Returns a float as the distance (length) between the two input points
float lineLength(int x1, int y1, int x2, int y2) {
    float x = pow((x2-x1), 2);
    float y = pow((y2-y1), 2);
    float length = sqrt(x+y);
    return length;
}



//Helper function for triangleClassifier()
//Uses the law of cosines to calculate an angle in degrees in a triangle
//Takes distances (lengths) of three lines as floats as parameters
//Returns an angle in degrees as a float
float calculateAngleA(float line1, float line2, float line3) {
    float numeratorA = (pow(line2, 2)) + (pow(line3, 2)) - (pow(line1, 2));
    float denominatorA = 2*line2*line3;
    float angleA = acos(numeratorA/denominatorA); //calculates angle in radians
    const float PI = 3.141592653589793238463f;
    return angleA * (180.0f/PI); //convert angle from radians to degrees
}



//Helper function for triangleClassifier()
//Uses law of cosines to calculate an angle in degrees in a triangle
//Takes distances (lengths) of three lines as floats as parameters
//Returns an angle in degrees as a float
float calculateAngleB(float line1, float line2, float line3) {
    float numeratorB = (pow(line3, 2)) + (pow(line1, 2)) - (pow(line2, 2));
    float denominatorB = 2*line3*line1;
    float angleB = acos(numeratorB/denominatorB); //calculates angle in radians
    const float PI = 3.141592653589793238463f;
    return angleB * (180.0f/PI); //convert angle from radians to degrees
}



//Using three (x, y) points as input within the function this classifies the triangle
//If the three (x, y) points do not make a valid triangle the input is classified as degenerate
//Returns a one-word standard print statement to the console stating the classification for a valid triangle
void triangleClassifier(int x1, int y1, int x2, int y2, int x3, int y3) {
    
    //calculate the lengths of the sides of the triangle
    float lineLength12 = lineLength(x1, y1, x2, y2);
    float lineLength13 = lineLength(x1, y1, x3, y3);
    float lineLength23 = lineLength(x2, y2, x3, y3);
    
    //if 2 sides added together are shorter than the 3rd side it's degenerate
        //Will never have this case as long as the input is three x,y points
//    if(lineLength12 + lineLength13 <= lineLength23
//       || lineLength12 + lineLength23 <= lineLength13
//       || lineLength23 + lineLength13 <= lineLength12) {
//        cout << "Degenerate. Not a triangle.\n";
//    }
    
    //calculate the angles in the triangle - rounded to 1 decimal place
    float angleA = roundf((calculateAngleA(lineLength12, lineLength13, lineLength23)*10)/10);
    float angleB = roundf((calculateAngleB(lineLength12, lineLength13, lineLength23)*10)/10);
    float angleC = roundf(((180.0f - angleA - angleB)*10)/10);
    
    //classify the triangle according to its side lengths or angles
        //right triangle: one 90 degree angle
        //isoceles: two sides same length
        //equilateral: all sides same length
        //obtuse: one angle > 90 degrees
        //acute: all angles < 90 degrees
    
    if(angleA == 90.0f || angleB == 90.0f || angleC == 90.0f) {
        cout << "Right triangle\n";
    }
    else if((lineLength12 == lineLength13 && lineLength12 != lineLength23)
            || (lineLength13 == lineLength23 && lineLength13 != lineLength12)
            || (lineLength12 == lineLength23 && lineLength12 != lineLength13)) {
        cout << "Isoceles\n";
    }
//EQUILATERAL will never be reached so it was removed
//    else if(lineLength12 == lineLength13 && lineLength13 == lineLength23) {
//        cout << "Equilateral\n";
//    }
    else if(angleA > 90.0f || angleB > 90.0f || angleC > 90.0f) {
        cout << "Obtuse\n";
    }
    else if(angleA < 90.0f && angleB < 90.0f && angleC < 90.0f) {
        cout << "Acute\n";
    }
//SCALENE will never be reached so it was removed
//    else {
//        cout << "Scalene\n";
//    }
}



//Using three (x, y) points as input the points are determined to be able to make a triangle or not
//If the three (x, y) points do not make a valid triangle the input is classified as degenerate
void triangle() {
    while(true) { //while(true) loop will run as long as there are points being entered
        int x1, y1, x2, y2, x3, y3; //represent three x, y points
         bool triangle = true; //if true then the points are classified as a type of triangle
        //cout << "\nEnter the three points of triangle " << i+1 << " in the following format (spaces in between): x1 y1 x2 y2 x3 y3\n";
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        if(!(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)) {
            break; //stops program
        }
       
        //integers entered should be between 0 and 100 inclusively
        if(x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0 || x3 < 0 || y3 < 0
           || x1 > 100 || y1 > 100 || x2 > 100 || y2 > 100 || x3 > 100 || y3 > 100) {
            triangle = false;
            cout << "Incorrect inputs. Points should be integers between 0 and 100 inclusively.\n";
        }
        
        //if two or more points are the same (Degenerate. Not a triangle.)
        if((x1 == x2 && y1 == y2) || (x2 == x3 && y2 == y3) || (x1 == x3 && y1 == y3)) {
            triangle = false;
            cout << "Degenerate. Not a triangle. 2 or more points are the same.\n";
        }
        
        //if points lie on the same line it is not a triangle (Degenerate. Not a triangle.)
        if((x1 == x2 && x2 == x3) || (y1 == y2 && y2 == y3)) { //need to fix and finish
            triangle = false;
            cout << "Degenerate. Not a triangle. Points lie on the same line.\n";
        }
        
        //if the three points are determined to be a triangle it is classified
        if(triangle == true) {
            triangleClassifier(x1, y1, x2, y2, x3, y3);
        }
    } //end of while(true) loop
}



//Test case examples
void testTriangle() {
    //Test right triangle
        //(0,0)(4,0)(4,3)
        //(0,0)(1,0)(1,1)
    
    //Test isoceles triangle
        //(2,1)(7,1)(5,5)
        //(5,5)(2,1)(7,1)
        //(7,1)(5,5)(2,1)
    
    //Test equilateral triangle
        //Difficult to find three integer points that make up an equilateral triangle
        //Equilateral case commented out in code
    
    //Test obtuse triangle
        //(0,2)(10,0)(18,2)
    
    //Test acute triangle
        //(0,0)(10,2)(4,30)
    
    //Test scalene triangle
        //Triangle will be classified as something else before being classified as scalene
        //Scalene case commented out in code
    
    //Test degenerate
        //(0,0)(10,5)(0,0) - two points are the same
        //(0,0)(5,0)(10,0) - points lie on the same line
    
    //Test incorrect inputs
        //(-1,0)(40,10)(0,15)
        //(50,101)(40,33)(20,70)
}

int main(int argc, const char * argv[]) {
    triangle();
    testTriangle();
    return 0;
}



