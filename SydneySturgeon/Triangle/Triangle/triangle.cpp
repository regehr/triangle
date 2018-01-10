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
//Uses the law of cosines to calculate an angle in a triangle
//Takes distances (lengths) of three lines as floats as parameters
//Returns an angle in degrees as a float
float calculateAngleA(float line1, float line2, float line3) {
    float numeratorA = (pow(line2, 2)) + (pow(line3, 2)) - (pow(line1, 2));
    float denominatorA = 2*line2*line3;
    float angleA = acos(numeratorA/denominatorA); //calculates angle in radians
    const float PI = 3.141592653589793238463f;
    float angle = angleA * (180.0f/PI); //convert from radians to degrees
    return angle;
}


//Helper function for triangleClassifier()
//Uses law of cosines to calculate an angle in a triangle
//Takes distances (lengths) of three lines as floats as parameters
//Returns an angle in degree as a float
float calculateAngleB(float line1, float line2, float line3) {
    float numeratorB = (pow(line3, 2)) + (pow(line1, 2)) - (pow(line2, 2));
    float denominatorB = 2*line3*line1;
    float angleB = acos(numeratorB/denominatorB); //calculates angle in radians
    const float PI = 3.141592653589793238463f;
    float angle = angleB * (180.0f/PI); //convert from radians to degrees
    return angle;
}


void triangleClassifier() {
    
}



//Using three (x, y) points as input within the function it classifies the triangle
//If the three (x, y) points do not make a valid triangle the input is classified as degenerate
//Returns a one-word standard print statement to the console stating the classification for a valid triangle
void triangle() {
    int numOfTriangles;
    bool triangle = true;
    cout << "Enter the number of triangles being entered.\n";
    cin >> numOfTriangles;
    for(int i = 0; i < numOfTriangles; i++) {
        int x1, y1, x2, y2, x3, y3;
        cout << "\nEnter the 3 points of triangle " << i+1 << " in the following format (spaces in between): x1 y1 x2 y2 x3 y3\n";
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        
        if(x1, y1, x2, y2, x3, y3 < 0 || x1, y1, x2, y2, x3, y3 > 100) {
            triangle = false;
            cout << "Incorrect inputs. Points should be integers between 0 and 100 inclusively.\n";
        }
        //if points are the same (degenerate. not a triangle)
        if(x1 == x2 && y1 == y2) {
            triangle = false;
            cout << "Degenerate. Not a triangle. 2 or more points are the same.\n";
        }
        if(x2 == x3 && y2 == y3) {
            triangle = false;
            cout << "Degenerate. Not a triangle. 2 or more points are the same.\n";
        }
        if(x1 == x3 && y1 == y3) {
            triangle = false;
            cout << "Degenerate. Not a triangle. 2 or more points are the same.\n";
        }
        
        
        if(x1 == x2 && x2 == x3) { //need to fix and finish
            triangle = false;
            cout << "Degenerate. Not a triangle.\n";
        }
        
        float lineLength12 = lineLength(x1, y1, x2, y2);
        cout << lineLength12 << "\n";
        float lineLength13 = lineLength(x1, y1, x3, y3);
        cout << lineLength13 << "\n";
        float lineLength23 = lineLength(x2, y2, x3, y3);
        cout << lineLength23 << "\n";
        
        if(lineLength12 + lineLength13 <= lineLength23
           || lineLength12 + lineLength23 <= lineLength13
           || lineLength23 + lineLength13 <= lineLength12) {
            cout << "Degenerate. Not a triangle.\n";
            //return 0;
        }
        
        
        
        float angleA = calculateAngleA(lineLength12, lineLength13, lineLength23);
        angleA = roundf(angleA*10)/10; //rounds to 1 decimal place
        cout << angleA << "\n";
        float angleB = calculateAngleB(lineLength12, lineLength13, lineLength23);
        angleB = roundf(angleB*10)/10; //rounds to 1 decimal place
        cout << angleB << "\n";
        float angleC = 180.0f - angleA - angleB;
        angleC = roundf(angleC*10)/10; //rounds to 1 decimal place
        cout << angleC << "\n";
        
        if(angleA || angleB || angleC == 90.0f) {
            cout << "Right triangle\n";
        }
        else if(lineLength12 == lineLength13 && lineLength13 == lineLength23) {
            cout << "Equilateral\n";
        }
        else if(lineLength12 == lineLength13 && lineLength12 != lineLength23) {
            cout << "Isoceles\n";
        }
        else if(lineLength13 == lineLength23 && lineLength13 != lineLength12) {
            cout << "Isoceles\n";
        }
        else if(lineLength12 == lineLength23 && lineLength12 != lineLength13) {
            cout << "Isoceles\n";
        }
        else if(angleA || angleB || angleC > 90.0f) {
            cout << "Obtuse\n";
        }
        else if(angleA && angleB && angleC < 90.0f) {
            cout << "Acute\n";
        }
        else {
            cout << "Scalene\n";
        }
    }
}

void testTriangle() {
    
}

int main(int argc, const char * argv[]) {
    triangle();
    testTriangle();
    return 0;
}



