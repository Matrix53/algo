#include <math.h>
#include <stdio.h>
#include <string.h>

int char2Int(char* start, int length) {
  int ans = 0;
  for (int i = length - 1; i >= 0; --i) {
    ans *= 10;
    ans += *(start + i) - '0';
  }
  return ans;
}

char num[100005];

int main() {
  int n;
  while (~scanf("%d", &n)) {
    memset(num, '0', sizeof(num));
    for (int i = 0; i < n; ++i) {
      scanf(" %c", &num[i]);
    }

    // 2
    if (char2Int(num, 1) % 2 == 0) {
      printf("Smash it with 2!\n");
      continue;
    }

    // 3
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += char2Int(num + i, 1);
    }
    if (sum % 3 == 0) {
      printf("Smash it with 3!\n");
      continue;
    }

    // 5
    if (char2Int(num, 1) % 5 == 0) {
      printf("Smash it with 5!\n");
      continue;
    }

    // 7, 11, 13
    int ans = 0;
    for (int i = 0; i < n; i += 3) {
      if (i % 2 == 0) {
        ans += char2Int(num + i, 3);
      } else {
        ans -= char2Int(num + i, 3);
      }
    }
    ans = abs(ans);
    int mod[] = {7, 11, 13};
    int i = 0;
    for (; i < 3; ++i) {
      if (ans % mod[i] == 0) {
        printf("Smash it with %d!\n", mod[i]);
        break;
      }
    }

    // other
    if (i == 3) printf("qwq\n");
  }
  return 0;
}