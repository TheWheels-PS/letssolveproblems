#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int n, temp;
  vector<int> v;

  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> temp;
    v.push_back(temp);
  }

  sort(v.begin(), v.end());

  cout << v[0] * v[n - 1] << endl;

  return 0;
}
