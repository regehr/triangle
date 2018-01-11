#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int coord[3][2];
    
    cout << "please enter 6 integers from 0 to 100 as 3 pairs of corrdinates to form a shape" << endl;
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            cin >> coord[i][j];
        }
    }
    
    int side1 = pow((coord[0][0] - coord[1][0]), 2) + pow((coord[0][1] - coord[1][1]), 2);

    int side2 = pow((coord[2][0] - coord[1][0]), 2) + pow((coord[2][1] - coord[1][1]), 2);

    int side3 = pow((coord[2][0] - coord[0][0]), 2) + pow((coord[2][1] - coord[0][1]), 2);

    if((sqrt(side1) + sqrt(side2)) <= sqrt(side3) || (sqrt(side3) + sqrt(side2) <= sqrt(side1)) || (sqrt(side1) + sqrt(side3)) <= sqrt(side2)){
        cout << "it is not a triangle" << endl;
        return 0;
    }
    
    if((side1 + side2 == side3) || (side1 + side3 == side2) || (side3 + side2 == side1)){
        cout << "it is a right triangle" << endl;
    }
    
    if((side1 + side2 < side3) || (side1 + side3 < side2) || (side3 + side2 < side1)){
        cout << "it is an obtuse triangle" << endl;
    }
    
    if((side1 + side2 > side3) && (side1 + side3 > side2) && (side3 + side2 > side1)){
        cout << "it is an acute triangle" << endl;
    }
    
    if(side1 == side2 || side3 == side2 || side3 == side1){
        cout << "it is an isosceles triangle" << endl;
    }
    
    if(side3 == side2 && side3 == side1){
        cout << "it is an equilateral triangle" << endl;
    }
    
    if(side3 != side2 && side3 != side1 && side2 != side1){
        cout << "it is a scalene triangle" << endl;
    }
    
}
