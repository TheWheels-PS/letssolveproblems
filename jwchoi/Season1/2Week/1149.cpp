/*
RGB 거리

i번째 집에서 각각 RGB로 칠했을 때 발생하는 비용 중 최솟값
그리고 N번째, N - 1번째, N + 1 번째 집들 간의 규칙이 지켜졌을 때

참고한 해설 : https://cryptosalamander.tistory.com/84
*/

#include <algorithm>
#include <iostream>

using namespace std;

int House[1001][3] = {
    0,
};

int main(void) {
  int cnt;
  int price[3] = {
      0,
  };

  cin >> cnt;

  for (int i = 1; i <= cnt; ++i) {
    cin >> price[0] >> price[1] >> price[2];

    // i - 1 연산을 하기 때문에, 배열의 인덱스 값을 1부터 시작
    House[i][0] = min(House[i - 1][1], House[i - 1][2]) + price[0];
    House[i][1] = min(House[i - 1][0], House[i - 1][2]) + price[1];
    House[i][2] = min(House[i - 1][0], House[i - 1][1]) + price[2];
  }

  cout << min(min(House[cnt][0], House[cnt][1]), House[cnt][2]) << endl;
}
