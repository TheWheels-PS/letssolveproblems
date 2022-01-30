#include <iostream>
#include <queue>

#define MAX 1001

using namespace std;

int m, n, days = 0;

// 익은 토마토의 위치를 중심으로 상하좌우에 존재하는 것들을 확인하기 위함
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

int box[MAX][MAX];

// Pair class
queue<pair<int, int>> q;

// 검사할 때 박스 밖으로 나가지 않기 위해
bool isInside(int row, int col) {
  return 0 <= row && 0 <= col && row < n && col < m;
}

void Solve(void) {
  // 박스에 익은 토마토의 위치를 바로 큐에 저장
  // 큐의 특징인 선입선출에 의해서 초기 익은 토마토의 위치가 몇 개가 되었든
  // 하루가 지나기 전에 전부 재고려한다
  while (!q.empty()) {
    int row = q.front().first;
    int col = q.front().second;
    q.pop();

    for (int i = 0; i < 4; ++i) {
      int tRow = row + dr[i];
      int tCol = col + dc[i];

      if (isInside(tRow, tCol) == 1 && box[tRow][tCol] == 0) {
        box[tRow][tCol] = box[row][col] + 1;
        q.push({tRow, tCol});
      }
    }
  }
}

int main(void) {
  // 입력은 가로, 세로이지만 배열은 행과 열로 판단해야 한다
  cin >> m >> n;
  for (int row = 0; row < n; ++row) {
    for (int col = 0; col < m; ++col) {
      cin >> box[row][col];

      // 익은 토마토이면 바로 큐에 저장
      if (box[row][col] == 1) {
        q.push({row, col});
      }
    }
  }

  Solve();

  for (int row = 0; row < n; ++row) {
    for (int col = 0; col < m; ++col) {
      if (box[row][col] == 0) {
        cout << -1 << endl;
        return 0;
      }

      if (days < box[row][col])
        days = box[row][col];
    }
  }

  cout << days - 1 << endl;

  return 0;
}
