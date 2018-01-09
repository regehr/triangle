//
//  main.cpp
//  Triangle
//
//  Created by Sydney Sturgeon on 1/9/18.
//  Copyright © 2018 Sydney Sturgeon. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;

//Uses the distance formula
float lineLength(int x1, int y1, int x2, int y2) {
    float x = pow((x2-x1), 2);
    float y = pow((y2-y1), 2);
    float length = sqrt(x+y);
    //length = roundf(length*100)/100;
    return length;
}


//Uses the law of cosines
float calculateAngleA(float line1, float line2, float line3) {
    float numeratorA = (pow(line2, 2)) + (pow(line3, 2)) - (pow(line1, 2));
    float denominatorA = 2*line2*line3;
    float angleA = acos(numeratorA/denominatorA);
    const float PI = 3.141592653589793238463f;
    float angle = angleA * (180.0f/PI);
    return angle;
}

//Uses law of cosines
float calculateAngleB(float line1, float line2, float line3) {
    float numeratorB = (pow(line3, 2)) + (pow(line1, 2)) - (pow(line2, 2));
    float denominatorB = 2*line3*line1;
    float angleB = acos(numeratorB/denominatorB);
    const float PI = 3.141592653589793238463f;
    float angle = angleB * (180.0f/PI);
    return angle;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    int x1, y1, x2, y2, x3, y3;
    cout << "Enter the 3 points of a triangle in the following format (spaces in between): x1 y1 x2 y2 x3 y3\n";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    
    
    if(x1, y1, x2, y2, x3, y2 < 0) {
        cout << "Incorrect inputs. Points should be integers between 0 and 100 inclusively.\n";
    }
    if(x1, y1, x2, y2, x3, y3 > 100) {
        cout << "Incorrect inputs. Points should be integers between 0 and 100 inclusively.\n";
    }
    
    float lineLength12 = lineLength(x1, y1, x2, y2);
        cout << lineLength12 << "\n";
    float lineLength13 = lineLength(x1, y1, x3, y3);
        cout << lineLength13 << "\n";
    float lineLength23 = lineLength(x2, y2, x3, y3);
        cout << lineLength23 << "\n";
    
    float angleA = calculateAngleA(lineLength12, lineLength13, lineLength23);
    angleA = roundf(angleA*100)/100; //rounds to 2 decimal places
        cout << angleA << "\n";
    float angleB = calculateAngleB(lineLength12, lineLength13, lineLength23);
    angleB = roundf(angleB*100)/100; //rounds to 2 decimal places
        cout << angleB << "\n";
    float angleC = 180.0f - angleA - angleB;
    angleC = roundf(angleC*100)/100; //rounds to 2 decimal places
        cout << angleC << "\n";
    
    if(lineLength12 == lineLength13 && lineLength13 == lineLength23) {
        cout << "Equilateral\n";
    }
    else {
        cout << "Scalene\n";
    }
    return 0;
}



