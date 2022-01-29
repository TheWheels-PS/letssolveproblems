#include <iostream>

using namespace std;

void Solution(int N, int B) {
  int temp;

  temp = N / B;

  if (N != 0) {
    Solution(temp, B);

    // 10진법이 넘어갈 때
    /*
    B > 10이 쉽게 생각할 수 있는 10진법을 넘어설 때
    하지만 이 조건만 달면 10진법을 넘지 않는 경우에도 싹다 10진법이 넘는
    상황으로 계산이 되기 떄문에, B > 10이어도 B <= 10일 때는 숫자로 출력할 수
    있도록 처리
    */
    if (N % B >= 10 && B > 10) {
      printf("%c", 'A' + (N % B) - 10);
    } else {
      printf("%d", N % B);
    }
  }
}

int main(void) {
  int N, B;

  scanf("%d%d", &N, &B);
  Solution(N, B);

  return 0;
}
