#include <bits/stdc++.h>
using namespace std;

const int MAX_SUM = 250005;

bool dp[MAX_SUM];

int main() {
  // freopen("D:/Workspace/algo/BUAAOJ-X/Matrix53-C4-F/data/2.in", "r", stdin);
  int n, x, sum = 0;
  dp[0] = true;
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &x);
    sum += x;
    for (int i = MAX_SUM; i >= x; --i) {
      if (dp[i - x]) dp[i] = true;
    }
  }
  for (int i = sum / 2; i >= 0; --i) {
    if (dp[i]) {
      x = i;
      break;
    }
  }
  printf("%d", sum - x * 2);
  return 0;
}