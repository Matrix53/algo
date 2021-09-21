#include <stdio.h>
int main() {
  int n, ans = 0;
  scanf("%d", &n);
  for (int i = 1; i < n; i <<= 1) ans++;
  printf("%d\n", ans);
  for (int i = 0; i < ans; ++i) {
    int m = 0;
    for (int j = 1; j <= n; ++j) {
      if (j & (1 << i)) m++;
    }
    printf("%d ", m);
    for (int j = 1; j <= n; ++j) {
      if (j & (1 << i)) {
        printf("%d ", j);
      }
    }
    printf("\n");
  }
  return 0;
}