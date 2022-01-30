// Hanoi
#include <bits/stdc++.h>

using namespace std;

void Hanoi(int N, int A, int B, int C) {
  if (N == 1) {
    printf("%d %d\n", A, C);
    return;
  } else {
    Hanoi(N - 1, A, C, B);
    printf("%d %d\n", A, C);
    Hanoi(N - 1, B, A, C);
    return;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N;
  cin >> N;
  // Can't use long long either
  // cout << cntHanoi(N) << endl;
  string ans = to_string(pow(2, N));
  int pos = ans.find('.');
  ans = ans.substr(0, pos);
  ans[ans.length() - 1] -= 1;
  cout << ans << endl;

  if (N <= 20)
    Hanoi(N, 1, 2, 3);
  return 0;
}
