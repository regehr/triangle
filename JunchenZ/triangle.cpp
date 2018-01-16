#include <cmath>
#include <iostream>

using namespace std;

void sortS(int s[]) {
  for (int i = 0; i < 2; i++) {
    int min = i;
    for (int j = i + 1; j < 3; j++) {
      if (s[min] > s[j]) {
        min = j;
      }
    }
    int temp = s[min];
    s[min] = s[i];
    s[i] = temp;
  }
}

int main(int argc, const char *argv[]) {
  int p[6] = {};

  cout << "please enter 6 integers from 0 to 100 as 3 pairs of corrdinates to "
          "form a triangle: "
       << endl;

  while (!cin.eof()) {
    for (int i = 0; i < 6; i++) {
      cin >> p[i];
    }
      
    for (int i = 0; i < 6; i++) {
        if(p[i] < 0 || p[i] > 100){
            continue;
        }
    }
      
    int s[3] = {};

    // calculate square of length of each side
    s[0] = pow((p[2] - p[0]), 2) + pow((p[3] - p[1]), 2);
    s[1] = pow((p[4] - p[0]), 2) + pow((p[5] - p[1]), 2);
    s[2] = pow((p[4] - p[2]), 2) + pow((p[5] - p[3]), 2);

    sortS(s);

    if (sqrt(s[0]) + sqrt(s[1]) <= sqrt(s[2])) {
      cout << "degenerate" << endl;
      continue;
    }

    if (s[0] + s[1] == s[2]) {
      cout << "right triangle" << endl;
      continue;
    }

    if (s[0] == s[1] || s[1] == s[2]) {
      cout << "isosceles" << endl;
      continue;
    }

    if (s[0] + s[1] < s[2]) {
      cout << "obtuse" << endl;
      continue;
    }

    if (s[0] + s[1] > s[2]) {
      cout << "acute" << endl;
      continue;
    }
  }
}