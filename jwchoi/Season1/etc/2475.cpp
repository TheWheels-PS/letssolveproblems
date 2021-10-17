#include <bits/stdc++.h>

using namespace std;

int main(void) {
  vector<int> v;

  int temp;
  for (int i = 0; i < 5; ++i) {
    cin >> temp;

    temp = temp * temp;
    v.push_back(temp);
  }

  int ans;

  ans = accumulate(v.begin(), v.end(), 0);

  cout << ans % 10 << endl;

  return 0;
}
