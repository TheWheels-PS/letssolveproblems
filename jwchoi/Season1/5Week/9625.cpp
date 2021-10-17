/*
문제를 분석하다보니까 피보나치 수열인 것을 확인
이후 재귀함수로 문제를 구현하려고 하니까 시간초과 문제 발생
그래서 반복문을 사용해서 문제해결
*/

#include <iostream>

using namespace std;

int main(void) {
  int n;

  int A[46], B[46];

  A[0] = 0;
  A[1] = 1;

  B[0] = 1;
  B[1] = 1;

  cin >> n;

  if (n >= 2) {
    for (int i = 2; i < n; ++i) {
      A[i] = A[i - 2] + A[i - 1];
      B[i] = B[i - 2] + B[i - 1];
    }
  }
  cout << A[n - 1] << " " << B[n - 1] << endl;

  return 0;
}
