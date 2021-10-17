#include <bits/stdc++.h>

using namespace std;

int ary[10];

int main(void) {
  int t;

  cin >> t;

  int temp;

  for (int i = 0; i < t; ++i) {
    for (int j = 0; j < 10; ++j) {
      cin >> temp;
      ary[j] = temp;
    }
    sort(ary, ary + 10);
    cout << ary[7] << endl;
  }

  return 0;
}
