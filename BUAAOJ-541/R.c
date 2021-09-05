#include <stdio.h>

int weight[100005];

int main() {
  // init
  int n, m, w;
  scanf("%d%d%d", &n, &m, &w);
  w -= m;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &weight[i]);
  }

  // double pointer
  int left = 0, right = n - 1;
  int ans = 0;
  while (left <= right) {
    if (weight[left] + weight[right] <= w) {
      left += 1;
      right -= 1;
    } else {
      right -= 1;
    }
    ans++;
  }
  printf("%d", ans);

  return 0;
}