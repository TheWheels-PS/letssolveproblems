#include <stdio.h>
#include <string.h>

int main() {
  char words[101];
  int len = 0;
  int cnt = 0;
  int cnt_c = 0;

  scanf("%s", words);
  len = strlen(words);

  for (int i = 0; i < len; ++i) {
    if (words[i] == 'c') {
      if (words[i + 1] == '=' || words[i + 1] == '-') {
        ++cnt_c;
      }
    } else if (words[i] == 'd') {
      if (words[i + 1] == 'z' && words[i + 2] == '=') {
        ++cnt_c;
      } else if (words[i + 1] == '-') {
        ++cnt_c;
      }
    } else if (words[i] == 'j') {
      if (words[i - 1] == 'l' || words[i - 1] == 'n') {
        ++cnt_c;
      }
    } else if (words[i] == '=') {
      if (words[i - 1] == 's' || words[i - 1] == 'z') {
        ++cnt_c;
      }
    }
  }

  printf("%d", len - cnt_c);

  return 0;
}
