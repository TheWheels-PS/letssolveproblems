#include <iostream>

using namespace std;

int sol(int n) { return (n + 1) / 2; }

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int answer = 0, total, p1, p2;

  cin >> total >> p1 >> p2;

  while (total) {
    p1 = sol(p1);
    p2 = sol(p2);

    if (p1 == p2) {
      ++answer;
      break;
    } else {
      ++answer;
    }
    total = sol(total);
  }

  cout << answer << endl;

  return 0;
}
