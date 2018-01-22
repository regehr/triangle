#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, const char *argv[]) {
  int p[6] = {};

  while (cin >> p[0]) {
    for (int i = 1; i < 6; i++) {
      cin >> p[i];
    }

    for (int i = 0; i < 6; i++) {
      if (p[i] < 0 || p[i] > 100) {
        cout << "degenerate" << endl;
        continue;
      }
    }

    int s[3] = {};

    // calculate square of length of each side
    s[0] = pow((p[2] - p[0]), 2) + pow((p[3] - p[1]), 2);
    s[1] = pow((p[4] - p[0]), 2) + pow((p[5] - p[1]), 2);
    s[2] = pow((p[4] - p[2]), 2) + pow((p[5] - p[3]), 2);

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

    if((p[3] - p[1]) * (p[4] - p[2]) == (p[2] - p[0]) * (p[5] - p[3])){
        cout << "degenerate" << endl;
        continue;
    }

    if (s[0] + s[1] == s[2]) {
      cout << "right" << endl;
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
