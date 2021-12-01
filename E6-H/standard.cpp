// Author: Matrix53
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e3 + 5;

ll dp[maxn][maxn], w[maxn][maxn];
int f[maxn], p[maxn], root[maxn][maxn];

ll dfs(int l, int r) {
  ll res = LONG_LONG_MAX;
  if (l + 1 == r) {
    int k = l + r - root[l][r];
    res = dp[l][k - 1] + dp[k + 1][r] + w[l][r];
  } else {
    if (2 <= root[l][r] - 1 - l + 1)
      res = min(res, dfs(l, root[l][r] - 1) + dp[root[l][r] + 1][r] + w[l][r]);
    if (2 <= r - root[l][r] - 1 + 1)
      res = min(res, dfs(root[l][r] + 1, r) + dp[l][root[l][r] - 1] + w[l][r]);
    for (int i = l; i <= r; ++i) {
      if (i != root[l][r]) {
        res = min(res, dp[l][i - 1] + dp[i + 1][r] + w[l][r]);
      }
    }
  }
  return res;
}

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
        ll sum = dp[l][mid - 1] + dp[mid + 1][r] + w[l][r];
        if (dp[l][r] > sum) {
          dp[l][r] = sum;
          root[l][r] = mid;
        }
      }
    }
  }
  printf("%lld", dfs(1, n));
  return 0;
}