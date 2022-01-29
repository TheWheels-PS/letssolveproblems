#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int graph[100][100] = {
      0,
  };
  int user[4];

  for (int i = 0; i < 4; ++i) {
    cin >> user[0] >> user[1] >> user[2] >> user[3];

    for (int j = user[0]; j < user[2]; ++j) {
      for (int k = user[1]; k < user[3]; ++k) {
        ++graph[j][k];
      }
    }
  }

  int cnt = 0;

  for (int i = 0; i < 100; ++i) {
    for (int j = 0; j < 100; ++j) {
      if (graph[i][j] > 0)
        ++cnt;
    }
  }

  cout << cnt;

  return 0;
}
