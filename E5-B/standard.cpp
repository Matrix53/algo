#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[505][505], g[505][505];

int main() {
  int n, m, p;
  scanf("%d%d%d", &n, &m, &p);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      g[i][j] = LONG_LONG_MAX;
      dp[i][j] = LONG_LONG_MAX;
    }
    g[i][i] = 0;
    dp[i][i] = 0;
  }
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    g[u][v] = min(g[u][v], ll(w));
  }
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (g[i][k] != LONG_LONG_MAX && g[k][j] != LONG_LONG_MAX &&
            g[i][k] + g[k][j] < dp[i][j]) {
          dp[i][j] = g[i][k] + g[k][j];
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