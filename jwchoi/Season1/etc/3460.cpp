#include <bits/stdc++.h>

using namespace std;

void sol(int n) {
  int ary[100001];
  int idx = 0;

  if (n == 1) {
    cout << 0 << endl;
    return;
  }

  while (n != 1) {
    ary[idx++] = n % 2;
    n = n / 2;

    if (n == 1) {
      ary[idx] = n;
      break;
    }
  }

  for (int i = 0; i <= idx; ++i) {
    if (ary[i] == 1) {
      cout << i << ' ';
    }
  }

  cout << endl;
}

int main(void) {
  int t, n;

  cin >> t;

  for (int i = 0; i < t; ++i) {
    cin >> n;

    sol(n);
  }

  return 0;
}
