#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
const int N = 2e5 + 5;

// (cost,value)
pll a[N], b[N];

int main() {
  // read data
  ll n, x, m, ans = LONG_LONG_MAX;
  int cntA, cntB;
  scanf("%lld%d%d", &n, &cntA, &cntB);
  scanf("%lld%lld", &x, &m);
  for (int i = 0; i < cntA; ++i) scanf("%lld", &a[i].first);
  for (int i = 0; i < cntA; ++i) scanf("%lld", &a[i].second);
  for (int i = cntB - 1; i >= 0; --i) scanf("%lld", &b[i].first);
  for (int i = cntB - 1; i >= 0; --i) scanf("%lld", &b[i].second);

  // preprocess
  a[cntA] = make_pair(0, x);
  b[cntB] = make_pair(0, 0);
  for (int i = 0; i < cntB; ++i) b[i].first = -b[i].first;

  // traverse A and use B greedily
  for (int i = 0; i <= cntA; ++i) {
    if (a[i].first > m) {
      ans = min(ans, n * x);
    } else {
      ll m_left = m - a[i].first;
      int pos = lower_bound(b, b + cntB, make_pair(-m_left, 0LL)) - b;
      ans = min(ans, a[i].second * (n - b[pos].second));
    }
  }

  // print answer
  printf("%lld", ans);
  return 0;
}