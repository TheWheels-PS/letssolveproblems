#include <bits/stdc++.h>

using namespace std;

vector<int> v(9);

void sol() {
  int sum = accumulate(v.begin(), v.end(), 0);

  for (int i = 0; i < 9; ++i) {
    for (int j = i + 1; j < 9; ++j) {
      if (sum - (v[i] + v[j]) == 100) {
        v[i] = 0;
        v[j] = 0;
        return;
      }
    }
  }
}

int main(void) {
  int temp;

  vector<int>::iterator iter;

  for (int i = 0; i < 9; ++i) {
    cin >> temp;
    v[i] = temp;
  }

  sol();

  sort(v.begin(), v.end());

  for (int i = 0; i < 9; ++i) {
    if (v[i] == 0) {
      continue;
    } else {
      cout << v[i] << endl;
    }
  }

  return 0;
}
