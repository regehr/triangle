#include <iostream>
#include <cmath>

using namespace std;

//while true loop?
//check input?
//delete unused cases?

int main(int argc, const char * argv[]) {
    
    int x1, y1, x2, y2, x3, y3;
    
    cout << "please enter 6 integers from 0 to 100 as 3 pairs of corrdinates to form a triangle" << endl;
    
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    //calculate square of length of each side
    int s1 = pow((x2 - x1), 2) + pow((y2 - y1), 2);
    int s2 = pow((x3 - x1), 2) + pow((y3 - y1), 2);
    int s3 = pow((x3 - x2), 2) + pow((y3 - y2), 2);
    
    if((sqrt(s1) + sqrt(s2) <= sqrt(s3)) || (sqrt(s3) + sqrt(s2) <= sqrt(s1)) || (sqrt(s1) + sqrt(s3) <= sqrt(s2))){
        cout << "degenerate" << endl;
        return 0;
    }
    
    if((s1 + s2 == s3) || (s1 + s3 == s2) || (s3 + s2 == s1)){
        cout << "right triangle" << endl;
        return 0;
    }
    
    if(s1 == s2 || s3 == s2 || s3 == s1){
        cout << "isosceles" << endl;
        return 0;
    }
    
    if(s3 == s2 && s3 == s1){
        cout << "equilateral" << endl;
        return 0;
    }
    
    if((s1 + s2 < s3) || (s1 + s3 < s2) || (s3 + s2 < s1)){
        cout << "obtuse" << endl;
        return 0;
    }
    
    if((s1 + s2 > s3) && (s1 + s3 > s2) && (s3 + s2 > s1)){
        cout << "acute" << endl;
        return 0;
    }
    
    if(s3 != s2 && s3 != s1 && s2 != s1){
        cout << "scalene" << endl;
        return 0;
    }
    
}
