/*
루트노드에서 각각의 리프노드까지의 깊이를 전부 더한 값을 구하는 것이 포인트
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v;
vector<bool> visited;

int total = 0;

void DFS(int vertex) {
  if (v[vertex].size() == 1 && vertex != 1) {
    ++total;
  }

  /*
  total 값을 구현하는 것이 난관
  */

  visited[vertex] = true;

  for (int i = 0; i < v[vertex].size(); ++i) {
    int next = v[vertex][i];

    if (visited[next] == false) {
      DFS(next);
    }
  }
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int vcnt, a, b;

  cin >> vcnt;

  v.resize(vcnt + 1);

  for (int i = 0; i < vcnt - 1; ++i) {
    cin >> a >> b;

    v[a].push_back(b);
    v[b].push_back(a);
  }

  visited = vector<bool>(vcnt + 1, false);

  DFS(1);

  if (total % 2 == 1)
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}
