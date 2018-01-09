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
};


double findLength(int x, int y) {
    return 0;
}


void triangleComputations(string triangles) {
    
//    for (int i = 0; i < triangles.length(); i+1) {
//
//    }
    
}



void getInput() {
    int numberOfTriangles = -1;
    
    while (numberOfTriangles < 0){
        cout << "Please enter how many triangles you would like to test: ";
        cin >> numberOfTriangles;
    }
    triangle allTriangles [numberOfTriangles];

    string triangles = "";
    for(int i = 0; i < numberOfTriangles; i++){
        cout << "Please enter points for triangle " << i+1 << " ";
        cin >> triangles;
        
    }
    
    triangleComputations(triangles);
    return;
}


int main(int argc, const char * argv[]) {
    
    getInput();
    return 0;
}
