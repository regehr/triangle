//
//  main.cpp
//  Triangle
//
//  Created by William Aldrich on 1/9/18.
//  Copyright © 2018 William Aldrich. All rights reserved.
//

#include <iostream>

using namespace std;

struct triangle {
    int pointA;
    int pointB;
    int pointC;
    float lengthSideA;
    float lengthSideB;
    float lengthSideC;
    float angleA;
    float angleB;
    float angleC;
};


double findLength(int x, int y) {
    return 0;
}


void triangleComputations(string triangles) {
    
    for (int i = 0; i < triangles.length(); i+1) {
        
    }
    
}



void getInput() {
    string triangles;
    cout << "Please enter points for triangle(s): ";
    cin >> triangles;
    
    triangleComputations(triangles);
}


int main(int argc, const char * argv[]) {
    
    getInput();
    return 0;
}
