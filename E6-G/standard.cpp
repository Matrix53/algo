#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;

long long dp[maxn][maxn], w[maxn][maxn];
int f[maxn], p[maxn], root[maxn][maxn];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%lld", &f[i]);
  for (int i = 0; i <= n; ++i) scanf("%lld", &p[i]);
  for (int i = 1; i <= n + 1; ++i) {
    root[i][i - 1] = i;
    dp[i][i - 1] = p[i - 1];
    w[i][i - 1] = p[i - 1];
  }
  for (int len = 1; len <= n; ++len) {
    for (int l = 1; l <= n - len + 1; ++l) {
      int r = l + len - 1;
      dp[l][r] = LONG_LONG_MAX;
      w[l][r] = w[l][r - 1] + f[r] + p[r];
      for (int mid = root[l][r - 1]; mid <= root[l + 1][r]; ++mid) {
        long long sum = dp[l][mid - 1] + dp[mid + 1][r] + w[l][r];
        if (dp[l][r] > sum) {
          dp[l][r] = sum;
          root[l][r] = mid;
        }
      }
    }
  }
  long long ans = LONG_LONG_MAX;
  for (int i = 1; i <= n; ++i) {
    if (i != root[1][n]) {
      ans = min(ans, dp[1][i - 1] + dp[i + 1][n] + w[1][n]);
    }
  }
  for (int i = 1; i < root[1][n]; ++i) {
    if (i != root[1][root[1][n] - 1]) {
      ans =
          min(ans, dp[1][i - 1] + dp[i + 1][root[1][n] - 1] +
                       w[1][root[1][n] - 1] + dp[root[1][n] + 1][n] + w[1][n]);
    }
  }
  for (int i = root[1][n] + 1; i <= n; ++i) {
    if (i != root[root[1][n] + 1][n]) {
      ans = min(ans, dp[1][root[1][n] - 1] + dp[root[1][n] + 1][i - 1] +
                         dp[i + 1][n] + w[root[1][n] + 1][n] + w[1][n]);
    }
  }
  printf("%lld", ans);
  return 0;
}