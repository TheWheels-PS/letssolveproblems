#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int line, num = 0;

  int temp;

  cin >> line;

  dp.resize(line + 1);

  for (int i = 0; i < line; ++i) {
    for (int j = 0; j <= i; ++j) {
      cin >> temp;

      dp[i].push_back(temp);
    }
  }

  for (int i = 1; i < line; ++i) {
    for (int j = 0; j <= i; ++j) {
      dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
    }
  }

  for (int i = 0; i < line; ++i) {
    num = max(num, dp[line - 1][i]);
  }

  cout << num;

  return 0;
}