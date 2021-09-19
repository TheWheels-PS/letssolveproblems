#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int ary[3][5];

int main(void) {
  for (int j = 0; j < 3; ++j) {
    for (int i = 0; i < 4; ++i) {
      cin >> ary[j][i];

      ary[j][4] += ary[j][i];
    }
  }

  for (int i = 0; i < 3; ++i) {
    if (ary[i][4] == 3)
      cout << 'A' << endl;
    else if (ary[i][4] == 2)
      cout << 'B' << endl;
    else if (ary[i][4] == 1)
      cout << "C" << endl;
    else if (ary[i][4] == 0)
      cout << "D" << endl;
    else if (ary[i][4] == 4)
      cout << "E" << endl;
  }
}
