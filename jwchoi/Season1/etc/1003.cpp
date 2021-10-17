#include <bits/stdc++.h>

using namespace std;

long long zero[41], one[41];

long long z(int n) {
  if (n == 0)
    return 1;
  else if (n == 1)
    return 0;
  else if (zero[n])
    return zero[n];

  return zero[n] = z(n - 1) + z(n - 2);
}

long long o(int n) {
  if (n == 0)
    return 0;
  else if (n == 1)
    return 1;
  else if (one[n])
    return one[n];

  return one[n] = o(n - 1) + o(n - 2);
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int time, input;
  long long zero, one;

  cin >> time;

  for (int i = 0; i < time; ++i) {
    cin >> input;

    cout << z(input) << " " << o(input) << endl;
  }

  return 0;
}