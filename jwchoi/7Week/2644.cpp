#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

int ans = -1;

void DFS(int p1, int p2, int cnt) {
  int next;

  visited[p1] = true;

  if (p1 == p2) {
    ans = cnt;
  }

  for (int i = 0; i < adj[p1].size(); ++i) {
    next = adj[p1][i];

    if (!visited[next]) {
      DFS(next, p2, cnt + 1);
    }
  }
}

int main(void) {
  int n, p1, p2, m, x, y, cnt = 0;

  cin >> n >> p1 >> p2 >> m;

  adj.resize(n + 1);

  for (int i = 0; i < m; ++i) {
    cin >> x >> y;

    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  visited = vector<bool>(m + 1, false);

  DFS(p1, p2, cnt);

  cout << ans;

  return 0;
}
