/*
그리디 알고리즘을 사용한 방법이다.

Q1
처음에 제출을 했을 때는, 에러가 발생했는데
백준에서 이유를 올려준 걸 보니까 bag가 초기화가 되지 않았다고 해서 틀렸음
그래서 bag = 0으로 초기화를 해주었는데 맞았다.
vsc에서는 딱히 0으로 초기화 하지 않아도 문제가 없던데, 왜 그런 것인감?

Q2
DP로 푸는 방법이 이해가 가지 않는다.
2839A1.cpp 코드에 인터넷에서 해설을 본 해결방법이 있는데 설명이 필요함
*/

#include <iostream>

using namespace std;

int main(void) {
  int n = 0, bag = 0;

  cin >> n;

  while (n >= 0) {
    if (n % 5 == 0) {
      bag += (n / 5);
      cout << bag << endl;
      return 0;
    }

    n -= 3;

    ++bag;
  }

  cout << -1 << endl;

  return 0;
}