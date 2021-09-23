/* 1932V를 반복자를 사용하여 구할 수 있는가? */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  vector<vector<int>>::iterator iter;

  int line, num = 0, temp;

  cin >> line;

  dp.resize(line + 1);
}