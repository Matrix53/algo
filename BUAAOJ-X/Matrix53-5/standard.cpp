#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll mod = 998244353;

pll data[100005];

bool isLower(pll a, pll b) {
  return a.first * b.second + a.second < b.first * a.second + b.second;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%lld", &data[i].first);
  for (int i = 0; i < n; ++i) scanf("%lld", &data[i].second);
  sort(data, data + n, isLower);
  for (int i = 0; i < n; ++i)
    printf("%lld %lld\n", data[i].first, data[i].second);
  return 0;
}