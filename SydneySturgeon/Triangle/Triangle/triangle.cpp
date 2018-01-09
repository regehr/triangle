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

float lineLength(int x1, int y1, int x2, int y2) {
    float length = 0;
    float x = pow((x2-x1), 2);
    float y = pow((y2-y1), 2);
    length = sqrt(x+y);
    return length;
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
    float lineLength13 = lineLength(x1, y1, x3, y3);
    float lineLength23 = lineLength(x2, y2, x3, y3);
    
    if(lineLength12 == lineLength13 && lineLength13 == lineLength23) {
        cout << "Equilateral\n";
    }
    return 0;
}



