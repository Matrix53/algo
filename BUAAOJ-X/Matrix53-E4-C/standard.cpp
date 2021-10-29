#include <bits/stdc++.h>
using namespace std;

long long dp[100005];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  while (n--) {
    int v, w;
    scanf("%d%d", &v, &w);
    for (int i = 0; i <= m - w; ++i) {
      dp[i + w] = max(dp[i + w], dp[i] + v);
    }
  }
  printf("%lld", dp[m]);
  return 0;
}