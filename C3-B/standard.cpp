#include <bits/stdc++.h>
using namespace std;

long long k[10005], dp[10005];

int main() {
  int v;
  scanf("%d", &v);
  for (int i = 1; i <= v; ++i) scanf("%d", &k[i]);
  for (int i = 1; i <= v; ++i) {
    for (int j = 1; j <= i; ++j) {
      dp[i] = max(dp[i], dp[i - j] + k[j]);
    }
  }
  printf("%lld", dp[v]);
  return 0;
}