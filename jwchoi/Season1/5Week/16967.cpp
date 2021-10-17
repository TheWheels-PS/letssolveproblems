/*
배열 복원하기
https://www.minigb.io/85?category=928819 을 참고했음.

전체적인 흐름을 파악하고 B[i][j] -= B[i - X][j - Y]; 을 생각함.

하지만 조건을 생각하는 것이 조금 시간이 걸렸는데,
솔직히 조건에서 &&는 혹시? 라는 생각으로 설마해서 넣어보긴 했음.

솔직히 명확한 해결방안이 생각나지 않아서 전체적인 흐름의 연산을 생각하고
조건은 손으로 구현해본 과정을 보면서 감으로 맞춘 경향임.

또한 질문

백준에서 채점시간이 굉장히 오래걸렸는데, 다른 사람들 코드는 어떤지 궁금함.
*/

#include <iostream>

using namespace std;

#define SIZE 601

int main(void) {
  int B[SIZE][SIZE];

  int H, W, X, Y;

  cin >> H >> W >> X >> Y;

  // 입력과정
  for (int i = 0; i < H + X; i++) {
    for (int j = 0; j < W + Y; j++) {
      cin >> B[i][j];
    }
  }

  // 연산과정
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (i >= X && j >= Y)
        B[i][j] -= B[i - X][j - Y];
    }
  }

  // 연산결과 출력과정
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      cout << B[i][j] << ' ';
    }
    cout << endl;
  }

  return 0;
}
