//
//  traingle.cpp
//  MSD_6015
//
//  Created by Gregory Colledge on 1/9/18.
//  Copyright © 2018 Gregory Colledge. All rights reserved.
//
//  The following link was used for reference:
//  https://stackoverflow.com/questions/1321137/convert-string-containing-several-numbers-into-integers

#include <iostream>
#include <string>
#include <sstream>

int main(int argc, const char * argv[]) {
    int x1, y1, x2, y2, x3, y3;
    std::string input;
    std::stringstream ss(str);

    std::cout << "Enter the points of a triangle as follows:\n";
    std::cout << "x1 y1 x2 y2 x3 y3\n";
    std::cout << "Where each x and y can be integers between 0 and 100 inclusive.\n";
    std::getline(std::cin, input);
    
    std::cout << "Your input looks like this: " + input;
    
    int [] xs = int[3];
    int [] ys = int[3];

    for(int i=0; i < 6; i++){
        
    }
    return 1;
}
