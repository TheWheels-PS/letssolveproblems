#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int a, b;
  int temp, time;

  cin >> time;

  for (int i = 0; i < time; ++i) {
    cin >> a >> b;
    temp = 1;

    for (int j = 0; j < b; ++j) {
      temp = (a * temp) % 10;
    }

    if (temp == 0) {
      cout << 10 << endl;
    } else
      cout << temp << endl;
  }

  return 0;
}