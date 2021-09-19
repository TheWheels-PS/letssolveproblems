/*
dp[i][j] = i번째 층에서 j인덱스의 수를 선택한 경우의 합
*/
#include <algorithm>
#include <iostream>

#define SIZE 501

using namespace std;

int py[SIZE][SIZE];
int dp[SIZE][SIZE];

int main(void) {
  int N, sum = 0;

  cin >> N;

  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= i; ++j) {
      cin >> py[i][j];
    }
  }

  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= i; ++j) {
      dp[i][j] =
    }
  }

  return 0;
}
