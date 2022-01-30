#include <iostream>
#include <queue>

#define SIZE 1001

using namespace std;

int N, M, V;

int map[SIZE][SIZE] = {0};
bool visited[SIZE] = {false};
queue<int> q;

void init() {
  for (int i = 1; i <= N; ++i)
    visited[i] = false;
}

void DFS(int v) {
  visited[v] = true;

  cout << v << " ";

  for (int i = 1; i <= N; ++i) {
    // 연결이 되었고 가본 적이 없는 정점일 때
    if (map[v][i] == 1 && visited[i] == 0)
      DFS(i);
  }
}

void BFS(int vertex) {
  q.push(vertex);
  visited[vertex] = true;
  cout << vertex << " ";

  while (!q.empty()) {
    vertex = q.front();
    q.pop();

    for (int i = 1; i <= N; ++i) {
      // 현재 정점과 연결되어 있고, 방문한 적이 없을 때
      if (map[vertex][i] == 1 && visited[i] == false) {
        q.push(i);
        visited[i] = true;
        cout << i << " ";
      }
    }
  }
}

int main(void) {
  int a, b;

  cin >> N >> M >> V;

  for (int i = 0; i < M; ++i) {
    cin >> a >> b;

    map[a][b] = 1;
    map[b][a] = 1;
  }

  DFS(V);

  init();
  cout << endl;

  BFS(V);

  return 0;
}
