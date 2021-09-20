#include <stdio.h>
typedef long long ll;
int a[200005];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  ll x;
  scanf("%lld", &x);
  ll ans = a[0];
  for (int i = 1; i <= n; ++i) {
    ans *= x;
    ans += a[i];
    ans %= 998244353;
  }
  printf("%lld", ans);
  return 0;
}