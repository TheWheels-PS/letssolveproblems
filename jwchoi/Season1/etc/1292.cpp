#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int main(void) {
  for (int i = 1; i <= 1000; ++i) {
    for (int j = 1; j <= i; ++j) {
      v.push_back(i);
    }
  }

  int ans = 0;

  int a, b;

  cin >> a >> b;

  for (int i = (a - 1); i <= (b - 1); ++i) {
    ans += v[i];
  }

  cout << ans << endl;

  return 0;
}
