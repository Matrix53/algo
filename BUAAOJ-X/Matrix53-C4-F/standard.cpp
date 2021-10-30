#include <cstdio>
#define MAX_SUM 250005

bool dp[MAX_SUM];

int main() {
  int n, x, i, sum = 0;
  dp[0] = true;
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &x);
    sum += x;
    for (i = MAX_SUM; i >= x; --i) {
      if (dp[i - x]) dp[i] = true;
    }
  }
  for (i = sum / 2; i >= 0; --i) {
    if (dp[i]) {
      printf("%d", sum - i * 2);
      return 0;
    }
  }
}