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

vector<int> v;

int main(void) {
  int a, b;

  cin >> a >> b;

  for (int i = a; i <= b; ++i) {
    if (isDecimal(i) == true) {
      v.push_back(i);
    } else {
      continue;
    }
  }

  int sum = accumulate(v.begin(), v.end(), 0);

  if (v.size() == 0) {
    cout << -1 << endl;
  } else {
    cout << sum << endl << v[0] << endl;
  }

  return 0;
}
