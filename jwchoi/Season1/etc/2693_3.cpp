#include <bits/stdc++.h>

using namespace std;

vector<int> v(10, 0);

int main(void) {
  int t;

  cin >> t;

  int temp;

  for (int i = 0; i < t; ++i) {
    for (int j = 0; j < 10; ++j) {
      cin >> temp;
      v[j] = temp;
    }
    sort(v.begin(), v.end());
    cout << v[7] << endl;
  }

  return 0;
}
