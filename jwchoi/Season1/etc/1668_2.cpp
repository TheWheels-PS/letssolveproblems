#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;

  vector<int> v;

  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> m;
    v.push_back(m);
  }

  int left = 1, right = 1, temp;

  temp = v[0];

  for (int i = 0; i < n; ++i) {
    if (temp < v[i]) {
      temp = v[i];
      ++left;
    }
  }

  temp = v[n - 1];

  for (int i = v.size() - 1; i >= 0; --i) {
    if (temp < v[i]) {
      temp = v[i];
      ++right;
    }
  }

  cout << left << endl;
  cout << right << endl;

  return 0;
}
