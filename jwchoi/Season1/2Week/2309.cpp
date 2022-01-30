#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main(void) {
  vector<int> elf(9);

  for (int i = 0; i < 9; ++i) {
    cin >> elf[i];
  }

  int sum = accumulate(elf.begin(), elf.end(), 0);
  sort(elf.begin(), elf.end());

  for (int i = 0; i < 9; ++i) {
    for (int j = i + 1; j < 9; ++j) {
      if (sum - (elf[i] + elf[j]) == 100) {
        cout << endl;

        for (int k = 0; k < 9; ++k) {
          if (k == i || k == j)
            continue;

          cout << elf[k] << endl;
        }
      }
    }
  }

  return 0;
}
