//
//  main.cpp
//  Triangles
//
//  Created by Chris Roper on 1/9/18.
//  Copyright © 2018 Chris Roper. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
#include <cmath>
#include <vector>
double pi = 3.1415926535897;

double slope(double x1, double x2, double y1, double y2){
    return (x1-x2)/(y1-y2);
}

double degreesToRadians(double degrees){
    return degrees*pi/180;
}

double radiansToDegrees(double radians){
    return radians*180/pi;
}

int main(int argc, const char * argv[]) {

    while(true){
        std::cout << "Please enter coordinates:\n";
        double x1,y1,x2,y2,x3,y3;
        double test;
        std::vector<double> triangleArguments;
        std::string input="";
        getline(std::cin,input);
        std::istringstream iss(input);
        while(iss>>test){
            triangleArguments.push_back(test);
        }
        if(triangleArguments.size()!=6){
            std::cout << "Invalid arguments\n";
            continue;
        }
        x1 = triangleArguments[0];
        y1 = triangleArguments[1];
        x2 = triangleArguments[2];
        y2 = triangleArguments[3];
        x3 = triangleArguments[4];
        y3 = triangleArguments[5];

        //check identical points
        if(x1 == x2 && y1 == y2){
            std::cout << "Degenerate: Not a triangle\n";
            continue;
        }
        if(x2 == x3 && y2 == y3){
            std::cout << "Degenerate: Not a triangle\n";
            continue;
        }
        if(x1 == x3 && y1 == y3){
            std::cout << "Degenerate: Not a triangle\n";
            continue;
        }
        //slope check
        if(slope(x1,x2,y1,y2)==slope(x2,x3,y2,y3) || slope(x1,x2,y1,y2)==slope(x1,x3,y1,y3)){
            std::cout << "Degenerate: Not a triangle\n";
            continue;
        }

        double lengthC = sqrt(pow((x1-x2),2)+pow((y1-y2),2));
        double lengthA = sqrt(pow((x2-x3),2)+pow((y2-y3),2));
        double lengthB = sqrt(pow((x3-x1),2)+pow((y3-y1),2));
        assert(lengthA > 0 && lengthB > 0 && lengthC > 0);
        
        double angleC = round((10*radiansToDegrees(acos((pow(lengthA,2)+pow(lengthB,2)-pow(lengthC,2))/(2*lengthA*lengthB))))/10);
        double angleB = round((10*radiansToDegrees(asin(lengthB*(sin(degreesToRadians(angleC))/lengthC))))/10);
        double angleA = 180 - angleC - angleB;
        assert(angleA > 0 && angleB > 0 && angleC > 0);
        
        std::cout << lengthA << " " << lengthB << " " << lengthC << std::endl;
        std::cout << angleA << " " << angleB << " " << angleC << std::endl;
        if(angleA>100 || angleB>100 || angleC>100){
            std::cout << "Degenerate: Not a triangle\n";
            continue;
        }
        else if(angleA == angleB && angleB == angleC){
            std::cout << "Equilateral Triangle\n";
            continue;
        }
        //(test for Equilateral)
        //(coordinates =
        else if (angleA == 90 || angleB == 90 || angleC == 90){
            std::cout << "Right Triangle\n";
            continue;
        }
        //(test for Right)
        //(coordinates = 0 0 0 1 1 0)
        else if (angleA == angleB || angleB == angleC || angleC == angleA || lengthA == lengthB || lengthB==lengthC || lengthC==lengthA){
            std::cout << "Isoceles Triangle\n";
            continue;
        }
        //(test for Isosceles)
        //(coordinates = -1 0 1 0 0 2)
        else if (angleA < 90 && angleB < 90 && angleC < 90){
            std::cout << "Scalene Acute Triangle\n";
            continue;
        }
        //(test for Scalene Acute)
        //(coordinates = 0 0 4 0 1 3)
        else if (angleA > 90 || angleB > 90 || angleC > 90){
            std::cout << "Scalene Obtuse Triangle\n";
            continue;
        }
        //(test for Scalene Obtuse)
        //(coordinates = 0 0 5 0 6 1)
    }
    return 0;
}
