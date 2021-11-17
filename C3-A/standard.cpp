// Author: Matrix53
#include <bits/stdc++.h>
using namespace std;

long long dp[100005];

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  while (n--) {
    int v, w;
    scanf("%d%d", &v, &w);
    for (int i = k; i >= w; --i) {
      dp[i] = max(dp[i], dp[i - w] + v);
    }
  }
  printf("%lld", dp[k]);
  return 0;
}