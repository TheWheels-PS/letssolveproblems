#include <algorithm>
#include <iostream>
#include <vector>

#define SIZE 100001

using namespace std;

vector<bool> visited;
vector< vector<int> > adj;

int parent[SIZE];

void DFS(int vertex) {
  visited[vertex] = true;

  for (int i = 0; i < adj[vertex].size(); ++i) {
    int next = adj[vertex][i];

    if (visited[next] == false) {
      parent[next] = vertex;

      DFS(next);
    }
  }
}

int main(void) {
  int N;
  int node1, node2;

  cin >> N;

  adj.resize(N + 1);

  for (int i = 0; i < N - 1; ++i) {
    cin >> node1 >> node2;

    adj[node1].push_back(node2);
    adj[node2].push_back(node1);
  }

  visited = vector<bool>(N + 1, false);
  for (int i = 0; i < adj.size(); ++i) {
    sort(adj[i].begin(), adj[i].end());
  }

  DFS(1);

  for (int i = 2; i <= N; ++i)
    cout << parent[i] << " ";

  return 0;
}
