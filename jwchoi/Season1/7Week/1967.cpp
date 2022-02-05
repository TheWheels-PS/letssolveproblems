#include <cstring>
#include <iostream>
#include <vector>

#define MAX 10002

using namespace std;

vector<pair<int, int>> vertex[MAX];
bool visit[MAX] = {false};
// temp 같은 경우는 Recursive를 사용하는 DFS의 성격에 따라
// 재선언을 하지 않도록 전역변수를 취해줌
int destination, diameter = 0;

void DFS(int v, int l) {
  visit[v] = true;

  if (l > diameter) {
    diameter = l;
    destination = v;
  }

  for (int i = 0; i < vertex[v].size(); ++i) {
    int next = vertex[v][i].first;
    if (!visit[next]) {
      int nLength = vertex[v][i].second;
      DFS(next, nLength + l);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int parent, child, length, vCnt;

  // Insert count of vertex
  cin >> vCnt;

  // Connect vertex
  for (int i = 0; i < vCnt - 1; ++i) {
    cin >> parent >> child >> length;
    vertex[parent].push_back({child, length});
    vertex[child].push_back({parent, length});
  }

  DFS(1, 0);
  memset(visit, false, sizeof(visit));
  diameter = 0;
  DFS(destination, 0);
  cout << diameter << endl;
  return 0;
}
