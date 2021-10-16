#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll mod = 998244353;
const int maxn = 1e5 + 5;

pll data[maxn];

bool isLower(pll a, pll b) {
  return a.first * b.second + b.first > b.first * a.second + a.first;
}

int main() {
  // freopen("D:\\Workspace\\algo\\BUAAOJ-X\\Matrix53-5\\data\\1.in", "r",
  // stdin);
  int n;
  scanf("%d", &n);
  for (int i = 0; i <= n; ++i) scanf("%lld", &data[i].first);
  for (int i = 0; i <= n; ++i) scanf("%lld", &data[i].second);
  sort(data, data + n + 1, isLower);
  ll ans = 0;
  for (int i = 0; i <= n; ++i)
    ans = (ans * data[i].second + data[i].first) % mod;
  printf("%lld", ans);
  return 0;
}