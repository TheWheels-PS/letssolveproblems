
#include <stdio.h>
#include <string.h>

int main() {
  char string[1000001];

  gets(string);

  int len = strlen(string);
  int lIdx = len - 1;
  int cnt = 0;

  for (int i = 0; i < len; ++i) {
    if (string[i] == ' ') {
      ++cnt;
    }
  }

  ++cnt;

  if (string[0] == ' ')
    --cnt;

  if (string[lIdx] == ' ')
    --cnt;

  printf("%d", cnt);

  return 0;
}
