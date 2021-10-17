#include <bits/stdc++.h>

using namespace std;

int main(void) {
  long long x, y, z, right, left, mid, tempZ;

  cin >> x >> y;

  z = 100 * y / x;
  if (z >= 99) {
    cout << -1;
    return 0;
  }

  left = 0;
  right = 1000000001;

  while (left <= right) {
    mid = (left + right) / 2;

    tempZ = 100 * (y + mid) / (x + mid);

    if (z < tempZ)
      right = mid - 1;
    else
      left = mid + 1;
  }

  cout << left;

  return 0;
}