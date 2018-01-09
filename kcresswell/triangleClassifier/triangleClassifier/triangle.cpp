//
//  triangle.cpp
//  triangleClassifier
//
//  Created by Kayla Cresswell on 1/9/18.
//  Copyright © 2018 Kayla Cresswell. All rights reserved.
//

#include <iostream>
#include <cmath>

std::string getTriangleType(int x1, int y1, int x2, int y2, int x3, int y3){
    //calculate each side length
    //d = sqrt((x2 - x1)^2 + (y2 - y1)^2)
    float length1, length2, length3;
    length1 = sqrt((x2 - x1)^2 + (y2 - y1)^2);
    length2 = sqrt((x3 - x1)^2 + (y3 - y1)^2);
    length3 = sqrt((x3 - x2)^2 + (y3 - y2)^2);
    
    //calculate each angle
    float angle1, angle2, angle3;
    angle1 = acos((length3 + length2 - length1)/(2*length3*length2)); //A
    angle3 = acos((length2 + length1 - length3)/(2*length2*length1)); //B
    angle2 = 180 - angle1 - angle3;
    
    //right triangle: one 90 degree angle
    if(angle1 == 90.0 || angle2 == 90.0 || angle3 == 90.0){
        std::cout << "right/n";
    }
    
    //isosceles: two sides same length
    else if(length1 == length2 || length1 == length3 || length2 == length3){
        std::cout << "isosceles/n";
    }
    
    //equilateral: all sides same length
    else if(length1 == length2 && length1 == length3){
        std::cout << "equilateral/n";
    }
    
    //obtuse: one angle >90
    else if(angle1 > 90 || angle2 > 90 || angle3 > 90){
        std::cout << "obtuse/n";
    }
    
    //acute: all angles <90
    else if(angle1 < 90 || angle2 < 90 || angle3 < 90){
        std::cout << "acute/n";
    }
    
    //scalene: none of the above
    return "scalene";
    
}

int main(int argc, const char * argv[]) {
    int x1, y1, x2, y2, x3, y3 = 0;
    std::cout << "Enter shape coordinates in the following format x1 y1 x2 y2 x3 y3: ";
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    std::cout << "You entered: " << x1 << " " << y1 << " " << x2  << " " << y2  << " " << x3  << " " << y3;
    std::cout << "Triangle Type: " << getTriangleType(x1, y1, x2, y2, x3, y3);
    
    return 0;
}
