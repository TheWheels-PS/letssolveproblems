#include <iostream>
#include <vector>

using namespace std;

int d[31][31];

int C(int a, int b) {
  if (a == b || b == 0)
    return 1;
  else if (d[a][b])
    return d[a][b];
  else
    return d[a][b] = C(a - 1, b - 1) + C(a - 1, b);
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, a, b;
  vector<int> v;
  vector<int>::iterator iter;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a >> b;
    v.push_back(C(b, a));
  }

  for (iter = v.begin(); iter != v.end(); ++iter) {
    cout << *iter << endl;
  }
}
