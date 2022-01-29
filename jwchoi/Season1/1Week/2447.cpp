#include <bits/stdc++.h>

using namespace std;

void solve(int i, int j, int N) {
  // 공백 처리
  if ((i / N) % 3 == 1 && (j / N) % 3 == 1) {
    cout << " ";
    return;
  } else {
    int div = N / 3;

    if (div == 0) {
      cout << "*";
      return;
    } else {
      solve(i, j, div);
    }
  }
}

int main(void) {
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      solve(i, j, N);
    }
    cout << endl;
  }

  return 0;
}
