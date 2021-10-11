#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll mod = 998244353;
const int maxn = 1e5 + 5;

pll data[maxn];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%lld", &data[i].first);
  for (int i = 0; i < n; ++i) scanf("%lld", &data[i].second);
  return 0;
}