#include <algorithm>
#include <iostream>

using namespace std;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m, l;
  int ary[51][51];
  string temp;

  cin >> n >> m;

  l = min(n, m);

  for (int i = 0; i < n; ++i) {
    cin >> temp;

    for (int j = 0; j < m; ++j) {
      ary[i][j] = temp[j] - '0';
    }
  }

  int result = 1;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int k = 1; k < l; ++k) {
        if (i + k < n && j + k < m) {
          if (ary[i][j] == ary[i + k][j] && ary[i][j] == ary[i][j + k] &&
              ary[i][j] == ary[i + k][j + k]) {
            result = max(result, k + 1);
          }
        }
      }
    }
  }

  cout << result * result << endl;
}