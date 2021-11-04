#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;

long long dp[maxn][maxn], w[maxn][maxn];
int f[maxn], p[maxn], root[maxn][maxn];

int main() {
  // freopen("D:/Workspace/algo/BUAAOJ-X/Matrix53-E4-C/data/1.in", "r", stdin);
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%lld", &f[i]);
  for (int i = 0; i <= n; ++i) scanf("%lld", &p[i]);
  for (int i = 1; i <= n; ++i) {
    root[i][i] = i;
    w[i][i] = f[i] + p[i - 1] + p[i];
    dp[i][i] = w[i][i];
  }
  for (int len = 1; len < n; ++len) {
    for (int l = 1; l <= n - len; ++l) {
      int r = l + len;
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
  printf("%lld", dp[1][n]);
  return 0;
}