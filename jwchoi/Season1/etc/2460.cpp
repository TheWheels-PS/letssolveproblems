#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int s = 0, mtemp = 0;
  int ary[10][2];

  for (int i = 0; i < 10; ++i) {
    cin >> ary[i][0] >> ary[i][1];

    s = s - ary[i][0] + ary[i][1];

    mtemp = max(mtemp, s);
  }

  cout << mtemp << endl;

  return 0;
}