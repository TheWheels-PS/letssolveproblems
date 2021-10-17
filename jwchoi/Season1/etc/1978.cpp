#include <bits/stdc++.h>

using namespace std;

bool isDecimal(int n) {
  if (n == 1) {
    return false;
  }
  int temp = 0;
  for (int i = 2; i <= n; ++i) {
    if (n % i != 0) {
      continue;
    } else if (n % i == 0) {
      ++temp;
    }
  }

  if (temp == 1) {
    return true;
  } else {
    return false;
  }
}

int main(void) {
  int t, temp, cnt = 0;

  cin >> t;

  for (int i = 0; i < t; ++i) {
    cin >> temp;

    if (isDecimal(temp) == true) {
      ++cnt;
    } else {
      continue;
    }
  }

  cout << cnt << endl;

  return 0;
}