// 타일 채우기
#include <bits/stdc++.h>
#define Max 31

using namespace std;

int shapeA[Max], shapeB[Max], shapeC[Max];

int main(void) {
  int n;
  cin >> n;
  shapeA[1] = shapeB[1] = shapeC[1] = 0;
  shapeA[2] = shapeB[2] = 1;
  shapeC[2] = 3;
  for (int i = 3; i <= n; i++) {
    shapeA[i] = shapeA[i - 2] + shapeC[i - 2];
    shapeB[i] = shapeB[i - 2] + shapeC[i - 2];
    shapeC[i] = shapeA[i] + shapeB[i] + shapeC[i - 2];
  }
  cout << shapeC[n] << "\n";
  return 0;
}