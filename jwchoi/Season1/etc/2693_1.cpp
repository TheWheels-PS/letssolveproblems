#include <bits/stdc++.h>

using namespace std;

vector<int> v[10];

int main(void) {
  int t;

  cin >> t;

  int temp;

  for (int i = 0; i < t; ++i) {
    for (int j = 0; j < 10; ++j) {
      cin >> temp;

      v[i].push_back(temp);
    }
    sort(v[i].begin(), v[i].end());
    cout << v[i][7] << endl;
  }

  return 0;
}
