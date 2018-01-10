//
//  main.cpp
//  SpecifyTriangle
//
//  Created by Eric Williams on 1/9/18.
//  Copyright © 2018 Eric Williams. All rights reserved.
//

#include <iostream>
#include <math.h>

int main(int argc, const char * argv[]) {
    int x1, y1, x2, y2, x3, y3;
    
    std::cout << "Please provide 3 points for a triangle in this format (x1 y1 x2 y2 x3 y3):" << std::endl;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    std::cout << "Your responses: " << x1 << " " << y1  << " " << x2 << " " << y2 << " " << x3 << " " << y3 << std::endl;
    std::cout << "Your responses: " << x1 << y1 << x2 << y2 << x3 << y3  << std::endl;
    
    
    
    return 0;
}

float findLength(int coorX1, int coorY1, int coorX2, int coorY2){
    return sqrtf(pow((coorX2 - coorX1),2) + pow((coorY2 - coorY1),2));
}
