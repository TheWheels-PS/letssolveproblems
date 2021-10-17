/*
이건 무슨 지랄을 한거니
이 문제는 굉장히 쉬운 문제인데, 허허허...
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int n;
  cin >> n;

  int *a = new int(n);

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int *m = max_element(a, a + n);
  int result_f, result_b;

  for (int *i = a; i <= m; ++i) {
    if (max(*i, *max_element(a, i)) == *i) {
      ++result_f;
    }
  }

  int *last = a + (n - 1);

  for (int *k = last; k >= m; --k) {
    if (max(*k, *max_element(k, last)) == *k) {
      ++result_b;
    }
  }

  cout << result_f << endl;
  cout << result_b << endl;

  return 0;
}
