/*
이왜맞?

두 번째 for문에서 int i = 1로 초기조건을 수정했기만 했는데, 정답이 되었다.
*/

#include <algorithm>
#include <iostream>

using namespace std;

#define SIZE 501

int dp[SIZE][SIZE] = {0};

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int line, num = 0;

  cin >> line;

  for (int i = 0; i < line; ++i) {
    for (int j = 0; j <= i; ++j) {
      cin >> dp[i][j];
    }
  }

  for (int i = 1; i < line; ++i) {
    for (int j = 0; j <= i; ++j) {
      dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
    }
  }

  // for (int i = 0; i < line; ++i) {
  //   for (int j = 0; j <= i; ++j) {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  for (int i = 0; i < line; ++i) {
    num = max(num, dp[line - 1][i]);
  }

  cout << num;

  return 0;
}
