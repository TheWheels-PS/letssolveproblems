// 바이러스
#include <stdio.h>
#define MAX 101

int N, M, count;
int arr[MAX][MAX];
int visited[MAX];
void DFS(int start) {
  int i;
  visited[start] = 1;

  for (i = 1; i <= N; i++) {
    if (arr[start][i] && !visited[i]) {
      count++;
      DFS(i);
    }
  }
  return;
}

int main(void) {
  scanf("%d", &N);
  scanf("%d", &M);
  int a, b;
  for (int i = 0; i < M; i++) {
    scanf("%d %d", &a, &b);
    arr[a][b] = 1;
    arr[b][a] = 1;
  }

  DFS(1);

  printf("%d\n", count);

  return 0;
}