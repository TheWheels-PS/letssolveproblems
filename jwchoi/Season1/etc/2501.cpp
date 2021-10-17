#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int p, q, idx = 1, temp;
  int ary[10001];

  cin >> p >> temp;

  for (q = 1; q <= p; ++q) {
    if (p % q == 0) {
      ary[idx] = q;
      ++idx;
    }
  }

  sort(ary, ary + idx);

  if (temp > idx) {
    cout << 0 << endl;
  } else {
    cout << ary[temp] << endl;
  }

  return 0;
}
