#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[505][505];

int main() {
  int n, m, p;
  scanf("%d%d%d", &n, &m, &p);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      dp[i][j] = LONG_LONG_MAX;
    }
    dp[i][i] = 0;
  }
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    dp[u][v] = min(dp[u][v], ll(w));
  }
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (dp[i][k] != LONG_LONG_MAX && dp[k][j] != LONG_LONG_MAX &&
            dp[i][k] + dp[k][j] < dp[i][j]) {
          dp[i][j] = dp[i][k] + dp[k][j];
        }
      }
    }
  }
  while (p--) {
    int u, v;
    scanf("%d%d", &u, &v);
    printf("%lld\n", dp[u][v] == LONG_LONG_MAX ? -1 : dp[u][v]);
  }
  return 0;
}